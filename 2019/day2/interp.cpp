#include <iostream>
#include <vector>
#include <stdlib.h>

int main(void)
{
    std::vector<int> program;
    int a;
    while (std::cin >> a) 
    {
        program.push_back(a);
        std::cin.ignore(1, ',');
    }

    int ins_p = 0;

    program[1] = 12;
    program[2] = 2;

    while(ins_p < program.size())
    {
        int arg1_p = program[ins_p + 1];
        int arg2_p = program[ins_p + 2];
        int result_p = program[ins_p + 3];
        switch(program[ins_p])
        {
            case 1:
                program[result_p] = program[arg1_p] + program[arg2_p];
                break;
            case 2:
                program[result_p] = program[arg1_p] * program[arg2_p];
                break;
            case 99:
                std::cout << program[0];
                exit(0);
            default:
                exit(1);
        }
        
        ins_p += 4;
    }

    std::cout << program[0];
    return 0;
}
