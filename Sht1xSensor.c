#include "Sht1xSensor.h"
#include <RPi_SHT1x.h>

/*
 * Class:     Sht1xSensor
 * Method:    getTemperatureInCelcius
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_Sht1xSensor_getTemperatureInCelcius
  (JNIEnv *env, jobject obj)
{
    unsigned char noError = 1;  
	unsigned short int sensorTicks;
	
	
	// Wait at least 11ms after power-up (chapter 3.1)
	delay(20); 
	
	// Set up the SHT1x Data and Clock Pins
	SHT1x_InitPins();
	
	// Reset the SHT1x
	SHT1x_Reset();
	
	// Request Temperature measurement
	noError = SHT1x_Measure_Start( SHT1xMeaT );
	if (!noError) {
		return;
	}
		
	// Read Temperature measurement
	noError = SHT1x_Get_Measure_Value( (unsigned short int*) &sensorTicks );
	if (!noError) {
		return;
	}

    // Calculate the temp based on the reading
    float tempReading = (float)sensorTicks;
    return (jfloat)SHT1x_CalcTemperature(&tempReading);
}

/*
 * Class:     Sht1xSensor
 * Method:    getTemperatureInFahrenheit
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_Sht1xSensor_getTemperatureInFahrenheit
    (JNIEnv *env, jobject obj)
{
    jfloat tempInCelcius = Java_Sht1xSensor_getTemperatureInCelcius(env, obj);
    return (jfloat) (tempInCelcius * 9 / 5) + 32;
}

/*
 * Class:     Sht1xSensor
 * Method:    getHumidity
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_Sht1xSensor_getHumidity
  (JNIEnv *env, jobject obj)
{
    
}

