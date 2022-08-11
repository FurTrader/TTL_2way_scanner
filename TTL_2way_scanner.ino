//TTL 2 way sniffer
//for an ESP32 devkit

//pins d2 and d17 are RX

//from BLE
#define RXD1 2
#define TXD1 4

//from BMS
#define RXD2 17
#define TXD2 16

volatile bool RXorTX;
byte inByte;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

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
  
}
