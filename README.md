# esp8266-wireless-switcher
A custom firmware to transform the ESP8266 wifi module into a wifi http based switcher

GPIO02 is used as an output pin. You can connect a led or a relay and controll it by a button added to GPIO00.
Also the firmware provides a web interface and a simple API that will controll the GPIO02 state.

# API DOC
> Set GPIO02 output to active.
```bash
POST http://{ipAddress}/gpio02.cgi
Request Body: value=1
```

> Set GPIO02 output to inactive.
```bash
POST http://{ipAddress}/gpio02.cgi
Request Body: value=0
```

> Returns the GPIO02 status as a string (on|off)
```bash
GET http://{ipAddress}/api/gpio02.tpl
```

> Returns device info in JSON format.
```bash
GET http://{ipAddress}/api/device-info.tpl
```

# Connect your device to your home network

Search for a network called "ESPxxxxx" and connect.
Now you can access the interface using this: http://192.168.4.1

Use http://192.168.4.1/wifi and connect the wifi module to your home network.

You can find the IP of module inside your home network on the main page: http://192.168.4.1

Now you have the IP and you can connect to your home network back and access the module using that IP
