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

struct pt {
    double x, y;
    pt(double x, double y){
        this->x=x;
        this->y=y;
    }

    bool operator < (const pt &p) const{
        return x < p.x || (x == p.x && y < p.y);
    }

    bool operator == (const pt &o) const{
        return x == o.x && y == o.y;
    }
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool clockwise(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool counter_clockwise(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

vector<pt> convex_hull(vector<pt> a) {
    if(a.size() == 1) return a;
    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for(int i = 1; i < (int)a.size(); i++){
        if(i == a.size()-1 || clockwise(p1, a[i], p2)){
            while (up.size() >= 2 && !clockwise(up[up.size()-2], up[up.size()-1], a[i])) up.pop_back();
            up.push_back(a[i]);
        }
        if(i == a.size()-1 || counter_clockwise(p1, a[i], p2)){
            while(down.size() >= 2 && !counter_clockwise(down[down.size()-2], down[down.size()-1], a[i])) down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for(int i = 0; i < (int)up.size(); i++) a.push_back(up[i]);
    for(int i = down.size()-2; i > 0; i--) a.push_back(down[i]);
    return a;
}

bool onSegment(pt p, pt q, pt r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
    return false;
}

int orientation(pt p, pt q, pt r){
    int val = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if(val == 0) return 0;
    return (val > 0)? 1: 2;
}

bool has_intersection_point(pt p1, pt q1, pt p2, pt q2){
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if(o1 != o2 && o3 != o4) return true;
    if(o1 == 0 && onSegment(p1, p2, q1)) return true;
    if(o2 == 0 && onSegment(p1, q2, q1)) return true;
    if(o3 == 0 && onSegment(p2, p1, q2)) return true;
    if(o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
}

bool onBoundary(vector<pt> ch, pt a){
    for(int i = 0; i < ch.size(); i++){
        int next=(i+1 == ch.size())?0:i+1;
        if(has_intersection_point(ch[i], ch[next], a, a)) return true;
    }
    return false;
}

int main(){
    int n, x, y, cnt;
    while(scanf("%d", &n) && n){
        vector<pt> onion;
        cnt=0;
        for(int i = 0; i < n; i++) scanf("%d %d", &x, &y), onion.pb(pt(x, y));
        while(!onion.empty()){
            vector<pt> ch = convex_hull(onion), cpy;
            set<pt> a;
            for(auto ai : ch) a.insert(ai);
            for(auto oi : onion) if(a.count(oi) == 0 && !onBoundary(ch, oi)) cpy.pb(oi);
            onion=cpy;
            cnt++;
        }
        if(cnt&1) printf("Take this onion to the lab!\n");
        else printf("Do not take this onion to the lab!\n");
    }
    return 0;
}
