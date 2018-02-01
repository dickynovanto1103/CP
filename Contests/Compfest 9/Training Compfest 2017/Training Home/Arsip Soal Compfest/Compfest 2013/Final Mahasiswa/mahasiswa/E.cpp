/* 
 * CompFest 2013 - Competitive Programming
 * Selai Kue
 * Author : Irvan Jahja
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

int nkasus;
int n,m;
double cum[105];
int x,k[105];

int main()
{
   scanf("%d", &nkasus);
   REP(jt,nkasus){
      scanf("%d%d", &n, &m);
      RESET(k,0);
      REP(i,n){
         scanf("%d", &x);
         // counting how many x-factor appeared
         k[x]++;
      }
      
      FOR(j,0,100){
         cum[j] = 1;
      }
      
      REP(i,m){
         double ans = 0;
         FOR(j,0,100){
            ans += cum[j]*(j/100.0)*k[j];
            
            cum[j] *= (100 - j)/100.0;
         }  
         // ans = \sum_{j=0}^{100} {k_j*x_j*(1-x_j)^i}
         printf("%.3lf\n", ans);
      }
   }
}
