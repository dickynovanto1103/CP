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
	int d,t,v1,v2,i;
	scanf("%d %d %d %d",&d,&t,&v1,&v2);
	int time = 0;
	int selisih = v2 - v1;
	// printf("d awal: %d selisih: %d\n",d,selisih);
	for(i=0;i<t;i++){
		d+=selisih;
		// printf("d jadi: %d\n",d);
		time++;
		if(d<=0){break;}
	}
	while(d>0){
		d-=v1;
		// printf("d sekarang jadi: %d\n",d);
		time++;
	}
	printf("%d\n",time);

	return 0;
};