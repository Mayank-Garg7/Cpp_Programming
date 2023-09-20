#include <iostream>
using namespace std;

int main() {

  int size = 5;
  // loop to print the pattern
  for (int i = 0; i < size; i++) {
    // print spaces
    for (int j = 1; j < size - i; j++) {
      cout << " ";
    }
    // print number
    for (int k = 0; k <= i; k++) {
      cout << (k+1);
    }
    cout << "\n";
  }
  return 0;
}