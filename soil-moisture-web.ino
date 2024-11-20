#include <WiFi.h>
#include <WebServer.h>
#include <TFT_eSPI.h> // Include the library for the TFT display

// WiFi credentials
const char* ssid = "YourWiFiSSID"; // Replace with your WiFi network name
const char* password = "YourWiFiPassword"; // Replace with your WiFi password

const int dryValue = 4095; // Replace with your calibrated dry soil reading
const int wetValue = 0;    // Replace with your calibrated wet soil reading

WebServer server(80); // Web server instance

// Define the GPIO pin for the sensor
const int sensorPin = 1; // ADC pin on the ESP32

// Initialize the TFT display
TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200); // Start the serial monitor for debugging

  // Turn on display power
  pinMode(15, OUTPUT);
  digitalWrite(15, HIGH);
  delay(500); // Small delay to ensure power is stabilized

  // Initialize the display
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);

  // Connect to WiFi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  // Display WiFi status on the screen
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(10, 10);
  tft.print("WiFi Connected!");
  tft.setCursor(10, 40);
  tft.print("IP: ");
  tft.print(WiFi.localIP());

  server.on("/", handleRoot); // Define a route for the web server
  server.begin();
}

void loop() {
  server.handleClient(); // Handle incoming HTTP requests

  // Read and display the sensor value
  int sensorValue = analogRead(sensorPin); // Read analog value from sensor
  int moisturePercentage = map(sensorValue, dryValue, wetValue, 0, 100); // Convert to percentage

  // Display the sensor value on the screen
  tft.fillRect(0, 70, 240, 30, TFT_BLACK); // Clear the previous value
  tft.setCursor(10, 70);
  tft.print("Moisture: ");
  tft.print(moisturePercentage);
  tft.print("%");

  delay(1000); // Update the screen every second
}

void handleRoot() {
  int sensorValue = analogRead(sensorPin); // Read analog value from sensor
  int moisturePercentage = map(sensorValue, 4095, 0, 0, 100); // Convert to percentage
  String message = "Soil Moisture: " + String(moisturePercentage) + "%";
  server.send(200, "text/plain", message); // Send the result via web server
}
