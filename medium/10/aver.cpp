#include <iostream>
#include <cstdio>

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;

    std::cin >> n >> k;
    
    int arr[n];
    int presum[n + 1] = {};
    for(int i = 0; i < n; ++ i){
        std::cin >> arr[i];
        arr[i] -= k;
        presum[i + 1] = presum[i] + arr[i];
    }

    int best = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (presum[j+1] - presum[i] >= 0) {
                best = std::max(best, j - i + 1);
            }
        }
    }
    
    std::cout << best;

    return 0;
}