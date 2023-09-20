#include <iostream>
using namespace std;

int main() {
  // size of the triangle
  int size = 5;
  for (int i = 0; i < size; i++) {
    // print spaces
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    // print stars
    for (int j = size; j > i; j--) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}