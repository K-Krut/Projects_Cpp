/*
Ниже приведена программа на языке С. Перепишите ее в 
соответствии со стилем ввода/вывода C++. 

Преобразуйте эту программу на С в соответствии со стилем программирования C++. 
Эта программа подсчитывает наименьшее общее кратное
*/


#include <iostream>

using namespace std;

int main() {

 int a, b, i, min;

 cout << "Enter 2 numbers" << endl;
 cin >> a >> b;

 min = a > b ? b : a;

 for (i = 2; i < min; ++i) {
    if (a % i == 0 && b % i == 0)
        break ;
    if (i == min) {
        cout << "No common denominators\n";
        return 0;
    }
 }
 cout << "The lowest common denominator is  " << i << endl;
return 0;
}
