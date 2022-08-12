#include <iostream>
#include "programmers/lv2/86052.h"


int main() {

    std::vector<int> v = solution({"R","R"});
    for(const auto &i : v){
       std::cout << i << " ";
    }

    return 0;
}
