#include <iostream>
using namespace std;

int main() {
  // size of the square
  int size = 5;
  // outer loop
  for (int i = 0; i < size; i++) {
    // inner loop
    for (int j = 0; j < size; j++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}