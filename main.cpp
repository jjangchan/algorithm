#include <vector>
#include <iostream>
#include <thread>

#define MAX 1000

int arr[MAX], dp[MAX];
int N;


std::ostream& operator<<(std::ostream& os, int* dp) {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        dp[i] = arr[i];
        for (int j = 0; j <= i; j++){
            if(arr[i] > arr[j]) if(dp[i] < dp[j]+arr[i]){
                dp[i] = dp[j]+arr[i];
            }
            sum = (sum > dp[i]) ? sum : dp[i];
        }
    }
    return os << sum;
}

void Init(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }
}

int main(){
    Init();
    std::cout << dp;
    return 0;
}