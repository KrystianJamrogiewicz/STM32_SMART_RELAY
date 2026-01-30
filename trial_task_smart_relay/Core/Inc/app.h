/*
 * app.h
 *
 *  Created on: Jan 29, 2026
 *      Author: kryst
 */

#ifndef INC_APP_H_
#define INC_APP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"


// Application I/O initial state setup
void App_Init(void);

// Application main loop
void App_Loop(void);



#ifdef __cplusplus
}
#endif


#endif /* INC_APP_H_ */
