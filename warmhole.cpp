#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,x1,x2,y1,y2,w;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=1;
        map<pair<int,int>,int>mp;
        vector<pair<int,int>>ver;
        cin>>x1>>y1>>x2>>y2;

        mp[ {x1,y1}]=cnt;
        cnt++;
        ver.push_back({x1,y1});
        mp[ {x2,y2}]=cnt;
        cnt++;
        ver.push_back({x2,y2});
        int cost[15][15];
        for(int i=0; i<15; i++)
        {
            for(int j=0; j<15; j++)
            {
                cost[i][j]=1e9;
            }
        }
        for(int i=1; i<=n; i++)
        {
            cin>>x1>>y1>>x2>>y2>>w;
            if( mp[ {x1,y1}]==0)
            {
                mp[ {x1,y1}]=cnt;
                cnt++;
                ver.push_back({x1,y1});
                
            }
            if( mp[ {x2,y2}]==0)
            {
                mp[ {x2,y2}]=cnt;
                cnt++;
                ver.push_back({x2,y2});
            }

            cost[mp[ {x1,y1}]][mp[ {x2,y2}]]=w;
             cost[mp[ {x2,y2}]][mp[ {x1,y1}]]=w;

        }
        n=cnt;

//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<n; j++)
//            {
//                cout<<cost[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        vector<int>dis(n,INT_MAX);
        dis[1]=0;
        priority_queue<pair<int,int>>q;
        q.push({0,1});
        while(!q.empty())
        {
            int u=q.top().second;
            q.pop();
            for(int v=1; v<n; v++)
            {
                 int w=min(cost[u][v],abs(ver[u-1].first-ver[v-1].first)+abs(ver[u-1].second-ver[v-1].second));
               // cout<<w<<endl;
                if(u!=v && dis[v]>dis[u]+w)
                {
                    dis[v]=dis[u]+w;
                    q.push({-dis[v],v});
                }
            }
        }
//        for(int i=0; i<n; i++)
//            cout<<dis[i]<<" ";
 //       cout<<endl;
        cout<<dis[2]<<endl;

    }
}
