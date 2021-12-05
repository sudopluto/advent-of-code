#include <iostream>
#include <string>


// 15-16 m: mhmjmzrmmlmmmmmm

int main(void) {
    int i0;
    int i1;
    char trash;
    char c;
    std::string passwd;

    int count_valid = 0;
    while (std::cin >> i0 >> trash >> i1 >> c >> trash >> passwd) {
       if (passwd[i0 - 1] == c ? !(passwd[i1 - 1] == c) : passwd[i1 - 1] == c) {
           ++count_valid;
       }
    }
    std::cout << count_valid << std::endl;
    return 0;
}
