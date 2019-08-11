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
typedef pair<pii, int> edge;
lli nl, arr[0];
int r, c;
vector<int> g[0];

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

int dist[1010][1010];
bool vist[1010][1010];
int energy[][5] = {
    {7,6,5,6,7},
    {6,3,2,3,6},
    {5,2,0,2,5},
    {6,3,2,3,6},
    {7,6,5,6,7}
};

void dijkstra(int rf, int cf, int rt, int ct){
    priority_queue<edge> pq;
    pq.push({{0, rf}, cf});
    dist[rf][cf]=0;
    int x1, y1, x2, y2, d, di;
    while(!pq.empty()){
        edge e=pq.top();
        pq.pop();
        d=-e.fp.fp;
        x1=e.fp.sp;
        y1=e.sp;
        if(x1==rt && y1==ct) break;
        for(int i = -2; i <= 2; i++){
            for(int j = -2; j <= 2; j++){
                x2=x1+i;
                y2=y1+j;
                di=d+energy[i+2][j+2];
                if(x2>=0 && x2<r && y2>=0 && y2<c && di<dist[x2][y2] && !vist[x2][y2]){
                    dist[x2][y2]=di;
                    pq.push({{-di, x2}, y2});
                }
            }
        }
    }
}

int main(){
    int rf, cf, rt, ct, w, rw1, cw1, rw2, cw2;
    while(scanf("%d %d", &r, &c) && r && c){
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) dist[i][j]=INT_MAX;
        scanf("%d %d %d %d", &rf, &cf, &rt, &ct);
        rf--, cf--, rt--, ct--;
        scanf("%d", &w);
        memset(vist, 0, sizeof(vist));
        while(w--){
            scanf("%d %d %d %d", &rw1, &cw1, &rw2, &cw2);
            rw1--, cw1--, rw2--, cw2--;
            for(int i = rw1; i <= rw2; i++) for(int j = cw1; j <= cw2; j++) vist[i][j]=1;
        }
        dijkstra(rf, cf, rt, ct);
        if(dist[rt][ct] == INT_MAX) printf("impossible\n");
        else printf("%d\n", dist[rt][ct]);
    }
    return 0;
}
