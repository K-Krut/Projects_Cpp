/*
В большинстве компиляторов C++ применяются нестандартные функции, 
управляющие позиционированием курсора и другими аналогичными действиями. 
Вы помните, что вам ранее уже было разрешено пользоваться любыми компиляторами, 
а не только g++? Если в используемом вами компиляторе применяются такие функции, 
создайте функцию myclreol(), которая стирает строку,  
начиная от текущей позиции курсора до конца строки. 
Передайте этой функции параметр, задающий число стираемых позиций. 
Если параметр не задавать, то по умолчанию должна стираться вся строка. 
В противном случае должно стираться число символьных позиций, заданное параметром.
*/


#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

void myclreol(int cursor, int len){
   COORD pos;
   //pos.Y = 5;
   pos.Y = 3;
   pos.X = cursor;
    for (int i = SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); i < len - pos.X + 1; ++i)
         cout << ' ';
}
int main(){
    string str;
    int a;
   // cout << "enter string" << endl;
    getline(cin, str);
    cout << str << endl;
  //  cout << "enter position" << endl;
    cin >> a;
    cout << str << endl;
    myclreol(a, str.length());

    return 0;
}
