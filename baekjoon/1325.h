//
// Created by momantic03 on 2021-10-26.
//

#ifndef MAIN_CPP_1325_H
#define MAIN_CPP_1325_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>

const int MAX = 10001;
std::vector<int> node[MAX];

void SearchNode(bool *is, const int key, int& count){
    if(node[key].empty()) return;
    for(int i = 0; i < node[key].size(); i++){
        if(!is[node[key][i]]){
            is[node[key][i]] = true;
            count++;
            SearchNode(is, node[key][i], count);
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d",&n, &m);
    int arr_m[m];
    for(int i = 0; i < m; i++){
        int value, key;
        scanf("%d %d", &value, &key);
        node[key].push_back(value);
        arr_m[i] = key;
    }
    bool all_access[n+1];
    memset(all_access, false, sizeof(all_access));
    int line = 0;
    std::vector<int> result;
    for(int i = 0; i < m; i++){
        if(all_access[arr_m[i]]) continue;
        all_access[arr_m[i]] = true;
        bool is_access[n+1];
        memset(is_access, false, sizeof(is_access));
        int count = 1;
        is_access[arr_m[i]] = true;
        SearchNode(is_access, arr_m[i], count);
        if(count == line) result.push_back(arr_m[i]);
        else if(count > line){
            result.clear();
            line = count;
            result.push_back(arr_m[i]);
        }
        //std::cout << "node : " << arr_m[i] << " , count : " << count << std::endl;
    }
    std::sort(result.begin(), result.end());
    for(auto i : result) std::cout << i << " ";
    return 0;
}
#endif //MAIN_CPP_1325_H
