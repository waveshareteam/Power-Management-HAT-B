# Power-Management-HAT-B
[Power Management HAT (B)](https://www.waveshare.com/power-management-hat-b.htm) Example code
## Example
### 1. Button_Ctr
* Power on or off by the PWR button
1. If Raspberry Pi is off
    * Press PWR button to start Raspberry Pi
2. If Raspberry Pi is on
    * Long-press PWR button for 2s~8s, Raspberry Pi will be first software shutdown and then cut off power
    * Long-press PWR button for more than 8s to directly cut off power of Raspberry Pi.
### 2. Period_Time
* Power on or off by Period_Time
1. Power on when Power_On_Time（default 9：00:30）
2. Power off when Power_Off_Time （default 10：00:00）
### 3. Cycle
* Power on or off by Cycle
1. Power_On_Keep_Time（default 1800S）
2. Power_Off_Keep_Time（default 3600S）
## Version Description
### V1.0
* First release
### V1.1
* Add cycle function, default：turning on 1800S  and turning off 3600s
* Fix the issue where STA did not wait when the timing switch was started for the first time
* Add Readme Description


# Power-Management-HAT-B
[Power Management HAT (B)](https://www.waveshare.net/shop/Power-Management-HAT-B.htm) Example code
## Example
### 1. Button_Ctr
* 使用PWR按键开关机
1. 当树莓派关机
    * 按下PWR按键则开机
2. 当树莓派开机
    * 长按PWR按键超过2S但不到8S，尝试将树莓派软关机
    * 长按PWR按键超过8S则尝试直接掐断电源
### 2. Period_Time
* 定时开关机
1. 当时间到达指定时间Power_On_Time（默认为 9：00:30）时开机
2. 当时间到达指定时间Power_Off_Time （默认为 10：00:00）时关机
### 3. Cycle
* 循环开关机
1. 保持开机时间Power_On_Keep_Time（默认为1800S）
2. 保持关机机时间Power_Off_Keep_Time（默认为3600S）
## 版本描述
### V1.0
* 初次提交
### V1.1
* 增加 循环开关机功能，默认开机1800S，关机3600S
* 修复定时开关机 初次开机STA没有等待的问题
* 增加readme描述