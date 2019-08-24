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

void convex_hull(vector<pt>& a) {
    if(a.size() == 1) return;
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
}

double triangle_area (const pt& p1, const pt& p2, const pt& p3) {
    return abs((double) p1.x * p2.y +
               (double) p2.x * p3.y +
               (double) p3.x * p1.y -
               (double) p1.y * p2.x -
               (double) p2.y * p3.x -
               (double) p3.y * p1.x) / 2.0;
}

double max_triangle_area(vector<pt> p){
    if(p.size() == 3) return triangle_area(p[0], p[1], p[2]);
    convex_hull(p);
    int n = p.size();
    int i = 0;
    int j = i + 1;
    int k = j + 1;
    double res = 0.;
    while (true) {
        double area = triangle_area(p[i], p[j], p[k]);
        while (true) {
            while (true) {
                int nk = (k + 1) % n;
                double narea = triangle_area(p[i], p[j], p[nk]);
                if (narea >= area) {
                    k = nk;
                    area = narea;
                } else {
                    break;
                }
            }
            int nj = (j + 1) % n;
            double narea = triangle_area(p[i], p[nj], p[k]);
            if (narea >= area) {
                j = nj;
                area = narea;
            } else {
                break;
            }
        }
        if (area > res) res = area;
        i++;
        if (i == j) j = (j + 1) % n;
        if (j == k) k = (k + 1) % n;
        if (i == n) break;
    }
    return res;
}

int main(){
    int n, x, y;
    while(scanf("%d", &n) == 1){
        vector<pt> p;
        for(int i = 0; i < n; i++) scanf("%d %d", &x, &y), p.pb(pt(x, y));
        printf("%.1lf\n", max_triangle_area(p));
    }
    return 0;
}
