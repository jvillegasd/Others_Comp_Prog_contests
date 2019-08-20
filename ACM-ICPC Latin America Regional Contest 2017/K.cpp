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
#define MAX 3020
#define NIL 0
#define INF (1<<28)

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
lli nl, arr[0];

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

vector<int> G[MAX+1];
int n, m, match[MAX], dist[MAX];

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n+m; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    memset(match, 0, sizeof(match));
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

int main(){
    BOOST;
    int r, c, type1cnt, di[]={1, -1, 0, 0}, dj[]={0, 0, 1, -1};
    while(cin >> r >> c){
        for(int i = 0; i < MAX; i++) G[i].clear();
        type1cnt=n=m=0;
        char table[r+2][c+2];
        int label[r+2][c+2], sz[r+2][c+2];
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> table[i][j];
                if(table[i][j] == 'o') type1cnt++;
                if((i+j)%2 == 0){
                    if(table[i][j] == 'o') label[i][j]=++n, sz[i][j]=1;
                    else n+=2, label[i][j]=n, sz[i][j]=2;
                }else{
                    if(table[i][j] == 'o') label[i][j]=++m, sz[i][j]=1;
                    else m+=2, label[i][j]=m, sz[i][j]=2;
                }
            }
        }
        if(type1cnt%2 != 0){
            printf("N\n");
            continue;
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if((i+j)%2 == 1) continue;
                for(int k = 0; k < 4; k++){
                    int ni=i+di[k], nj=j+dj[k];
                    if(ni >= 0 && ni < r && nj >= 0 && nj < c){
                        int lu=label[i][j]-sz[i][j]+1, ru=label[i][j];
                        int lv=label[ni][nj]-sz[ni][nj]+1, rv=label[ni][nj];
                        for(int u=lu; u <= ru; u++) for(int v=lv; v <= rv; v++) G[u].pb(v+n);
                    }
                }
            }
        }
        if(hopcroft_karp() == (n+m)/2) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
