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
