#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

struct edge{
    lli u, l, c;
    bool operator < (const edge& e) const{ //Se organiza asi para simular Greater<> de la priority queue
        if(l == e.l) return c > e.c;
        return l > e.l;
    }
};

int cmp(const edge& a, const edge& b){
    if(a < b) return 1; //A es mayor que b
    if(b < a) return -1; //B es mayor que A
    return 0;
}

vector<edge> cities[550000];
int n, m;

void dijkstra(){
    priority_queue<edge> pq;
    vector<edge> dist(n + 1, {1, INT64_MAX, INT64_MAX});
    vector<lli> cost(n + 1, 0);
    lli sum = 0;
    pq.push({1, 0, 0});
    dist[1] = {1, 0, 0};
    while(!pq.empty()){
        auto e = pq.top();
        pq.pop();
        if(cmp(e, dist[e.u]) == 1) continue; //Comprobar que el camino actual es menor que el mejor que existe
        for(auto ev : cities[e.u]){
            edge added = {ev.u, ev.l + e.l, ev.c};
            if(cmp(added, dist[ev.u]) == -1){
                dist[ev.u] = added;
                cost[ev.u] = ev.c;
                pq.push(added);
            }
        }
    }
    for(int i = 1; i <= n; i++) sum+=cost[i];
    printf("%lld\n", sum);
}

int main(){
    lli a, b, c, l;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%lld %lld %lld %lld", &a, &b, &l, &c);
        cities[a].push_back({b, l, c});
        cities[b].push_back({a, l, c});
    }
    dijkstra();
    return 0;
}