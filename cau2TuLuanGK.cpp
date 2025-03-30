#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int M, int N){
    return x >= 0 && x < M && y >= 0 && y < N;
}

int main(){
    int M, N, K, Q;
    cin >> M >> N >> K >> Q;
    vector<vector<int>> a(M, vector<int>(N, 0));
    for(int i = 0; i < K; i++){
        int xk, yk, vk;
        cin >> xk >> yk >> vk;
        a[xk][yk] = vk;
    }

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    vector<int> result;
    for(int i = 0; i < Q; i++){
        int xq, yq;
        cin >> xq >> yq;
        int sum = 0;
        for(int d = 0; d < 8; d++){
            int newX = xq + dx[d];
            int newY = yq + dy[d];
            if(isValid(newX, newY, M, N)) sum += a[newX][newY];
        }
        result.push_back(sum);
    }
    for(int x : result){
        cout << x << endl;
    }
    return 0;
}

