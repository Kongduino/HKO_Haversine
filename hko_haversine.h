#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atof */
#include <math.h>       /* sin */
#include <stdint.h>

const char *hkoName[12] = {
  "Chek Lap Kok", "Cheung Chau", "HK Observatory", "Lau Fau San",
  "Peng Chau", "Sha Tin", "Shek Kong", "Sheung Shui",
  "Ta Kwu Ling", "Tai Po", "Waglan Island", "Wetland Park"
};
float hkoLat[12] = {
  22.305582, 22.210121, 22.302246, 22.469236,
  22.286995, 22.390721, 22.435531, 22.505465,
  22.538829, 22.444778, 22.181801, 22.470267
};
float hkoLon[12] = {
  113.914124, 114.029108, 114.174139, 113.983401,
  114.038209, 114.202234, 114.083070, 114.122356,
  114.160223, 114.168508, 114.303081, 114.005896
};

float toRad(float x) {
  return x * 3.141592653 / 180;
}

float haversine(float lat1, float lon1, float lat2, float lon2) {
  float R = 6371; // km
  float x1 = lat2 - lat1;
  float dLat = toRad(x1);
  float x2 = lon2 - lon1;
  float dLon = toRad(x2);
  float a = sin(dLat / 2) * sin(dLat / 2) +
            cos(toRad(lat1)) * cos(toRad(lat2)) *
            sin(dLon / 2) * sin(dLon / 2);
  float c = 2 * atan2(sqrt(a), sqrt(1 - a));
  float d = R * c;
  return round(d * 100.0) / 100;
}

uint8_t closestDataPoint(float lat1, float lon1, float *distance) {
  float d, dpLat, dpLon;
  uint8_t x, ix;
  float dl = 10000000;
  for (x = 0; x < 12; x++) {
    d = haversine(lat1, lon1, hkoLat[x], hkoLon[x]);
    if (d < dl) {
      dl = d;
      dpLat = hkoLat[x];
      dpLon = hkoLon[x];
      ix = x;
    }
  }
  *distance = dl;
  return ix;
}
