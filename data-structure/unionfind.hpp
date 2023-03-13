#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    vector<int> par;
    vector<int> siz;

    UnionFind(int n) {
        init(n); 
    } 

    void init(int n){
        par.assign(n, 0);
        siz.assign(n, 1);
        for(int i = 0; i < n; i++) par[i] = i;
    }

    int getRoot(int x){
        if(par[x] == x) return x;
        return par[x] = getRoot(par[x]);//
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
