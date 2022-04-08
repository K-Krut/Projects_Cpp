/*
Пусть дано следующее неполное описание класса, 
добавьте конструкторы так, чтобы оба объявления в функции main() 
были правильны.  Подсказка: вам необходимо дважды перегрузить конструктор samp().
*/

#include <iostream>

using namespace std;

class Object {
private:
    int a;
public:
    Object() { a = 0; }
    Object(int n) { a = n; }
    int get_a() { return a; }
};

int main() {

    Object obj(88); // init obj a to 88
    Object objarray[10]; // non - initialized 10-element array

    cout << obj.get_a() << endl;

//    for(int i = 0; i < 10; i++)
//       cout << objarray[i].get_a() << ' ';

return 0;
}

