#include <stdio.h>
#include <assert.h>


#define E_OK			0;
#define E_NOK 			1;
#define Temp_Low		0;
#define Temp_High		45;
#define	Soc_Low			20;
#define Soc_High		80;
#define ChargeRate_Low	0;
#define ChargeRate_High	0.8;
#define Battery_NOK		0;
#define Battery_OK 		1;

int batteryIsOk(float temperature, float soc, float chargeRate) {

  int isAllOk_f = E_OK;
  isAllOk_f  = CheckParamIsInRange (float temperature,float Temp_Low,float Temp_High , char "Temperature");
  isAllOk_f |= CheckParamIsInRange (float soc,float Soc_Low,float Soc_High , char "Soc");
  isAllOk_f |= CheckParamIsInRange (float chargeRate,float ChargeRate_Low,float ChargeRate_High , char "ChargeRate");

  return (isAllOk_f == E_OK) ? Battery_OK:Battery_NOK;
}

int CheckParamIsInRange (float inParamToCheck,float Lower_Limit ,float Upper_Limit , char ParamName)
{
	int Error = E_OK;
	if(inParamToCheck < Lower_Limit )
	{
	    printf("%c IS LOW!\n", ParamName);
	    Error = E_NOK;
	}
	else if (inParamToCheck > Upper_Limit)
	{
		printf("%c is HIGH!\n", ParamName);
	    Error = E_NOK;
	}
	else{
		printf("%c is in range!\n", ParamName);
	}
	return Error;
}


int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
