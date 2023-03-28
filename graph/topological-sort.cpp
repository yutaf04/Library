//トポロジカルソート
//
//問題 aojGRL_4_B(https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B)

/*
DAG(サイクルのない有向グラフ)の各ノードを順序づけして
どのノードもその出力辺の先のノードよりも前にくるように並び替えること

入次数0の頂点をqueueに入れて順に取り出していく.
取り出した頂点を削除することによって入次数が変わる頂点を計算し，
入次数が0になったら新たにキューに追加する

各ステップで入次数が0の頂点を全頂点から探すのではなく
変化した頂点のみを候補に絞って探すことで計算量を削減できる

problem_ex)
①トポロジカルソートの一意性(ABC291-E)
->各ステップでキューの要素数が常に1個

②辞書式順序のトポロジカルソート(ABC223-D)
->priority_queueを用いる

③トポロジカル順序の数え上げ(ABC041-D)
bitdp(未履修)*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n);

    vector<int> indegree(n, 0);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        //u--; v--;
        g[u].push_back(v);

        //入次数をカウント
        indegree[v]++;
    }

    queue<int> q;
    //priority_queue<int, vector<int>, greater<int> > q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> Ans;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int v: g[t]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }

        Ans.push_back(t);
    }

    if(Ans.size() == n){
        for(int i = 0; i < (int)Ans.size(); i++) cout << Ans[i] << endl;
    }else{
        cout << -1 << endl;
    }
}
