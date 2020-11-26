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

void dfs(vector<int> V[], int num, int visited[])
{
    visited[num]=1;
    for(int i=0;i<V[num].size();i++)
    {
        if(visited[V[num][i]]==0)
        {
            dfs(V,V[num][i],visited);
        }
    }
}

int connected(vector<int> V[], int num, int visited[] )
{
    int ans=0;
    for(int i=0;i<num;i++)
    {
        if(visited[i]==0)
        {
            dfs(V,i,visited);
            ans++;
        }
    }
    return ans;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 // OJ;
 int n,m;
 cin>>n>>m;
 char a[n][m];
 int b[n][m];
 int count=0;
 int hash=0;
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
         cin>>a[i][j];
         if(a[i][j]=='#')
         {
             hash++;
         }
         b[i][j]=count;
         count++;
     }
 }
 
 int num=n*m;
vector<int> V[num];

int d1[]={-1,1,0,0},d2[]={0,0,-1,1};
for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
      for(int k=0;k<4;k++)
      {

          int x=i+d1[k];
          int y=j+d2[k];
          if(x<0||y<0) continue;
          if(x>=n||y>=m) continue;
          if(a[x][y]=='.'&&a[i][j]=='.')
          {
              V[b[i][j]].push_back(b[x][y]);
          }
      }

     }
     }
    
     
     int visited[num]={0};
     cout<<connected(V,num,visited)-hash;
 }

