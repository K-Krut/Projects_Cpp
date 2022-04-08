/*
Перегрузите конструктор Date() (См. Unit6 "Select the most convenient method of 
initializing an object") так, чтобы он имел параметр типа time_t.  
Подсказка: Вспомните, что time_t - это тип данных, определенный стандартными 
библиотечными функциями времени и даты компилятора C++.
*/

#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }
    Date(const char *str){
        sscanf(str, "%d%*c%d%*c%d", &month, &day, & year);
    }
    Date(time_t info){
        struct tm *p;
        time(&info);
        p = localtime(&info);
        //p = gmtime(&info);
        month = p -> tm_mon;
        day = p -> tm_mday;
        year = p -> tm_year;
    }

    void show(){
        cout << month << '/' << day << '/' << year << endl;
    }
};

int main(){

    Date t1("19/03/21");
    t1.show();

    Date t2(19, 03, 21);
    t2.show();

    Date t3(time(NULL));
    t3.show();

    return 0;
}
