// Test program starter file for CSCI 60 Homework 2; due Thursday 01/23/25
// Give a program description, list any collaborators, and write your name here

#include <iostream>
#include "histogram.h"

using namespace std;

int main() {

  /* TODO: replace this comment and the code below with your unit tests */
  
  
  int total = 0; // var to store total
  ifstream in("data.txt"); // open a file called data.txt as an input stream in
  int val; // var to store one int at a time
  while (in >> val) { // read int tokens from stream 1-by-1 until end of file
    total += val; // add value of each token to total
  }
  in.close(); // close file
  cout << "Sum of all ints in a file = " << total << endl; // report total
  

  Histogram h("data.txt");
  cout << "The stub 1-argument constructor ran without error!\n";

  return 0;
}
