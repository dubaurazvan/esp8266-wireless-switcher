/*
Some random cgi routines.
*/

/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Jeroen Domburg <jeroen@spritesmods.com> wrote this file. As long as you retain 
 * this notice you can do whatever you want with this stuff. If we meet some day, 
 * and you think this stuff is worth it, you can buy me a beer in return. 
 * 
 * Razvan Dubau <dubau_razvan@yahoo.com> modified some of the files. So you can give 
 * me a beer and 2 beers to Jeroen.
 * ----------------------------------------------------------------------------
 */


#include <string.h>
#include <osapi.h>
#include "user_interface.h"
#include "mem.h"
#include "httpd.h"
#include "cgi.h"
#include "io.h"
#include "espmissingincludes.h"

//Cgi that turns the LED on or off according to the 'led' param in the POST data
int ICACHE_FLASH_ATTR cgiGpio02(HttpdConnData *connData) {
        int requestedState;
	char buff[1024];
	
	if (connData->conn==NULL) {
		//Connection aborted. Clean up.
		return HTTPD_CGI_DONE;
	}

	httpdFindArg(connData->postBuff, "value", buff, sizeof(buff));
        
        requestedState = atoi(buff);
        
        os_printf("%d  vasilooooon \n", requestedState);
        
        //currLedState=atoi(buff);
        ioLed(requestedState);

	httpdRedirect(connData, "api/gpio02.tpl");
	return HTTPD_CGI_DONE;
}



//Template code for the led page.
void ICACHE_FLASH_ATTR tplApiGpio02(HttpdConnData *connData, char *token, void **arg) {
	char buff[128];
	if (token==NULL) return;

        os_printf("%d", ioGetGpio02());
        os_printf(" after the number \n");
        
	os_strcpy(buff, "Unknown");
	if (os_strcmp(token, "ledstate")==0) {
		if (ioGetGpio02() == 1) {
			os_strcpy(buff, "on");
		} else {
			os_strcpy(buff, "off");
		}
	}
	espconn_sent(connData->conn, (uint8 *)buff, os_strlen(buff));
}

//Template code for device name page
void ICACHE_FLASH_ATTR tplApiDeviceInfo(HttpdConnData *connData, char *token, void **arg) {
        struct ip_info pTempIp;
	char buff[128];
        char temp[64];
        
	if (token==NULL) return;
	
        wifi_get_ip_info(0x00, &pTempIp);
        
        os_strcmp(token, "IP");
        if(pTempIp.ip.addr != 0)
        {
            os_sprintf(temp, "%d.%d.%d.%d",
                     IP2STR(&pTempIp.ip));
          
            os_strcpy(buff, temp);
        }
        else
        {
          os_strcpy(buff, "No IP");
        }
	espconn_sent(connData->conn, (uint8 *)buff, os_strlen(buff));
}