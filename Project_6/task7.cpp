/*
Попытайтесь провести компиляцию всех программ (см. Unit6,  "Overloading And Ambiguity"), 
в которых имеет место неоднозначность. Сопоставьте сообщения компилятора, 
объясните и запомните эти сообщения об ошибках. 
Это поможет вам сразу распознать ошибки неоднозначности, 
если они появятся в ваших программах.
*/



// a) 
#include <iostream>
using namespace std;
float f(float t) {
    return t /2.0;
}

double f(double t){
     return t/3.0;
}

int main(){

    float x = 10.09;
    cout<<f(x);
    double y = 10.09;
    cout<<f(y);
    cout<<f(10);

    return 0;
}
/*
Неоднозначність при перезагрузці функцій
При виклику функції f(10); передається аргумент типу int має відбуватись 
приведення типу, але через те, що типи float і double аналогічні виникає 
неооднозначність – компілятор не знає яку функцію викликати
*/




// b)
#include <iostream>

 using namespace std;

 void f(unsigned char c) {
     cout << c;
}

void f(char c){
     cout << c;
}

int main() {

     f('c');
     f(86);
     return 0;
}

/*
Неоднознаність при виклику функції з неправильним типом f(86);
Компілятор не знає, яку функцію викликати для приведення типу, 
адже f(unsigned char) і f(char)  аналогічні
*/





//c)
#include <iostream>
 
using namespace std;
 
int f(int a, int b) { return a + b; }
int f(int a, int &b) { return a - b; }

int main() {
    int x = 1, y = 2;
    cout << f(x, y);
    return 0;
}

/*
Неоднозначність при перезагрузці функцій, одна з яких використовує посилання, 
інша –значення. Синтаксично ці функції не відрізняються, тому виникає неоднозначність
і компілятор не знає, яку з ункцій викликати
*/


//d)
#include <iostream>
 
using namespace std;
 
int f(int a) { return a * a; }
int f(int a, int b = 0) { return a * b; }
 
int main() {
    
    cout << f(10, 2);
    cout << f(10);
    return 0;
}

/*
При виклику функції f(10) компілятор не знає, яку версію функції 
вибрати f(int a) чи f(int a, int b = 0)
*/

