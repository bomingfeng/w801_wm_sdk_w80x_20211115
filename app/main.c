/***************************************************************************** 
* 
* File Name : main.c
* 
* Description: main 
* 
* Copyright (c) 2014 Winner Micro Electronic Design Co., Ltd. 
* All rights reserved. 
* 
* Author : dave
* 
* Date : 2014-6-14
*****************************************************************************/ 
#include "wm_include.h"

void UserMain(void)
{
	printf("\n Main task Run ing...\n");

#if DEMO_CONSOLE
	CreateDemoTask();
	printf("\n user task \n");
#endif
//用户自己的task
}

