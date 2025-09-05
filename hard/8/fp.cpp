#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

class bitarray
{
    public:
    bitarray(size_t size){
        bits = new unsigned int[(size + 31) / 32]();
        memset(bits, 0xFF, (size + 31) / 32 * sizeof(unsigned int));
    }
    void set(size_t index, bool val){
        size_t offset = index / 32;
        size_t pos = 31 - (index % 32);
        if (val)
            bits[offset] |= (1u << pos);
        else
            bits[offset] &= ~(1u << pos);
    }
    bool get(size_t index){
        size_t offset = index / 32;
        size_t pos = 31 - (index % 32);
        return (bits[offset] >> pos) & 1u;
    }
    ~bitarray(){ delete[] bits; }
    unsigned int* bits = nullptr;
};

void sang(bitarray &prime, int l, int r){
    for(int i = 2; i <= sqrt(r); i++){
		for(int j = std::max(i * i, (l + i - 1) / i * i); j <= r; j += i){
			prime.set(j - l, 0);
		}
	}
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    std::cin >> n;

    int input[n]= {};
    int minN = INT_MAX, maxN = 0;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> input[i];
        minN = std::min(minN, input[i]);
        maxN = std::max(maxN, input[i]);
    }

    bitarray prime(maxN + 200 - minN + 1);

    sang(prime, minN, maxN + 200);

    for(int i = 0; i < n; ++i)
    {
        for(int j = input[i]; j <= maxN + 200; ++j){
            if(prime.get(j - minN))
            {
                std::cout << j << "\n";
                break;
            }
        }
    }

    return 0;
}