/*
 * TemplateFile.h
 *
 *  Created on: Nov 18, 2021
 *      Author: M.Saadat (m.saadat@mail.com)
 * Github: https://github.com/mahmood-saadat/ESP32-Templates/tree/master/Task%20Templates
 * This file provide as is with no guarantee of any sort.
 * Any modification and redistribution of this file is allowed as long as this description is kept at the top of the file.
 *
 *  V1.0.0: Base release
 */

#ifndef __TEMPLATEMANAGER_H__
#define __TEMPLATEMANAGER_H__


class TemplateFile{
public:
	//------------------------------ Public static variables  -------------------------------

private:
	//------------------------------ Private static variables  ------------------------------

	//------------------------------ Private variables  -------------------------------------
	TaskHandle_t 			mainTask;
	uint32_t				stackWatermarkPrintLastMillis = 0;

public:
	//------------------------------ Public functions  -------------------------------------
	TemplateFile();
	void begin();
	

protected:

private:
	//------------------------------ Private functions  ------------------------------------
	static TaskFunction_t 	TaskStart(void * pvParameters);
	void 					MainTask();
	void					PrintStackWatermark();
};

extern TemplateFile templateFile;
#endif
