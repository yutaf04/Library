//エラトステネスのふるい
#include <bits/stdc++.h>
using namespace std;
vector<bool> prime(1000001, true);//1e6

//エラトステネスの篩い O(nloglogn)... 10^6~10^7程度までなら2s以内で計算可能
void Eratosthenes(int n){
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(prime[i]){
            for(int j = i * 2; j <= n; j += i){
                prime[j] = false;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    Eratosthenes(100);

    for(int i = 1; i <= 100; i++){
        if(prime[i]) cout << i << " ";
    }
    cout << endl;
}
