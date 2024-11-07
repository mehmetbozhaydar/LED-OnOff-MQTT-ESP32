# LED-OnOff-MQTT-ESP32
Turn LED OnOff with MQTT and ESP32
materials required:
• Esp WROOM 32
• Led and resistor
![image](https://github.com/user-attachments/assets/373e5c9a-54a9-42d7-9c46-1293b664ca10)

#How to do it:
* Download and install Mosquitto MQTT Broker.

* Add the code "listener 1883 allow_anonymous true" to the "mosquitto.conf" file of Mosquitto MQTT Broker.
Note: If Mosquitto is installed in the default location, the conf file is in "C:\Program Files\mosquitto".

* Run the "net stop mosquitto" command in the terminal to stop Mosquitto, run the "net start mosquitto" command to restart Mosquitto and restart it.

* Learn the IP address with the "ipconfig" command.

* Load the library.

* Select the ESP32 Module.

* Write the code to connect to Wifi and the code to connect to Mosquitto MQTT Broker and connect to the “led/control” topic and run according to the “ON” and “OFF” data.

* Upload the code to ESP.

* You can control the system by running the codes [mosquitto_pub -h ipadresi -t led/control -m "OFF" mosquitto_pub -h ipadresi -t led/control -m "ON"] from the thermal.
