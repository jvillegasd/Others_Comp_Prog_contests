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

string toLower(string a){
    for(int i = 0; i < a.size(); i++) a[i]=tolower(a[i]);
    return a;
}

bool cmp(const pair<string, int> &a, const pair<string, int> &b){
    if(a.sp != b.sp) return a.sp > b.sp;
    return toLower(a.fp) < toLower(b.fp);
}

int main(){
    int p, points, flag, j, cases=0;
    string line, name;
    while(cin >> p){
        vector<pair<string, int>> pj;
        getchar();
        for(int k = 0; k < p; k++){
            points=flag=j=0;
            getline(cin, line);
            for(int i = 0; i < line.size(); i++){
                if(line[i] == ';' && !flag){
                    name=line.substr(0, i);
                    flag=1;
                }else if(line[i] != ';' && flag){
                    if(line[i] == ' ') continue;
                    if(j != 4) points+=((line[i]-'0')), j++;
                    else points+=(2*(line[i]-'0')), j=0;
                }
            }
            pj.pb({name, points});
        }
        sort(pj.begin(), pj.end(), cmp);
        printf("Case %d:\n", ++cases);
        for(auto pi : pj) cout << pi.fp << " " << pi.sp << endl;
    }
    return 0;
}
