# Protokoll

## Commands (dringend)

Folgende Methoden sollen implementiert werden, um grundlegende Funktionalität zu gewährleisten:

### UVC LEDs
```
parameters              :   onOffStatus:Boolean
return value(s)         :   none
potential status codes  :   none
example                 :   "UVC ON"
```
### FAN
```
parameters              :   onOffStatus:Boolean
return value(s)         :   none
potential status codes  :   none
example                 :   "FAN ON"
```

### LED stripe
```
parameters              :   colorMode:String
return value(s)         :   none
potential status codes  :   UNKNOWN_COLOR
example                 :   "LEDSTRIPE RAINBOW"
```

COLOR           |   MEANING
-------------   |   -------------
RAINBOW         |   default
NOWIFI          |   no WIFI connection (yellow)
DEVICEOPEN      |   device open (red)


## Commands (zweitrangig)

Folgende Methoden sollen implementiert werden, um anwenderfreundliche Bedienung zu gewährleisten:

### GETSTATUS [module]
```
parameters              :   module:String
return value(s)         :   status:Boolean
potential status codes  :   MODULE_NOT_FOUND
example                 :   "GETSTATUS FAN"
```
