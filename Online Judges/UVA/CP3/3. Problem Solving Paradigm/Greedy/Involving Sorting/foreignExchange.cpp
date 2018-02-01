#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct pas{
	int first,second;
};

bool acompare(pas a, pas b){return a.first < b.first;}
bool bcompare(pas a, pas b){return a.second < b.second;}

pas a[500010],b[500010];

int main() {
	int n,a1,b1,i;
	int test = 1;
	while(scanf("%d",&n),n){
	//	printf("test %d\n", test++);
		if(n%2==1){
			for(i=0;i<n;i++){
				scanf("%d %d",&a1,&b1);
			}
			printf("NO\n");
		}
		else{
			for(i=0;i<n;i++){
				scanf("%d %d",&a1,&b1);
				a[i].first = a1; a[i].second = b1;
				b[i].first = b1; b[i].second = a1;
			}
			sort(a,a+n,acompare); sort(b,b+n,acompare);
			int bil = a[0].first, idxAwal = 0;
			for(i=1;i<n;i++){
				if(a[i].first!=bil){sort(a+idxAwal,a+i,bcompare); idxAwal = i; bil = a[idxAwal].first;}
			}
			sort(a+idxAwal,a+i,bcompare);

			bil = b[0].first, idxAwal = 0;
			for(i=1;i<n;i++){
				if(a[i].first!=bil){sort(b+idxAwal,b+i,bcompare); idxAwal = i; bil = b[idxAwal].first;}
			}
			sort(b+idxAwal,b+i,bcompare);
			//tampilkan
			/*printf("a:\n");
			for(i=0;i<n;i++){
				printf("%d %d\n",a[i].first,a[i].second);
			}*/
			for(i=0;i<n;i++){
				if(a[i].first!=b[i].first || a[i].second!=b[i].second){break;}
			}
			if(i==n){printf("YES\n");}
			else{printf("NO\n");}

		}
	}
	return 0;
}