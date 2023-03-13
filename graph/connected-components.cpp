//グラフの連結成分の個数を求める
#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;
    vector<int> siz;

    UnionFind(int n){
        init(n);
    }

    void init(int n){
        par.resize(n);
        siz.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            siz[i] = 1;
        }
    }

    int getRoot(int x){
        if(par[x] == x) return x;
        return par[x] = getRoot(par[x]);
    }

    bool isSame(int x, int y){
        if(getRoot(x) == getRoot(y)) return true;
        return false; 
    }

    bool unite(int x, int y){
        x = getRoot(x);
        y = getRoot(y);
        if(x == y) return false;
        if(siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int getSize(int x){
        return siz[getRoot(x)];
    }

};

//Union-Findで
void solve1(){
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a, b);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i == uf.getRoot(i)){
            ans++;
        }
    }

    cout << ans << endl;
}

//BFSで
void solve2(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> seen(n, false);

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!seen[i]){
            ans++;
            queue<int> q;
            q.push(i);
            seen[i] = true;
            while(!q.empty()){
                int t = q.front();
                q.pop();
                for(int j: g[t]){
                    if(!seen[j]){
                        seen[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }

    cout << ans << endl;
}


vector<bool> seen;
void dfs(vector<vector<int> > &g, int v){
    seen[v] = true;
    for(int i : g[v]){
        if(!seen[i]){
            dfs(g, i);
        }
    }
}

//DFSで
void solve3(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    seen.assign(n, false);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!seen[i]){
            dfs(g, i);
            ans++;
        }
    }

    cout << ans << endl;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve1();//Union-Find
    //solve2();//BFS
    //solve3();//DFS
}
