//This code assumes the OLED display is connected using I2C (SDA to pin 21, SCL to pin 22 on ESP32) and the 
//ultrasonic sensor is connected with its trigger pin to pin 18 and its echo pin to pin 19 on the ESP32.
//Adjust the pin numbers and connections as needed for your setup.

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

#define TRIGGER_PIN 18
#define ECHO_PIN    19

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  long duration, distance;
  
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Distance: ");
  display.print(distance);
  display.print(" cm");
  display.display();

  delay(1000);
}
