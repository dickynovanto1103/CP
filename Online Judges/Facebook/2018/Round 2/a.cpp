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
	int tc,i,j;
	int n,k;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d %d",&n,&k);
		if(n==2){
			printf("0\n");
			printf("1\n1 2 1\n");
		}else{
			int sum = k;
			int sum2 = 0;
			int banyakIterasiMaks = min(k-1, n-1);
			int banyakIterasiMaksAwal = banyakIterasiMaks;
			for(i=k-1;i>=1;i--){
				if(banyakIterasiMaks == 0){break;}
				sum2 += i;
				banyakIterasiMaks--;
				if(banyakIterasiMaks == 0){break;}
			}

			if(sum2 >= sum){
				printf("%d\n",sum2-sum);
				printf("%d\n1 %d %d\n",banyakIterasiMaksAwal+1,n,k);
				for(i=1;i<=banyakIterasiMaksAwal;i++){
					if(i==banyakIterasiMaksAwal){
						printf("%d %d %d\n",i,n,k-i);
					}else{
						printf("%d %d %d\n",i,i+1,k-i);	
					}
					
				}
			}else{
				printf("0\n");
				printf("1\n1 %d 1\n",n);
			}
		}
	}
	return 0;
};