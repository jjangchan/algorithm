#include <iostream>
#include <vector>
int N,W;

std::pair<int, int>work[1001];
int dp_table[1001][1001];

int dist(std::pair<int, int> a, std::pair<int, int> b){
    return std::abs(b.first - a.first) + std::abs(b.second - a.second);
}

int dp(int x, int y){
    std::cout << "( " << x << " , " << y << " )" << std::endl;
    if(x == W || y == W) return 0;
    //memoization
    int &cache = dp_table[x][y];
    if(cache != -1) return dp_table[x][y];

    int next = std::max(x, y)+1;
    int distance1, distance2;

    //base
    // move x
    distance1 = (x==0) ? dist({1,1}, work[next]) : dist(work[x], work[next]);
    // move y
    distance2 = (y == 0) ? dist({N,N}, work[next]) : dist(work[y], work[next]);
    int t_d1 = dp(next, y) + distance1;
    int t_d2 = dp(x, next) + distance2;
    std::cout << "[" << x << ", " << y << "] total distance1 : " << t_d1 << std::endl;
    std::cout << "[" << x << ", " << y << "] total distance2 : " << t_d2 << std::endl;
    cache = std::min(t_d1, t_d2);
    std::cout << "cache : " << cache << std::endl;
    return cache;
}

int main(){

    int w;

    w = getchar();

    //w = 12;

    std::cout <<sizeof(w) << "," << (char)w;

    return 0;

    scanf("%d\n%d", &N, &W);
    for(int i = 1; i <= W; i++) {
        int first, second;
        scanf("%d %d",&first,&second);
        work[i].first = first, work[i].second = second;
    }
    memset(dp_table, -1, sizeof(dp_table));
    std::cout << dp(0,0);
    return 0;
}