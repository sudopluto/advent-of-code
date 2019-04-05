#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main(void) {


  fstream fin("input");
  regex re("[[:digit:]]+");

  string line;
  while(getline(fin, line)) {
    cout << line << endl; 
    auto num_begin = sregex_iterator(line.begin(), line.end(), re);
    auto num_end = sregex_iterator();
    for (sregex_iterator ii = num_begin; ii != num_end; ++ii) {
      cout << ii->str() << endl; 
    }

  }





  

  return 0;
}
