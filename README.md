# ArduinoLGACremoteTimer
Simple project - Just send power on / mode 1 / mode 2 and wait 30 min, then power off and wait 30 min. 

Using Arduino's IRremote lib.(https://github.com/z3t0/Arduino-IRremote) examples, 
I got IR RAW data as well as LG code # for PowerOn,Mode1,Mode2,and PowerOff. 
Then, just send it using irsend.sendLG(0xXYZXYZXY, 28); whileas irsend.sendRAW() is not working well for mode1 key. 
So, I used onboard LED as indicator as follows:
LONG once : Power On
SHORT once : Mode 1
SHORT twice : Mode 2
SHORT three times: Power Off

1) to send Power On / delay 5s
2) to send Mode 1 / delay 2s/ Mode 2 / 
3) to wait 30 min/20m/15m for 2hours / 3hours / 4 hours
4) to send Power off 
5) to wait 30 min/40m/45m for 2hours / 3hours / 4hours
That's all folks,

Hope to use my code easily.
