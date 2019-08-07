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
#define BOOST ios_base::sync_with_stdio(0), ci  n.tie(0), cout.tie(0)
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
    int r, c, k, area;
    while(scanf("%d %d %d", &r, &c, &k) && r && c && k){
        string seats;
        area=r*c;
        int dp[r+2][c+2];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= r; i++){
            cin >> seats;
            for(int j = 0; j < c; j++){
                if(seats[j] == '.') dp[i][j+1]=1;
                else dp[i][j+1]=0;
            }
        }
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++) dp[i][j]=dp[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
        for(int c1 = 1; c1 <= c; c1++){
            for(int c2 = c1; c2 <= c; c2++){
                for(int r1 = 1, r2 = 1; r2 <= r; r2++){
                    while(r1 < r2 && dp[r2][c2]-dp[r1][c2]-dp[r2][c1-1]+dp[r1][c1-1] >= k) r1++;
                    if(dp[r2][c2]-dp[r1-1][c2]-dp[r2][c1-1]+dp[r1-1][c1-1] >= k) area=min(area, (c2-c1+1)*(r2-r1+1));
                }
            }
        }
        printf("%d\n", area);
    }
    return 0;
}
