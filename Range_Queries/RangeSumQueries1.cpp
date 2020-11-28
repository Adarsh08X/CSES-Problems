#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define OJ \
        freopen("input.txt","r",stdin); \
        freopen("output.txt","w",stdout);
int mod=1000000007;
int gcd(int a, int b)  
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
 
const int N = 100000;  
ll tree[4 * N]; 
  
void build( ll arr[], int n)  
{  
    
    for (int i=0; i<n; i++)     
        tree[n+i] = arr[i]; 
      
   
    for (int i = n - 1; i > 0; --i)      
        tree[i] = tree[i<<1] + tree[i<<1 | 1];     
} 
  
/*
void updateTreeNode(int p, int value)  
{  
  
    tree[p+n] = value; 
    p = p+n; 
      
  
    for (int i=p; i > 1; i >>= 1) 
        tree[i>>1] = tree[i] + tree[i^1]; 
}*/ 
  
 
ll query(int l, int r, int n)  
{  
   ll res = 0; 
      
   
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    { 
        if (l&1)  
            res += tree[l++]; 
      
        if (r&1)  
            res += tree[--r]; 
    } 
      
    return res; 
} 
 
 
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 // OJ;
  
int n,q;
cin>>n>>q;
ll a[n];
 
for(int i=0;i<n;i++)
{
  cin>>a[i];
}
build(a,n);
while(q--)
{
  int l,r;
  cin>>l>>r;
  cout<<query(l-1,r, n)<<endl;
}
}