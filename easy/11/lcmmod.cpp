#include <iostream>
#include <cstdio>
#include <vector>

int gcd(int a, int b){
   while(b != 0){
      int r = a % b;
      a = b;
      b = r;
   }
   return a;
}

int lcm(int a, int b) {return (a / gcd(a, b)) * b;}

int lcm_of_list(const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int res = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        res = lcm(res, nums[i]);
    }
    return res;
}

int main(){
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);


   std::vector<int> input;

   int n;
   while(std::cin >> n){
      input.push_back(n);
   }

   int m = input.back();
   input.pop_back();

   std::cout << lcm_of_list(input) % m;


   return 0;
}