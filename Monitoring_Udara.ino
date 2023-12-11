#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MQ135.h>
#include <DHT.h>

// LCD configuration
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 columns, 2 rows

// DHT configuration
#define DHTPIN 2          // Pin tempel untuk output sensor DHT
#define DHTTYPE DHT11// Tipe sensor DHT yang digunakan (DHT11 atau DHT22)
#define buzzer 6     
DHT dht(DHTPIN, DHTTYPE);

// MQ135 configuration
const int MQ135_PIN = A0;  // Pin analog untuk sensor MQ135
MQ135 gasSensor = MQ135(MQ135_PIN);



void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  // digitalWrite(buzzer,HIGH);

  lcd.begin(16, 2); // Initialize the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MQ135 & DHT11");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring");
  lcd.backlight();

  dht.begin(); // Inisialisasi sensor DHT
  
  delay(2000);
}

void loop() {
  float air_quality = gasSensor.getPPM();
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.print("Air Quality: ");
  Serial.print(air_quality);
  Serial.println(" PPM");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Air Quality");

  lcd.setCursor(0, 1);
  lcd.print("PPM: ");
  lcd.print(air_quality);

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humi: ");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");

  delay(2000);

  if (air_quality >= 550){
    
      digitalWrite(buzzer, HIGH);
      delay(200);

      digitalWrite(buzzer, LOW);
      delay(200);
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
    }
    else{
      digitalWrite(buzzer, LOW);
    }
}