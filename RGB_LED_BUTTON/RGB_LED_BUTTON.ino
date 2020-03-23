int redPin= 3;// Red Color to pin 3 on the Arduino
int greenPin = 5;//Green Color to pin 5 on the Arduino
int bluePin = 6;//Blue Color to pin 6 on the Arduino
int buttonApin = 8;//anther button  to pin 8 on the Arduino
int greenLighPin = 9;//anther button  to pin 8 on the Arduino
int remain = 0;  // 0.5 second
int count_second = 5400; // 1.5 hours
bool On = false; // if the light shines.
int type_cnt = 7;
int colors[][3] = {
  {150, 0, 0},{0, 150, 0},{0, 0, 150},
  {0, 100, 100},{100, 0, 100}, {100, 100, 0}, 
  {150, 150, 150}, 
};

// In the setup section we need to define redPin, greenPin and bluePin as outputs.
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenLighPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP); 
}

void loop() {  
  if (digitalRead(buttonApin) == LOW) {
      remain = count_second * 2; 
      digitalWrite(greenLighPin,HIGH);      
  }
  if (remain > 0) {
    --remain;
    if (remain == 0) {
      digitalWrite(greenLighPin,LOW);
    }
  }
  delay(500);
}

void loop_light_on() {
  switchButton();
  if (On) {
    digitalWrite(greenLighPin,HIGH);
  } else {
    digitalWrite(greenLighPin,LOW);
  }
  delay(500);
}


void loop_led() {  
  for (int i = 0; i < type_cnt; ++i) {
    if (On) setColor(colors[i][0], colors[i][1], colors[i][2]);
    switchButton();
    if (!On) setColor(0,0,0); 
    delay(500);  
  }  
}

void all_color(int step) {  
  for (int i = 0; i < type_cnt; ++i) {
    if (On) setColor(colors[i][0], colors[i][1], colors[i][2]);
    switchButton();
    if (!On) setColor(0,0,0); 
    delay(500);  
  }  
}

void switchButton() {
  if (digitalRead(buttonApin) == LOW) {
    On = !On;       
  }
}
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

