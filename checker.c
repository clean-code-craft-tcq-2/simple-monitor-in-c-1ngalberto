#include <stdio.h>
#include <assert.h>


#define E_OK			0
#define E_NOK 			1
#define Temp_Low		0
#define Temp_High		45
#define	Soc_Low			20
#define Soc_High		80
#define ChargeRate_Low	0
#define ChargeRate_High	0.8
#define Battery_NOK		0
#define Battery_OK 		1

enum ParamIndex{
	Temperature,
	Soc,
	ChargeRate
};

int CheckParamIsInRange (float inParamToCheck,float Lower_Limit ,float Upper_Limit , const char* ParamName)
{
	int Error = E_OK;
	if(inParamToCheck < Lower_Limit )
	{
	    printf("%s IS LOW!\n", ParamName);
	    Error = E_NOK;
	}
	else if (inParamToCheck > Upper_Limit)
	{
		printf("%s is HIGH!\n", ParamName);
	    Error = E_NOK;
	}
	else{
		printf("%s is in range!\n", ParamName);
	}
	return Error;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {

  int isAllOk_f = E_OK;
  const char* ParamName[] = {"Temperature","Soc","ChargeRate"};

  isAllOk_f  = CheckParamIsInRange ( temperature, Temp_Low, Temp_High ,ParamName[Temperature]);
  isAllOk_f |= CheckParamIsInRange ( soc, Soc_Low, Soc_High , ParamName[Soc]);
  isAllOk_f |= CheckParamIsInRange ( chargeRate, ChargeRate_Low, ChargeRate_High , ParamName[ChargeRate]);

  return isAllOk_f == E_OK ? Battery_OK:Battery_NOK;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 1));
  assert(!batteryIsOk(-15, 10, -1));
}
