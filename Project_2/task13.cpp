/*
Создайте функцию rev_str() для изменения порядка следования символов строки на обратный. 
Перегрузите rev_str() так, чтобы она могла вызываться с одним или двумя
символьными строками. Если функция вызывается с одной строкой, 
то операция должна осуществляться с ней. Если она вызывается с двумя строками, 
то результирующая строка должна оказаться во втором аргументе 
(см. Unit 2 "Overloaded functions that differ in the number of their arguments").
*/



#include <iostream>
#include <cstring>

#define SIZE 100

using namespace std;

void reverse_string(char *str1, char *str2){
    for(int i = 0, j = strlen(str1); i < j; ++i)
        str2[i] = str1[j - i - 1];
            cout << str2 << endl;
}

void reverse_string(char *str1){
    char str3[SIZE];
    for(int i = 0, j = strlen(str1); i < j; ++i)
        str3[i] = str1[j - i - 1];
    strncpy(str1, str3, strlen(str3));
    cout << str3 << endl;
}
/*
void reverse_1(char *str){
int i, j;
    for(i = 0, j = strlen(str) - 1; i < j; ++i, --j)
        swap(str[i], str[j]);
    cout << "reverse_1  " << str << endl;
}
*/
int main() {

  char str1[SIZE], str2[SIZE];
  cin >> str1;
  reverse_string(str1);
//reverse_1(str1);
  cin >> str1;
  reverse_string(str1, str2);

  return 0;
}

