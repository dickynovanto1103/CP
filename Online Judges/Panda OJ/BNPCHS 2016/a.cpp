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
	int hh,mm,x,y,z;
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Kasus #%d: ",tt);
		scanf("%d:%d %d %d %d",&hh,&mm,&x,&y,&z);
		int lama = z;
		if(x>=z){
			mm+=lama;
			while(mm>=60){
				mm-=60;
				hh++;
				hh%=24;
			}
		}else{
			ll loop = (z-x)/x;
			if((z-x)%x!=0){loop++;}
			lama+=(loop*y);
			mm+=lama;
			while(mm>=60){
				mm-=60;
				hh++;
				hh%=24;
			}
		}
		printf("%.2d:%.2d\n",hh,mm);
	}
	return 0;
};