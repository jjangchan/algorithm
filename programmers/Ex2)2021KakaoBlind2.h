//
// Created by jjangchan on 2021-09-07.
//

#ifndef ALGORITHM_EX2_2021KAKAOBLIND2_H
#define ALGORITHM_EX2_2021KAKAOBLIND2_H

#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
map<string,int> combi;

void combination(string src, string crs, int depth) {
    if (crs.size() == depth) combi[crs]++;

    else for (int i = 0; i < src.size(); i++)
            combination(src.substr(i+1), crs+src[i], depth);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string &order : orders)
        sort(order.begin(), order.end());

    for (int crs : course) {
        for (string order : orders)
            combination(order, "", crs);

        int sup = 0;
        for (auto it : combi)
            sup = max(sup, it.second);
        for (auto it : combi)
            if (sup >= 2 && it.second == sup)
                answer.push_back(it.first);
        combi.clear();
    }

    sort(answer.begin(), answer.end());
    return answer;
}


#endif //ALGORITHM_EX2_2021KAKAOBLIND2_H
