/*****************************************************************************
* | File        :   examples.h
* | Author      :   Waveshare team 
* | Function    :   
* | Info        :   examples Demo
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
#ifndef _EXAMPLES_H_
#define _EXAMPLES_H_

#include "GUI_Paint.h"
#include "DEV_Config.h"
#include "LCD_1in14_V2.h"
#include "pico/multicore.h"
#include "Power_Management_Lib.h"
#include "MP28167.h"

#define USE_CURRENT_TO_CHECK_PI_STATUS 0


void Button_Ctr_Init(void);
void Button_Ctr_Loop(void);

void Period_Time_Init(void);
void Period_Time_Loop(void);

#endif
