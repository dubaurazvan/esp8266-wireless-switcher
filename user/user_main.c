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

#include "espmissingincludes.h"
#include "osapi.h"

#include "ets_sys.h"
#include "httpd.h"
#include "io.h"
#include "httpdespfs.h"
#include "cgi.h"
#include "cgiwifi.h"
#include "stdout.h"
#include "user_interface.h"

HttpdBuiltInUrl builtInUrls[]={
	{"/", cgiRedirect, "/index.tpl"},
	
	//{"/index.tpl", cgiEspFsTemplate, tplIndex},
	//{"/gpio02.tpl", cgiEspFsTemplate, tplGpio02},
        {"/gpio02.cgi", cgiGpio02, NULL},
        
        // API routing
        {"/api/device-info.tpl", cgiEspFsTemplate, tplApiDeviceInfo},
        {"/api/gpio02.tpl", cgiEspFsTemplate, tplApiGpio02},
        
	//Routines to make the /wifi URL and everything beneath it work.
	{"/wifi", cgiRedirect, "/wifi/wifi.tpl"},
	{"/wifi/", cgiRedirect, "/wifi/wifi.tpl"},
	{"/wifi/wifiscan.cgi", cgiWiFiScan, NULL},
	{"/wifi/wifi.tpl", cgiEspFsTemplate, tplWlan},
	{"/wifi/connect.cgi", cgiWiFiConnect},

	{"*", cgiEspFsHook, NULL}, //Catch-all cgi function for the filesystem
	{NULL, NULL, NULL}
};

void user_init(void) {
    stdoutInit();
    ioInit();
    httpdInit(builtInUrls, 80);
    os_printf("\nReady\n");
}
