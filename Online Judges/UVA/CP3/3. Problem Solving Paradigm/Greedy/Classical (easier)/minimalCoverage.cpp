#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct pas{
	int awal, akhir;
};

bool acompare(pas a, pas b){return a.awal < b.awal;}
bool bcompare(pas a, pas b){return a.akhir > b.akhir;}

int main() {
	int tc,i,j,n,test=1;
	pas a[100010];
	scanf("%d",&tc);
	while(tc--){
		if(test==2){printf("\n");}
		scanf("%d",&n);
		int i = 0;
		while(scanf("%d %d",&a[i].awal,&a[i].akhir),(a[i].awal || a[i].akhir)){
			i++;
		}
		int m = i;
		sort(a,a+m,acompare);

		int idx = 0, curbil = a[0].awal;
		for(i=0;i<m;i++){
			if(a[i].awal > curbil){sort(a+idx,a+i,bcompare); idx = i; curbil = a[i].awal;}
		}
		sort(a+idx,a+m,bcompare);
		/*printf("terurut akhir:\n");
		for(i=0;i<m;i++){
			printf("%d %d\n",a[i].awal,a[i].akhir);
		}*/
		int flag = 0, right = 0;
		pas ans[100010];
		for(i=0,j=0;i<m;i++){
			int ch = -1;
			int temp = right;
			while(j<m && a[j].awal <= right){
				if(temp < a[j].akhir){
					temp = a[j].akhir;
					ch = j;
					ans[i].awal = a[j].awal; ans[i].akhir = a[j].akhir;//mencatat solusi
				}
				j++;
			}

			if(ch==-1){break;}
			if(temp >= n){
				printf("%d\n",i+1);
				for(int k=0;k<i+1;k++){
					printf("%d %d\n",ans[k].awal,ans[k].akhir);
				}
				flag = 1;
				break;
			}
			right = temp;
		}
		if(!flag){printf("0\n");}
		test=2;
	}
	return 0;
}