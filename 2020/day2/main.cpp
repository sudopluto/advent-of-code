#include <iostream>
#include <string>
#include <algorithm>


// 15-16 m: mhmjmzrmmlmmmmmm

int main(void) {
    int min;
    int max;
    char trash;
    char c;
    std::string passwd;

    int count_valid = 0;
    while (std::cin >> min >> trash >> max >> c >> trash >> passwd) {
       int freq = std::count(passwd.begin(), passwd.end(), c);
       if ( freq >= min && freq <= max) {
           ++count_valid;
       }
    }
    std::cout << count_valid << std::endl;
    return 0;
}
