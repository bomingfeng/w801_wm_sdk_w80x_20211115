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

#define    Test_TASK_SIZE      2048
static OS_STK 			TestTaskStk[Test_TASK_SIZE];

void demo_Test_task(void *sdata)
{
	for(;;){
		
	}
}

void UserMain(void)
{
	printf("\n user task \n");

#if DEMO_CONSOLE
	CreateDemoTask();
#endif
//用户自己的task
    tls_os_task_create(NULL, NULL,
                       demo_Test_task,
                       NULL,
                       (void *)TestTaskStk,          /* task's stack start address */
                       Test_TASK_SIZE * sizeof(u32), /* task's stack size, unit:byte */
                       DEMO_TASK_PRIO,
                       0);
/* tls_os_task_create(
            tls_os_task_t * task,           任务句柄	
            const char * name,              命名的任务名
            void(*)(void *param) entry,     任务函数
            void * param,                   传递的参数
            u8 * stk_start,                 任务栈起始地址
            u32 stk_size,                   任务栈大小
            u32 prio,                       任务优先级
            u32 flag                        附加的任务行为信息 
*/
}

