/*
Конструктор копий вызывается и в тех случаях, когда функция генерирует временный объект, 
используемый в качестве ее возвращаемого значения 
(для тех функций, которые возвращают объекты). 
Зная это, рассмотрим следующий результат работы программы:

Constructing normally
Constructing normally
Constructing copy
Constructing copy

Эти строки появились в результате работы следующей программы:
*/


#include <iostream>

using namespace std;

class myclass {
public:
    myclass();
    myclass(const myclass &obj);
    myclass f();
    myclass g(myclass obj);
};

// Normal constructor
myclass::myclass() {
    cout << "Constructing normally\n";
}

// Copy constructor
myclass::myclass(const myclass &obj) {
    cout << "Constructing copy\n";
}

// Return an object.
myclass myclass::f() {
    myclass temp;
    return temp;
}

myclass myclass::g(myclass obj) {
    myclass temp = obj;
    return temp;
}

int main() {

    myclass obj;

    obj = obj.f();

    obj = obj.g(obj);

return 0;
} 


/*Об’єкти obj temp створюються за допомогою звичайного конструктора, але у функція obj = obj.f(); повертає об’єкт temp, тому генерується тимчасовий об’єкт, який викликає конструктор копіювання.*/

