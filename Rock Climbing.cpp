// BFS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<climits>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int graph[n][m];
    int x,y;
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<m; j++)
        {
            cin>>graph[i][j];
            if(graph[i][j]==3)
            {
                x=i;
                y=j;
            }
        }
    }

    priority_queue<pair<int,pair<int,int>>>q;
    q.push({0,{0,0}});
    int vis[n][m];
    memset(vis,0,sizeof(vis));
    vis[0][0]=1;
    int ans=INT_MAX;
    while(!q.empty())
    {
        //cout<<"okk"<<endl;
        int h=q.top().first;
        int u=q.top().second.first;
        int v=q.top().second.second;
        q.pop();
       // cout<<u<<" "<<v<<" "<<-h<<endl;
        if(graph[u][v]==3)
        {
         //   cout<<"OK"<<q.size()<<endl;
            ans=min(ans,-h);
            continue;
        }
        for(int i=v+1; i<m; i++)
        {
            if(graph[u][i]!=0)
            {

                if(!vis[u][i])
                {
                    vis[u][i]=1;
                    q.push({h,{u,i}});
                    vis[x][y]=0;

                }
            }
            else
                break;

        }

        for(int i=u-1; i>=0; i--)
        {
            if(graph[u][i]!=0)
            {

                if(!vis[u][i])
                {
                    vis[u][i]=1;
                    q.push({h,{u,i}});
                    vis[x][y]=0;

                }
            }
            else
                break;


        }
        for(int i=u+1; i<n; i++)
        {
            if(graph[i][v]!=0 && !vis[i][v])
            {
                vis[i][v]=1;
                q.push({-max(-h,abs(u-i)),{i,v}});
                vis[x][y]=0;
                break;

            }

        }
        for(int i=u-1; i>=0; i--)
        {
            if(graph[i][v]!=0 && !vis[i][v])
            {
                vis[i][v]=1;
                q.push({-max(-h,abs(u-i)),{i,v}});
                vis[x][y]=0;
                break;

            }
        }


    }
    cout<<ans<<endl;


}
