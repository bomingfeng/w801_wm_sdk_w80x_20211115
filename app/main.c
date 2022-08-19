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
		tls_os_time_delay(1000 / (1000 / HZ));
		printf("\n demo_Test_task\n");
	}
}

void UserMain(void)
{
	printf("\n Main task Run ing...\n");

#if DEMO_CONSOLE
	CreateDemoTask();
	printf("\n user task \n");
#endif
//�û��Լ���task


/* tls_os_task_create(
            tls_os_task_t * task,           ������	
            const char * name,              ������������
            void(*)(void *param) entry,     ������
            void * param,                   ���ݵĲ���
            u8 * stk_start,                 ����ջ��ʼ��ַ
            u32 stk_size,                   ����ջ��С
            u32 prio,                       �������ȼ�
            u32 flag                        ���ӵ�������Ϊ��Ϣ 
*/
    tls_os_task_create(NULL, NULL,
                       demo_Test_task,
                       NULL,
                       (void *)TestTaskStk,          /* task's stack start address */
                       Test_TASK_SIZE * sizeof(u32), /* task's stack size, unit:byte */
                       DEMO_TASK_PRIO,
                       0);
}

