#include <iostream>
#include <cstdio>

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int a,b,c;

    std::cin >> a >> b >> c;

    std::cout << (((a + b > c) && (b + c > a) && (c + a > b)) ? "YES" : "NO");

    return 0;
}