/* 
 * CompFest 2013 - Competitive Programming
 * Pilihan Ganda Campuran
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
#include <queue>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define RESET(c,v) memset(c, v, sizeof(c))

#define PB push_back
#define mp make_pair
#define MAXN 150
#define INF 2123123123

int nkasus;
int par[MAXN];
int admat[MAXN][MAXN];
vector<int> adlis[MAXN];
int st,ss,ns,nt;
int u,v,w;

void add_ej(int a, int b, int c){
   admat[a][b] += c;
   
   adlis[a].PB(b);
   adlis[b].PB(a);
}

int f;
void augment(int x, int d){
   if (x == ss){
      f = d;
   }else{
      augment(par[x], min(d, admat[par[x]][x]));
      
      admat[par[x]][x] -= f;
      admat[x][par[x]] += f;
   }
}

// normal Edmond's Karp
int mf(){
   int ret = 0;
   
   while (1){
      queue<int> q;
      RESET(par,-1);
      f = 0;
      
      q.push(ss);
      par[ss] = ss;
      while (!q.empty()){
         u = q.front();
         q.pop();
         
         if (u == st) break;
         
         REP(i,adlis[u].size()){
            v = adlis[u][i];
            
            if ((admat[u][v] > 0) && (par[v] == -1)){
               par[v] = u;
               q.push(v);
            }   
         }
      }
      
      if (u == st){
         augment(st, INF);
      }else{   
         break;
      }
      
      ret += f;
   }
   
   return ret;
}   


int main()
{
   scanf("%d", &nkasus);
   REP(jt,nkasus){
      // clean up
      REP(i,MAXN){
         adlis[i].clear();   
      }
      RESET(admat,0);
   
      scanf("%d%d", &ns, &nt);
      REP(i,ns){
         int m,a;
         scanf("%d", &m);
         REP(j,m){
            scanf("%d", &a);
            
            // i'th problem has a solution to (a-1)'th answer choice
            add_ej(i, ns + a-1, 1);
         }
      }      
      
      // connecting super source
      ss = ns + nt;
      st = ns + nt + 1;
      REP(i,ns){
         add_ej(ss, i, 1);
      }
      // connecting super sink
      REP(i,nt){
         int a;
         scanf("%d", &a);
         add_ej(ns + i, st, a);
      }
      
      // do max flow
      printf("%d\n", mf());
   }
}
