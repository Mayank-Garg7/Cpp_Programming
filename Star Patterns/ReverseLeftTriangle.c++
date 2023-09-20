#include <iostream>
using namespace std;

int main() {
  // size of the triangle
  int size = 5;
  for (int i = 0; i < size; i++) {
    // print stars
    for (int j = 0; j < size - i; j++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}