# SPF（高速素因数分解）
<br>

## 概要
- Smallest Prime Factorの略.
- 事前に $n$ 以下の「最小の素因数」を計算しておくことで素因数分解を $O(\log n)$ で行う
- 複数クエリの素因数分解等で有効

## 制約
- $n\leq10^6$

## 計算量
- 前計算 $O(n\log \log n)$
- クエリ $O(\log n)$

## コード

```
//n以下の最小の素因数を事前に計算
vector<int> SPF(int n){

    vector<int> res(n+1, 0);
    for(int i = 0; i <= n; i++) res[i] = i;

    for(int i = 2; i * i <= n; i++){
        if(res[i] == i){
            for(int j = i; i * j <= n; j++){
                res[i * j] = i;
            }
        }
    }

    return res;
}

//整数xをspf配列を利用して素因数分解(O(log n))
vector<int> FPF(int x, vector<int> &spf){
    vector<int> res;
    while(x != 1){
        res.push_back(spf[x]);
        x /= spf[x];
    }

    sort(res.begin(), res.end());
    return res;
}

int main(){
    int q;
    cin >> q;

    //事前にSPFを実行(O(nlogn))
    auto spf = SPF(1000000); 

    while(q--){
        int x;
        cin >> x;

        auto res = FPF(x, spf);
        for(int i = 0; i < (int)res.size(); i++){
            cout << res[i] << endl;
        }
    }
}
```
