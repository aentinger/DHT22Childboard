/**
 * @author Alexander Entinger, MSc / LXRobotics
 * @brief this file demonstrates how to use the the LXRobotics DHT22 Childboard for reading out temperature and humidity values and displaying the via serial as well as blinking the childboard led
 * @file dht22_childboard_demo.ino
 * @license Attribution-NonCommercial-ShareAlike 4.0 Unported (CC BY-NC-SA 4.0) ( http://creativecommons.org/licenses/by-nc-sa/4.0/ )
 */

/* INCLUDES */

#include "DHT.h"

/* GLOBAL CONSTANTS */

// led pin is pin D3
static int const LED_PIN = 3;
// dht22 data pin is D4
static int const DHT22_DATA_PIN = 4;

/* GLOBAL VARIABLES */

DHT dht;

/* FUNCTIONS */

/**
 * @brief setup function is executed once
 */
void setup()
{
  // set led pin as output
  pinMode(LED_PIN, OUTPUT);
  // init DHT library
  dht.setup(DHT22_DATA_PIN);
  // init serial output
  Serial.begin(115200);
}

/**
 * @brief main loop
 */
void loop()
{
  turn_led_on();
  delay(500);
  turn_led_off();
  delay(500);

  float const humidity = dht.getHumidity();
  float const temperature = dht.getTemperature();

  Serial.print(dht.getStatusString());
  Serial.print(" | ");
  Serial.print(humidity, 1);
  Serial.print(" % | ");
  Serial.print(temperature, 1);
  Serial.println(" C ");
}

/**
 * @brief turn the led of the dht22 childboard on
 */
void turn_led_on()
{
  digitalWrite(LED_PIN, LOW);
}

/**
 * @brief turn the led of the dht22 childboard off
 */
void turn_led_off()
{
  digitalWrite(LED_PIN, HIGH);
}
