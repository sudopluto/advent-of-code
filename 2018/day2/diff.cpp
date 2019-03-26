#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  fstream input("input");

  vector<string> ids;

  string id;
  while (input >> id) {
    ids.push_back(id);
  }


  for (int ii = 0; ii < ids.size() -1; ++ii) {
    for (int jj = ii + 1; jj < ids.size(); ++jj) {
      int diff = 0;
      string ans = "";
      for (int kk = 0; kk < ids[ii].length() && diff <= 1; ++kk) {
        if (ids[ii][kk] == ids[jj][kk]) {
          ans.push_back(ids[ii][kk]);
        }
        else {
          ++diff; 
        }

      }

      if (diff == 1) {
        cout << ans << endl; 
        return 0;
      }

    }
  }

  return 0;

}

