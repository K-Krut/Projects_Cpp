/*
Объясните, почему работает такой код:

*/

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  
	cout << argv[argc - 1] << endl << argc[argv - 1] << endl;
  
	return EXIT_SUCCESS;
}

/*
argv и argc - это встороеные аргументы функции main предназначеные для
получения аргументов командной строки
аргумент argc - это количество аргументов командной строки
имя програмы - это первый аргумент создержащийся в argc 
потому если argc < 1 то выводиться имя программы
argv - указатель на массив символьных указателейб указателей на на аргументы  
командной строкию Таким образом argv[0] - указатель на первую строку,
на имя программы
*/