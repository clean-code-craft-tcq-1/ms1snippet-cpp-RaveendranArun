#include "sensor-validate.h"

bool withInDelta(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return false;
  }

  return true;
}

bool iterCheckForSurge(double* values, int numOfValues, double maxDelta)
{
  int lastButOneIndex = numOfValues - 1;

  for(int i = 0; i < lastButOneIndex; i++) {
    if(!withInDelta(values[i], values[i + 1], 0.05)) {
      return false;
    }
  }

  return true;
}
bool validateReadings(double* values, int numOfValues, double maxDelta)
{
  if (!values || !numOfValues)
    return false;

  return iterCheckForSurge(values, numOfValues, maxDelta);
}

bool validateSOCreadings(double* values, int numOfValues) {
  return validateReadings(values, numOfValues, MAX_SOC_DELTA);
}

bool validateCurrentreadings(double* values, int numOfValues) {
  return validateReadings(values, numOfValues, MAX_CURRENT_DELTA);
}
