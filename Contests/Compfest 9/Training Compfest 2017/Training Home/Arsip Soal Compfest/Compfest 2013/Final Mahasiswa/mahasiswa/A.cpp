/* 
 * CompFest 2013 - Competitive Programming
 * Pangeran Berti
 * Author : Alham Fikri Aji
 * Code   : Cakra Wishnu Wardhana
 */
 
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cassert>
#include <ctime>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define sz(a) int((a).size())
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define uniq(c) sort(all((c))); (c).resize(unique(all((c))) - (c).begin())
#define lobo(c, x) (int) (lower_bound(all((c)), (x)) - (c).begin())
#define upbo(c, x) (int) (upper_bound(all((c)), (x)) - (c).begin())
#define mii(a, b) if(b < a) a = b
#define maa(a, b) if(b > a) a = b

#define INF 2000000000
#define EPS 1e-5
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define X first
#define Y second
#define DEBUG(x) printf("debugging.. %d\n", x);
#ifdef TEST
#define deb(...) fprintf(stderr, __VA_ARGS__)
#else 
#define deb(...)
#endif
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

string tobin(int x, int len) {
   string c;
   while(x) { c.PB(x%2+'0'); x /= 2; }
   while(sz(c) < len) c.PB('0');
   reverse(all(c));
   return c;
}
//------------------------------


int T, N, W[25];
string K[25];


int main() {
   scanf("%d", &T);
   
   for ( int tc = 0; tc < T; tc++ ) {
      scanf("%d", &N);
      
      int sumall = 0;
      map <string, int> cnt;
      
      for ( int i = 0; i < N; i++ ) {
         char s[105];
         scanf("%s", &s);
         
         K[i] = s;
         scanf("%d", &W[i]);
         scanf("%s", &s);
         
         cnt[K[i]] += W[i];
         sumall += W[i];
      }
      
      int ma = -1;
      
      tr(cnt, i) tr(cnt, j) {
         int sum = i->S;
         if ( j->F != i->F ) sum += j->S;
         ma = max(ma, sum);
      }
      
      printf("%d Juta\n", sumall-ma);
   }
   
   return 0;
}
