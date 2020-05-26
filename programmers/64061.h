//
// Created by JKC on 14/05/2020.
// 64061 - 크레인 인형뽑기 게임
//

#include <string>
#include <vector>
#include <stack>

using namespace std;

#ifndef ALGORITHM_64061_H
#define ALGORITHM_64061_H

int programmers()
{
    vector<vector<int>> board;
    vector<int> move {1,5,3,5,1,2,1,4};

    vector<int> row1 {0,0,0,0,0};
    vector<int> row2 {0,0,1,0,3};
    vector<int> row3 {0,2,5,0,1};
    vector<int> row4 {4,2,4,4,2};
    vector<int> row5 {3,5,1,3,1};

    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    board.push_back(row4);
    board.push_back(row5);

    int answer = 0;

    stack<int> s;

    for(int i=0; i< move.size();i++)
    {
        for(int j=0; j < board.size(); j++)
        {
            if(board[j][move[i]-1] != 0)
            {
                if(s.empty())
                {
                    s.push(board[j][move[i]-1]);
                }
                else
                {
                    if(s.top() == board[j][move[i]-1])
                    {
                        s.pop();
                        answer +=2;
                    }
                    else{
                        s.push(board[j][move[i]-1]);
                    }
                }
                board[j][move[i]-1] = 0;
                break;
            }
        }
    }

}

#endif //ALGORITHM_64061_H
