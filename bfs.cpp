#include<bits/stdc++.h>
using namespace std;

#define MX 110

vector <int> graph[MX];
bool vis[MX];
int dis[MX];

void bfs(int source)
{
    queue <int> q;

    vis[source] = 1;
    dis[source] = 0;
    q.push(source);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0;i<graph[node].size();i++){
        int next = graph[node][i];
        if(vis[next] == 0){
            vis[next] = 1;
            dis[next] = dis[node] + 1;
            q.push(next);
        }
    }
    }
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=1;i<=edges;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int source;
    cin>>source;
    bfs(source);
    cout<<"From node "<<source<<endl;
    for(int i=1;i<=nodes;i++){
        cout<<"Distance of "<<i<<" is : "<<dis[i]<<endl;
    }
    return 0;
}
