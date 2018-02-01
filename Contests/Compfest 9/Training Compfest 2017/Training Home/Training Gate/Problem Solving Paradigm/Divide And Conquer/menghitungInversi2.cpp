#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll ans;
int arr1[100010],arr2[100010],b[100010];

void merge(int a[], int kiri, int tengah, int kanan){
	int kiri1,kiri2,i;
	
	kiri1 = kiri; kiri2 = tengah+1; i=kiri;
	while(kiri1<=tengah && kiri2<=kanan){
		if(a[kiri1]<=a[kiri2]){
			b[i]=a[kiri1]; kiri1++;
		}else{
			b[i]=a[kiri2]; kiri2++;
		}
		i++;
	}
	//cek jika masih ada elemen bagian kiri array a
	while(kiri1<=tengah){
		b[i]=a[kiri1];
		kiri1++; i++;
	}
	//cek jika masih ada elemen bagian kanan array a
	while(kiri2<=kanan){
		b[i]=a[kiri2];
		kiri2++; i++;
	}
	for(i=kiri;i<=kanan;i++){a[i]=b[i];}
}

void mergeSort(int a[], int i, int j){
	if(i<j){
		int k = (i+j)/2;
		mergeSort(a,i,k);
		mergeSort(a,k+1,j);
		
		int cnt1 = 0;
		for(int idx=i;idx<=k;idx++){arr1[cnt1] = a[idx]; cnt1++;}
		int cnt2 = 0;
		for(int idx=k+1;idx<=j;idx++){arr2[cnt2] = a[idx]; cnt2++;}
		/*printf("arr1:");
		for(int idx=0;idx<cnt1;idx++){
			printf(" %d",arr1[idx]);
		}
		printf("\n");
		printf("arr2:");
		for(int idx=0;idx<cnt2;idx++){
			printf(" %d",arr2[idx]);
		}
		printf("\n");*/
		//printf("j: %d\n",j);
		//printf("banyak array1: %d array2: %d\n",cnt1,cnt2);
		for(int idx = 0;idx<cnt1;idx++){
			ll indeks = lower_bound(arr2,arr2+cnt2,arr1[idx]) - arr2;
			/*printf("mencari arr1[%d]: %d\n",idx,arr1[idx]);
			printf("idx: %d indeks: %d\n",idx,indeks);*/
			if(indeks==cnt2){
				ans+=(indeks);
				//printf("masuk tambahan: %d ans jd: %d\n",(indeks),ans);
			}else{
				
				/*printf("yang dicari: a[%d]: %d\n",idx,a[idx]);
				printf("a[%d]: %d\n",indeks+kiri2,a[indeks+kiri2]);
				printf("kiri2: %d\n",kiri2);*/
				while(indeks>=0 && arr2[indeks]>=arr1[idx]){indeks--;}
				ll tambahan = (indeks+1);
				//printf("ans sebelum: %d\n",ans);
				ans+=tambahan;
				//printf("tambahan: %d ans: %d\n",tambahan,ans);	
			}
			
		}
		merge(a,i,k,j);
	}
}

int main() {
	int a[100010],i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	ans = 0;
	mergeSort(a,0,n-1);
	/*printf("array terurut:\n");
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");*/
	printf("%lld\n",ans);
	return 0;
}