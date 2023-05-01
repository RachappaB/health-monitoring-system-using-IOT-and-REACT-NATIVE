#include<ESP8266WiFi.h>
#include <SoftwareSerial.h>

#include <DHT.h>
int LED = D0;
SoftwareSerial btSerial(5, ); // RX,

#define DHTPIN 4 
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
void setup() {
   pinMode(LED, OUTPUT);

  // put your setup code here, to run once:
  Serial.begin(9600);  // put your setup code here, to run once:
  dht.begin();
  btSerial.begin(9600);

  WiFi.begin("Rachappa","shantappa9945483471");//name,and password
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP Address");
  Serial.println(WiFi.localIP());
  Serial.print("MAC Address");
  Serial.println(WiFi.macAddress());
  Serial.println("Running DHT!");
 


}
int timeSinceLastRead = 0;
void loop() {

  // Report every 2 seconds.
  if(timeSinceLastRead > 2000) {
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float f = dht.readTemperature(true);

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println("Failed to read from DHT sensor!");
      timeSinceLastRead = 0;
      return;
    }

    // Compute heat index in Fahrenheit (the default)
    float hif = dht.computeHeatIndex(f, h);
    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(hif);
    Serial.println(" *C ");
    //     Serial.println(f);
    //         Serial.println(hif);
    // Serial.println(hic);
        digitalWrite(LED, HIGH);
      delay(2000);
        digitalWrite(LED, LOW);
        delay(2000);

   

    timeSinceLastRead = 0;
  }
  timeSinceLastRead += 100;




     

  
}
