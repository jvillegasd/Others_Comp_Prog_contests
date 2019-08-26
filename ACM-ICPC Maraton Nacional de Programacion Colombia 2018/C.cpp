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
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
unordered_map<string, int> words;
unordered_map<string, vector<string>> anagrams;

lli gcd(lli a, lli b){if(b == 0) return a;a%=b;return gcd(b, a);}
lli lcm(lli a, lli b){return (a*b)/gcd(a, b);}
int bs(lli sum){int l=0,r=nl-1,mid;while(l<=r){mid=(l+r)/2;if(arr[mid]==sum)return mid;if(arr[mid]<sum)l=mid+1;else r=mid-1;}return -1;}
lli modPow(lli a, lli b){a%=MOD;lli ans=1;while(b > 0){if(b & 1) ans=ans*a%MOD;a=a*a%MOD;b>>=1;}return ans;}

void BFS(string src, string endd){
    if(src.size() != endd.size()){
        printf("%s TO %s IMPOSSIBLE\n", src.c_str(), endd.c_str());
        return;
    }
    if(src == endd){
        printf("%s TO %s 0 0\n", src.c_str(), endd.c_str());
        return;
    }
    queue<string> q;
    unordered_map<string, pii> dist;
    q.push(src);
    dist[src]={0, 0};
    while(!q.empty()){
        string u=q.front();
        q.pop();
        pii d=dist[u];
        if(u == endd){
            printf("%s TO %s %d %d\n", src.c_str(), endd.c_str(), d.fp, d.sp-words[endd]);
			return;
        }
        for(int i = 0; i < u.size(); i++){
            char aux=u[i];
            for(int j = 'a' ; j <= 'z'; j++){
                if(aux == j) continue;
                u[i]=j;
                auto it=words.find(u);
                if(it == words.end()) continue;
                auto du=dist.find(u);
                if(du == dist.end()){
                    q.push(u);
                    dist[u]={d.fp+1, d.sp+it->second};
                }else if(du->second.first == d.fp+1) du->second={du->second.first, max(du->second.second, d.sp+it->second)};
            }
            u[i]=aux;
        }
        sort(u.begin(), u.end());
        for(auto v : anagrams[u]){
            auto it=words.find(v);
            auto dv=dist.find(v);
            if(dv == dist.end()){
                q.push(v);
                dist[v]={d.fp+1, d.sp+it->second};
            }else if(dv->second.first == d.fp+1) dv->second={dv->second.first, max(dv->second.second, d.sp+it->second)};
        }
    }
    printf("%s TO %s IMPOSSIBLE\n", src.c_str(), endd.c_str());
}

int main(){
    int n, q;
    char word[32], u[32], v[32];
    while(scanf("%d", &n) != EOF){
        words.clear(), anagrams.clear();
        for(int i = 0; i < n; i++){
            scanf("%s", &word);
            int pt=0;
            for(int j = 0; word[j]; j++) pt+=points[word[j]-'a'];
            words[word]=pt;
            string sw=word;
            sort(sw.begin(), sw.end());
            anagrams[sw].pb(word);
        }
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%s %*s %s", &u, &v);
            BFS(u, v);
        }
    }
    return 0;
}
