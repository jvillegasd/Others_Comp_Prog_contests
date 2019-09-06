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
int xi, yi, xf, yf, m;
bool vist[1010][1010], flag;
int dr[] = {1,1,0,-1,-1,-1, 0, 1}, dc[] = {0,1,1, 1, 0,-1,-1,-1};

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void flood_fill(int r, int c){
    if (r < 0 || r >= 1010 || c < 0 || c >= 1010) return;
    if (vist[r][c]) return;
    vist[r][c] = 1;
    if(r == yf && c == xf){
        flag=1;
        return;
    }
    for (int d = 0; d < 8; d++) flood_fill(r + dr[d], c + dc[d]);
}

int dist(int a, int b, int c, int d){
    return (a-c)*(a-c)+(b-d)*(b-d);
}

void set_visited(int x, int y){
    for(int i = y-m; i <= y+m; i++){
        for(int j = x-m; j <= x+m; j++){
            if(dist(x, y, j, i) <= m*m && i >= 0 && i < 1010 && j >= 0 && j < 1010) vist[i][j]=1;
        }
    }
}

int main(){
    int n, x, y;
    while(scanf("%d %d", &n, &m) && n && m){
        vector<pii> polygon;
        memset(vist, 0, sizeof(vist));
        flag=0;
        for(int i = 0; i < n; i++) scanf("%d %d", &x, &y), polygon.pb({x, y});
        scanf("%d %d %d %d", &xi, &yi, &xf, &yf);
        pii po=*polygon.begin();
        polygon.erase(polygon.begin());
        polygon.pb(po);
        for(auto p : polygon){
            if(po.sp == p.sp){
                for(int i=min(po.fp, p.fp); i <= max(po.fp, p.fp); i++){
                    set_visited(i, po.sp);
                }
            } else if(po.fp == p.fp){
                for(int i=min(po.sp, p.sp); i <= max(po.sp, p.sp); i++){
                    set_visited(po.fp, i);
                }
            }
            po=p;
        }
        flood_fill(yi, xi);
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
