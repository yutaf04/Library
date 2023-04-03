//座標圧縮(座圧)
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
using namespace std;

bool asc2(tuple<int,int,int> &left, tuple<int,int,int> &right){
    return get<1>(left) < get<1>(right);
}

bool asc(pair<int,int> &left, pair<int,int> &right){
    return left.second < right.second;
}

int main(){
    vector<int> a = {4, 10, 5, 7, 2};
    /* expected output: 1 4 2 3 0 */

    // 1...mapに突っ込む
    map<int,int> mp;
    for(int i = 0; i < a.size(); i++) mp[a[i]] = 0;

    int itr = 0;
    for(auto &i : mp) i.second = itr++;
    for(int i = 0; i < a.size(); i++){
        if(i > 0) cout << " ";
        cout << mp[a[i]] + 1;
    }
    cout << "\n";


    // 2...indexを保持して値をソート→カウントしたのち保持したindexの順に出力
    // タプルをソート
    // vector<tuple<int,int,int> > aa;
    // for(int i = 0; i < a.size(); i++) aa.push_back({a[i], i, 0});
    
    // //a[i]の昇順にソート
    // sort(aa.begin(), aa.end());

    // int itr = 0;
    // for(int i = 0; i < aa.size(); i++) get<2>(aa[i]) = itr++;

    // //iの昇順にソート
    // sort(aa.begin(), aa.end(), asc2);
    // for(int i = 0; i < aa.size(); i++) cout << get<2>(aa[i]) << " ";
    // cout << endl; 

    // 3...コピーしてそれをソートして重複要素を削除→二分探索で何番目かを先頭から見る
    // 

    /*
    vector<pair<int,int> > aa;
    for(int i = 0; i < a.size(); i++) aa.push_back({a[i], i});

    //a[i]の昇順に並び替え
    sort(aa.begin(), aa.end()); 

    int itr = 0;
    for(int i = 0; i < aa.size(); i++) aa[i].first = itr++;

    //入力順に戻す    
    sort(aa.begin(), aa.end(), asc);
    for(int i = 0; i < aa.size(); i++) cout << aa[i].first << " ";
    cout << endl;*/


    // vector<int> acopy = a;
    // sort(acopy.begin(), acopy.end());

    // for(int i = 0; i < (int)acopy.size(); i++) cout << acopy[i] << " ";
    // cout << endl;

    // for(int i = 0; i < (int)a.size(); i++){
    //     int l = 0;
    //     int r = (int)acopy.size();
    //     while(r - l > 1){
    //         int mid = (l + r) / 2;
    //         if(acopy[mid] > a[i]) r = mid;
    //         else l = mid; 
    //     }
    //     cout << l << " ";
    // }

    // cout << endl;
}
