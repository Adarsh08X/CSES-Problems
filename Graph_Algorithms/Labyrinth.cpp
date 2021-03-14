#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define endl "\n"
#define revall(x) x.rbegin(), x.rend()
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
using namespace std;
int mod = 1000000007;
int gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    char a[n][m];
    char s[n][m];
    int fx,fy;
     queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='A'){
                q.push(make_pair(i,j));

            }
            if(a[i][j]=='B'){
                fx=i,fy=j;
            }
                s[i][j]='.';
        }
    }
    while(!q.empty()){
        pair<int,int> x=q.front();
        q.pop();
        int i=x.first,j=x.second;
         if(a[i][j]=='B'){
            break;
        }
        if(i+1<n&&s[i+1][j]=='.'&&a[i+1][j]!='#'&&a[i+1][j]!='A'){
            s[i+1][j]='U';
            q.push(make_pair(i+1,j));
        }
        if(i>0&&s[i-1][j]=='.'&&a[i-1][j]!='#'&&a[i-1][j]!='A'){
            s[i-1][j]='D';
            q.push(make_pair(i-1,j));
        }
        if(j+1<m&&s[i][j+1]=='.'&&a[i][j+1]!='#'&&a[i][j+1]!='A'){
            s[i][j+1]='L';
            q.push(make_pair(i,j+1));
        }
        if(j>0&&s[i][j-1]=='.'&&a[i][j-1]!='#'&&a[i][j-1]!='A'){
            s[i][j-1]='R';
            q.push(make_pair(i,j-1));
        }
        
    }
   
    if(s[fx][fy]=='.'){
        cout<<"NO";
    }
    else{
        cout<<"YES\n";
        string ans;
        while(a[fx][fy]!='A'){

            if(s[fx][fy]=='D'){
                ans+="U";
                fx++;
            }
            if(s[fx][fy]=='U'){
                ans+="D";
                fx--;
            }
            if(s[fx][fy]=='L'){
                ans+="R";
                fy--;
            }
            if(s[fx][fy]=='R'){
                ans+="L";
                fy++;
            }

        }
        reverse(all(ans));
        cout<<ans.size()<<endl;
        cout<<ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // OJ;
    int T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }
}