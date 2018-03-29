#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,a,b;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++) {
		scanf("%d %d",&a,&b);
		printf("Case #%d: ",tt);
		if(a > b){printf("impossible\n");}
		else if(a==b){printf("%d\n",a);}
		else{
			int selisih = b-a;
			int mod = selisih%12;
			if(mod!=0){printf("impossible\n");}
			else{
				int hasil = selisih/12;
				printf("%d\n",7*hasil + a);	
			}
			
			
		}
	}
	return 0;
};