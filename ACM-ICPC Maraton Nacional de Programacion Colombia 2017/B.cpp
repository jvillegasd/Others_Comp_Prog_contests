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
int l, r;

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

lli extended_gcd(lli a, lli b, lli &x, lli &y) {
    if(a == 0){
        x=0, y=1;
        return b;
    }
    lli x1, y1;
    lli d=extended_gcd(b%a, a, x1, y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}

bool can_solve(lli a, lli b, lli c, lli &x0, lli &y0, lli &g) {
    g=extended_gcd(abs(a), abs(b), x0, y0);
    if (c%g) return false;
    x0*=c/g;
    y0*=c/g;
    if(a < 0) x0*=-1;
    if(b < 0) y0*=-1;
    return true;
}

void shift_solution(lli &x, lli &y, lli a, lli b, lli cnt) {
    x+=cnt*b;
    y-=cnt*a;
}

lli all_solutions(lli a, lli b, lli c, lli minx, lli maxx, lli miny, lli maxy) {
    lli x, y, g;
    if(!can_solve(a, b, c, x, y, g)) return 0;
    a/=g;
    b/=g;
    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;
    shift_solution(x, y, a, b, (minx-x)/b);
    if(x < minx) shift_solution(x, y, a, b, sign_b);
    if(x > maxx) return 0;
    lli lx1=x;
    shift_solution(x, y, a, b, (maxx-x)/b);
    if(x > maxx) shift_solution(x, y, a, b, -sign_b);
    lli rx1=x;
    shift_solution(x, y, a, b, -(miny-y)/a);
    if(y < miny) shift_solution(x, y, a, b, -sign_a);
    if(y > maxy) return 0;
    lli lx2=x;
    shift_solution(x, y, a, b, -(maxy-y)/a);
    if(y > maxy) shift_solution(x, y, a, b, sign_a);
    lli rx2=x;
    if(lx2 > rx2) swap(lx2, rx2);
    lli lx=max(lx1, lx2);
    lli rx=min(rx1, rx2);
    if(lx > rx) return 0;
    return (rx-lx)/abs(b)+1;
}

int main(){
    lli a, b, z, w, x, y, g, m, dp, sol;
    lli cnt=0;
    while(scanf("%lld %lld", &m, &w) == 2){
        scanf("%lld %lld %lld", &a, &b, &z);
        cnt=0;
        for(int zi = -m; zi <= m; zi++){
            dp=w-z*zi;
            if(dp >= -m*(a+b) && dp <= m*(a+b)) cnt+=all_solutions(a, b, dp, -m, m, -m, m);
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
