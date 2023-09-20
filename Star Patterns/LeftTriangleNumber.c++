#include <iostream>
using namespace std;

int main() {

  int size = 5;
  // loop to print the pattern
  for (int i = 0; i < size; i++) {
    // print column
    for (int j = 0; j <= i; j++) {
      cout << (j+1);
    }
    cout << "\n";
  }
  return 0;
}