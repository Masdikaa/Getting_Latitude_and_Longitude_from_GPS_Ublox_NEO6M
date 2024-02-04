#include <SoftwareSerial.h>
#include <TinyGPS++.h>
// Using library from TinyGPSPlus to getting GPS location and SoftwareSerial to get RX and TX pinout.

SoftwareSerial serial_gps(16, 17); // RX2 and TX2 in ESP32
TinyGPSPlus gps;
double latitude,logitude;

void setup() {
  Serial.begin(9600);
  serial_gps.begin(9600);
  Serial.println("Starting GPS!");
}

void loop() {

  // Check if the GPS is getting a signal
  while(serial_gps.available()){
    gps.encode(serial_gps.read());
  }

  if (gps.location.isUpdated()){
    Serial.print("Latitude : ");
    Serial.print(gps.location.lat(),6);
    Serial.print(" Longitude : ");
    Serial.println(gps.location.lng(),6);
    delay(2000);
  }

}
