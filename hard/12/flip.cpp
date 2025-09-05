#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cmath>

bool gf2_collapse_sum16(uint16_t n){
    n ^= n >> 8;
    n ^= n >> 4;
    n ^= n >> 2;
    n ^= n >> 1;
    return n & 1;
}

uint16_t gf2_matmul16(const uint16_t* mat, uint16_t vec){
    uint16_t ans = 0;
    #pragma unroll
    for(int i = 0; i < 16; ++i){
        uint16_t temp = gf2_collapse_sum16(mat[i] & vec);
        ans |= temp << (15 - i);
    }
    return ans;
}

/*
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
*/

//                        1234567890123456
const uint16_t A[16] = {0b1100100000000000,
                        0b1110010000000000,
                        0b0111001000000000,
                        0b0011000100000000,
                        0b1000110010000000,
                        0b0100111001000000,
                        0b0010011100100000,
                        0b0001001100010000,
                        0b0000100011001000,
                        0b0000010011100100,
                        0b0000001001110010,
                        0b0000000100110001,
                        0b0000000010001100,
                        0b0000000001001110,
                        0b0000000000100111,
                        0b0000000000010011};

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int c;
    std::cin >> c;

    for(int p = 0; p < c; ++p)
    {
        std::string str;
        uint16_t b = 0;
        #pragma unroll
        for(int i = 0; i < 4; ++i){
            std::cin >> str;
            b |= (str[0] == 'H') ? 0 : 1;
            b <<= 1;
            b |= (str[1] == 'H') ? 0 : 1;
            b <<= 1;
            b |= (str[2] == 'H') ? 0 : 1;
            b <<= 1;
            b |= (str[3] == 'H') ? 0 : 1;
            if(i < 3) b <<= 1;
        }

        if(b == 0 || b == 0xFFFF){
            std::cout << "0\n";
            continue;
        }

        int minCount = INT32_MAX;

        #pragma unroll
        for(int x = 0xFFFF; x > 0; --x){
            uint16_t ans = gf2_matmul16(A, (uint16_t)x) ^ b;
            int count = 0;
            if(ans == 0 || ans == 0xFFFF){
                #pragma unroll
                for(int i = 0; i < 16; ++i)
                count += (x >> i) & 1;
                minCount = std::min(minCount, count);
            }
        }

        if(minCount == INT32_MAX)
        std::cout << "Impossible\n";
        else
        std::cout << minCount << "\n";
    }
    
    return 0;
}