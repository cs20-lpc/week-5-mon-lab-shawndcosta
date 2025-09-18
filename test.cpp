#include <iostream>
#include <string>
#include "DoublyList.hpp"

using namespace std;

void testList() {
    DoublyList<int> list;
    list.append(10);
    list.append(20);
    list.append(30);
    cout << list;

    cout << "length: " << list.getLength() << endl;
    list.insert(1, 15);
    cout << list;
    list.remove(2);
    cout << list;
    list.replace(1, 99);
    cout << list;
    list.clear();
    cout << list;

}



int main() {
    testList();
    return 0;
}
