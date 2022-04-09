/*/
Напишите программу, использующую стиль ввода/вывода C++, 
для ввода двух целых с клавиатуры и затем вывода на экран 
результата возведения первого в степень второго. (Например, пользователь вводит 2 и 4, 
тогда результатом будет 24, или 16.)
*/


#include <iostream>
#include <cmath>
using namespace std;

int pow_ab(int a, int b){
    return pow(a, b);
}
/*
int pow_ba(int a, int b){
    return pow(b, a);
}*/

int main() {
    int a, b;

    cin >> a >> b;
    cout << pow_ab(a, b) << ' ' << pow_ab(b,a) << endl;
//  cout << pow_ab(a, b) << pow_ba(a, b) << pow_ab(b,a) << endl;

    return 0;
}
