#pragma once

#include "esp_log.h"
#include "esp32s3/rom/rtc.h"

void print_reset_reason(int reason)
{
  switch ( reason)
  {
    case 1 : log_i("POWERON_RESET");break;          /**<1,  Vbat power on reset*/
    case 3 : log_i("SW_RESET");break;               /**<3,  Software reset digital core*/
    case 4 : log_i("OWDT_RESET");break;             /**<4,  Legacy watch dog reset digital core*/
    case 5 : log_i("DEEPSLEEP_RESET");break;        /**<5,  Deep Sleep reset digital core*/
    case 6 : log_i("SDIO_RESET");break;             /**<6,  Reset by SLC module, reset digital core*/
    case 7 : log_i("TG0WDT_SYS_RESET");break;       /**<7,  Timer Group0 Watch dog reset digital core*/
    case 8 : log_i("TG1WDT_SYS_RESET");break;       /**<8,  Timer Group1 Watch dog reset digital core*/
    case 9 : log_i("RTCWDT_SYS_RESET");break;       /**<9,  RTC Watch dog Reset digital core*/
    case 10 : log_i("INTRUSION_RESET");break;       /**<10, Instrusion tested to reset CPU*/
    case 11 : log_i("TGWDT_CPU_RESET");break;       /**<11, Time Group reset CPU*/
    case 12 : log_i("SW_CPU_RESET");break;          /**<12, Software reset CPU*/
    case 13 : log_i("RTCWDT_CPU_RESET");break;      /**<13, RTC Watch dog Reset CPU*/
    case 14 : log_i("EXT_CPU_RESET");break;         /**<14, for APP CPU, reseted by PRO CPU*/
    case 15 : log_i("RTCWDT_BROWN_OUT_RESET");break;/**<15, Reset when the vdd voltage is not stable*/
    case 16 : log_i("RTCWDT_RTC_RESET");break;      /**<16, RTC Watch dog reset digital core and rtc module*/
    default : log_i("NO_MEAN");
  }
}

void print_reset_reason() {
  log_i("CPU0 reset reason:");
  print_reset_reason(rtc_get_reset_reason(0));

  log_i("CPU1 reset reason:");
  print_reset_reason(rtc_get_reset_reason(1));
}