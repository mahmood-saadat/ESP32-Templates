/*
 * TemplateFile.h
 *
 *  Created on: Nov 18, 2021
 *      Author: M.Saadat (m.saadat@mail.com)
 * This file provide as is with no garantee of any sort.
 * Any modification and redistribution of this file is allowed as long as this discription is kept at the top of the file.
 *
 *  V1.0.0: Base release
 */

#ifndef __TEMPLATEMANAGER_H__
#define __TEMPLATEMANAGER_H__

#include "../Functions/Global/Global.h"
#include "../Functions/Global/types.h"
#include "../Functions/Flash/Flash.h"
#include "../Functions/Activation.h"

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