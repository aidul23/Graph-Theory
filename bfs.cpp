#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
vector<int> graph[MAX + 5];
vector<int> dis;

void bfs(vector<int> srcs, int n)
{
    dis.clear();
    dis.resize(n + 1, INT_MAX / 2);

    queue<int> q;
    for(auto src : srcs)
    {
        q.push(src);
        dis[src] = 0;
    }

    while(!q.empty())
    {
        auto u = q.front();
        q.pop();

        for(auto v : graph[u])
        {
            if(dis[v] == INT_MAX / 2)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int u,v;
    cin>>u>>v;
    for(int i = 0; i < v; i++)
    {
        int a,b;
        cin>>a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs({1},u);

    for(int i = 1 ; i <= u; i++)
    {
        cout<<"dis: "<<i<<" "<<dis[i]<<"\n";
    }
    return 0;
}
