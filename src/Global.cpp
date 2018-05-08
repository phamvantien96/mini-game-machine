/** @file Global.cpp
 *  @author Tien.P.V
 *  @date 07-May-2018
 */

#include "Global.h"

unsigned long TimerCount;
unsigned long Semaphore;
unsigned long FrameCount=0;

Entity Thuy((point_t) {120-12, 160-16}, 1, img_thuy);
dir_t joystick_dir = STAY;

