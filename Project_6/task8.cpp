/*
Ниже приведены две перегруженные функции. 
Покажите в демонстрационной программе, как получить и как использовать адрес каждой из них:
*/


#include <iostream>

using namespace std;

int f(int a, int b) {
    return a - b;
}
float f(float a, float b) {
    return a - b;
}

int main() {
    int (* p1)(int, int); //creating a pointer to function
    float (* p2)(float, float);
    p1 = f;
    cout << p1(87, 4) << endl;
    p2 = f;
    cout << p2(7.557, 1.554) << endl;
    return 0;
}
