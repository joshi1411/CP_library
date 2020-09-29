#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 1e5;
vector<int> g[N];
int n;

pair<int,int> bfs1(int v){
    queue<pair<int,int>> q;
    vector<int> vis(N+5,0);
    int farNode = v;
    int mxDis = 0;
    q.push({v ,0 });
    vis[v] = 1;
    while(!q.empty()){
        int u = q.front().first;
        int dis = q.front().second;
        if(dis > mxDis){
            mxDis = dis;
            farNode = u;
        }
        q.pop();
        for(int i : g[u]){
            if(vis[i])
                continue;
            vis[i] = 1;
            q.push({i,dis+1});
        }
    }
    // cout<<farNode<<" "<<mxDis<<"\n";
    return {farNode, mxDis};
}

int diameter(){
    auto x = bfs1(0);
    return bfs1(x.first).second;
}

int main(){

    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    cout<<diameter();
}