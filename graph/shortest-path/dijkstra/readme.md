
# Dijkstra（ダイクストラ法）
<br>

## 概要
- 重みが0以上のグラフの， 一点から全ての点への最短距離（単一始点全点間最短経路）を求めるアルゴリズム.
- 各ステップで最も近い頂点の距離が確定していく．
- 距離順にソートされたヒープ（優先度付きキュー）を用いることで効率よく距離を確定させることができる．

## 制約
- $n\leq10^5$ 程度

## 計算量
- $O(E\log V)$

## コード

※ $dijkstra(n, g, s)$ ... $n$ 頂点からなる重み付きグラフ $g$ の始点 $s$ からの最短経路を求め，各頂点の $s$ からの距離を返す.

```
vector<ll> dijkstra(int n, vector<vector<pair<ll,ll> > > &g, ll s){
    vector<ll> dist(n, INF64);
    vector<bool> finished(n, false);
    dist[s] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
    pq.emplace(0, s);
    while(!pq.empty()){
        auto[curCost, v] = pq.top(); pq.pop();
        //if(dist[v] < curCost) continue;
        if(!finished[v]){
            finished[v] = true;
            for(auto &[nxt, cost]: g[v]){
                dist[nxt] = min(dist[nxt], dist[v] + cost);
                pq.emplace(dist[nxt], nxt);
            }
        }
    } 

    return dist;
}
```
