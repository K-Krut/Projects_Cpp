/*
Создайте класс mybox, конструктору которого передаются три значения типа double,
представляющие собой длины сторон параллелепипеда. 
Класс mybox должен подсчитывать его объем и хранить результат также 
в виде значения типа double. Включите в класс функцию-член volume(), 
которая будет выводить на экран объем любого объекта типа mybox.
*/



#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

//typedef double dl;

class figure{
    double side_a;
    double side_b;
    double side_c;
    double volume;
    public:
        figure(double side_a, double side_b, double side_c);
        void show();
};

figure::figure(double side_a, double side_b, double side_c){
    volume = side_a * side_b * side_c;
}

void figure::show(){
    cout << volume;
}

int main(){

    double a, b, c;

    cin >> a >> b >> c;
    assert(a > 0 && b > 0 && c > 0);

    figure box(a, b, c);
    box.show();

    return 0;
}

b)
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class figure{
    double side_a;
    double side_b;
    double side_c;
    public:
        figure(double side_a, double side_b, double side_c);
        void show();
};

figure::figure(double side_a, double side_b, double side_c){
    cout << side_a * side_b * side_c;
}

int main(){
    double a, b, c;
    cin >> a >> b >> c;
    assert(a > 0 && b > 0 && c > 0);
    figure box(a, b, c);

    return 0;
}

