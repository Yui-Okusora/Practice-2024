#include <iostream>
#include <cstdio>

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m, n, k, ans;
    std::cin >> m >> n >> k;

    int arr[m][n];
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            std::cin >> arr[i][j];
    
    int prizes[m - k + 1][n - k + 1] = {};

    int maxPrize = 0;
    
    for(int i = 0; i <= m - k; ++i){
        int prevCol = 0;
        for(int j = 0; j <= n - k; ++j){
            int& prize = prizes[i][j];
            if(j == 0){
                for(int l = 0; l < k; ++l){
                    for(int p = 0; p < k; ++p){
                        prize += arr[i + l][j + p];
                    }
                    prevCol += arr[i + l][j];
                }
            }else{
                prize = prizes[i][j-1] - prevCol;
                int nextCol = 0;
                prevCol = 0;
                for(int l = 0; l < k; ++l){
                    nextCol += arr[i + l][j + k - 1];
                    prevCol += arr[i + l][j];
                }
                prize += nextCol;
            }
            maxPrize = std::max(maxPrize, prize);
        }
    }
    std::cout << maxPrize;
    return 0;
}