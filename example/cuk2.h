//
// Created by jjangchan on 2022/06/09.
//

#ifndef MAIN_CPP_CUK2_H
#define MAIN_CPP_CUK2_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>

void exam1(std::map<std::string, int> &m, std::string name, int score){
    m[name] = score;
    std::vector<std::pair<std::string, int>> v(m.begin(), m.end());
    std::sort(v.begin(), v.end(), [](std::pair<std::string,int> &a, std::pair<std::string , int> &b)->bool {
        if(a.second > b.second) return true;
        else if(a.second == b.second){
            if(a.first > b.first) return true;
        }
        return false;
    });
    for(auto pair : v){
        std::cout << pair.first << " , "  << pair.second << std::endl;
    }
}

int exam2(std::vector<int> v){
    int swap_count = 0;
    for(int i = 0; i < v.size(); i++){
        int min_index = i;
        for(int j = i+1; j < v.size(); j++){
            if(v[min_index] > v[j]) min_index = j;
        }
        if(min_index != i){
            swap_count++;
            int temp = v[min_index];
            v[min_index] = v[i];
            v[i] = temp;
        }
    }
    return swap_count;
}

void com(std::vector<std::pair<int,int>> &d, int r, int start, int krw, int kg, int max_kg, int size, int& max_krw){
   if(size >= r){
       if(max_kg >= kg) max_krw = std::max(max_krw, krw);
       return;
   }
   for(int i = start; i < d.size(); i++){
       com(d, r, i+1, krw+d[i].second, kg+d[i].first, max_kg, size+1, max_krw);
   }
}

void exam3(int kg){
    std::vector<std::pair<int, int>> diamond = {{6,13}, {4,8}, {3,6}, {5,12}};
    int max = 0;
    for(int r = 1; r <= diamond.size(); r++){
        com(diamond, r, 0, 0, 0, kg, 0, max);
    }
    std::cout << max << std::endl;
}

void exam4(int n , int k){
    std::queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i);
    int last_value;
    while(!q.empty()){
        if(q.size() == 1){
            last_value = q.front();
            break;
        }
        for(int i = 0; i < k-1; i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    std::cout << last_value;
}

int bs(std::vector<int> &v,int left, int right, int target){
    //std::cout << count << std::endl;
    int mid = (left+right)/2;
    if(v[mid] == target) {
        return 1;
    }
    v[mid] < target ? left = mid+1 : right = mid-1;
    return bs(v, left, right, target)+1;
}

int a(int count){
    return count+1;
}

void exam5(std::vector<int> v, int target){
    std::cout << bs(v,0, v.size()-1, target);
}

#endif //MAIN_CPP_CUK2_H
