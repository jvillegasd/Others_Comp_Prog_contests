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
int tree[400010];
bool prime[100010];
vector<int> primes;

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

bool cmp(const pair<pii, int> &a, const pair<pii, int> &b){
    return a.fp.fp > b.fp.fp;
}

void sieve(){
    memset(prime, 1, sizeof(prime));
    prime[0]=prime[1]=0;
    for(int i = 2; i <= 100010; i++){
        if(prime[i]){
            primes.pb(i);
            for(int j = 2*i; j <= 100010; j+=i) prime[j]=0;
        }
    }
}

void buildTree(int node, int l, int r){
    if(l == r){
        tree[node]=1;
        return;
    }
    int mid=(l+r)/2;
    buildTree(2*node, l, mid);
    buildTree(2*node+1, mid+1,r);
    tree[node]=tree[2*node]+tree[2*node+1];
}

void updateTree(int node, int l, int r, int i){
    if(l == i && r == i){
        tree[node] = 0;
        return;
    }
    int mid=(l+r)/2;
    if(i <= mid) updateTree(2*node, l, mid, i);
    else updateTree(2*node+1, mid+1, r, i);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node, int l, int r, int i, int j){
    if(i <= l && r <= j) return tree[node];
    if(r < i || l > j) return 0;
    int mid=(l+r)/2;
    return query(2*node, l, mid, i, j)+query(2*node+1, mid+1, r, i, j);
}

int main(){
    sieve();
    int n, k, q, ni, ki, idx, pidx=primes.size()-1, ans[100010];
    vector<pair<pii, int>> queries;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) scanf("%d %d", &n, &k), queries.pb({{k, n}, i});
    sort(queries.begin(), queries.end(), cmp);
    buildTree(1, 1, 100005);
    for(auto qi : queries){
        ki=qi.fp.fp;
        ni=qi.fp.sp;
        idx=qi.sp;
        while(primes[pidx] > ki && pidx >= 0){
            for(int i = primes[pidx]; i < 100005; i+=primes[pidx]) updateTree(1, 1, 100005, i);
            pidx--;
        }
        ans[idx]=query(1, 1, 100005, 2, ni);
    }
    for(int i = 0; i < q; i++) printf("%d\n", ans[i]);
    return 0;
}
