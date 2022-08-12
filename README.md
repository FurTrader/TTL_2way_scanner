# TTL_2way_scanner
 A handy 2 way TTL serial sniffer on an ESP32
 
 The data is sent to the USB port in ascii for compatability with the arduino serial monitor,     
 reformatted to display HEX bytes with spaces between. 

This would also work on an Arduino MEGA, just change the tx/rx pins
  
## Example output:
```
11:45:30.864 -> from BLE: DD A5 03 00 FF FD 77 
11:45:30.910 -> from BMS: DD 03 00 1B 0A 7E 00 00 27 0A 27 10 00 00 29 8A 00 00 00 00 00 00 16 64 03 08 02 0B 95 0B 95 FC 7B 77 
11:45:31.003 -> 
11:45:31.003 -> from BLE: DD A5 04 00 FF FC 77 
11:45:31.003 -> from BMS: DD 04 00 10 0D 08 0D 30 0D 34 0D 36 0D 09 0D 08 0D 09 0D 34 FE 98 77 
11:45:31.096 -> 
11:45:31.096 -> from BLE: DD A5 05 00 FF FB 77 
11:45:31.143 -> from BMS: DD 05 00 19 4A 42 44 2D 53 50 31 30 53 30 30 39 2D 4C 38 53 2D 31 30 30 41 2D 42 2D 4B FA 10 77 
```

## Pic
    
![the thing](https://github.com/FurTrader/TTL_2way_scanner/raw/main/Image%20from%20iOS.jpg)


