#include <iostream>
#include <cstdio>
#include <string>

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    std::string str;
    std::cin >> str;

    int* pos = new int[str.length() / 2]();
    int j = 0;
    for(int i = 0; i < str.length(); ++i){
        char& c = str[i];
        if(c == '('){
            pos[j] = i;
            ++j;
        }
        if(c == ')'){
            --j;
            std::cout << pos[j] << " ";
        }
    }
    delete[] pos;
    return 0;
}