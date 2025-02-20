#include <iostream>
#include "parity.h"

using namespace std;

int main() {
    Parity p;
    p.insert(3);
    p.insert(2);
    p.insert(4);
    p.insert(5);
    p.insert(10);

    cout << p; 
    cout << "Min: " << p.min() << endl;
    cout << "Max: " << p.max() << endl;
    cout << "Odd? " << (p.odd() ? "yes" : "no") << endl;

    int arr[] = {3, 5, -1, 2, 6, 8, 10, 7, -2, 11, 15};
    Parity p2(arr, 11);

    cout << "\nTesting 2-argument constructor:" << endl;
    cout << p2;
    cout << "Min: " << p2.min() << endl;
    cout << "Max: " << p2.max() << endl;
    cout << "Odd? " << (p2.odd() ? "yes" : "no") << endl;

    return 0;
}