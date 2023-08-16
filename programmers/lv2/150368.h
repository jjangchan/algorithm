//
// Created by jjangchan on 2023/08/03.
//

#ifndef MAIN_CPP_150368_H
#define MAIN_CPP_150368_H

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    double discount[4] = {0.9, 0.8, 0.7, 0.6};
    int discount_cnt[4] = {0,0,0,0};
    for(const std::vector<int>& v : users){
        for(int i = 0; i < 4; i++){
            int a = std::round((1.0-discount[i])*100.0);
            if(a >= v[0]) discount_cnt[i]++;
        }
    }
    std::vector<double> v_discount;
    std::stack<std::string> go;
    for(int i = 0; i < 4; i++) if(discount_cnt[i]) v_discount.push_back(discount[i]);
    for(int i = 0; i < v_discount.size(); i++) go.push(std::to_string(i));
    std::vector<std::vector<int>> result(v_discount.size()+1);
    int max_size = 0;

    while(!go.empty()){
        std::string str = go.top();
        go.pop();
        if(str.size() == emoticons.size()){
            std::cout << str << std::endl;
            int plus_cnt = 0, buy = 0;
            for(const std::vector<int>& v : users){
                int total = 0;
                for(int i = 0; i < str.size(); i++){
                    int a = std::round((1.0-v_discount[str[i]-'0'])*100.0);
                    std::cout << a << " ";
                    if(a >= v[0]) total += (std::round(emoticons[i]*v_discount[str[i]-'0']));
                }
                if(total >= v[1]) plus_cnt++;
                else buy += total;
            }
            std::cout << std::endl;
            std::cout << plus_cnt << "," << buy << std::endl;
            std::cout << "=============================" << std::endl;
            result[plus_cnt].push_back(buy);
            max_size = std::max(max_size, plus_cnt);
        } else for(int i = 0; i < v_discount.size(); i++) go.push( str+std::to_string(i));
    }

    std::sort(result[max_size].begin(), result[max_size].end(), greater<>());
    for(int i : result[max_size]){
        std::cout << i << " ";
    }
    return {max_size, result[max_size][0]};
}

#endif //MAIN_CPP_150368_H
