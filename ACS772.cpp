#include "ACS772.h"
int zero; 
ACS772::ACS772(ACS772_type type, uint8_t _pin) {
	switch (type) {
		case ACS772LCB_050U_PF:
		 sensitivity = 0.08 ;
		 break;
		case ACS772LCB_050B_PF:
		 sensitivity = 0.04 ;
		 break;
		case ACS772LCB_050B_PS:
		 sensitivity = 0.04 ;
		 break;
		case ACS772LCB_050B_SM:
		 sensitivity = 0.04 ;
		 break;   
		case ACS772LCB_100U_PF:
		 sensitivity = 0.04 ;
		 break;	
		case ACS772LCB_100B_PF:
		  sensitivity = 0.02 ;
		  break;
		case ACS772LCB_100B_SM:
		  sensitivity = 0.02 ;
		  break;
		case ACS772KCB_150U_PF:
		 sensitivity = 0.02666 ;
		 break;
		case ACS772KCB_150B_PF:
		 sensitivity = 0.01333 ;
		 break;
		case ACS772KCB_150B_SM:
		 sensitivity = 0.01333 ;
		 break;
		case ACS772ECB_200U_PF:
		 sensitivity = 0.02 ;
		 break;
		case ACS772ECB_200B_PF:
		 sensitivity = 0.01 ;
		 break;
		case ACS772ECB_250U_PF:
		 sensitivity = 0.016 ;
		 break;
		case ACS772ECB_250U_PSF:
		 sensitivity = 0.016 ;
		 break;
		case ACS772ECB_250B_PF:
		 sensitivity = 0.008 ;
		 break;
		case ACS772ECB_250B_PSF:
		 sensitivity = 0.008 ;
		 break;
		case ACS772ECB_300B_PF:
		 sensitivity = 0.00666 ;
		 break;
		case ACS772ECB_400B_PF:
		 sensitivity = 0.005 ;
		 break; 
		default:
			sensitivity = 0.005 ;
			break;
	}
	pin = _pin;
}

int ACS772::calibrate() {
	int _zero = 0;
	for (int i = 0; i < 10; i++) {
		_zero += analogRead(pin);
		delay(10);
	}
	_zero /= 10;
	zero = _zero;
	return _zero;
}

void ACS772::setZeroPoint(int _zero) {
	zero = _zero;
}

void ACS772::setSensitivity(float sens) {
	sensitivity = sens;
}

float ACS772::getCurrentDC() {
	float I = (zero - analogRead(pin)) / ADC_SCALE * VREF / sensitivity;
	return I;
}

float ACS772::getCurrentAC() {
	return getCurrentAC(DEFAULT_FREQUENCY);
}

float ACS772::getCurrentAC(uint16_t frequency) {
	uint32_t period = 1000000 / frequency;
	uint32_t t_start = micros();

	uint32_t Isum = 0, measurements_count = 0;
	int32_t Inow;

	while (micros() - t_start < period) {
		Inow = zero - analogRead(pin);
		Isum += Inow*Inow;
		measurements_count++;
	}

	float Irms = sqrt(Isum / measurements_count) / ADC_SCALE * VREF / sensitivity;
	return Irms;
}
