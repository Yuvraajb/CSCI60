// CSCI 60 HW1, due Thursday, Jan. 16, 2025
// This program includes functions to check if an array is sorted, shift array elements to the right,
// find the intersection of two arrays, and swap two variables. 
// Name: Yuvraaj Bhatter


#include <iostream>
using namespace std;

bool isSorted(int a[], int size);
void shiftRight(int a[], int size);
bool findIntersection(int a1[], int size1, int a2[], int size2, int a3[], int size3);
void swap(int &a, int &b); // Declaration of the swap function

// Definition of the swap function
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Main function
int main() {
    int a1[5] = {2, -10, 90, 6, 4};

    // Test for isSorted
    cout << "Is a1 sorted in ascending order? "
         << (isSorted(a1, 5) ? "True" : "False") << endl;

    // Test for shiftRight
    cout << "a1 before shiftRight\n";
    for (int i = 0; i < 5; i++) {
        cout << a1[i] << " ";
    }
    cout << endl;
    shiftRight(a1, 5);
    cout << "a1 after shiftRight\n";
    for (int i = 0; i < 5; i++) {
        cout << a1[i] << " ";
    }
    cout << endl;

    // Test for findIntersection
    int a2[4] = {90, 2, 4, 5}, a3[2], a4[10];
    cout << "Does a3 contain the common elements in a1 and a2? "
         << (findIntersection(a1, 5, a2, 4, a3, 2) ? "True" : "False")
         << endl;

    cout << "Does a4 contain the common elements in a1 and a2? "
         << (findIntersection(a1, 5, a2, 4, a4, 10) ? "True" : "False")
         << endl;

    // Test for swap function
    int a = 2, b = 10;
    swap(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}

/* Check if the array is sorted in ascending order */
bool isSorted(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

/* Find the intersection of two arrays */
bool findIntersection(int a1[], int size1, int a2[], int size2, int a3[], int size3) {
    int count = 0;  
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (a1[i] == a2[j]) {  
                if (count < size3) {
                    a3[count] = a1[i]; 
                    count++;  
                } else {
                    return false;  
                }
                break;
            }
        }
    }
    cout << "Number of common elements: " << count << endl;
    return count > 0; // Return true if there are common elements
}

/* Shift the array elements to the right */
void shiftRight(int a[], int size) {
    int temp = a[size - 1];
    for (int i = size - 1; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = temp; 
}