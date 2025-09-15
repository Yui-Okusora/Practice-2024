#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;

    std::cin >> n >> k;

    if(k == 0){
        std::cout << n;
        return 0;
    }
    
    std::vector<pair<long long, int>> presum(n+1);
    presum[0] = {0, 0};
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        presum[i + 1] = {presum[i].first + (a - k), i + 1};
    }

    sort(presum.begin(), presum.end());

    int ans = 0;
    int min_idx = INT_MAX;

    for (auto [val, idx] : presum) {
        if (min_idx != INT_MAX) {
            ans = max(ans, idx - min_idx);
        }
        min_idx = min(min_idx, idx);
    }

    cout << ans;

    return 0;
}