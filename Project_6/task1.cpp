/*Дано неполное определение класса:
 
Добавьте в это определение два конструктора. В первом не должно быть параметров.
Он должен выделять 255 байтов памяти (с помощью оператора new), 
инициализировать эту память нулевой строкой и устанавливать переменную len равной 255. 
Во втором конструкторе должно быть два параметра. Первый — это строка, 
используемая при инициализации, второй — число выделяемых байтов. 
Во второй версии конструктора должно выделяться заданное количество памяти, 
в которую должна помещаться копия строки. Необходимо реализовать полный контроль 
границ массива (подсказка: см. Unit 5) и, разработать в короткую программу вывода, показать,
что оба конструктора работают так, как это было задумано.
*/

#include <iostream>
#include <string.h>

using namespace std;

class String {
private:
    char *p;
    int len;
public:
    char *getstring () { return p; }
    int getlenght () { return len; }

    String(){
        len = 255;
        p = new char[255];
        if(!p)
            exit(1);
        *p = '\0';
    }

    String(char const *str, int size){
        if(strlen(str) >= size)
            exit(1);
        len = size;
        p = new char[size];
        if(!p)
            exit(1);
        strcpy(p, str);
    }

    ~String() {
        delete p;
    }

//    show() {
//        cout << p << ' ' << len << endl;
//    }

};

int main() {

    int a;
    char str[100];

    String s1;

    cin >> str >> a;

    String s2(str, a);
    //String s2("HELLO!", a);

    cout << s1.getstring() << ' ' << s1.getlenght() << endl;
    cout << s2.getstring() << ' ' << s2.getlenght() << endl;

   // s2.show();

    return 0;
}
