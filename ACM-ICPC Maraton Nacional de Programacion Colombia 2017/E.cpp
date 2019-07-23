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
    lli p, q, n, p1, q1, p2, q2, pm, qm, aux;
    while(scanf("%lld %lld %lld", &p, &q, &n) == 3){
        p1=0, q1=1, p2=1, q2=1;
        aux=n;
        while(true){
            if(p1 == p && q1 == q) break;
            if(p2 == p && q2 == q) break;
            pm=p1+p2;
            qm=q1+q2;
            if(pm == p && qm == q) break;
            if((double)p*qm <= (double)q*pm) p2=pm, q2=qm;
            else p1=pm, q1=qm;
        }
        set<pair<lli, lli>> ans;
        if((p1 != p || q1 != q) && n) ans.insert({p1, q1}), p1+=p, q1+=q, n--;
        if((p2 != p || q2 != q) && n) ans.insert({p2, q2}), p2+=p, q2+=q, n--;
        while(ans.size() <= aux){
            if((p1 != p || q1 != q) && ans.count({p1, q1}) == 0) ans.insert({p1, q1}), p1+=p, q1+=q;
            if((p2 != p || q2 != q) && ans.count({p2, q2}) == 0) ans.insert({p2, q2}), p2+=p, q2+=q;
        }
        for(auto ai : ans){
            aux--;
            printf("M(%lld/%lld)%s", ai.fp, ai.sp, (aux == 0)?"\n":" ");
            if(aux == 0) break;
        }
    }
    return 0;
}
