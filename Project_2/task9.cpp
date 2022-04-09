/*
Стандартная библиотека C++ содержит три функции:
double atof (const char *s);
int atoi (const char *s);
long atol(const char *s);
Эти функции возвращают численное значение, содержащееся в строке, на которую указывает s. 
Заметьте, что atof() возвращает double, atoi возвращает int и atol возвращает long. 
Почему нельзя перегрузить эти функции? Продемонстрируйте пример кода.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

double atof(const char *s);
int atoi(const char *s);
long int atol(const char *s);

int main() {

    char res[256], res1[256], res2[256];

    cout << atof("243.345 radom words") << endl;
    cout << atoi("435Hi hello bye") << endl;
    cout << atol("384758689 very long number kek") << endl;

   /* cin >> res;
    cout << atof(res) << endl;
    cin >> res;
    cout << atof(res) << endl;
    cin >> res1;
    cout <<atoi(res1) << endl;
    cin >> res2;
    cout << atol(res2) << endl;*/

    return 0;
}

/*Функция atoi(const char *s); превращает строку содержащую целое число в тип int, если 
строка не содержит числа типа Int то функция возвражает непределеное значение
Функция double atof(const char *s); превращает строку начинающуюся на число с плавающей точкой в тип double. Если число заканчиваеться точкой или символом е E то функция возвражает непределеное значение.
Функция atol(const char *s); делает то же, что и предыдущые, но для чисел типа  long при этом число может завершаться любим символом (если   atol(“345.445”), то возвращает 345), если строка содержит не коректное предствление числа, то функция возвраащет 0;
Предполагаю, что перезагрузка невозможна из-за того, что для роботы функций строка должна содержать коректное представление числа, которое для каждой функции отличаеться.*/
