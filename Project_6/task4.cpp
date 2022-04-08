/*
Объясните, почему следующая программа заканчивается сообщением
Aborted (core dumped) и исправьте ее: 
*/
#include <iostream>
#include <cstdlib>

using namespace std;

class myclass {
private:
    int *ptr;
public:
    myclass(int i);
    ~myclass() { delete ptr; }
    friend int getval(myclass &obj);
};

myclass::myclass(int i){

    ptr = new int(i);
    if (!ptr)
        exit(1);

}

int getval(myclass &obj) {
    return *obj.ptr;
}

int main() {

    myclass a(1), b(2);

    cout << getval(a) << ' ' << getval(b) << endl;
    cout << getval(a) << ' ' << getval(b);

return 0;
}

/*
При передачі об'єкта у функцію getval() створюється його копія, 
але Функція getval() повертає значення копія видаляється, 
а пам'ять виділена для об'єкта який передається getval(myclass obj) 
звільнюється і в подальшому вона не може бути використана, тому виникає помилка
*/

