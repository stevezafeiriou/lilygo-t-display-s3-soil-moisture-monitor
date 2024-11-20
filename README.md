# LilyGO T-Display S3 Soil Moisture Monitor

This project demonstrates how to use the **LilyGO T-Display S3** to monitor soil moisture levels. It connects to a WiFi network, hosts a web server to display the moisture readings, and also displays the sensor data in real-time on the built-in TFT screen.

## Features

- **WiFi Connectivity**: Connects to your WiFi network to host a web server.
- **Web Server**: Access real-time soil moisture percentage via a browser.
- **TFT Display Integration**: Displays WiFi connection status and soil moisture readings directly on the LilyGO T-Display S3 screen.
- **Customizable**: Easily adaptable for other ESP32 boards by removing or modifying the TFT display functionality.

## Hardware Requirements

- **LilyGO T-Display S3** (or any ESP32 board with a TFT display)
- Soil moisture sensor
- USB-C cable for programming and power
- WiFi network

## Software Requirements

- Arduino IDE (or any compatible IDE)
- Required libraries:
  - `TFT_eSPI` for the display
  - `WiFi` and `WebServer` for networking
- ESP32 board package installed in the Arduino IDE

## How It Works

1. The ESP32 reads data from the soil moisture sensor via an analog pin.
2. Converts the raw sensor value to a percentage representing the moisture level.
3. Displays the following information on the TFT screen:
   - WiFi connection status
   - Real-time soil moisture percentage
4. Hosts a web server that serves the moisture readings when accessed from a browser.

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/stevezafeiriou/lilygo-t-display-s3-soil-moisture-monitor.git
```

### 2. Configure WiFi Credentials

Edit the `ssid` and `password` in the code to match your WiFi network:

```cpp
const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";
```

### 3. Upload the Code

1. Open the code in the Arduino IDE.
2. Select the correct **Board** and **Port**.
3. Install the required libraries if not already installed.
4. Upload the code to the ESP32.

### 4. Access the Web Server

Once connected to WiFi:

1. Check the IP address displayed on the TFT screen.
2. Open the IP address in a web browser to view real-time moisture readings.

### 5. Monitor on the TFT Screen

The built-in TFT screen will show:

- WiFi status (connected/disconnected)
- Real-time soil moisture readings in percentage.

## Customization

- **Make sure you calibrate the sensor for accurate monitoring**
- **Using a Different ESP32 Board**:
  - If your ESP32 board doesn't have a built-in display, remove the TFT-related code.
  - Focus on the web server functionality to access the sensor readings.
- **Adjusting the Sensor Pin**:
  - Update the `sensorPin` variable to match the analog pin connected to your soil moisture sensor.

## Example Output

### On the TFT Screen:

```
WiFi Connected!
IP: 192.168.1.100
Moisture: 75%
```

### In the Browser:

```
Soil Moisture: 75%
```

## Troubleshooting

- **WiFi Connection Issues**:

  - Ensure the correct SSID and password.
  - Verify your ESP32 board supports 2.4 GHz networks (5 GHz is not supported).

- **Sensor Calibration**:
  - Adjust the `map()` function to match your sensor's output range.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Contributing

Feel free to submit issues, fork the repository, and send pull requests for improvements or additional features!

## Credits

Developed by [Steve Zafeiriou] (https://stevezafeiriou.com). Inspired by IoT and smart gardening projects.
