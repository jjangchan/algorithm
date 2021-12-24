//
// Created by jjangchan on 2021-08-25.
//

#ifndef ALGORITHM_EX2_2021KAKAOBLIND_H
#define ALGORITHM_EX2_2021KAKAOBLIND_H
#include <algorithm>
#include <string>
#include <vector>
#include <map>

/** 간결하고 가독성 좋은 풀이
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
**/

void Combination(const int n,
                 const int r,
                 const int index,
                 const int target,
                 const std::string source_str,
                 std::string& key,
                 std::map<std::string, int>& result_map,
                 int &max)
{
    if(r == 0)
    {
        auto iter = result_map.find(key);
        int value = (iter == result_map.end()) ? 1 : result_map.find(key)->second+1;
        result_map[key] = value;
        max = (value > max) ? value : max;
    }
    else if(n == target)
        return;
    else
    {
        key[index] = source_str[target];
        Combination(n, r-1, index+1, target+1, source_str, key, result_map, max);
        Combination(n, r, index, target+1, source_str, key, result_map, max);
    }
}

void Input()
{
    std::vector<std::string> answer;
    std::vector<std::string> orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
    std::vector<int> course = {2,3,5};


    for(int i = 0; i < course.size(); i++)
    {
        int r = course[i];
        std::map<std::string, int> m;
        int max = 0;
        for(int j = 0; j < orders.size(); j++)
        {
            std::string source = orders[j];
            std::sort(source.begin(), source.end());
            if(source.size() >= r)
            {
                std::string key;
                key.resize(r);
                Combination(source.size(), r, 0, 0, source, key, m, max);

            }
        }
        for(auto it = m.begin(); it != m.end(); it++)
        {
            std::string key = it->first;
            int value = it->second;
            if(value == max && max > 1)
                answer.push_back(key);
        }
    }

    for(int i = 0; i < answer.size(); i++)
    {
        std::cout << answer[i] << std::endl;
    }
}

#endif //ALGORITHM_EX2_2021KAKAOBLIND_H
