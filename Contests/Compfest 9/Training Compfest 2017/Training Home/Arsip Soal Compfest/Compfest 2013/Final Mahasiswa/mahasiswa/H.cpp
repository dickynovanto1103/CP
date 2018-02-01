/* 
 * CompFest 2013 - Competitive Programming
 * Pulau Sederhana
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
#define MAXN 50000

int nkasus;
int n;
vector<int> adlis[MAXN], radlis[MAXN];
int anak[MAXN];
long long tot;

// root the tree!
void ruted(int x, int par){
   REP(i,adlis[x].size()){
      int v = adlis[x][i];
      
      if (v != par){
         radlis[x].pb(v);
         ruted(v, x);
      }
   }
}

// compute x's child
void canak(int x){
   anak[x] = 1;
   
   REP(i,radlis[x].size()){
      int v = radlis[x][i];
      
      canak(v);
      anak[x] += anak[v];
   }
}

// compute solution
void rek(int x){
   REP(i,radlis[x].size()){
      int v = radlis[x][i];
      
      rek(v);
      
      // this edge contribute to the solution:
      // (anak[0] - anak[v]) * anak[v]
      tot += (long long)(anak[0] - anak[v]) * anak[v];
   }
}  

int main()
{
	scanf("%d", &nkasus);
	REP(jt,nkasus){
	   scanf("%d", &n);
	   REP(i,n){
	      adlis[i].clear();
	      radlis[i].clear();
      }
      
	   int a,b;
	   REP(i,n-1){
	      scanf("%d%d", &a, &b);
	      a--;
	      b--;
	      adlis[a].pb(b);
	      adlis[b].pb(a);
	   }
	   
	   // root the tree
	   ruted(0, -1);
	   
	   // precomputation
	   RESET(anak,0);
      canak(0);
      
      // find answer
      tot = 0;
      rek(0);
        	   
	   printf("%lld\n", 2*tot);
	}
}
