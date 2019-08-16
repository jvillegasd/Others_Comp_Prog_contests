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
vector<pii> mst[100010];
int lg2n=18, parent[100010][18], maxWlca[100010][18], edge_w[100010], tin[100010], tout[100010], cntt=0, rankdsu[100010], parentdsu[100010], depth[100010];
struct edge{
    int u, v, w;
};

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

bool cmp(const edge &a, const edge &b){
    return a.w < b.w;
}

void make_set(int n){
    for(int i = 1; i <= n; i++) parentdsu[i] = i, rankdsu[i]=0, mst[i].clear(), depth[i]=0, tin[i]=0, tout[i]=0, edge_w[i]=0;
}

int find(int i){
    if(i == parentdsu[i]) return i;
    return parentdsu[i] = find(parentdsu[i]);
}

bool union_set(int i, int j){
    int iRoot = find(i), jRoot = find(j);
    if(iRoot == jRoot) return false;
    if(rankdsu[iRoot] < rankdsu[jRoot]) swap(iRoot, jRoot);
    parentdsu[jRoot] = iRoot;
    if(rankdsu[iRoot] == rankdsu[jRoot]) rankdsu[iRoot]++;
    return true;
}

void DFS(int u, int p, int dep){
    tin[u] = cntt++;
    parent[u][0] = p;
    maxWlca[u][0]=edge_w[u];
    depth[u]=dep;
    for(int i = 1; i < lg2n; ++i){
        parent[u][i] = parent[parent[u][i-1]][i-1];
        maxWlca[u][i]=max(maxWlca[u][i-1], maxWlca[parent[u][i-1]][i-1]);
    }
    for(auto e : mst[u]){
        int v=e.fp, w=e.sp;
        if(v == p) continue;
        edge_w[v]=w;
        DFS(v, u, dep+1);
    }
    tout[u] = cntt++;
}

bool is_anc(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if(is_anc(u, v)) return u;
    if(is_anc(v, u)) return v;
    for(int i = lg2n - 1; i >= 0; --i) if(parent[u][i] && !is_anc(parent[u][i], v)) u = parent[u][i];
    return parent[u][0];
}

int maxW(int u, int lca_node){
    int lca_lvl=depth[lca_node], maxi=0;
    for(int i = lg2n-1; i >= 0; i--){
        if(parent[u][i] && depth[u]-(1<<i) >= lca_lvl){
            maxi=max(maxi, maxWlca[u][i]);
            u=parent[u][i];
        }
    }
    return maxi;
}

int main(){
    int n, r, u, v, w, q, lca_node;
    lli total;
    while(scanf("%d %d", &n, &r) != EOF){
        vector<edge> g;
        map<pii, int> edge_list;
        total=cntt=0;
        memset(parent, 0, sizeof(parent));
        memset(maxWlca, 0, sizeof(maxWlca));
        make_set(n);
        for(int i = 0; i < r; i++) scanf("%d %d %d", &u, &v, &w), g.pb({u, v, w}), edge_list[{u, v}]=w;
        sort(g.begin(), g.end(), cmp);
        for(auto e : g){
            u=e.u, v=e.v, w=e.w;
            if(union_set(u, v)) mst[u].pb({v, w}), mst[v].pb({u, w}), total+=w;
        }
        DFS(1, 0, 0);
        scanf("%d", &q);
        while(q--){
            scanf("%d %d", &u, &v);
            lca_node=lca(u, v);
            printf("%lld\n", total+edge_list[{u, v}]-max(maxW(u, lca_node), maxW(v, lca_node)));
        }
    }
    return 0;
}
