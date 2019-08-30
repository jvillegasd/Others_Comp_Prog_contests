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

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

int main(){
    int n, m, a, b, u, v;
    set<int> g[100010];
    while(scanf("%d %d %d %d", &n, &m, &a, &b) != EOF){
        for(u = 1; u <= n; u++) g[u].clear();
        set<pii> sz;
        for(int i = 0; i < m; i++){
            scanf("%d %d", &u, &v);
            g[u].insert(v);
            g[v].insert(u);
        }
        for(u = 1; u <= n; u++) if(g[u].size() > 0)sz.insert({g[u].size(), u});
        while(!sz.empty()){
            pii ls=*sz.begin(), bs=*(--sz.end());
            int total=sz.size();
            if(ls.fp >= a && bs.fp <= total-b-1) break;
            if(ls.fp < a){
                u=ls.sp;
                sz.erase(ls);
                for(auto v : g[u]){
                    int szv=g[v].size();
                    sz.erase({szv, v});
                    if(szv > 1) sz.insert({szv-1, v});
                    g[v].erase(u);
                }
                g[u].clear();
                continue;
            }
            if(bs.fp > total-b-1 && ls != bs){
                u=bs.sp;
                sz.erase(bs);
                for(auto v : g[u]){
                    int szv=g[v].size();
                    sz.erase({szv, v});
                    if(szv > 1) sz.insert({szv-1, v});
                    g[v].erase(u);
                }
                g[u].clear();
            }
        }
        printf("%d\n", sz.size());
    }
    return 0;
}
