// Implementation file for CSCI 60 Homework 6; due Wednesday, 03/12/2025
// Yuvraaj Bhatter

#include "node.h"
ostream& operator <<(ostream& out, const node * head) {
    if (head==nullptr) return out;
    out << head->data() << " ";
    return (out << head->link());
}


int f1(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return f1(n - 2) + n - 1;
}

void f2(int * a, int first, int last) {
    if (first >= last) {
        return;
    }

    int temp = a[first];
    a[first] = a[last];
    a[last] = temp;

    f2(a, first + 1, last - 1);
}

void f3(node *& head, node *& tail, int * a, int n) {

    if (n <= 0) {
        return;
    }

    if (head == nullptr) {
        head = new node(a[0], nullptr);
        tail = head;
    } else {

        tail->set_link(new node(a[0], nullptr));
        tail = tail->link();
    }
    f3(head, tail, a + 1, n - 1);
}

void f4(node *& head, node *& tail) {
    if (head == nullptr) {
        tail = nullptr;
        return;
    }

    node* next = head->link();
    delete head;
    head = next;
    f4(head, tail);
}
