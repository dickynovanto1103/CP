#include <cstdio>
#include <algorithm>

using namespace std;
#define MAX 10000


int main(){
	int n,i,angka,q,idx;
	int a[MAX];
	//printf("masukkan banyak elemen:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n);
	printf("array:\n");
	for(i=0;i<n;i++){printf("%d ",a[i]);}
	printf("\n");
	//printf("masukkan banyaknya query\n");
	scanf("%d",&q);
	while(q--){
		//printf("masukkan angka yang mau dicek\n");
		scanf("%d",&angka);
		printf("angka: %d\n",angka);
		idx=lower_bound(a,a+n,angka)-a;
		printf("lower: a[%d] dengan nilai %d\n",idx,a[idx]);//menghasilkan indeks minimal
		idx=upper_bound(a,a+n,angka)-a;
		printf("upper: a[%d] dengan nilai %d\n",idx,a[idx]);//upper bound menghasilkan indeks yang nilai array indeks tersebut diatas angka yang dimasukkan
	}
	return 0;
}