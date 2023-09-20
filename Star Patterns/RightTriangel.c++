#include <iostream>
using namespace std;

int main() {
  // size of the triangle
  int size = 5;
  // loop to print the pattern
  for (int i = 0; i < size; i++) {
    // print spaces
    for (int j = 1; j < size - i; j++) {
      cout << " ";
    }
    // print stars
    for (int k = 0; k <= i; k++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}