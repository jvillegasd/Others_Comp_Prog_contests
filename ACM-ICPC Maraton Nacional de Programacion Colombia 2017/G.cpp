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
bool label[505];
int dp[505][505], dp2[505][505], k[505], m;

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void DFS(int u, vector<pii> g[]){
    k[u]=label[u];
    for(auto e : g[u]){
        DFS(e.fp, g);
        k[u]+=k[e.fp];
    }
    dp[u][label[u]]=0;
    for(auto e : g[u]){ //Caminos incompletos (Inicio y fin no son transmisores)(Apenas vamos creando los caminos)
        for(int i = k[u]; i >= label[u]; i--){
            if(dp[u][i] == -1) continue;
            for(int j = k[e.fp]; j >= 1; j--){
                if(dp[e.fp][j] == -1 || i+j > m) continue;
                dp[u][i+j]=max(dp[u][i+j], dp[u][i]+e.sp+dp[e.fp][j]);
            }
        }
    }
    dp2[u][0]=0;
    for(auto e : g[u]){ //Caminos completos (Inicio y fin son transmisores)(Con los caminos ya creados con dp, unirlos aqui)
        for(int i = k[u]; i >= 0; i--){
            if(dp2[u][i] == -1) continue;
            for(int j = k[e.fp]; j >= 1; j--){
                if(dp2[e.fp][j] == -1 || i+j > m) continue;
                dp2[u][i+j]=max(dp2[u][i+j], dp2[u][i]+dp2[e.fp][j]);
            }
        }
    }
    if(label[u]) for(int i = 1; i <= k[u]; i++) dp2[u][i]=max(dp2[u][i], dp[u][i]); //Si u es transmisor, ver si es mayor dp o dp2
}

int main(){
    int n, q, u, v, w, xi, qi;
    while(scanf("%d %d %d", &n, &m, &q) == 3){
        int inDeg[n+1]={0}, ans[505]={};
        vector<pii> g[n+1];
        memset(k, 0, sizeof(k));
        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));
        memset(label, 0, sizeof(label));
        for(int i = 0; i < n-1; i++) scanf("%d %d %d", &u, &v, &w), dwEdge(u, v, w), inDeg[v]++;
        for(int i = 0; i < m; i++) scanf("%d", &u), label[u]=1;
        u=0;
        while(inDeg[u]) u++;
        DFS(u, g);
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= m; j++) ans[j]=max(ans[j], dp2[i][j]);
        }
        while(q--){
            scanf("%d", &qi);
            if(qi > m) printf("0\n");
            else printf("%d\n", ans[qi]);
        }
    }
    return 0;
}
