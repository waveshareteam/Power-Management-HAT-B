/*****************************************************************************
* | File        :   Button_Ctr.h
* | Author      :   Waveshare team 
* | Function    :   
* | Info        :   Button_Ctr Demo
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

#if USE_CURRENT_TO_CHECK_PI_STATUS
#define Shutdown_Current_Ma 320
#endif
Power_All_State Read_State;
static struct repeating_timer timer;
/******************************************************************************
    function: Timer_Callback
    brief : The Timer Callback and Output Power State
    parameter:
        t   :   The timer struct
******************************************************************************/
static bool Timer_Callback(struct repeating_timer *t)
{
    Read_State = Power_State_Get_All();
    //Now power supply State
    printf("Power_State (): %d \r\n", Read_State.Power_State);
    //Now Raspberry Pi Run State (Based on GPIO,need to run Python script)
    printf("Running_State : %d \r\n", Read_State.Running_State);
    //Now the power input voltage, It could be USB voltage or Li-battery voltage
    printf("Vin_Voltage(V) : %.2f \r\n", Read_State.Vin_Voltage);
    //Now the power output voltage，
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
    function: Button_Ctr_Init
    brief : Initialize the Button function
    parameter:
******************************************************************************/
void Button_Ctr_Init(void)
{
    
    Power_init();
    MP28167_Default_Config();
    add_repeating_timer_ms(1500, Timer_Callback, NULL, &timer);
}
/******************************************************************************
    function: Button_Ctr_Loop
    brief : loop function that handles button events,need a loop call
    parameter:
******************************************************************************/
void Button_Ctr_Loop(void)
{
    static bool power_state, running_state;
    power_state = Power_Ctrl_By_Button();
}
