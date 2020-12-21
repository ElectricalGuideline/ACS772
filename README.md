ACS772
======

Hi this is Sajid Akhtar Gazi, contributing custom library for ACS772.

An Arduino library to interact with the ACS772 Hall effect-based linear current sensor. Includes DC and RMS AC current measuring. Supports ACS772LCB_050U_PF, ACS772LCB_050B_PF, ACS772LCB_050B_PS,ACS772LCB_050B_SM,ACS772LCB_100U_PF,ACS772LCB_100B_PF,ACS772LCB_100B_SM,ACS772KCB_150U_PF,ACS772KCB_150B_PF,ACS772KCB_150B_SM,ACS772ECB_200U_PF,ACS772ECB_200B_PF,ACS772ECB_250U_PF,ACS772ECB_250U_PSF,ACS772ECB_250B_PF,ACS772ECB_250B_PSF,ACS772ECB_300B_PF,ACS772ECB_400B_PF sensors. Typical applications include motor control, load detection and management, switch mode power supplies, and overcurrent fault protection.

For more information see the datasheet: http://www.allegromicro.com/~/media/Files/Datasheets/ACS772-Datasheet.ashx

Wiring
======
| ACS772 | Arduino |
|:------:|:-------:|
| GND    | GND     |
| OUT    | A1      |
| VCC    | 5V      |

Here OUTPUT pin is connected to A1 pin. You can change the OUTPUT pin of ACS772 to any analog pin of Arduino.

Methods
=======
### Constructor:
### **ACS772(** *ACS772_type* type, *uint8_t* _pin **)**
Constructor has two parameters: sensor model and analog input to which it is connected. Supported models: *ACS772LCB_050U_PF, ACS772LCB_050B_PF, ACS772LCB_050B_PS,ACS772LCB_050B_SM,ACS772LCB_100U_PF,ACS772LCB_100B_PF,ACS772LCB_100B_SM,ACS772KCB_150U_PF,ACS772KCB_150B_PF,ACS772KCB_150B_SM,ACS772ECB_200U_PF,ACS772ECB_200B_PF,ACS772ECB_250U_PF,ACS772ECB_250U_PSF,ACS772ECB_250B_PF,ACS772ECB_250B_PSF,ACS772ECB_300B_PF,ACS772ECB_400B_PF.

### *float* **getCurrentDC()**
This method reads the value from the current sensor and returns it.

### *float* **getCurrentAC(** *uint16_t* frequency **)**
This method allows you to measure AC voltage. Current frequency is measured in Hz. Method use the Root Mean Square technique for the measurement. The measurement itself takes time of one full period (1second / frequency). RMS method allow us to measure complex signals different from the perfect sine wave.

### *float* **getCurrentAC()**
Does the same as the previous method, but frequency is equal to 50 Hz.

### *int* **calibrate()**
This method reads the current value of the sensor and sets it as a reference point of measurement, and then returns this value. By default, this parameter is equal to half of the maximum value on analog input - 512; however, sometimes this value may vary. It depends on the concrete sensor, power issues etc… It is better to execute this method at the beginning of each program. Note that when performing this method, no current must flow through the sensor, and since this is not always possible - there is the following method:

### *void* **setZeroPoint(** *int* _zero **)**
This method sets the obtained value as a zero point for measurements. You can use the previous method once, in order to find out zero point of your sensor and then use this method in your code.
