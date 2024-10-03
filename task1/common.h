#include <cstdlib>
#include <cmath>
#include <iostream>
#include <time.h>
/* Для доступа к структуре данных "map", используемой для хранения распределения шума */
#include <map>
/* Для доступа к функции копирования блока данных memcpy */
#include <cstring>
//#include <fstream>

#define TIME (15.0f)
#define CALC_SAMPLES_N(x) ((int)(x * DISC_FREQ))
