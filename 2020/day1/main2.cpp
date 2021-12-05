
#include <iostream>
#include <unordered_set>
#include <vector>


int main(void) {

    std::unordered_set<int> entries;
    std::vector<int> entries_l;

    int in = -1;
    while( std::cin >> in) {
        entries.insert(in);
        entries_l.push_back(in);
    }

    for (int i = 0; i < entries_l.size(); ++i) {
        for (int j = i + 1; j < entries_l.size() -1; ++j) {
            int temp = 2020 - (entries_l[i] + entries_l[j]);
            if (entries.find(temp) != entries.end()) {
                std::cout << entries_l[i] * entries_l[j] * temp << std::endl;
                return 0;
            }
        }
    }

    return 0;
}
