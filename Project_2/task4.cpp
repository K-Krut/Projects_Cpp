/*
Создайте класс card, который поддерживает каталог библиотечных карточек. 
Этот класс должен хранить заглавие книги, имя автора и выданное на 
руки число экземпляров книги. Заглавие и имя автора храните в виде 
строки символов, а количество экземпляров - в виде целого числа. 
Используйте открытую функцию-член store() для запоминания информации 
о книгах и открытую функцию-член show() для вывода информации на экран. 
В функцию main() включите краткую демонстрацию работы созданного класса
*/


#include <iostream>
#include <cstring>

typedef const char cchar;
using namespace std;

class card {
private:
	int copies;
	char name[100];
	char author[100];
public:
	void get_data(cchar* title, cchar* men, int num);
	void show();
};

void card::get_data(cchar* title, cchar* men, int num) {
	copies = num;
	strcpy(name, title);
	strcpy(author, men);
}

void card::show() {
	cout << name << ' ' << author << ' ';
	cout << copies << endl;
}

main() {
	card book1, book2;

	book1.get_data("The Da Vinci Code", "Dan Brown", 14);
	book2.get_data("The Three Musketeers", "Alexandre Dumas", 25);

	book1.show();
	book2.show();

	return 0;
}

