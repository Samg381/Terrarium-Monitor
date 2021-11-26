# Terrarium-Monitor
A basic environmental monitoring system for a reptile terrarium based on the Arduino enviromnent.
Features LCD display integration for simplified readings.

![IMG_20200416_151510](https://user-images.githubusercontent.com/3127698/143528249-05b1a57f-f263-4f53-85b3-22306f69a9b0.jpg)

**Abstract**
This project documents the inception, assembly and programming performed in pursuit of a 
custom lizard tank environmental monitoring system. After identifying key variables critical to 
proper bearded dragon health; temperature, light and humidity, hardware was procured to 
address the challenge. An Arduino UNO microcontroller board was chosen to support three 
different sensors, allowing data collection of the aforementioned environmental variables. 
Additionally, an LCD screen was employed to facilitate rapid understanding of current tank 
condition data to the caretaker, and the entire system packaged for ease of deployment. Despite 
an unprecedented global health crisis putting strain on component availability, team meetings
and testing, this project yielded a simple and powerful device to augment routine lizard care.

**Background**
Bearded dragons, like all reptiles, are ectotherms. Unlike mammals, reptiles are unable to actively 
regulate their body temperature. As such, reptiles rely on their location in the environment to 
maintain a healthy body temperature; often shifting between shaded and sunlit areas. Owning a 
bearded dragon requires careful consideration into a living environment, or terrarium (Fig. 2). 
Terrariums are large glass tanks outfitted to replicate a natural living environment, including heat 
and UV-B lamps to produce light and warmth

**Environment**
While the prospect of maintaining a bearded dragon terrarium may seem daunting, the task can 
be reasonably simplified into three critical variables. First and foremost, the terrarium 
temperature is the most critical condition to monitor as it is the limiting factor when compared 
to other needs. Closely related to temperature is light, of which a bearded dragon requires a 
near-constant supply throughout the day. Finally, humidity must be carefully regulated, as the 
environments where bearded dragons naturally exist are comparatively arid to a common home.
While there exists a plethora of reputable sources providing information on the proper
environmental conditions for bearded dragons, the suggestions found in the majority of these 
are harmonious.

**Design requirements**
The system:
1. Shall not harm or injure the bearded dragon.
2. Shall not interfere with any existing implements within the tank.
3. Shall display a reading of internal temperature taken within the terrarium.
4. Shall display a reading of internal humidity taken within the terrarium.
5. Shall indicate current light level in a simple, unitless fashion.
6. Shall be packaged such that only sensors and power cables are exposed.

**Design Description**
The monitoring system (Fig. 4) is comprised of an Arduino UNO microcontroller, power supply, 
temperature sensor, humidity sensor, light sensor, LCD screen, extension leads, breadboard and 
mounting enclosure.

![IMG_20200416_151617](https://user-images.githubusercontent.com/3127698/143528367-7f7ff0d2-6eb0-4c68-8dc3-18f525c5aa3c.jpg)

![IMG_20200416_151552](https://user-images.githubusercontent.com/3127698/143528410-92995dea-f180-4384-a5b8-0df426663399.jpg)

The sensor package (Fig. 5) consists of three environmental sensors external to the enclosure and 
designed for placement within the terrarium. A DS18B20 Temperature sensor is powered via 5
volts and provides an accuracy of ±0.5°C from -10°C to +85°C, outputting a 12-bit temperature to 
a digital word value via the 1-Wire Arduino library [3]. Next, a SHTC3 humidity sensor supplied 
with 3.3 volts offers a relative humidity (RH) reading of ±2% [4]. Finally, a SEN-09088 Mini 
Photocell is powered with 5 volts and offers a varying level of resistance depending on lighting 
conditions, with higher readings corresponding to lower ambient light levels [5]. This relationship 
required manual calibration in order to match known light levels to resistances. Due to the lack 
of a terrarium as a result of COVID-19, an oven fume hood lamp was used as an analog to a 
replicate the terrarium light. This will require adjustment should the system eventually be 
installed in a lizard tank

**Construction Photos**

![IMG_20200407_202224](https://user-images.githubusercontent.com/3127698/143528544-b654b6a9-b5fa-4593-b53d-f3294982b58c.jpg)

![IMG_20200407_204719](https://user-images.githubusercontent.com/3127698/143528571-d2e91b92-a7fa-4aaf-8f61-248a78a4d45a.jpg)

![IMG_20200407_202250](https://user-images.githubusercontent.com/3127698/143528591-024f26f8-9970-4b4a-ab69-708d802faeac.jpg)
