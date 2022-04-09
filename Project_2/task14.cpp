/*
Создайте класс stopwatch для имитации секундомера. 
Используйте конструктор для начальной установки секундомера в 0. 
Образуйте две функции-члена start() и stop() соответственно для запуска и 
остановки секундомера. Включите в класс и функцию-член show() для вывода 
на экран величины истекшего промежутка времени. Также используйте деструктор 
для автоматического вывода на экран времени, прошедшего с момента создания 
объекта класса stopwatch , до его удаления. (Для простоты время приведите в секундах.)  
*/


#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

class watch{
    clock_t start_p;
    clock_t start_time;
public:
    watch();
    ~watch();
    void start();
    void show();
};

watch::watch(){
    start_p = clock();
}

void watch::start(){
    start_time = clock();
}

void watch::show(){
    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;
}

watch::~watch(){
    cout << (double)(clock() - start_p)/CLOCKS_PER_SEC << endl;
}

int main(){
    srand(time(NULL));
    watch timer;
    int num;

    cin >> num;
    timer.start();

    for (int i = 0; i < 10; ++i) {
        cout << rand() % 64 << ' ';
        if (i == 4){
             Sleep(num * 1000);
             puts("\n");
        }
    }
    puts("\n\n");
    timer.show();
    return 0;
}
