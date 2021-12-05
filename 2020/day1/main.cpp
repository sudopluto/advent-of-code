#include <iostream>
#include <unordered_set>


int main(void) {

    std::unordered_set<int> entries;

    int in = -1;
    while( std::cin >> in) {
        entries.insert(in);
    }

    for (auto i : entries) {
        if (entries.find(2020 - i) != entries.end()) {
            std::cout << i * (2020 - i) << std::endl;
            return 0;
        }
    }

    return 0;
}
