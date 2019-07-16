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
    int n, s, dp[110][110], a, b, c, worst_case, u, v, w, sum;
    while(scanf("%d %d", &n, &s) == 2){
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 1; i <= n; i++) dp[i][i]=0;
        for(int i = 0; i < s; i++){
            scanf("%d %d %d", &u, &v, &w);
            u++;
            v++;
            dp[u][v]=dp[v][u]=w;
        }
        worst_case=0;
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(dp[i][k]+dp[k][j] < dp[i][j]) dp[i][j]=dp[i][k]+dp[k][j];
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) worst_case=max(worst_case, dp[i][j]);
        }
        scanf("%d %d %d", &a, &b, &c);
        a=min(a, min(b, c));
        printf("%d\n", (worst_case-1+a)/a);
    }
    return 0;
}
