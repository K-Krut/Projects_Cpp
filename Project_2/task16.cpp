/*
Измените класс stack (см . Unit 2 "An Improved Version of the Stack class") так, 
чтобы память для стека выделялась динамически. 
При этом длина стека должна задаваться параметром конструктора. 
(Не забудьте освободить эту память с помощью деструктора!)
*/


#include <iostream>

using namespace std;

class stack{
	int size;
	char *stack_1;
public:
	stack();
	~stack();
	void push(char name);
	char pop();
};

stack::~stack(){
	delete[] stack_1;
}

stack::stack(){
	size = 16;
	stack_1 = new char[size];
}

char stack::pop(){
	//if (size == 0)
	--size;
	return stack_1[size];
}

void stack::push(char name){
	stack_1[size] = name;
	++size;
}

int main(){
	stack s1;
	s1.push('a');
	s1.push('b');
	s1.push('c');
	s1.push('d');
	s1.push('e');

	for (int i = 0; i < 5; i++)
        		cout << s1.pop() << endl;
	return 0;
}

