/* 
 * CompFest 2013 - Competitive Programming
 * Jumlahan Bilangan
 * Author : Muhammad Febrian Ramadhana
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

#define PB push_back
#define mp make_pair
#define M 1000000007

int nkasus;
int n,m;
int dp[502][2002];

int rek(int di, int sisa){
   if (di == 0){
      // base
      if (sisa == 0){
         return 1;
      }else{
         return 0;
      }
   }else if (dp[di][sisa] != -1){
      // memo
      return dp[di][sisa];
   }else{
      // reccurence
      dp[di][sisa] = 0;
      FOR(x,1,9){
         if (sisa-x >= 0){
            dp[di][sisa] += rek(di-1, sisa-x);
            dp[di][sisa] %= M;
         }
      }
      return dp[di][sisa];
   }
}

int main()
{
	scanf("%d", &nkasus);
	
   RESET(dp,-1);
	REP(jt,nkasus){
	   scanf("%d%d", &n, &m);
	   
	   // no need to reinitialize DP memo!
	   printf("%d\n", rek(m,n));
	}
}
