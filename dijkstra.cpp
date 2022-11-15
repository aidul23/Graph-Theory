#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<pair<int , int>> graph[N];

void dijkstra(int source)
{
    vector<int> vis(N , 0);
    vector<int> dis(N , INT_MAX / 2);

    set<pair<int , int>> st;

    st.insert({0 , source});
    dis[source] = 0;
    while(st.size() > 0)
    {
        auto node = *st.begin();

        int v = node.second;
        int v_dis = node.first;

        st.erase(st.begin());

        if(vis[v]) continue;
        vis[v] = 1;

        for(auto child : graph[v])
        {
            int child_v = child.first;
            int wt = child.second;

            if(dis[v] + wt < dis[child_v])
            {
                dis[child_v] = dis[v] + wt;
                st.insert({dis[child_v] , child_v});
            }
        }
    }
}

int main()
{
    int n , m;
    scanf("%d %d",&n,&m);

    for(int i = 0 ; i < m ; i++)
    {
        int a , b , wt;
        scanf("%d %d %d",&a,&b,&wt);

        graph[a].push_back({b,wt});
    }
    return 0;
}
