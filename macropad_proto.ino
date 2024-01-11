#include <Keyboard.h>

int k0 = 5;
int k1 = 6;

int keyPins[] = {k0, k1};
int keyPresses[] = {0, 1};

void press_key(int k){
  switch(k){
    case 0:
      Serial.print("key 1");
      break;
    case 1:
      Serial.print("key 2");
      break;
  }
}

void setup() {
  // put your setup code here, to run once:====================================================
  Keyboard.begin();
}

size_t s = sizeof(keyPins) / sizeof(keyPins[0]);
void loop() {
  delay(5000);
  Keyboard.press(KEY_LEFT_GUI);
//  Keyboard.press("r");
  delay(50);
  Keyboard.releaseAll();
//  delay(50);=KM=KM=K=K=K
//  Keyboard.write("C:/Users/isaac/AppData/Local/Discord/app-1.0.9028/Discord.exe");
//  delay(50);
//  Keyboard.press("KEY_RETURN");
//  Keyboard.releaseAll();
}
