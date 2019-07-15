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
vector<int> g[1000000];
int n, m, lg2n = 20, parent[1000000][20], dist[1000000], tin[1000000], tout[1000000], cntt=0;

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

int convert(int x, int y){
    return x*n+y;
}
void DFS(int u, int p){
    tin[u] = cntt++;
    parent[u][0] = p;
    dist[u]=dist[p]+1;
    for(int i = 1; i < lg2n; ++i) parent[u][i] = parent[parent[u][i-1]][i-1];
    for(auto v : g[u]){
        if(v == p) continue;
        DFS(v, u);
    }
    tout[u] = cntt++;
}

bool is_anc(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA(int u, int v){
    if(is_anc(u, v)) return u;
    if(is_anc(v, u)) return v;
    for(int i = lg2n - 1; i >= 0; --i) if(parent[u][i] && !is_anc(parent[u][i], v)) u = parent[u][i];
    return parent[u][0];
}
int main(){
    memset(dist, 0, sizeof(dist));
    int queries, xi, yi, xf, yf, u, v;
    lli ans=0;
    string maze, trash;
    cin >> n >> m;
    getline(cin, trash), getline(cin, trash);
    for(int i = 0; i < n; i++){
        getline(cin, maze);
        for(int j = 1; j < 2*m; j++){
            int x=(j-1)/2, y=i;
            u=convert(x, y);
            if(j%2 == 1 && maze[j] == ' ') v=convert(x, y+1), uEdge(u, v); //Par (indice 0)
            if(j%2 == 0 && maze[j] == ' ') v=convert(x+1, y), uEdge(u, v); //Impar (indice 0)
        }
    }
    DFS(0, 0);
    scanf("%d", &queries);
    scanf("%d %d", &yi, &xi);
    xi--;
    yi--;
    queries--;
    while(queries--){
        scanf("%d %d", &yf, &xf);
        xf--;
        yf--;
        u=convert(xf, yf);
        v=convert(xi, yi);
        int lca = LCA(min(u,v), max(u,v));
        ans+=(dist[u]+dist[v]-2*(dist[lca]-1)-2);
        xi=xf;
        yi=yf;

    }
    cout << ans << endl;
    return 0;
}
