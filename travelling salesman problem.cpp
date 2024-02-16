#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

int TSP(int i,int mask,vector<vector<int>>&dis,vector<vector<int>>&dp)
{
    if(mask==( 1<<i | 3))
        return dis[1][i];
    if(dp[i][mask]!=0)
        return dp[i][mask];
    int ans=1e9;
    for(int j=1; j<dis.size(); j++)
    {
        if((mask & 1<<j) && i!=j && j!=1)
            ans=min(ans,TSP(j,mask & ~(1<<i),dis,dp)+dis[j][i]);
    }
    return dp[i][mask]=ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<vector<int>>dis(n+1,vector<int>(n+1,0));

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cin>>dis[i][j];
            }
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
        vector<vector<int>>dp(n+1,vector<int>(1<<(n+1),0));
        int ans=1e9;
        for(int i=1; i<=n; i++)
        {
            ans=min(ans,TSP(i,(1<<(n+1))-1,dis,dp)+dis[i][1]);
        }
        cout<<ans<<endl;
    }
}
