#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> a(N);
    for(int &x : a){
        cin >> x;
    }
    int K; cin >> K;
    set<int> saw;
    vector<pair<int,int>> result;

    for(int i = 0; i < N; i++){
        if(saw.count(K-a[i])){
            int smaller = min(a[i], K-a[i]);
            int bigger = max(a[i], K-a[i]);
            result.push_back({smaller, bigger});
        }
        saw.insert(a[i]);
    }
    reverse(result.begin(), result.end());
    for(auto p : result){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
