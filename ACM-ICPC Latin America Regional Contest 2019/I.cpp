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

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
lli nl, arr[0];
vector<int> g[3000];
bool vist[3000];
lli memo[3000], after = 0, MOD = 1e9+7, mailing;

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

bool isMailing(int u){
    return u >= 1 && u <= mailing;
}

void DFS(int u, int p = 0){
    for(auto v : g[u]){
        if(v == p) continue;
        if(!isMailing(v)){
            if(!vist[v]) after = (after + 1) % MOD;
            vist[v] = 1;
            memo[v] = 1;
        }
        if(memo[v] == 0) DFS(v, u);
        memo[u] = (memo[u] + memo[v]) % MOD;
    }
}

int main(){
    int n, l, v, k;
    memset(vist, 0, sizeof(vist));
    memset(memo, 0, sizeof(memo));
    scanf("%d %d", &n, &l);
    mailing = l;
    for(int u = 1; u <= l; u++){
        scanf("%d", &k);
        for(int i = 0; i < k; i++){
            scanf("%d", &v);
            dEdge(u, v);
        }
    }
    DFS(1);
    printf("%lld %lld", memo[1], after);
    return 0;
}