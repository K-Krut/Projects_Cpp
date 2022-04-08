/*
Для продвинутых. Разработайте свою хэш-функцию для хранения координат 
точек в 2-мерном пространстве. Насколько легко адаптировать вашу функцию 
к изменениям типа координат (например, от целочисленных к вещественным), 
системы координат (от декартовой к полярной) или размерности (от двух к более высокой)? 
Например, можно хэш-кодировать 2-мерные координаты точек, тем самым организуя хранилище 
данных в виде линейной таблицы порядка 0(количество точек) 
вместо 2- мерного массива порядка 0(размерX * размерY).
*/


//a)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    doublex;
    double y;
} point_t;

enum { NHASH = 19, MULTIPLIER = 31 };

int hash_point(point_t point, int NHASH) {
    return abs(point.x *MULTIPLIER + point.y) % NHASH;
}

int main () {

    srand(time(NULL));

    int n;
    scanf("%d", &n);

    point_t *arr = malloc(n * sizeof(point_t));
    for (int i = 0; i < n; ++i) {
        arr[i].x = rand() % 128 * (rand() % 2 ? 1 : -1);
        arr[i].y = rand() % 128 * (rand() % 2 ? 1 : -1);
		//scanf("%d%d", &arr[i].x, &arr[i].y);
    }

    for (int i = 0; i < n; ++i) {
        printf("(%lf, %lf) -> %d\n", arr[i].x, arr[i].y, hash_point(arr[i], NHASH));
    }

}




//b)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} point_t;

enum { NHASH = 19, MULTIPLIER = 31 };

int hash_point(point_t point, int NHASH) {
    return abs(point.x *MULTIPLIER + point.y) % NHASH;
}
int main () {

    srand(time(NULL));

    int n;
    scanf("%d", &n);

    point_t *arr = malloc(n * sizeof(point_t));
    for (int i = 0; i < n; ++i) {
        arr[i].x = rand() % 64 * (rand() % 2 ? 1 : -1);
        arr[i].y = rand() % 64 * (rand() % 2 ? 1 : -1);
    //scanf("%d%d", &arr[i].x, &arr[i].y);
    }

    for (int i = 0; i < n; ++i) {
        printf("(%d, %d) -> %d\n", arr[i].x, arr[i].y, hash_point(arr[i], NHASH));
    }

}




//c)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {

    int x;
    int y;
    int z;

} point_t;

enum { mod = 19, MULTIPLIER = 31 };

/*
int hash_point(point_t point, int mod) {
    return abs(point.x *MULTIPLIER + point.y * point.z) % mod;
}*/

int hash_point(point_t point, int mod) {
    return (point.x * point.y + point.z ) % mod;
}


int main () {

    srand(time(NULL));

    int n;
    scanf("%d", &n);

    point_t *arr = malloc(n * sizeof(point_t));
    for (int i = 0; i < n; ++i) {
        arr[i].x = rand() % 64 * (rand() % 2 ? 1 : -1);
        arr[i].y = rand() % 64 * (rand() % 2 ? 1 : -1);
        arr[i].z = rand() % 64 * (rand() % 2 ? 1 : -1);
		//scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].z);
    }

    for (int i = 0; i < n; ++i) {
        printf("(%d, %d, %d) -> %d\n", arr[i].x, arr[i].y, arr[i].z, hash_point(arr[i], mod));
    }

}



//d)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
typedef struct {

    int r;
    int theta;

} point_t;

enum { mod = 19, MULTIPLIER = 31 };

int hash_point(point_t point, int mod){
	return ((point.r * MULTIPLIER + point.theta + MULTIPLIER) * MULTIPLIER) % mod;
}

int main () {

    srand(time(NULL));

    int n;
    scanf("%d", &n);

    point_t *arr = malloc(n * sizeof(point_t));
    for (int i = 0; i < n; ++i) {
        arr[i].r = cos(rand() % 2 * (rand() % 2 ? 1 : -1));
        arr[i].theta = tan(rand() % 1028 * (rand() % 2 ? 1 : -1));
		//scanf("%d%d", &arr[i].r, &arr[i].theta);
    }

    for (int i = 0; i < n; ++i) {
        printf("(%d, %d) -> %d\n", arr[i].r, arr[i].theta, hash_point(arr[i], mod));
    }

}

