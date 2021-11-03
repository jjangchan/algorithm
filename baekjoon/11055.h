//
// Created by jjangchan on 2021-11-02.
//

#ifndef MAIN_CPP_11055_H
#define MAIN_CPP_11055_H
#include <algorithm>
#include <iostream>

int main(){
    int N = 0, sum = 0;
    scanf("%d", &N);
    int arr[N];
    int dp[N];
    for(int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        arr[i] = value;
    }
    for(int i = 0; i < N; i++){
        dp[i] = arr[i];
        for(int j = 0; j <= i; j++){
            if(arr[i] > arr[j]) if(dp[i] < dp[j]+arr[i]){
                    dp[i] = dp[j] + arr[i];
                }
            sum = (sum > dp[i]) ? sum : dp[i];
        }
    }
    std::cout << sum;
    return 0;
}

#endif //MAIN_CPP_11055_H
