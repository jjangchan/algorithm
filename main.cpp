#include <iostream>
#include <vector>
#include "programmers/42578.h"


void combination(string src, string crs, int depth) {
    if (crs.size() == depth) std::cout << crs << std::endl;

    else for (int i = 0; i < src.size(); i++)
            combination(src.substr(i+1), crs+src[i], depth);
}

int main(){
    std::vector<std::vector<std::string>> v = {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}};
    solution(v);
    return 0;
}






