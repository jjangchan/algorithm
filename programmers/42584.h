//
// Created by JKC on 17/05/2020.
//

#ifndef ALGORITHM_42584_H
#define ALGORITHM_42584_H
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0; i<prices.size()-1;i++)
    {
        int now = prices[i];
        bool flag = false;
        for(int j=i+1; j<prices.size();j++)
        {
            if(now > prices[j])
            {
                answer.push_back(j-i);
                flag = true;
                break;
            }
        }
        if(!flag)answer.push_back(prices.size()-(i+1));
    }
    answer.push_back(0);

    return answer;
}
#endif //ALGORITHM_42584_H
