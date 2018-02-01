/* 
 * CompFest 2013 - Competitive Programming
 * Pembiakan Hibrida
 * Author : William Gozali
 * Code   : William Gozali
 * Template by Ashar Fuadi
 */

#include <cstdio>
#include <cstring>

#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define RESET(c,v) memset(c, v, sizeof(c))

#define pb push_back
#define mp make_pair
#define LL long long
#define MAXN 100001
#define INF 2123123123

struct titik{
   LL x,y;
   int id;
};

int nkasus;
int n,nq,orin;
titik ar[MAXN];
titik qs[MAXN];
LL ans[MAXN];

int cvx[MAXN];
int p,pc;

LL norm(titik a){
   LL dx = a.x - ar[0].x;
   LL dy = a.y - ar[0].y;
   return dx*dx + dy*dy;
}

LL det(titik a, titik b, titik c){
   return (a.x*b.y) + (b.x*c.y) + (c.x*a.y) - (a.x*c.y) - (b.x*a.y) - (c.x*b.y);
}

LL dot(titik a, titik b){
   return a.x*b.x + a.y*b.y;
}

bool by_grad(titik a, titik b){
   return a.y*b.x < a.x*b.y;
}

bool by_piv(titik a, titik b){
   LL h = det(ar[0], a, b);
   if (h != 0){
      return h > 0;
   }else{
      return norm(a) < norm(b);
   }
}  

// normal Graham's Scan
void convex_hull(){
   REP(i,n){
      if ((ar[i].y < ar[0].y) || ((ar[i].y == ar[0].y) && (ar[i].x > ar[0].x))){
         swap(ar[i], ar[0]);
      }
   }
   
   sort(ar+1, ar+n, by_piv);
   
   cvx[0] = 0;
   cvx[1] = 1;
   pc = 2;
   p = 2;
   while (p < n){
      if (det(ar[cvx[pc-2]], ar[cvx[pc-1]], ar[p]) > 0){
         cvx[pc++] = p++;
      }else{
         pc--;
      }
   }
}

vector<int> feet;
void gather_feet(){
   // finds point with smallest x coordinate
   LL minx = INF;
   REP(i,pc){
      minx = min(minx, ar[cvx[i]].x);
   }
   
   // walk backward (clockwise) until meet the smallest x point
   feet.clear();
   int d = 0;
   while (ar[cvx[d]].x != minx){
      feet.pb(cvx[d]);
      
      d--;
      if (d < 0) d = pc-1;
   }
   feet.pb(cvx[d]);
   
   // double last element for simplicity
   feet.pb(feet.back());
}

void work(){
   // for each query, finds its most suitable point
   // note that it is always monotonic!
   int d = 0;
   REP(i,nq){
      while (dot(qs[i], ar[feet[d+1]]) < dot(qs[i], ar[feet[d]])){
         d++;
      }  
      
      ans[qs[i].id] = dot(qs[i], ar[feet[d]]);
   }
   
   REP(i,nq){
      printf("%lld\n", ans[i]);
   }  
}  

int main()
{
//   scanf("%d", &nkasus);
   nkasus = 1;
   REP(jt,nkasus){
      scanf("%d%d", &n, &nq);
      
      REP(i,n){
         scanf("%lld %lld", &ar[i].x, &ar[i].y);
      }
      convex_hull();    
      
      // loads all queries
      REP(i,nq){
         scanf("%lld %lld", &qs[i].x, &qs[i].y);        
         qs[i].id = i;
      }
      
      sort(qs, qs + nq, by_grad);
      reverse(qs, qs + nq);
      
      // finds "feet", the lower left of convex hull
      gather_feet();
      // finds answer
      work();
   }   
}
