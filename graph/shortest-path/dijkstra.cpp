#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF64 = numeric_limits<ll>::max();

void solve(){
    int n, m;
    cin >> n >> m;

    int s, t;
    cin >> s >> t;
  
    vector<vector<pair<int,long long> > > g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    vector<long long> dist(n, INF64);
    dist[s] = 0;

    vector<bool> finished(n, false);
    priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
    pq.push({0, s});

    vector<int> pre(n, -1);
    vector<int> post(n, -1);
    while(!pq.empty()){
        int v = pq.top().second; pq.pop();

        if(!finished[v]){
            finished[v] = true;
            for(auto &[nxt, cost]: g[v]){
                if(dist[nxt] > dist[v] + cost){
                    dist[nxt] = dist[v] + cost;
                    pre[nxt] = v;
                    post[v] = nxt;
                }
                pq.push({dist[nxt], nxt});
            }
        }
    }

    if(dist[t] == INF64){
        cout << -1 << endl;
    }else{
        cout << dist[t] << " ";
        
        vector<int> ans = {t};
        int i = t;
        while(pre[i] != -1){
            i = pre[i];
            ans.push_back(i);
        }

        cout << ans.size() - 1 << endl;
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < (int)ans.size() - 1; i++){
            cout << ans[i] << " " << ans[i+1] << endl;
        }
    }

}

int main(){
    solve();
}
