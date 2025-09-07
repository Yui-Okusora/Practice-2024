#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using ll = long long;
const ll INF = (1LL<<60);

struct Interval {
    int a, b;
    ll c;
};

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, T;
    std::cin >> n >> T;

    std::vector<Interval> iv(n);
    std::vector<int> coords;
    coords.push_back(0);
    coords.push_back(T);

    for(int i = 0; i < n; i++){
        std::cin >> iv[i].a >> iv[i].b >> iv[i].c;
        coords.push_back(iv[i].a);
        coords.push_back(iv[i].b);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    int m = coords.size();

    auto idx_of = [&](int x){
        return (int)(lower_bound(coords.begin(), coords.end(), x) - coords.begin());
    };

    int s = idx_of(0);
    int t = idx_of(T);

    std::vector<std::vector<std::pair<int,ll>>> adj(m);

    for (int k = 0; k < n; k++) {
        int &a = iv[k].a, &b = iv[k].b;

        int l = idx_of(a);
        int r = idx_of(b);

        for (int i = l; i < r; i++) {
            adj[i].push_back({r, iv[k].c});
        }
    }
    
    std::vector<ll> dist(m, INF);
    std::priority_queue<std::pair<ll,int>, std::vector<std::pair<ll,int>>, std::greater<std::pair<ll,int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();

        if(d != dist[u]) continue;
        if(u == t) break;

        for(auto &e : adj[u]){
            int v = e.first;
            ll w = e.second;
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    if(dist[t] >= INF) {
        std::cout << "Impossible\n";
    } else {
        std::cout << dist[t] << "\n";
    }

    return 0;
}