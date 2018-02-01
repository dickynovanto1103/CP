/* 
 * CompFest 2013 - Competitive Programming
 * Ini Prima?
 * Author : Gede Wahyu Adi Pramana
 * Code   : Gede Wahyu Adi Pramana
 */

#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
#define pb push_back
#define XMAX 1000000

vector<int> p;
bool us[XMAX+10],use[XMAX+10];;
void generate(int X){
   memset(use,false,sizeof(use));
   for (int i=2,j=(int)sqrt(X);i<=j;++i){
      if (!us[i]){
         for (int k=i*i;k<=X;k+=i){
            use[k]=true;
         }
      }
   }
   for (int i=2;i<=X;++i) if (!use[i]) p.pb(i); 
}
void solve(){
   int n,m;
   scanf("%d",&n);
   memset(us,false,sizeof(us));
   bool ok = true;
   while(n--){
      scanf("%d",&m);
      int i=0;
      if (!use[m]){
         if (us[m]) ok = false;
         us[m]=true;
         m = 0;
      }
      while(m>1){
         if (m%p[i]==0){
            if (us[p[i]]){
               ok = false;
               m = 0;
            } else {
               us[p[i]]=true;
               while(m%p[i]==0) m/=p[i];
            }
         }
         ++i;
      }
   }
   if (ok) puts("YA");
   else puts("TIDAK");
}
int main(){
   int tc;
   generate(XMAX);
   scanf("%d",&tc);
   while(tc--) solve();
}
