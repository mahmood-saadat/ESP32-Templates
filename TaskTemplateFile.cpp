/*
 * TemplateFile.cpp
 *
 *  Created on: Nov 18, 2021
 *      Author: M.Saadat (m.saadat@mail.com)
 * This file provide as is with no garantee of any sort.
 * Any modification and redistribution of this file is allowed as long as this discription is kept at the top of the file.
 */

#include "TemplateFile.h"
#include <esp_task_wdt.h>

TemplateFile templateFile;

TemplateFile::TemplateFile(){
	mainTask = NULL;
}

/*
 * Initialize the class
 */
void TemplateFile::begin(){
	DEBUG_println("[Template] Setup is started ...");

	xTaskCreate((TaskFunction_t)TemplateFile::TaskStart, "TemplateFileTask", 4096, this, 20, &mainTask);

	DEBUG_println("[Template] Setup is done.");

}

/*
 * Task function needed to be static and in static members, we could not access class members easily,
 * so we created this function and we passed the class as input argument, then we call our main function from here.
 */
TaskFunction_t TemplateFile::TaskStart(void * pvParameters){
	TemplateFile* manager;
	esp_task_wdt_init(WDT_TASK_TIMEOUT, true);
	esp_task_wdt_add(NULL);
	manager = (TemplateFile*) pvParameters;
	manager->MainTask();
	// It will never get here. The main task never returns.
	return 0;
}
/*
 * The main loop
 */
void TemplateFile::MainTask() {
	// First check the activation; we need to disable the main function because we are going to send .bin file to users
	while(!activation.IsDeviceActivated()){
		esp_task_wdt_reset();
		vDelay_ms(10000);
	}

	while(1){
		esp_task_wdt_reset();

		PrintStackWatermark();
		vDelay_ms(60000);
	}
}

void TemplateFile::PrintStackWatermark(){
	if(millis() > (stackWatermarkPrintLastMillis + 60000)){
		stackWatermarkPrintLastMillis = millis();
		DEBUG_printf("[Template] Task Stack left: %d\r\n", uxTaskGetStackHighWaterMark(NULL));
	}
}



