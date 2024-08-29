//
// Created by jjangchan on 2023/12/20.
//

#ifndef MAIN_CPP_2023_12_20_H
#define MAIN_CPP_2023_12_20_H

#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::string solution(const std::string& character, const std::vector<std::string>& monsters){
    std::string result;
    double rank = 0;
    int c_hp, c_power, c_defense;
    std::istringstream iss(character);
    iss >> c_hp >> c_power >> c_defense;

    for(const auto& m : monsters){
        int m_exp, m_hp, m_power, m_defense;
        std::string name;
        std::istringstream m_iss(m);
        m_iss >> name >> m_exp >> m_hp >> m_power >> m_defense;
        double cal = ceil((double)m_hp/((double)c_power-(double)m_defense));
        if(cal > 1 && (c_hp-(m_power-c_defense)) <= 0) continue;
        double total_exp = (double)m_exp/cal;
        if(total_exp > rank){
            result = name;
            rank = total_exp;
        }
    }
    return result;
}

#endif //MAIN_CPP_2023_12_20_H
