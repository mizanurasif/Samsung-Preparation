#include<bits/stdc++.h>
using namespace std;

int TSP(int i,int mask,vector<pair<int,int>>&dis,vector<vector<int>>&dp)
{
    if(mask==( 1<<i | 3))
        return abs(dis[i].first-dis[1].first)+abs(dis[i].second-dis[1].second);
    if(dp[i][mask]!=0)
        return dp[i][mask];
    int ans=1e9;
    for(int j=1; j<dis.size(); j++)
    {
        if((mask & 1<<j) && i!=j && j!=1)
        {
            int d=abs(dis[i].first-dis[j].first)+abs(dis[i].second-dis[j].second);
            ans=min(ans,TSP(j,mask & ~(1<<i),dis,dp)+d);
        }
    }
    return dp[i][mask]=ans;
}
int main()
{
    int t;
    for(int t=1; t<=10; t++)
    {
        int n;
        cin>>n;

        vector<pair<int,int>>dis(n+3);

        cin>>dis[1].first>>dis[1].second;
        cin>>dis[n+2].first>>dis[n+2].second;

        for(int i=2; i<=n+1; i++)
        {
            cin>>dis[i].first>>dis[i].second;
        }
        /*
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }*/
        n=n+1;
        vector<vector<int>>dp(n+1,vector<int>(1<<(n+1),0));
        int ans=1e9;
        for(int i=1; i<=n; i++)
        {
            int d=abs(dis[i].first-dis[n+1].first)+abs(dis[i].second-dis[n+1].second);
            ans=min(ans,TSP(i,(1<<(n+1))-1,dis,dp)+d);
        }
        cout<<"# "<<t<<" "<<ans<<endl;
    }
}
