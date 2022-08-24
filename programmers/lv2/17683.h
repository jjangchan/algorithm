//
// Created by jjangchan on 2022/08/22.
//

#ifndef MAIN_CPP_17683_H
#define MAIN_CPP_17683_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

std::string convert_m(const std::string& m){
    std::string str = "";
    for(int i = 0; i < m.size(); i++){
        if(m[i] == '#'){
           char a = m[i-1]+'#';
           str.pop_back(), str.push_back(a);
        }else str.push_back(m[i]);
    }
    return str;
}

string solution(string m, vector<string> musicinfos) {
    std::string c_m = convert_m(m);
    std::vector<std::vector<std::string>> infos;
    for(const auto& s: musicinfos){
        std::stringstream ss(s);
        std::string token;
        std::vector<std::string> v;
        while(std::getline(ss, token, ',')) v.push_back(token);
        infos.push_back(v);
    }
    std::pair<std::string, int> result = {"(None)", 0};
    for(const auto& v : infos){
        int hour = std::stoi(v[1].substr(0,2)) - std::stoi(v[0].substr(0,2));
        int min2 = std::stoi(v[1].substr(3,2));
        int min1 = std::stoi(v[0].substr(3,2));
        int total = hour*60;
        if(min2 >= min1) total += (min2-min1);
        else {
            total -= 60;
            total += (min2-min1+60);
        }
        std::string info = v[3];
        std::string c_info = convert_m(info);
        if(total > c_info.size()){
            std::string temp = c_info;
            int size = (total/c_info.size())-1;
            for(int i = 0; i < size; i++) c_info += temp;
            for(int i = 0; i < total%temp.size(); i++) c_info.push_back(temp[i]);

        }else if(total < c_info.size()) c_info = c_info.substr(0, total);
        int find_index = c_info.find(c_m);
        if(find_index != -1 && result.second < total){
            result.first = v[2];
            result.second = total;
        }
    }
    return result.first;
}

#endif //MAIN_CPP_17683_H
