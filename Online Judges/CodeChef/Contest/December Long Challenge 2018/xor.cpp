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

const int maxn = 5e4 + 4;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		int a[maxn];
		int sor[maxn];
		for(i=1;i<=n-2;i++){
			int pertama = i;
			int kedua = i+1;
			int ketiga = i+2;
			printf("1 %d %d %d\n",i,i+1,i+2);
			fflush(stdout);
			int hasil;
			scanf("%d",&hasil);
			
			sor[i] = hasil;
		}
		printf("1 1 4 2\n");
		fflush(stdout);
		int jawab;
		scanf("%d",&jawab);
		// if(jawab==1){assert(false);}
		a[2] = sor[1]^sor[2]^jawab;

		printf("1 2 5 1\n");
		fflush(stdout);
		scanf("%d",&jawab);
		a[1] = sor[2]^sor[3]^jawab;

		for(i=3;i<=n;i++){
			a[i] = sor[i-2]^a[i-2]^a[i-1];
		}
		
		printf("2");
		for(i=1;i<=n;i++){
			printf(" %d",a[i]);
		}
		printf("\n");
		fflush(stdout);

		int jawaban;
		scanf("%d",&jawaban);
		if(jawaban == -1){return 0;}
	}
	return 0;
};