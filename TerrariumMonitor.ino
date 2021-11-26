/*
ME 313: Final Project - Lizard Tank Monitor
Samuel Gregg | Justin Rhodes

Documentation and snippets provided by:
Rui Santos - Random Nerd Tutorials
Jim Lindblom - SparkFun Electronics
Owen Lyke - SparkFun Electronics
*/

// Temperature sensor initialization
  #include <OneWire.h>
  #include <DallasTemperature.h>
  #define ONE_WIRE_BUS 4
  OneWire oneWire(ONE_WIRE_BUS);
  DallasTemperature sensors(&oneWire);

// Light sensor initialization
  const int LIGHT_PIN = A0;               // Pin connected to voltage divider output
  const int LED_PIN = 13;                 // Use built-in LED as dark indicator
  const float VCC = 4.98;                 // Measured voltage of Ardunio 5V line
  const float R_DIV = 4660.0;             // Measured resistance of 3.3k resistor

// Humidity Sensor Initialization
  #include "SparkFun_SHTC3.h" 
  SHTC3 mySHTC3;                          // Declare an instance of the SHTC3 class

// LCD Screen Initialization
#include <LiquidCrystal.h> 
int Contrast=135;                         // Replacement for potentiometer contrast control
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);   // Declare LCD digital pins
 
void setup(void)
{
  Serial.begin(9600);
  pinMode(LIGHT_PIN, INPUT);
  sensors.begin();
  mySHTC3.begin();                        // Initialize SHTC3 Humidity Sensor
  Wire.setClock(400000);                  // Humidity Sensor Clockspeed
  analogWrite(6,Contrast);                // Declare digital pin 6 as analog control due to lack of potentiometer
  lcd.begin(16, 2);                       // 16 Columns, 2 rows
  delay(1000);
}    

void loop(void){ 
// Temperature sensor
        sensors.requestTemperatures();
        
// Light sensor (Darker = higher resistance, Lighter = lower resistance.)
        int lightADC = analogRead(LIGHT_PIN);               // Fetch ADC value from sensor
        float lightV = lightADC * VCC / 1023.0;             // Calculate Voltage
        float lightR = R_DIV * (VCC / lightV - 1.0);        // Calculate Resistance
        
        
// Humidity Sensor
        mySHTC3.update();

// Update LCD
   
        if (lightR >= 3000) {
           lcd.setCursor(0, 0);
           lcd.print("Light:  Low");  
        }   
        else {
           lcd.setCursor(0, 0);
           lcd.print("Light: High");
        }
       
       lcd.setCursor(0, 1);
       lcd.print("T= " + String(round(sensors.getTempFByIndex(0))) + (char)223+ + "F");

       lcd.setCursor(9, 1);
       lcd.print("RH= " + String(round(mySHTC3.toPercent())) + "%");

       delay(200);
}
