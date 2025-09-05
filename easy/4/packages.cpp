#include <iostream>
#include <cstdio>

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    std::cin >> n;

    if(n % 5 == 0){
        std::cout << n / 5;
        return 0;
    }

    for(int i = 0; i <= n / 3; ++i)
    {
        for(int j = 0; j <= (n / 3) - i; ++j){
            if(i * 3 + j * 5 > n) 
                break;
            if(i * 3 + j * 5 == n){
                std::cout << i + j;
                return 0;
            }
        }
    }
    
    std::cout << -1;
    return 0;
}