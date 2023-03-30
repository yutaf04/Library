// 高速素因数分解(SPF) 
#include<bits/stdc++.h>
using namespace std;

/*
事前にある整数の最小の素因数を求めておくことで素因数分解をO(logN)で行う
複数クエリの素因数分解等で有効

①試し割り
1 前処理...なし
2 各クエリ...(O√N)

②SPF
1 前処理...O(loglogN)
2 各クエリ...(OlogN)

*/

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

    //事前にSPFを実行
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
