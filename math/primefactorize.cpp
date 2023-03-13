#include <bits/stdc++.h>
using namespace std;

//nを素因数分解したときの素因数の種類を返す
//ex) 60 -> {2, 3, 5}
vector<int> prime_factorize(int n){
    vector<int> res;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            while(n % i == 0){
                n /= i;
            }
        }
    }

    if(n != 1) res.push_back(n);

    return res;
}


int main(){
    int n;
    cin >> n;

    auto a = prime_factorize(n);

    if(a.size() == 0){
        cout << 1 << endl;
        return 0;
    }

    for(int i = 0; i < (int)a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
