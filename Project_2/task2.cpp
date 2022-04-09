/*
Напишите программу для преобразования метров в футы и футов в дюймы. 
Организуйте ввод числа метров и вывод на экран соответствующего 
числа футов и дюймов. Повторяйте эту процедуру до тех пор, 
пока пользователь не введет 0 в качестве числа метров.
*/

#include <iostream>

using namespace std;
#define feet 3.280839895
#define inch 39.37007874
//enum { feet = 3.280839895, inch = 39.37007874 };

int main() {
    double meters;
    do {
      cin >> meters;
      cout << "feets " << meters * feet << endl;
      cout << "inches " << meters * inch << endl;
    } while(meters != 0);
    return 0;
}
