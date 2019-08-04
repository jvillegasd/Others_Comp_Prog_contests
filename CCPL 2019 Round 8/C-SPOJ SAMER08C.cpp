#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define pob pop_back
#define fp first
#define sp second
#define mp make_pair
#define ins insert
#define uEdge(u, v) g[u].pb(v), g[v].pb(u)
#define uwEdge(u, v, w) g[u].pb({v, w}), g[v].pb({u, w})
#define dEdge(u, v) g[u].pb(v)
#define dwEdge(u, v, w) g[u].pb({v, w})
#define BOOST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define minHeap int, vector<int>, greater<int>
#define MOD 1000000007

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
lli nl, arr[0];
vector<int> g[0];

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) && n && m){
        int grid[n+2][m+2];
        vector<int> rows;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) scanf("%d", &grid[i][j]);
        for(int i = 1; i <= n; i++){
            int dp[m+2][2];
            dp[0][0]=dp[0][1]=0;
            for(int j = 1; j <= m; j++){
                if(j > 1){
                    dp[j][1]=grid[i][j]+max(dp[j-2][1], dp[j-1][0]);
                    dp[j][0]=max(dp[j-1][1], dp[j-1][0]);
                }else{
                    dp[j][1]=grid[i][j];
                    dp[j][0]=max(dp[j-1][1], dp[j-1][0]);
                }

            }
            rows.pb(max(dp[m][0], dp[m][1]));
        }
        int dp[n+2][2];
        dp[0][0]=dp[0][1]=0;
        for(int j = 1; j <= n; j++){
            if(j > 1) dp[j][1]=rows[j-1]+max(dp[j-2][1], dp[j-1][0]);
            else dp[j][1]=rows[j-1];
            dp[j][0]=max(dp[j-1][1], dp[j-1][0]);
        }
        printf("%d\n", max(dp[n][0], dp[n][1]));
    }
    return 0;
}
