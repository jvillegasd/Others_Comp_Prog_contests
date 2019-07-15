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
lli nl, arr[0], ans=0;
int val[5010];
vector<pii> g[5010];

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void DFS(int u, int p, lli sum=0){
    for(auto e : g[u]){
        int v=e.fp, c=e.sp;
        if(v==p) continue;
        if(sum+c>ans) ans=sum+c;
        if(sum+c>val[v]){
            val[v]=sum+c;
            DFS(v, u, sum+c);
        }else continue;
    }
}

int main (){
    int n, m, u, v, c, inDegree[5010];
    memset(inDegree,0,sizeof inDegree);
    memset(val, 0, sizeof(val));
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d %d %d", &u, &v, &c), g[u].pb({v, c}), inDegree[v]++;
    for(u = 1; u <= n; u++) if(!inDegree[u]) DFS(u, 0);
    printf("%lld\n", ans);
    return 0;
}
