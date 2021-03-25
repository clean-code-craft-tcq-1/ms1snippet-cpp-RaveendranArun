#ifndef __SENSOR_VALIDATE_H
#define __SENSOR_VALIDATE_H

#define MAX_SOC_DELTA      0.5
#define MAX_CURRENT_DELTA  0.1

bool withInDelta(double value, double nextValue, double maxDelta);
bool validateReadings(double* values, int numOfValues, double maxDelta);
bool validateSOCreadings(double* values, int numOfValues);
bool validateCurrentreadings(double* values, int numOfValues);  



#endif