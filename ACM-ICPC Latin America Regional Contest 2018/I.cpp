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
vector<int> g[100010];
int lvl[100010];
set<pii> s; //Para organizar del mayor nivel al menor

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void DFS(int u, int p, int lv){
    lvl[u]=lv;
    if(u!=1) s.insert({-lvl[u], u});
    for(auto v : g[u]){
        if(v == p) continue;
        DFS(v, u, lv+1);
    }
}

int main(){
    int n, u, p[100010], deg[100010], ans=0, parent;
    memset(deg, 0, sizeof(deg));
    scanf("%d", &n);
    p[1]=0;
    for(int i = 2; i <= n; i++) scanf("%d", &p[i]), uEdge(p[i], i), deg[p[i]]++;
    DFS(1, 0, 0);
    while(!s.empty()){
        pii node=*s.begin();
        s.erase(node);
        u=node.sp;
        parent=p[u];
        node={-lvl[parent], parent};
        if(deg[u] >= 2 && deg[parent] >= 3 && parent!=1 && s.find(node) != s.end()) s.erase(node), deg[p[parent]]--, ans++;
    }
    printf("%d\n", ans);
    return 0;
}
