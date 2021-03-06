#include <Adafruit_NeoPixel.h>   //include library

#define PIN            6  // Which pin on the Arduino is connected to the NeoPixels?
#define NUMPIXELS      5  // How many NeoPixels are attached to the Arduino?

int fadeSpeed = 1;          //variable to determine fade speed

// When we setup the NeoPixel library object, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();                       // This initializes the NeoPixel library.
  pixels.setBrightness(255);            //sets overall brightness 0-255

}

void loop() {

  for (int led = 0; led <= NUMPIXELS; led++) {
    for (int level = 0; level <= 255; level++) {
      pixels.setPixelColor(led, 0, level, level); //parameters are (LED number in chain, Red 0-255, Green 0-255, Blue 0-255)
      pixels.show();
      delay(fadeSpeed);
    }
  }
  for (int led = 0; led <= NUMPIXELS; led++) {
    for (int level = 0; level <= 255; level++) {
      pixels.setPixelColor(led, 0, 255 - level, 255 - level); //parameters are (LED number in chain, Red 0-255, Green 0-255, Blue 0-255)
      pixels.show();
      delay(fadeSpeed);
    }
  }
}
