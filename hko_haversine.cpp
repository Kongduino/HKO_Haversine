#include "hko_haversine.h"

int main() {
  char buffer[256];
  printf("Enter lat: ");
  fgets(buffer, 256, stdin);
  float lat1 = atof(buffer);
  printf("Enter lon: ");
  fgets(buffer, 256, stdin);
  float lon1 = atof(buffer);
  float distance = -1.0;
  uint8_t x = closestDataPoint(lat1, lon1, &distance);
  
  printf ("Closest Data Point = %s, %f,%f\nDistance: %2.2f km.\n", hkoName[x], hkoLat[x], hkoLon[x], distance);
  return 0;
}
