/*****************************************************************************
* | File        :   Period_Time.h
* | Author      :   Waveshare team 
* | Function    :   
* | Info        :   Period_Time Demo
*----------------
* |	This version:   V1.0
* | Date        :   2022-10-01
* | Info        :   
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "examples.h"

#define USE_CURRENT_TO_CHECK_PI_STATUS 0

#if USE_CURRENT_TO_CHECK_PI_STATUS
#define Shutdown_Current_Ma 320
#endif

static const char *Bool_Str[2] = {"off", "on"};

struct repeating_timer timer;

extern Power_All_State Read_State;

static datetime_t Set_Time = {
    .year = 2022,
    .month = 10,
    .day = 01,
    .dotw = 6,
    .hour = 9,
    .min = 0,
    .sec = 0};
static datetime_t Power_On_Time = {
    .hour = 9,
    .min = 0,
    .sec = 30};
static datetime_t Power_Off_Time = {
    .hour = 10,
    .min = 0,
    .sec = 0};
/******************************************************************************
    function: Timer_Callback
    brief : The Timer Callback and Output Power State
    parameter:
        t   :   The timer struct
******************************************************************************/
static bool Timer_Callback(struct repeating_timer *t)
{
    char datetime_buf[256];
    char *datetime_str = &datetime_buf[0];
    datetime_t Now_time;
    PCF85063A_Read_now(&Now_time);
    datetime_to_str(datetime_str, sizeof(datetime_buf), &Now_time);
    printf("Now_time is %s \r\n",datetime_str);
    Read_State = Power_State_Get_All();
    printf("Power_State : %d \r\n", Read_State.Power_State);
    printf("Rtc_State : %d \r\n", Read_State.Rtc_State);
    printf("Running_State : %d \r\n", Read_State.Running_State);

    printf("Vin_Voltage(V) : %.2f \r\n", Read_State.Vin_Voltage);
    printf("Vout_Voltage(V) : %.2f \r\n", Read_State.Vout_Voltage);
    printf("Vout_Current(MA) : %.2f \r\n", Read_State.Vout_Current);


#if USE_CURRENT_TO_CHECK_PI_STATUS
    // If the power is on, there is no running flag and it is not in a change state
    if (Read_State.Power_State && (!Read_State.Running_State) && (!Read_State.Change_State))
    {
        // Check whether the current is lower than the shutdown current
        if (Check_Runing_State_By_CURRENT(Shutdown_Current_Ma) == false)
        {
            Debug("detected current low.\r\n");
            Power_off();
        }
        Read_State = Power_State_Get_All();
    }
#endif
    printf("\r\n\r\n\r\n");
}
/******************************************************************************
    function: Period_Time_Init
    brief : Initialize Period Time function
    parameter:
******************************************************************************/
void Period_Time_Init(void)
{
    Power_init();
    Power_on_by_Period_Time_Init(&Set_Time,&Power_On_Time,&Power_Off_Time);
    //Power_on_by_Period_Time_Init((void *)NULL,&Power_On_Time,&Power_Off_Time);
    add_repeating_timer_ms(1500, Timer_Callback, NULL, &timer);
}
/******************************************************************************
    function: Period_Time_Loop
    brief : loop function that handles Period Time events,need a loop call
    parameter:
******************************************************************************/
void Period_Time_Loop(void)
{
    Power_Ctrl_By_Period_Time();
}