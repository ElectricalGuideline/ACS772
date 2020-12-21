#ifndef ACS772_h
#define ACS772_h

#include <Arduino.h>

#define ADC_SCALE 1023.0
#define VREF 5.0
#define DEFAULT_FREQUENCY 50

enum ACS772_type {ACS772LCB_050U_PF, ACS772LCB_050B_PF, ACS772LCB_050B_PS,ACS772LCB_050B_SM,ACS772LCB_100U_PF,ACS772LCB_100B_PF,ACS772LCB_100B_SM,ACS772KCB_150U_PF,ACS772KCB_150B_PF,ACS772KCB_150B_SM,ACS772ECB_200U_PF,ACS772ECB_200B_PF,ACS772ECB_250U_PF,ACS772ECB_250U_PSF,ACS772ECB_250B_PF,ACS772ECB_250B_PSF,ACS772ECB_300B_PF,ACS772ECB_400B_PF };

class ACS772 {
public:
	ACS772(ACS772_type type, uint8_t _pin);
	int calibrate();
	void setZeroPoint(int _zero);
	void setSensitivity(float sens);
	float getCurrentDC();
	float getCurrentAC();
	float getCurrentAC(uint16_t frequency);

private:
	float zero = 512.0;
	float sensitivity;
	uint8_t pin;
};

#endif