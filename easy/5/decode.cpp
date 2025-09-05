#include <iostream>
#include <cstdio>
#include <cmath>

int encode (int n);

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    std::cin >> n;

    int length = ceil(log10(n + 1));

    int start = n - 9 * length;
    start = std::max(start, 1);

    for (int i = start; i < n; ++i)
    {
        if(n == encode(i)){
            std::cout << i;
            return 0;
        }
    }
    return 0;
}

int encode(int n)
{
    int temp = n;
    int target = 0;
    while(temp != 0){
        target += temp % 10;
        temp /= 10;
    }
    return n + target;
}