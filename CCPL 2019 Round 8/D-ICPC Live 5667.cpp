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
    int n, m, k, ni;
    scanf("%d", &m);
    while(m--){
        scanf("%d %d %d", &n, &k, &ni);
        bool dp[10050][105];
        memset(dp, 0, sizeof(dp));
        dp[1][(ni%k+k)%k]=1;
        for(int i = 2; i <= n; i++){
            scanf("%d", &ni);
            ni=abs(ni);
            ni%=k;
            for(int j = 0; j < k; j++){
                if(dp[i-1][j]){
                    dp[i][(j+ni)%k]=dp[i][(j-ni+k)%k]=1;
                }
            }
        }
        if(dp[n][0]) printf("Divisible\n");
        else printf("Not divisible\n");
    }
    return 0;
}