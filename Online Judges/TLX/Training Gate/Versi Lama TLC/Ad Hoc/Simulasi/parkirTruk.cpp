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

int counter[110];

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int i,j;
	for(i=0;i<3;i++){
		int awal,akhir;
		scanf("%d %d",&awal,&akhir);
		for(j=awal;j<akhir;j++){
			counter[j]++;
		}
	}
	int ans = 0;
	for(i=1;i<=100;i++){
		//printf("counter[%d]: %d\n",i,counter[i]);
		if(counter[i]==1){ans+=a;}
		else if(counter[i]==2){ans+=(2*b);}
		else if(counter[i]==3){ans+=(3*c);}
	}
	printf("%d\n",ans);
	return 0;
};