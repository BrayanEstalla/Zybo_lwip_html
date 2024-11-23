//--- freeRTOS Example Application

#include <stdio.h>
#include "xparameters.h"
#include "xil_io.h"

#include "freeRTOS.h"
#include "task.h"
#include "portmacro.h"
#include "lwipopts.h"

/*
int adcdata;

void task_ADC (void *p)
{
	while (1)
	{
		vTaskDelay (100);  // 10 Hz

		adcdata  = Xil_In32(0x43C00000) & 0xFFF;
		printf ("Adc: %d = %3.1f \n", adcdata,   (3.3/4095.0) * adcdata );
	}
}
 */


/*
int LedCnt;
int LedSpeed;

void task_GPIO(void *p)
{
	LedCnt	 = 0;
	LedSpeed = 500;
	while (1)
	{
		vTaskDelay (LedSpeed);
		Xil_Out32(XPAR_AXI_GPIO_0_BASEADDR, LedCnt);
		LedCnt++;
	}

}


void printTaskList (void)
{
char hstr[1024];
	printf ("  Task       State   Priority   Stack    \n");
	printf ("**********************************************\n" );
	vTaskList(hstr);  // Then the list of tasks and their status...
	printf (hstr);
	printf ("----------------------------------------------\n" );
}


void task_ConsoleIn (void *p)
{
char inp[32];
	while (1)
	{
		scanf ("%s", inp);
		printf ("%s \n", inp);

		switch (inp[0])
		{
			case 't' :	printTaskList ();
						break;
			case 'r' :	LedCnt=0;
						break;
			case '+' :	if (LedSpeed>100) LedSpeed -= 100;
						break;
			case '-' :	LedSpeed -= 100;
						break;

		}
		vTaskDelay (100);
	}
}
*/


void task_Print (void *p)
{
int i;
	i=0;
	while (1)
	{
		printf ("Hello World %d \n", i);
		i++;
		vTaskDelay (2000);
	}
}


int main()
{
	xTaskCreate (task_Print,  		(char*)"Print", 2048, NULL, DEFAULT_THREAD_PRIO, NULL);
//	xTaskCreate (task_GPIO,  		(char*)"GPIO",  2048, NULL, DEFAULT_THREAD_PRIO, NULL);
//	xTaskCreate (task_ConsoleIn,  	(char*)"ConIn", 2048, NULL, DEFAULT_THREAD_PRIO, NULL);

	vTaskStartScheduler();
    while(1);
    return 0;
}

