//#include <bits/stdc++.h>
#include <stdio.h>
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

int main(){
    int n, m, cnt=0, idx;
    while(scanf("%d", &n) && n){
        int x[10];
        char vva[200]={0}, query[10];
        for(int i = 0; i < n; i++) scanf("\nx%d", &x[i]);
        scanf("%s", vva);
        scanf("%d", &m);
        printf("S-Tree #%d:\n", ++cnt);
        for(int i = 0; i < m; i++){
            scanf("%s", query);
            idx=0;
            for(int j = 0; j < n; j++) idx=idx*2+(query[x[j]-1]-'0');
            printf("%c", vva[idx]);
        }
        printf("\n\n");
    }
    return 0;
}
