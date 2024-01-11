#include <Keyboard.h>

int keyPins[8] = {7,6,14,15,9,8,10,16};
int keySwitch[8] = {0,1,2,3,4,5,6,7};

size_t skeyPins = sizeof(keyPins) / sizeof(keyPins[0]);

char conf[][10] = {
  "MACRO", "MACRO", "MACRO", "del",
  "f15", "f16", "f17", "f18"
  };

void startexe(){
  Serial.print("starting exe\n");
  Keyboard.press(KEY_RIGHT_GUI);
  delay(50);
  Keyboard.releaseAll();
  delay(100);
}
void enter(){
  delay(50);
  Keyboard.write(KEY_RETURN);
  delay(50);
}
void write(byte val){
  Keyboard.write(val);
}

void writeKey(char key[]){
  if(strcmp(key, "del") == 0){
    Keyboard.write(0xD4);
  }
  else if(strcmp(key, "f15") == 0){
    Keyboard.write(0xF2);
  }
  else if(strcmp(key, "f16") == 0){
    Keyboard.write(0xF3);
  }
  else if(strcmp(key, "f17") == 0){
    Keyboard.write(0xF4);
  }
  else if(strcmp(key, "f18") == 0){
    Keyboard.write(0xF5);
  }
}


void macros(int k) {
  switch (k){
    case 0:
      // key 1 macro   
      // put the code here:
      startexe();
      Keyboard.write(0x44);
      Keyboard.write(0x69);
      Keyboard.write(0x73);
      Keyboard.write(0x63);
      Keyboard.write(0x6F);
      Keyboard.write(0x72);
      Keyboard.write(0x64);
      enter();
      break;
      
    case 1:
      // key 2 macro  
      // put the code here:

      startexe();
      write(0x45);
      write(0x70);
      write(0x69);
      write(0x63);
      write(0x20);
      write(0x47);
      write(0x61);
      write(0x6D);
      write(0x65);
      write(0x73);
      write(0x20);
      write(0x4C);
      write(0x61);
      write(0x75);
      write(0x6E);
      write(0x63);
      write(0x68);
      write(0x65);
      write(0x72);
      enter();   
      break;
      
    case 2:
     // key 3 macro
     //put the code here:
      startexe();
      write(0x53);
      write(0x74);
      write(0x65);
      write(0x61);
      write(0x6D);
      enter();
      break;
      
    case 3:
      //key 4 macro
      // put the code here:
      
      break; 
  }
}

void setup() {
  for(int x=0;x<skeyPins;x++){
    pinMode(keyPins[x], INPUT);
    digitalWrite(keyPins[x], HIGH);
  }
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  for(int x=0;x<skeyPins;x++){
    if(digitalRead(keyPins[x]) == LOW){
      int k = keySwitch[x];
      int val = strcmp(conf[x], "MACRO");
      if(val == 0)
      {
        Serial.print(conf[x]);
        Serial.print("\n");
        macros(k);
      }
      else{
        Serial.print(conf[x]);
        Serial.print("\n");
        writeKey(conf[x]);
      }
      delay(200);
    }
  }
}
