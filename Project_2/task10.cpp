/*
Создайте свою функцию min(), которая возвращает наименьший из двух численных аргументов, 
используемых при ее вызове. Перегрузите функцию min() так, 
чтобы она воспринимала в качестве аргументов символы, 
целые и действительные двойной точности (см. Unit 2 "Introducing Function Overloading").
*/


#include <iostream>

using namespace std;

int min(int a, int b) {
    return a > b ? b : a;
}

double min(double a, double b){
    return a > b ? b : a;
}

char min(char a, char b){
    return a > b ? b : a;
}

int main() {
    cout << min(2, 45) << endl;
    cout << min (345.345, 2.34) << endl;
    cout << min('a', 'c') << endl;
    return 0;
}



#include <iostream>

using namespace std;

int min(int a, int b);
double min(double a, double b);
char min(char a, char b);

int main() {
    int a, b;
    double c, d;
    char e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << min(a, b) << ' ' << min(c, d) << ' ' << min(e, f)<<endl;

    return 0;
}

int min(int a, int b) {
    return a > b ? b : a;
}

double min(double a, double b){
    return a > b ? b : a;
}

char min(char a, char b){
    return a > b ? b : a;
}

