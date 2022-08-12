//TTL 2 way sniffer
//for an ESP32 devkit

//pins d2 and d17 are connected to the BMS-BLE serial wires 

//from BLE
#define RXD1 2 //data line from BLE module to BMS
#define TXD1 4 //not connected to anything

//from BMS
#define RXD2 17 //data line from BMS to BLE module
#define TXD2 16 //not connected to anything

volatile bool RXorTX;
byte inByte;

void setup() {
  //to serial console, speed can be whtever you want
  Serial.begin(115200);
  while (!Serial) {
    ;
  }

  //the BMS is 9600 baud
  Serial1.begin(9600, SERIAL_8N1, RXD1, TXD1);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

}

void loop() {

  if (Serial2.available() && RXorTX){
    RXorTX = false;
    Serial.println();
    Serial.print("from BMS: ");
  }
  while (Serial2.available()) {
    inByte = char(Serial2.read());
    if ( inByte < 0x10 ){
      Serial.print("0");
    }
    Serial.print(inByte, HEX);
    Serial.print(" ");
  }

  delay(10);
  
  if (Serial1.available() && !RXorTX){
    RXorTX = true;
    Serial.println();
    Serial.println();
    Serial.print("from BLE: ");
  }
  while (Serial1.available()) {
    inByte = char(Serial1.read());
    if ( inByte < 0x10 ){
      Serial.print("0");
    }
    Serial.print(inByte, HEX);
    Serial.print(" ");
  }

  delay(10);
  
}
