#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
vector<int> graph[MAX + 5];
bool vis[MAX + 5];
stack<int> s;

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : graph[u])
    {
        if(!vis[v])
        {
            dfs(v);
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

    ///component count
    for(int i = 1; i <= u; i++)
    {
       if(!vis[i])
       {
           dfs(i);
           cout<<"Component Found\n";
       }
    }

    return 0;
}
