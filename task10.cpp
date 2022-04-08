/*
Создайте функцию reverse() с двумя параметрами. Первый параметр str - это указатель на строку, 
порядок следования символов в которой, после возвращения функцией своего значения, 
должен быть заменен на обратный. Второй параметр count задает количество переставляемых 
в строке str символов. Значение count по умолчанию должно быть таким, 
чтобы в случае его не задания функция reverse() меняла порядок следования символов в целой строке.
*/

#include <iostream>
#include <cstring>

using namespace std;

void reverse_s(char str[], int n){
    for(int j = 0, k = n - 1; j < k; j++, k--)
        swap(str[j],str[k]);
}

void reverse_s(char str[]) {
for(int j = 0, k = strlen(str) - 1; j < k; j++, k--)
    swap(str[j],str[k]);
}


int main (){

    char *str = new char[100];
    char *str1 = new char[100];
    int n;

    cin.getline(str, 100);
    reverse_s(str);
    cout << str << endl;

    cin.getline(str1, 100);
    cin >> n;

    reverse_s(str1, n);
    cout << str1 << endl;

    delete [] str;
    delete [] str1;

return 0;
}
