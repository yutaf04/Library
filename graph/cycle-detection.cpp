//有向グラフのサイクル検出

/*
dfsで有向グラフのサイクル検出を行う
有向グラフが与えられたときサイクルがあるかを判定し，あるならばパスも出力する

気持ち)
適当な頂点からdfsを行い，「一度訪問した頂点を再び訪問した場合」サイクルあり?は間違いで
正しくは「一度訪問した頂点が帰りがけになる前に再び訪問した場合」サイクルありである．

帰りがけになる前は一度ある頂点Vを訪れていれば，Vから出るパスを探索しているはずなのでそこで
再びVを訪れた場合はV...Vまでのサイクルが保証される．
一方でVが帰りがけになった後はVから出るパスを全て探索し終わっているはずなので再びVに訪れても
そこでサイクルはできない．

実装に関してはある頂点が未訪問かどうかの2種類に加えて「帰りがけで探索済みかどうか」のもう1種類を
状態として持っておく必要があるため, 1つの配列で3状態を管理するか新たに別の配列を用意する必要がある．*/

#include <bits/stdc++.h>
using namespace std;

int pos = -1;
vector<vector<int> > g;
vector<int> seen;
// seen 
// -1 未訪問
// 1 訪問済み(行きがけで)
// 2 訪問済み(帰りがけで)

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
