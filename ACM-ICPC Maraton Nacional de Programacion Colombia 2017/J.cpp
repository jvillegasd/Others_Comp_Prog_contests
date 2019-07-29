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
int z[2][200100];

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void z_function(int *z, string s){
    int n = (int) s.length();
    z[0]=0;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        z[i]=0;
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

int main(){
    int tc, k, n, m, ans;
    string t, s, p;
    scanf("%d", &tc);
    while(tc--){
        cin >> s >> p;
        scanf("%d", &k);
        ans=0;
        t=p+"$"+s;
        n=s.length();
        m=p.length();
        z_function(z[0], t);
        reverse(s.begin(), s.end());
        reverse(p.begin(), p.end());
        t=p+"$"+s;
        z_function(z[1], t);
        reverse(z[1]+m+1, z[1]+n+m+1);
        for(int i = m+1; i+m-1 < n+m+1; i++) if(z[0][i]+z[1][i+m-1]+k >= m) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
