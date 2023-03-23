//dfsでサイクル検出
#include <bits/stdc++.h>
using namespace std;
/*
有向グラフ(1-index)が与えられたとき，辺素なサイクルがあるか判定し，
あるならばそれを空白区切りで1つ出力する

ex)

Input
3 3
1 2
2 3
3 1

Output
Yes
1 2 3 1


seen
-1...未探索
1...訪問済み(行きがけで)
2...訪問済み(帰りがけで)

※サイクルがあると言えるのはある頂点vが帰りがけになる前に(vから出るパス
を全て探索する前に)再びvを訪問してしまう場合である.

*/
int pos = -1;
vector<vector<int> > g;
vector<int> seen;

vector<int> res;
void cycle_dfs(int v){
    seen[v] = 1;
    res.push_back(v);
    for(auto nxt: g[v]){
        if(seen[nxt] == 1){
            pos = nxt;
            return;
        }else if(seen[nxt] == -1){
            cycle_dfs(nxt);
        }

        if(pos != -1) return; //閉路を検出したならば次以降の頂点を探索しない
    }

    seen[v] = 2;//帰りがけ順で探索済みにする
    res.pop_back();
}



int main(){
    int n, m;
    cin >> n >> m;

    //vector<vector<int> > g(n);
    g.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        //g[v].push_back(u);
    }

    //vector<int> seen(n, -1);
    seen.assign(n, -1);
    //cycle_dfs(0);

    for(int i = 0; i < n; i++){
        if(seen[i] == -1){
            cycle_dfs(0);
        }
    }

    if(pos != -1){
        cout << "Yes" << endl;

        // for(int i = 0; i < (int)res.size(); i++) cout << res[i] << " ";
        // cout << endl;

        //stackから逆順に始点(pos)が見つかるまで取り出す
        //取り出したものを別のstackに入れて取り出す(vectorのpush_back及びpop_back())
        vector<int> ans;
        ans.push_back(pos);
        while(res.back() != pos){
            ans.push_back(res.back());
            res.pop_back();
        }
        ans.push_back(pos);
        //reverse(begin(ans), end(ans));

        while(!ans.empty()){
            cout << ans.back() + 1 << " ";
            ans.pop_back();
        }
        cout << endl;
    }else{
        cout << "No" << endl;
    }
}
