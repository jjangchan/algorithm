//
// Created by jjangchan on 2021-11-19.
// 2757 - 엑셀
//

#ifndef MAIN_CPP_2757_H
#define MAIN_CPP_2757_H

#include <iostream>
#include <string>
#include <vector>
std::vector<std::pair<int,int>> row_col;

void Init(){
    while(true){
        int row, col;
        int row_count = 1;
        std::string excel;
        std::cin >> excel;
        while(isdigit(excel[row_count])) row_count++;
        row = atoi(excel.c_str()+1);
        col = atoi(excel.c_str()+row_count+1);
        if(row+col == 0)break;
        row_col.push_back({row,col});
    }
}

int main(){
    Init();
    for(auto& p : row_col){
        int col = p.second;
        std::string str = "";
        while(col){
            str = (char)('A'+((col-1)%26)) + str;
            col = (col-1) / 26;
        }
        std::cout << str << p.first << std::endl;
    }
    return 0;


#endif //MAIN_CPP_2757_H
