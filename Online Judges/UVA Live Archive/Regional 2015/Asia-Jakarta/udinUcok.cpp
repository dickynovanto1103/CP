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
	int tc,n,i,j;
	
	n=1050;
	/*grun[0] = 0; grun[1] = 1; grun[2] = 1; grun[3] = 2;
	for(i=4;i<=n;i++){
		set<int> s;
		s.insert(grun[i-3]); s.insert(grun[i-2]);
		j=1;
		int k = i-3-j;
		while(j<=k){
			k = i-3-j;
			s.insert(grun[j]^grun[k]);
			j++;
		}
		for(j=0; ;j++){
			if(!s.count(j)){
				grun[i] = j;
				break;
			}
		}
	}*/
	int grunPertama[] = {1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 0, 5, 2, 2, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 2, 7, 4, 0,1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 2, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7, 4, 8};
	//int sizeGrunPertama = sizeof(grunPertama)/sizeof(grunPertama[0]);
	
	//int a[]= {1,2,3,4};
	//printf("size: %d\n",sizeof(a)/sizeof(a[0]));
	int grun[] = {1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,9,3,3,0,1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7, 4, 8};
	int sizeGrunPertama = sizeof(grunPertama)/sizeof(grunPertama[0]);
	int sizeGrun = sizeof(grun)/sizeof(grun[0]);
	// printf("size pertama: %d\n",sizeGrunPertama);
	// printf("size: %d\n",sizeGrun);
	scanf("%d",&tc);
	int test = 1;
	while(tc--){
		printf("Case #%d: ",test++);
		scanf("%d",&n);
		if(n<=68){
			if(grunPertama[n-1]==0){printf("UCOK\n");}
			else{printf("UDIN\n");}	
		}else{
			n%=34; n--;
			if(n<0){n=33;}
			if(grun[n]==0){printf("UCOK\n");}
			else{printf("UDIN\n");}
		}
		
		//printf("%d\n",grun[n]);
	}
	// for(i=1;i<=n;i++){
	// 	if(i>1){printf(" ");}
	// 	printf("%d",grun[i]);
	// }
	// printf("\n");
	return 0;
};