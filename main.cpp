#include <iostream>
#include "programmers/1829.h"
#include <vector>

int main()
{
    std::vector<vector <int>> v;
    v={{1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3}};
    solution(6,4, v);
    return 0;
}
