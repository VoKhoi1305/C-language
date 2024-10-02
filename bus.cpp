#include<bits/stdc++.h>
using namespace std; 
const int N = 15;
int n, K;
int C[2*N+1][2*N+1], x[2*N+1];
int fcur = 0, fOpt = INFINITY, load = 0;
bool visited[2*N+1];
int cmin = 1e6;

bool check(int v, int k){
    if (visited[v]) return false;
    if (v > n) {
        if(!visited[v-n]) return false;
    } else {
        if (load == K) return false;
    }
    return true;
}

void updatebest(){
    if(fcur + C[2*n][0]<fOpt){
        fOpt = fcur +C[2*n][0];
    }
}
int Try(int k){
    for (int v = 1; v <= 2*n; i++){
        if(check(v,k)){
            x[k]=v;
            visited[v] = true; 
            fcur += C[x[k-1]][v];
            load += (v>n? -1:1);
            if (k == 2*n) updatebest();
            else {
                if (fcur + (2*n+1 - k) * cmin <fOpt)
            }
            visited[v] = false; 
            fcur -= C[x[k-1]][v];
            load -= (v>n? -1:1);
        }
    }
}

void input(){
    cin >> n >> K; 
    for (int i = 0; i < 2*n;i++) {
        for(int j = 0; j<2*n; j++){
            cin >> C[i][j];
            if(i != j) cmin = min(cmin, C[i][j]);
        }
    }
}

int main(){
    input();
    x[0]=0; visited[0] =true;
    Try(1);
    cout << fOpt;
    return 0;
}