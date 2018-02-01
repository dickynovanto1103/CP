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
	int k;
	scanf("%d",&k);
	int mod = k%4;
	ll selisih;
	if(mod==1){
		selisih = k-1;
	}else if(mod==2){
		selisih = k-2;
	}else if(mod==3){
		selisih = k-3;
	}else if(mod==0){
		selisih = k-4;
	}
	int banyakStep = selisih/4;
	int x = 0, y = 0;
	if(mod==1){
		y-=banyakStep;
	}else if(mod==2){
		x = -1;
		x-=banyakStep;
	}else if(mod==3){
		y=1;
		y+=banyakStep;
	}else if(mod==0){
		x=1;
		x+=banyakStep;
	}
	printf("%d %d\n",x,y);

	return 0;
};