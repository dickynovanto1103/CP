/* 
 * CompFest 2013 - Competitive Programming
 * DNA Misterius
 * Author : Cakra Wishnu Wardhana
 * Code   : Cakra Wishnu Wardhana
 */

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cassert>

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

const int MXN = 100000;
char s[MXN+5];
int n, ar[MXN+5];
int stsum[4*MXN+5], lzsum[4*MXN+5], stmin[4*MXN+5], lzmin[4*MXN+5];

void build(int node, int be, int en) {
   if ( be == en ) {
      stsum[node] = ar[be];
      stmin[node] = ar[be];
      
      return;
   }
   
   int mid = (be + en) >> 1, nl = 2*node+1, nr = 2*node+2;
   
   build(nl, be, mid);
   build(nr, mid+1, en);
   
   stsum[node] = stsum[nl] + stsum[nr];
   stmin[node] = min(stmin[nl], stmin[nr]);
}

inline void prop(int node, int be, int en, int lsum, int lmin) {
   // printf("{bef} node=%d, (%d, %d), stsum=%d, stmin=%d\n", node, be, en, stsum[node], stmin[node]);
   stsum[node] += lsum*(en-be+1);
   stmin[node] += lmin;
   
   lzsum[node] += lsum;
   lzmin[node] += lmin;
   
   // printf("{aft} node=%d, (%d, %d), stsum=%d, stmin=%d\n", node, be, en, stsum[node], stmin[node]);
}

void update(int node, int be, int en, int i, int j, int val) {
   if ( i <= be && en <= j ) {
      prop(node, be, en, val, val);
      return;
   }
   
   int mid = (be + en) >> 1, nl = 2*node+1, nr = 2*node+2;
   
   if ( lzsum[node] != 0 || lzmin[node] != 0 ) {
      prop(nl, be, mid, lzsum[node], lzmin[node]);
      prop(nr, mid+1, en, lzsum[node], lzmin[node]);
      lzsum[node] = 0;
      lzmin[node] = 0;
   }
   
   if ( mid >= i )      update(nl, be, mid, i, j, val);
   if ( mid+1 <= j )   update(nr, mid+1, en, i, j, val);
   
   stsum[node] = stsum[nl] + stsum[nr];
   stmin[node] = min(stmin[nl], stmin[nr]);
}

int querysum(int node, int be, int en, int i, int j) {
   if ( j < be || i > en )      return 0;
   if ( i <= be && en <= j )   return stsum[node];
   
   int mid = (be + en) >> 1, nl = 2*node+1, nr = 2*node+2;
   
   if ( lzsum[node] != 0 || lzmin[node] != 0 ) {
      prop(nl, be, mid, lzsum[node], lzmin[node]);
      prop(nr, mid+1, en, lzsum[node], lzmin[node]);
      lzsum[node] = 0;
      lzmin[node] = 0;
   }
   
   int res = 0;
   if ( mid >= i )      res = querysum(nl, be, mid, i, j);
   if ( mid+1 <= j )   res += querysum(nr, mid+1, en, i, j);
   
   // printf("$ querysum(%d, [%d, %d], [%d, %d]=%d\n", node, be, en, i, j, res);
   
   return res;
}


int querymin(int node, int be, int en, int i, int j) {
   if ( i <= be && en <= j )   return stmin[node];
   
   int mid = (be + en) >> 1, nl = 2*node+1, nr = 2*node+2;
   
   if ( lzsum[node] != 0 || lzmin[node] != 0 ) {
      prop(nl, be, mid, lzsum[node], lzmin[node]);
      prop(nr, mid+1, en, lzsum[node], lzmin[node]);
      lzsum[node] = 0;
      lzmin[node] = 0;
   }
   
   int res = 0;
   if ( mid >= i )      res = querymin(nl, be, mid, i, j);
   if ( mid+1 <= j )   res = min(res, querymin(nr, mid+1, en, i, j));
   
   return res;
}

inline void flip(int i) {
   if ( s[i] == '(' ) {
      s[i] = ')';
      update(0, 0, n-1, i, n-1, -2);
   }
   else {
      s[i] = '(';
      update(0, 0, n-1, i, n-1, 2);
   }
}

