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
set<string> ans;

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void BT(char tree[], int l, int r){
    ans.insert(tree+l);
    int pos=-1;
    for(int i=l; i <= r; i++){
        if(!isalpha(tree[i])){
            pos=i;
            break;
        }
    }
    if(pos == -1) return;
    pos++;
    for(int i=pos, paren=0; i <= r; i++){
        if(tree[i]=='(') paren++;
        else if(tree[i] == ')') paren--;
        if(tree[i] == ',' || i == r){
            if(paren == 0 || i == r){
                tree[i]='\0';
                BT(tree, pos, i-1);
                pos=i+1;
            }
        }
    }
}

int main(){
    char tree[110000];
    while(cin >> tree){
        ans.clear();
        BT(tree, 0, strlen(tree)-1);
        printf("%d\n", ans.size());
    }
    return 0;
}
