/*
Создайте функцию myroot(), которая возвращает квадратный корень своего аргумента. 
Перегрузите myroot() тремя способами (см. Unit 2 "Introducing Function Overloading"):
чтобы получить квадратный корень целого, длинного целого и числа с плавающей 
точкой двойной точности. (Для непосредственного подсчета квадратного корня вы 
можете использовать стандартную библиотечную функцию sqrt().
*/

#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

int myroot(int a);
double myroot(double a);
long int myroot(long int a);

int main() {
    int num1;
    double num2;
    long int num3;

    cin >> num1 >> num2 >> num3;
    assert(num1 > 0 && num2 > 0 && num3 > 0);
    cout << myroot(num1) << '  ' << myroot(num2) << '  ' << myroot(num3);
    return 0;
}

int myroot(int num) {
    return sqrt(num);
}

double myroot(double num){
    return sqrt(num);
}

long int myroot(long int num){
    return sqrt(num);
}
