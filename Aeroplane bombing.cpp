//recursion

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;

int ans;

void solve(vector<vector<int>>&grid,int curans,int curr,int curc,bool bomb,int effect)
{
    //cout<<curr<<endl;

    if(curr==-1)
    {
        ans=max(ans,curans);
        return;
    }
    for(int i=-1; i<=1; i++)
    {
        if(curc+i<0 || curc+i>4)
            continue;

        if(grid[curr][curc+i]==0 || grid[curr][curc+i]==1)
        {
            if(bomb==false)
            {
                solve(grid,curans+grid[curr][curc+i],curr-1,curc+i,bomb,effect);
            }
            else
            {
                solve(grid,curans+grid[curr][curc+i],curr-1,curc+i,bomb,effect-1);
            }

        }
        else
        {
            if(bomb==false)
            {
                solve(grid,curans,curr-1,curc+i,true,4);
            }
            else
            {
                if(effect>0)
                    solve(grid,curans,curr-1,curc+i,bomb,effect-1);
                else
                {
                    ans=max(curans,ans);
                    return;
                }
            }
        }
    }

}
int main()
{
    int t,n;
    cin>>t;
    for(int tt=1; tt<=t; tt++)
    {
        cin>>n;
        vector< vector<int> >grid(n,vector<int>(5) );
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<5; j++)
            {
                cin>>grid[i][j];
            }
        }

        ans=0;
        solve(grid,0,n-1,2,false,0);
        cout<<"#"<<tt<<" "<<ans<<endl;

    }

}
