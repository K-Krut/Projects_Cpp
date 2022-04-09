/*
Создайте свою функцию sleep(), приостанавливающую работу компьютера на столько секунд, 
сколько указано в аргументе функции. Перегрузите sleep() так, 
чтобы она могла вызываться или с целым, или со строкой, задающей целое. 
Например, оба этих вызова должны заставить компьютер остановиться на 10 секунд: 
sleep(10); sleep("10"); Продемонстрируйте работу ваших функций, 
включив их в короткую программу.
*/

#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

void sleep(const size_t seconds) {
    clock_t start = clock();
    while((double)(clock() - start)/CLOCKS_PER_SEC < seconds);
}

void sleep(const char * seconds) {
    clock_t start = clock();
    while((double)(clock() - start)/CLOCKS_PER_SEC < atoi(seconds));
}

int main() {
    srand(time(NULL));
    int num;
    cin >> num;
    for (int i = 0; i < 10; ++i) {
        cout << rand() % 64 << endl;

        if (i == 4) {
            cout << "\a" << endl;
            sleep(num);
        }
    }
    return 0;
}
