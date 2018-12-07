#include <fstream>
#include <iostream>
#include <set>

int main() { 
  bool repeat_not_found = true;
  int acc = 0;
  std::set<int> prev_seen {acc};
  while (repeat_not_found) {
    std::fstream infile("input.txt");
    int x;
    while (infile >> x) {
      acc += x;
      auto insert_stat = prev_seen.insert(acc);
      if (!insert_stat.second) {
        std::cout << acc << std::endl;
        repeat_not_found = false;
        break; 
      }
    }
  }
}
