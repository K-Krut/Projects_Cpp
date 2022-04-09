/*
  Напишите программу для ввода количества отработанных 
  персоналом часов и размера почасовой оплаты каждого. 
  Затем выведите суммарную зарплату персонала. (Удостоверьтесь в правильности ввода.)
*/


#include <iostream>
#include <cassert>

using namespace std;

int main(){

    int hours, wage;
    cout << "Enter hours & wage" <<endl;
    cin >> hours >> wage;
    assert(hours > 0); assert( wage > 0);
    cout << "Result  " << hours * wage << endl;

    return 0;
}
