#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <optional>
#include <array>
#include <bit>

std::optional<uint16_t> solveGF2(std::array<uint32_t, 16> &M) {
    int rank = 0;

    for (int col = 0; col < 16; ++col) {
        int pivot = -1;
        for (int row = rank; row < 16; ++row) {
            if (M[row] & (1u << col)) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;

        if (pivot != rank) std::swap(M[pivot], M[rank]);

        for (int row = 0; row < 16; ++row) {
            if (row != rank && (M[row] & (1u << col))) {
                M[row] ^= M[rank];
            }
        }
        ++rank;
    }

    for (int row = rank; row < 16; ++row) {
        if ((M[row] & 0xFFFFu) == 0 && (M[row] >> 16)) {
            return std::nullopt;
        }
    }

    uint16_t x = 0;
    for (int row = 0; row < 16; ++row) {
        uint16_t a = M[row] & 0xFFFFu;
        if (a == 0) continue;
        int col = std::__countr_zero(a);
        if (M[row] >> 16) {
            x |= (1u << col);
        }
    }
    return x;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int c;
    std::cin >> c;

    for(int p = 0; p < c; ++p)
    {
        std::string str;
        std::array<uint32_t, 16> M1 = {0b00000000000000001100100000000000,
                                       0b00000000000000001110010000000000,
                                       0b00000000000000000111001000000000,
                                       0b00000000000000000011000100000000,
                                       0b00000000000000001000110010000000,
                                       0b00000000000000000100111001000000,
                                       0b00000000000000000010011100100000,
                                       0b00000000000000000001001100010000,
                                       0b00000000000000000000100011001000,
                                       0b00000000000000000000010011100100,
                                       0b00000000000000000000001001110010,
                                       0b00000000000000000000000100110001,
                                       0b00000000000000000000000010001100,
                                       0b00000000000000000000000001001110,
                                       0b00000000000000000000000000100111,
                                       0b00000000000000000000000000010011};
        std::array<uint32_t, 16> M2(M1);

        for(int i = 0; i < 4; ++i){
            std::cin >> str;
            for(int j = 0; j < 4; ++j)
            {
                M1[i * 4 + j] |= ((str[j] == 'H') ? 0 : 1) << 16;
                M2[i * 4 + j] |= ((str[j] == 'H') ? 1 : 0) << 16;
            }
        }
        
        auto ans1 = solveGF2(M1);
        auto ans2 = solveGF2(M2);

        int best = 0x7FFFFFFF;

        if (ans1) {
            best = std::min(best, std::__popcount(ans1.value()));
        }
        if (ans2) {
            best = std::min(best, std::__popcount(ans2.value()));
        }

        if (best == 0x7FFFFFFF) {
            std::cout << "Impossible\n";
        } else {
            std::cout << best << "\n";
        }
    }
    return 0;
}