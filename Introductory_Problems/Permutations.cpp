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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
// OJ;
int n;
cin>>n;
 
 
if(n==2||n==3)
{
  cout<<"NO SOLUTION";
  return 0;
}
int eve=2;
while(eve<=n)
{
  cout<<eve<<" ";
  eve+=2;
}
eve=1;
while(eve<=n)
{
  cout<<eve<<" ";
  eve+=2;
}
}