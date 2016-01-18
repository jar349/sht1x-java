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
	jclass Exception = (*env)->FindClass(env, "java/lang/Exception");
	
	// Wait at least 11ms after power-up (chapter 3.1)
	delay(20); 
	
	// Set up the SHT1x Data and Clock Pins
	SHT1x_InitPins();
	
	// Reset the SHT1x
	SHT1x_Reset();
	
	// Request Temperature measurement
	noError = SHT1x_Measure_Start( SHT1xMeaT );
	if (!noError) {
		(*env)->ThrowNew(env, Exception, "Failed to send a temperature measure start command");
	}
		
	// Read Temperature measurement
	noError = SHT1x_Get_Measure_Value( (unsigned short int*) &sensorTicks );
	if (!noError) {
		(*env)->ThrowNew(env, Exception, "Failed to calulate a temperature value");
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
	unsigned char noError = 1;
	value humi_val,temp_val;
	jclass Exception = (*env)->FindClass(env, "java/lang/Exception");

    // Wait at least 11ms after power-up (chapter 3.1)
	delay(20); 
	
	// Set up the SHT1x Data and Clock Pins
	SHT1x_InitPins();
	
	// Reset the SHT1x
	SHT1x_Reset();
	
	// Request Temperature measurement
	noError = SHT1x_Measure_Start( SHT1xMeaT );
	if (!noError) {
		(*env)->ThrowNew(env, Exception, "Failed to send a temperature measure start command");
	}
		
	// Read Temperature measurement
	noError = SHT1x_Get_Measure_Value( (unsigned short int*) &temp_val.i );
	if (!noError) {
		(*env)->ThrowNew(env, Exception, "Failed to calulate a temperature value");
	}

	// Request Humidity Measurement
	noError = SHT1x_Measure_Start( SHT1xMeaRh );
	if (!noError) {
		(*env)->ThrowNew(env, Exception, "Failed to send a humidity measure start command");
	}
		
	// Read Humidity measurement
	noError = SHT1x_Get_Measure_Value( (unsigned short int*) &humi_val.i );
	if (!noError) {
		(*env)->ThrowNew(env, Exception, "Failed to calulate a humidity value");
	}

	// Convert intergers to float and calculate true values
	temp_val.f = (float)temp_val.i;
	humi_val.f = (float)humi_val.i;
	
	// Calculate Temperature and Humidity
	SHT1x_Calc(&humi_val.f, &temp_val.f);

	return (jfloat) humi_val.f;
}

