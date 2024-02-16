#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<cstring>
#include<string>
#include<string>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    int cnt=0;
    for(int i=0; i<s.size(); i++)
    {


        if(cnt==n+1)
        {
            string cur;
            while(i<s.size() && s[i]!=')' && s[i]!='(' )
            {
                cur.push_back(s[i]);
                i++;
            }
            if(cur.size()!=0)
            {
                ans=ans+(int)stoi(cur);

               // cout<<"-->"<<stoi(cur)<<endl;
            }
        }
        if(i==s.size())
            continue;
        if(s[i]=='(' )
        {
            cnt++;
        }
        if(s[i]==')')
            cnt--;

    }
    cout<<ans<<endl;
}
