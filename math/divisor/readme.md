
# 約数列挙(divisor.hpp)
<br>

## 概要
- 整数 $n$ の約数を昇順に列挙する

## 制約
- $n\geq1$

## 計算量
- $O(\sqrt{n})$

## コード

```
vector<long long> divisor(long long n){
    vector<long long> res;
    for(long long i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i * i != n) res.push_back(n / i);
        }
    }

    sort(begin(res), end(res));
    return res;
}
```
