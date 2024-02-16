// dijkstra

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,c=0;
    cin>>t;
    while(t--)
    {
        c++;
        int n,m,x,y,w;
        cin>>n;
        int cost[n+1];
        for(int i=1; i<=n; i++)
        {
            cin>>cost[i];
        }
        vector<pair<int,int>>adj;
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
            adj.push_back({x,y});
        }
        vector<int>dis(n+1,INT_MAX);
        dis[1]=0;
        for(int i=0; i<n-1; i++)
        {
            int flag=0;
            for(int j=0; j<adj.size(); j++)
            {
                int u=adj[j].first;
                int v=adj[j].second;
                int w=(cost[v]-cost[u])*(cost[v]-cost[u])*(cost[v]-cost[u]);
                if(dis[u]+w < dis[v])
                {
                    dis[v]=dis[u]+w;
                    flag=1;
                }
            }
            if(!flag)
                break;
        }

        cout<<"Case "<<c<<":"<<endl;
        int q;
        cin>>q;
        while(q--)
        {
            cin>>x;
            if(dis[x]< 3 || dis[x]==INT_MAX)
                cout<<"?"<<endl;
            else
                cout<<dis[x]<<endl;
        }
    }
}
