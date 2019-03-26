#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int main() {
  std::fstream input("input");
  int pair_freq = 0;
  int trip_freq = 0;
  std::unordered_map<char, int> hist;

  std::string id;
  while (input >> id) {
    hist.clear();
     for (char c : id) {
      if (hist.count(c) == 0) {
        hist.insert({c, 1}); 
      } else {
        hist[c]++; 
      }
     }
    bool pair_counted = false;
    bool trip_counted = false;
     for (std::pair<char, int> p : hist) {
      std::cout << p.first << " : " <<  p.second << std::endl;
      if (!pair_counted && p.second == 2) {
        pair_freq++; 
        pair_counted = true;
      }
      else if (!trip_counted && p.second == 3) {
        trip_freq++; 
        trip_counted = true;
      }
      else if (pair_counted && trip_counted) {
        break; 
      }
     }
    std::cout << "-----" << std::endl;
  }


  std::cout << (pair_freq * trip_freq) << std::endl;
}

