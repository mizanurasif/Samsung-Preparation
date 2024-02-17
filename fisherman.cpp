//all possible solution recursion + backtrack

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
struct gate
{
    int loc;
    int man;
}gate[4];
int visited[100];
int ans=INT_MAX;
int n;
int giveleft(int x)
{
    for(int i=gate[x].loc; i>0; i--)
    {
        if(visited[i]==0)
            return i;
    }
    return INT_MAX;
}
int giveright(int x)
{
    for(int i=gate[x].loc; i<=n; i++)
    {
        if(visited[i]==0)
            return i;
    }
    return INT_MAX;
}
void solve(int x,int y,int z,int dis,int cur)
{
    if(dis>ans)
        return ;
    if(gate[cur].man==0)
    {
        if(cur==x)
            cur=y;
        else if(cur==y)
            cur=z;
        else
        {
            ans=min(dis,ans);
            return;
        }
    }
    int l=giveleft(cur);
    int r=giveright(cur);

    int locl=abs(l-gate[cur].loc)+1;
    int locr=abs(r-gate[cur].loc)+1;
    if(locl==locr)
    {
        visited[l]=1;
        gate[cur].man--;
        solve(x,y,z,dis+locl,cur);
        visited[l]=0;
        gate[cur].man++;


        visited[r]=1;
        gate[cur].man--;
        solve(x,y,z,dis+locr,cur);
        visited[r]=0;
        gate[cur].man++;


    }
    else if(locl<locr)
    {
        visited[l]=1;
        gate[cur].man--;
        solve(x,y,z,dis+locl,cur);
        visited[l]=0;
        gate[cur].man++;
    }
    else
    {
        visited[r]=1;
        gate[cur].man--;
        solve(x,y,z,dis+locr,cur);
        visited[r]=0;
        gate[cur].man++;
    }


}

int main()
{
    cin>>n;
    cin>>gate[1].loc>>gate[2].loc>>gate[3].loc;
    cin>>gate[1].man>>gate[2].man>>gate[3].man;

    memset(visited,0,sizeof(visited));

    solve(1,2,3,0,1);
    solve(1,3,2,0,1);
    solve(2,1,3,0,2);
    solve(2,3,1,0,2);
    solve(3,1,2,0,3);
    solve(3,2,1,0,3);

    cout<<ans<<endl;


}
