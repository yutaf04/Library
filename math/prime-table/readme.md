# エラトステネスの篩(prime-table.hpp)
<br>

## 概要
- $n$ 以下の素数表を構築する

## 制約
- $n\leq10^6$

## 計算量
- $O(n\log \log n)$

## コード

```
vector<bool> makebitPrimes(int n){
    vector<bool> prime(1000001, true);
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(prime[i]){
            for(int j = 2; i * j <= n; j++){
                prime[i * j] = false;
            }
        }
    }

    return prime;
}

```