inline void flip(int i, bool isQuery) {   flip(i); if ( isQuery ) { printf("1 %d\n", i); if ( rand()%5 == 0 ) printf("0\n"); } }
inline int querysum(int i, int j) { return querysum(0, 0, n-1, i, j); }
inline int querymin(int i, int j) { return querymin(0, 0, n-1, i, j); }
inline bool getBracket(int i) { return querysum(i, i)-querysum(i-1, i-1) == 1; }
inline void printBracket() {
   for ( int i = 0; i < n; i++ ) printf("%c", getBracket(i) ? '(' : ')'); puts("");
}
inline void printBracket(string prefix) {
   printf("%s", prefix.c_str()); printBracket();
}

inline void init() {
   // precondition: n, s
   memset(stsum, 0, sizeof(stsum));
   memset(lzsum, 0, sizeof(lzsum));
   memset(stmin, 0, sizeof(stmin));
   memset(lzmin, 0, sizeof(lzmin));
   
   int sum = 0;
   for ( int i = 0; i < n; i++ ) {
      if ( s[i] == '(' )    sum++;
      else            sum--;
      ar[i] = sum;
   }
   
   build(0, 0, n-1);
}

inline bool validate() {
   int qsum = querysum(n-1, n-1),
      qmin = querymin(0, n-1);
   
   // printf("[qsum=%d, qmin=%d]\n", qsum, qmin);
   
   if ( qsum == 0 && qmin >= 0 )
      printf("Y");
   else
      printf("T");
}

void solution() {
   int T; scanf("%d", &T);
   
   for ( int tc = 0; tc < T; tc++ ) {
      // printf("Kasus %d:\n", tc+1);
      
      scanf("%s", &s);
      n = strlen(s);
      
      assert(1 <= n <= MXN);
   
      init();
   
      int cmd, a, b;
   
      // printBracket();
      int cnt = 0;
      for ( int ii = 1; ; ii++ ) {
         assert(1 <= ii <= MXN);
         
         scanf("%d", &cmd);
      
         // printf("cmd=%d, cnt=%d\n", cmd, cnt++); for ( int xx = 0; xx < 1e7; xx++ );
      
         if ( cmd == 0 ) {
            validate();
         }
         else if ( cmd == 1 ) {
            int k;
            scanf("%d", &k);
         
            // printf("--k=%d\n", k);
         
            flip(k);
         
            // printBracket();
         }
         else break;
      }   
      puts("");
   }
}

void balance(bool isQuery) {
   int pos = 0;
   while ( querymin(0, n-1) < 0 ) {
      while ( querysum(pos, pos) >= 0 ) pos++;
      flip(pos, isQuery);
      pos++;
   }
   // printBracket();   puts("^after ++"); validate();
   
   if ( querysum(0, n-1) > 0 ) {
      for ( int i = n-1; i >= 0; i-- ) {
         if ( querysum(n-1, n-1) == 0 ) break;
         if ( s[i] == '(' ) 
            flip(i, isQuery);
      }
      
      // printBracket(); puts("^after--"); validate();
   }
   
   if ( isQuery ) printf("0\n");
}

void generateTC() {
   int seed = time(0);
   // int seed = 1379511569;
   printf("seed=%d\n", seed);
   srand(seed);
   
   // n = rand()%2000;
   n = 2000;
   if ( n & 1 ) n++;
   
   for ( int i = 0; i < n; i++ ) {
      s[i] = rand()%2 == 1 ? '(' : ')';
   }
   
   init();
   
   validate(); printBracket("bef: ");
   
   balance(false);
   
   // printBracket("aft: ");
   validate();
   
   int NCORRECT = rand()%100;
   for ( int i = 0; i < NCORRECT; i++ ) {
      int K = rand()%100;
      
      for ( int j = 0; j < K; j++ )
         flip(rand()%n, true);
      
      balance(true);
   }
}

int main() {
   solution();   return 0;
   // generateTC(); return 0;
   
   return 0;
}
