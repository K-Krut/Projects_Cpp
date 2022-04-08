/*
В Unit 2 (см. файл Pract02.pdf, Задача 2.14) вы создали имитацию секундомера. 
Модифицируйте ваше решение так, чтобы в классе stopwatch был и конструктор 
без параметров (как это уже сделано) и его перегруженная версия для доступа
к системному времени через стандартную функцию clock(). 
Покажите, что внесенные изменения работают. Совет от ВВ: 
Подумайте о том, каким образом перегруженный конструктор может быть полезен 
для ваших собственных программных задач, например, в курсовой работе.
*/

Код програми:
#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

class Watch {
	clock_t start_p;
	clock_t start_time;
public:
    Watch();
    Watch(clock_t time){
        start_p = time;
    }
	~Watch();
	void start();
	void show();
};
Watch::Watch() {
	start_p = clock();
}
void Watch::start() {
	start_time = clock();
}
void Watch::show() {
	cout << (double)(clock() - start_time) / CLOCKS_PER_SEC << endl;
}
Watch::~Watch() {
	cout << (double)(clock() - start_p) / CLOCKS_PER_SEC << endl;
}
int main() {
	srand(time(NULL));

	Watch timer;
	int num;

	cin >> num;

	timer.start();

	for (int i = 0; i < 10; ++i) {
		cout << rand() % 64 << ' ';
		if (i == 4) {
			Sleep(num * 1000);
			puts("\n");
		}
	}
	puts("\n");
	timer.show();
	puts("\n");

    Watch timer2(clock());

    for (int i = 0; i < 10; ++i) {
		cout << rand() % 16  << ' ';
		if (i == 4) {
			Sleep(num * 1000);
			puts("\n");
		}
	}
	puts("\n");

	timer.show();
	puts("\n");

	return 0;
}
