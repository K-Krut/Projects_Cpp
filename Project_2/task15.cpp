/*
Создайте новый вариант разработанного ранее класса strtype, 
в котором используется конструктор с параметром 
(см . Unit 2 "An Example that Shows the Need for Both a Constructor and a Destructor Function"). 
В вашей версии класса strtype строка получает свое начальное значение с помощью конструктора.
*/



#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class strtype {
    char *p;
    int len;
public:
    strtype(const char *ptr);
    ~strtype();

    void show();
};

strtype::strtype(const char *ptr) {
    len = strlen(ptr);
    p = (char *)malloc(strlen(ptr) + 1);
    if(!p)
        exit(1);
    strcpy(p, ptr);
}

strtype::~strtype(){
    free(p);
}


void strtype::show(){
    cout << p <<"   lenght   " << len << endl;
}

int main(){
    strtype s1("ABC");
    strtype s2("ABCDEFG");
    s1.show();
    s2.show();
    return 0;
}

