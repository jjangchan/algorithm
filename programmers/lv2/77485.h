//
// Created by jjangchan on 2021-12-24.
// 행렬 테두리 회전하기
//

#ifndef MAIN_CPP_77485_H
#define MAIN_CPP_77485_H

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    // initialize Data
    int matrix[rows+1][columns+1];
    int temp_matrix[(((rows-1)*2)+((columns-1)*2))+1];
    for(int i = 1; i <= rows; i++) for(int j = 1; j <= columns; j++){
        matrix[i][j] = ((i-1)*columns)+j;
    }
    // Rotation
    for(const auto& v : queries){
        int r = v[0], c = v[1];
        int min = matrix[r][c], count = 0;
        temp_matrix[count++] = min;
        for(int i = 0; i < 4; i++){
            int end = i&1 ? v[2]-v[0] : v[3]-v[1];
            int x = "1210"[i] -'1', y = "2101"[i] -'1';
            for(int j = 0; j < end; j++, count++){
                r += x, c += y;
                min = std::min(matrix[r][c], min);
                temp_matrix[count] = matrix[r][c];
                matrix[r][c] = temp_matrix[count-1];
            }
        }
        answer.push_back(min);
    }
    return answer;
}

#endif //MAIN_CPP_77485_H
