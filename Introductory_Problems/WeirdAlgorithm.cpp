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
 ll  int n;
   cin>>n;
   while(n!=1)
   {
        cout<<n<<" ";
       if(n%2)
       {
           n*=3;
           n++;
       }
       else{
           n/=2;
       }
      
   }
   cout<<1;
}