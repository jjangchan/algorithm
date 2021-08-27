#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "programmers/Ex2)2021KakaoBlind.h"

using namespace std;
map<string,int> combi;

void combination(string src, string crs, int depth) {
    std::cout << "src : " << src << " , crs : " << crs << endl;
    if (crs.size() == depth) combi[crs]++;

    else for (int i = 0; i < src.size(); i++)
            combination(src.substr(i+1), crs+src[i], depth);
}

int main()
{
    std::vector<std::string> answer;
    std::vector<std::string> orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
    std::vector<int> course = {2,3,5};

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
    return 0;
}


