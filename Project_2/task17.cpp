/*

Создайте класс time_and_date, которому при его создании передается текущее 
системное время и дата в виде параметров конструктора. 
Этот класс должен включать в себя функцию-член, выводящую время и дату на экран.
Подсказка : Для нахождения и вывода на экран этих данных 
воспользуйтесь стандартной библиотечной функцией времени и даты.
*/

#include <iostream>
#include <ctime>

using namespace std;

class get_date {

public:
    get_date(char *data);
};

get_date::get_date(char *date){
    cout << date << endl;
}

int main() {
    time_t current = time(NULL);
    char *date = ctime(&current);
    get_date type(date);
    return 0;
}
