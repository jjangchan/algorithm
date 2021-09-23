#include "programmers//12949.h"
#include <iostream>
#include <vector>

int main(){
    std::vector<std::vector<int>> arr1;
    std::vector<std::vector<int>> arr2;
    arr1.push_back({2, 3, 2});
    arr1.push_back({4, 2, 4});
    arr1.push_back({3, 1, 4});
    arr2.push_back({5, 4, 3});
    arr2.push_back({2, 4 ,1});
    arr2.push_back({3, 1 ,1});
    std::vector<std::vector<int>> result = solution(arr1, arr2);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[0].size(); j++){
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}






