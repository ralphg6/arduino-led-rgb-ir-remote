#include <IRremote.h>

#define pino_recept 7
IRrecv receptor(pino_recept);
int ultimopin = 13;
decode_results results;
void setup() {
  Serial.begin(9600);
  receptor.enableIRIn();
}

void loop() {
  if (receptor.decode(&results)) {
    Serial.println(results.value);
    switch (results.value) {
      case 16780815: 
        RGB(255,0,0);
        break;
      case 16813711: 
        RGB(0,255,0);
        break;
      case 16830159: 
        RGB(0,0,255);
        break;
      case 16797263: 
        RGB(255,255,255);
        break;
     }
     receptor.resume();
   }
}

void RGB(int r, int g, int b) {
  analogWrite(A0, r);
  analogWrite(A1, g);
  analogWrite(A2, b);
}
