#ifndef CGI_H
#define CGI_H

#include "httpd.h"

int cgiGpio02(HttpdConnData *connData);
void tplApiGpio02(HttpdConnData *connData, char *token, void **arg);
void tplApiDeviceInfo(HttpdConnData *connData, char *token, void **arg);

#endif