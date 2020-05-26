//
// Created by JKC on 14/05/2020.
//
#include <iostream>
#ifndef ALGORITHM_2020_05_14_2_1_3_H
#define ALGORITHM_2020_05_14_2_1_3_H

void natural_number(int num1, int num2)
{
    if(num1 == 1)
    {
        std::cout << num2 << " ";
        return;
    }
    else if(num1 !=0 && num2%num1 != 0)
    {
        natural_number(num1-1,num2);
    }
    return;
}

int go()
{
    int a, b;
    std::cin >> a >> b;
    for(int i=a; i<=b; i++){
        natural_number(i-1,i);
    }
    return 0;
}

#endif //ALGORITHM_2020_05_14_2_1_3_H
