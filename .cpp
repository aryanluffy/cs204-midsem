#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#pragma GCC optimize("-O2")
#define mod2 998244353
#define MAXN 1000000000
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector<vector<int>>
#define v4096 vector<vector<lli>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)
#define lb lower_bound
#define ld long double
#define m64 map<lli, lli>
#define m32 map<int, int>
#define m64it map<lli, lli>::iterator
#define m32it map<int, int>::iterator
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define ist insert
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp>
#define p_q priority_queue
#define min_p_q priority_queue<int, vt<int>, greater<int>>
using namespace std;
using namespace __gnu_pbds;

int main()
{
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    v32 arr(n),arr2;f(i,0,n)cin>>arr[i];
    arr2=arr;
    int dp[n][n],dp2[n][n+1];
    f(i,0,n)f(j,0,n)dp[i][j]=0;
    f(i,0,n)f(j,0,n+1)dp2[i][j]=0;
    f(i,0,n)arr[i]=arr[i]%n;
    f(i,0,n)arr2[i]=arr2[i]%(n+1);
    dp[0][arr[0]]=1;
    dp2[0][arr2[0]]=1;
    f(i,1,n){
      f(j,0,n){
        dp[i][j]=(dp[i-1][j])||(dp[i-1][(j-arr[i]+n)%n])||(arr[i]==j);
      }
    }
    f(i,1,n){
      f(j,0,n+1){
        dp2[i][j]=(dp2[i-1][j])||(dp2[i-1][(j-arr2[i]+n+1)%(n+1)])||(arr2[i]==j);
      }
    }
    if(!dp[n-1][0])cout<<-1<<"\n";
    else {
       v32 ans;
       int i=n-1, curr=0;
       //cout<<arr[i]<<" "<<curr<<"\n";
       while(i>-1){
         if(arr[i]==curr){
           ans.pb(i);
           break;
         }
         else if(dp[i-1][(curr-arr[i]+n)%n]==1){
           ans.pb(i);
           curr=(curr-arr[i]+n)%n;
         }
         i--;
       }
       //cout<<ans.size()<<"\n";
       fd(i,(int)ans.size()-1,-1)cout<<ans[i]+1<<" ";
       cout<<"\n";
    }
    if(!dp2[n-1][0])cout<<-2<<"\n";
    else{
       v32 ans;
       int i=n-1,curr=0;
       while(i>-1){
         if(arr2[i]==curr){
           ans.pb(i);
           break;
         }
         else if(dp2[i-1][(curr-arr2[i]+n+1)%(n+1)]==1){
           ans.pb(i);
           curr=(curr-arr2[i]+n+1)%(n+1);
         }
         i--;
       }
       fd(i,(int)ans.size()-1,-1)cout<<ans[i]+1<<" ";
       cout<<"\n";
    }
  }
  return 0;
}
