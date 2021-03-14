#include<bits/stdc++.h>
#define ll long long 
#define OJ \
        freopen("input.txt","r",stdin); \
        freopen("output.txt","w",stdout);
using namespace std;
int mod=1000000007;
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

vector<int> v;
void dfs(vector<int> V[], int node, int visited[])
{
    visited[node]=1;
    for(int i=0;i<V[node].size();i++)
    {
        if(visited[V[node][i]]==0)
        {
            dfs(V,V[node][i],visited);
        }
    }
}

int connected(vector<int> V[], int n, int visited[] )
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(V,i,visited);
            v.push_back(i);
            ans++;
        }
    }
    return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 //OJ;
 int n,m;
 cin>>n>>m;
 vector<int> V[n+1];
 for(int i=0;i<m;i++)
 {
     int a,b;
     cin>>a>>b;
    V[a].push_back(b);
    V[b].push_back(a);
 }
 int visited[n+1]={0};
int tot=connected(V,n,visited);
if(v.size()==1)
{
    cout<<0;
}
else{
    cout<<v.size()-1<<endl;
    for(int i=0;i<v.size()-1;i++)
    {
        cout<<v[i]<<" "<<v[i+1]<<endl;
    }

}
 }

