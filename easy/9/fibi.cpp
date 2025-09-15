#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

char kth(int n, long long k, const std::vector<long long>& len){
    while (n > 1) {
        if (k <= len[n-2]) 
            n -= 2;
        else{
            k -= len[n-2];
            n -= 1;
        }
    }
    return (n == 0 ? 'a' : 'b');
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    std::cin >> t;

    std::vector<long long> len(46);
    
    len[0] = 1;
    len[1] = 1;
    
    for(int e = 0, i = 2; e < t; ++e)
    {
        int n, k;
        std::cin >> n >> k;

        for(; i <= n; ++i)
        {
            len[i] = len[i - 2] + len[i - 1];
        }

        std::cout << kth(n, k, len) << "\n";

    }
    return 0;
}