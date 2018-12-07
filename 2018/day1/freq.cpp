#include <fstream>
#include <iostream>

int main() {
  std::fstream infile("input.txt");
  int x;
  int acc = 0;
  while (infile >> x) {
    acc += x;
  }
  std::cout << acc << std::endl;
}
