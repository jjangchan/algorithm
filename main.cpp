#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include "baekjoon/2667.h"

int A[27][27],B[1000],p=0;
int house(int x, int y){
    if(A[x][y]==1){
        A[x][y]=0;
        B[p]++;
        for(int i=0; i<4; i++)
        {
            int cal_x = x +"0112"[i] - '1';
            int cal_y = y + "1201"[i] - '1';
            std::cout << " x = " << x << " , y = " << y << std::endl;
            std::cout << " cal_x = " << cal_x << " , cal_y = " << cal_y << std::endl;
            house(cal_x,  cal_y);
        }
    }
    return 0;
}
int main(){
    int N;
    int i,j;
    scanf("%d",&N);
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)scanf("%1d",&A[i][j]);
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)if(A[i][j]==1){
                house(i,j);
                p++;
            }
    std::sort(B,B+p);
    printf("%d\n",p);
    for(i=0; i<p; i++)printf("%d\n",B[i]);
    return 0;
}






