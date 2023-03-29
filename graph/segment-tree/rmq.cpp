//segment-tree(RMQ)
#include <bits/stdc++.h>
using namespace std;
const long long INF = numeric_limits<int>::max();

class SegmentTree{
private:
    int n;
    vector<int> node;
public:
    SegmentTree(vector<int> v){
        int sz = v.size();
        n = 1;
        while(n < sz) n *= 2;
        node.resize(2 * n - 1, INF);
        
        //最下段に値を入れる
        for(int i = 0; i < sz; i++){
            node[i + n - 1] = v[i];
        }

        //下段から順に更新していく
        for(int i = n - 2; i >= 0; i--){
            node[i] = min(node[2 * i + 1], node[2 * i + 2]);
        }
    };

    //x番目の要素をvalに変更する
    void update(int x, int val){
        x += (n - 1);

        node[x] = val;
        while(x > 0){
            x = (x - 1) / 2;
            node[x] = min(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    //半開区間[a, b)の最小値を求める
    //[l, r)は対象区間, k...現在注目しているノード
    int rmq(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];

        int vl = rmq(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = rmq(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};


int main(){
    int n, q;
    cin >> n >> q;

    vector<int> A(n, INF);
    SegmentTree seg(A);

    while(q--){
        int c, x, y;
        cin >> c >> x >> y;

        if(c == 0){
            seg.update(x, y);
        }else{
            cout << seg.rmq(x, y+1) << endl;
        }
    }
}
