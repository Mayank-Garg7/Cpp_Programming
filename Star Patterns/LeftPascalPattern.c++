#include <iostream>
using namespace std;

int main() {
  // left pasal triangle
  int size = 5;

  for (int i = 1; i <= size; i++) {
    for (int j = 0; j < size - i; j++) {
      cout << " ";
    }
    for (int k = 0; k < i; k++) {
      cout << "*";
    }
    cout << "\n";
  }
  for (int i = 1; i <= size - 1; i++) {
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    for (int k = 0; k < size - i; k++) {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}