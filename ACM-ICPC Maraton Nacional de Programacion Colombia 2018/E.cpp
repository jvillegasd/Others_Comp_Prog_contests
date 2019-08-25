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

int merge(int a[], int l, int m, int r){
    int i = l, j = m+1, bsize = 0, b[1000100], inv=0;
    while(i<=m && j<=r){
        if(a[i]<=a[j]) b[bsize++]=a[i++];
        else b[bsize++]=a[j++], inv+=(m-i+1);
    }
    while(i<=m) b[bsize++]=a[i++];
    while(j<=r) b[bsize++]=a[j++];
    for(int k = 0; k < bsize; k++) a[l+k] = b[k];
    return inv;
}

int mergesort(int a[], int l, int r){
    int inv=0;
    if(l >= r) return inv;
    int m = (l+r)/2;
    inv=mergesort(a, l, m);
    inv+=mergesort(a, m+1, r);
    inv+=merge(a, l, m, r);
    return inv;
}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        int a[n*m+1], k=0, row, col, ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &a[k++]);
                if(a[k-1] == n*m) row=i, col=j;
            }
        }
        ans=mergesort(a, 0, (n*m)-1)+(n-1-row+m-1-col);
        if(ans%2 == 0) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
