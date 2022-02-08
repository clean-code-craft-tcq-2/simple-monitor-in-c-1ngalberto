#include <stdio.h>
#include <assert.h>


#define E_OK			0;
#define E_NOK 			1;
#define Temp_Low		0;
#define Temp_High		45;
#define	Soc_Low			20;
#define Soc_High		80;
#define ChargeRate_High	0.8;
#define Battery_NOK		0;
#define Battery_OK 		1;

int batteryIsOk(float temperature, float soc, float chargeRate) {

  int isAllOk_f = E_OK;
  isAllOk_f  = isTemperatureInRange (float temperature);
  isAllOk_f |= isSocInRange (float soc);
  isAllOk_f |= isChargeRateInRange (float chargeRate);

  return (isAllOk_f == E_OK) ? Battery_OK:Battery_NOK;
}

int isTemperatureInRange (float temperature)
{
	int Error = E_OK;
	if(temperature < Temp_Low || temperature > Temp_High)
	{
	    printf("Temperature out of range!\n");
	    Error = E_NOK;
	}
	else{}
	return Error;
}

int isSocInRange (float soc)
{
	int Error = E_OK;
	if(soc < Soc_Low || soc > Soc_High)
	{
		printf("State of Charge out of range!\n");
		Error = E_NOK;
	}
	else{}
	return Error;
}

int isChargeRateInRange (float chargeRate)
{
	int Error = E_OK;
	if(chargeRate > ChargeRate_High)
	{
	    printf("Charge Rate out of range!\n");
	    Error = E_NOK;
	}
	else{}
	return Error;
}


int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
