#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    std::cin >> t;
    int maxIndex = 1;

    std::vector<std::string> fibos;
    fibos.reserve(46);
    fibos.push_back("a");
    fibos.push_back("b");
    
    for(int e = 0; e < t; ++e)
    {
        int n, k;
        std::cin >> n >> k;

        for(int i = maxIndex; i < n; ++i)
        {
            fibos.push_back(fibos[i - 1] + fibos[i]);
            maxIndex = i;
        }
        std::cout << fibos[n][k - 1] << "\n";

    }
    
    return 0;
}