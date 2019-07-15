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
bool prime[10000001];

lli gcd(int a, int b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void sieve(){
    memset(prime, 1, sizeof(prime));
    prime[0]=prime[1]=0;
    for(int i = 2; i <= 10000001; i++){
        if(prime[i]) for(int j = 2*i; j <= 10000001; j+=i) prime[j]=0;
    }
}

int main(){
    sieve();
    int n, gcdab, n1, n2;
    double a, b;
    scanf("%d", &n);
    while(n--){
        scanf("%lf %lf", &a, &b);
        n1=round(a*1e5);
        n2=round(b*1e5);
        gcdab=gcd(n1, n2);
        n1/=gcdab;
        n2/=gcdab;
        if(n1 == 1 && n2 == 1) printf("2 2\n");
        else if(prime[n1] && prime[n2]) printf("%d %d\n", n1, n2);
        else printf("impossible\n");
    }
    return 0;
}
