#include <iostream>
using namespace std;

int main() {
  int size = 5;
  // upside pyramid
  for (int i = 1; i <= size; i++) {
    // printing spaces
    for (int j = size; j > i; j--) {
      cout << " ";
    }
    // printing star
    for (int k = 0; k < i * 2 - 1; k++) {
      if (k == 0 || k == 2 * i - 2) {
        cout << "*";
      }
      else {
        cout << " ";
      }
    }
    cout << "\n";
  }
  // downside triangle
  for (int i = 1; i < size; i++) {
    // printing spaces
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    // printing star
    for (int k = (size - i) * 2 - 1; k >= 1; k--) {
      if (k == 1 || k == (size - i) * 2 - 1) {
        cout << "*";
      }
      else {
        cout << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}