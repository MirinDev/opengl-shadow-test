#pragma once

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define clamp(a, b, c) (a < b ? b : a > c ? c : a)

#define PI 3.1415926535897932384626433832795
#define RAD (PI / 180)
#define DEGTORAD(deg) (deg * RAD)
#define RADTODEG(deg) (deg / RAD)