#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;
#define MAX_N 10010
struct a{
	int l;
	int m;
};

void reconstructPrint(int end, int a[], int p[]) {
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  printf("[%d", a[x]);
  for (; !s.empty(); s.pop()) printf(", %d", s.top());
  printf("]\n");
}
bool acompare(a lhs, a rhs){return lhs.l < rhs.l;}
bool mcompare(a lhs, a rhs){return lhs.m < rhs.m;}
int main(){
	int n,i,pos,lis,lis_end,array[MAX_N],L[MAX_N],L_id[MAX_N],P[MAX_N],curidx;
	a arr[MAX_N];
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){scanf("%d %d",&arr[i].l, &arr[i].m);}
		//for(i=0;i<n;i++){printf("%d %d\n",arr[i].l, arr[i].m);}
		//printf("sorted\n");
		sort(arr,arr+n,acompare);
		//for(i=0;i<n;i++){printf("%d %d\n",arr[i].l, arr[i].m);}
		/*printf("sorted awal\n");
		for(i=0;i<n;i++){printf("%d %d\n",arr[i].l, arr[i].m);}*/
		curidx=0;
		i=0;
		while(i<n){
			while(arr[i].l==arr[curidx].l){i++;}
			sort(arr+curidx,arr+i,mcompare);
			curidx=i;
		}
		/*printf("sorted\n");
		for(i=0;i<n;i++){printf("%d %d\n",arr[i].l, arr[i].m);}*/
		lis=0;lis_end=0;
		for(i=0;i<n;i++){array[i]=arr[i].m;}
		for(i=0;i<n;i++){
			pos=lower_bound(L,L+lis,array[i])-L;
			if(i>0){
				if(L[pos]==array[i]){pos=lis;}
			}
			L[pos]=array[i];
			L_id[pos]=i;
			P[i] = pos ? L_id[pos-1]:-1;
			if(pos+1 > lis){
				lis=pos+1;
				lis_end=i;
			}
			/*printf("LIS sekarang dengan panjang %d adalah\n",lis);
			reconstructPrint(i,array,P);*/
		}
		/*printf("LIS akhir dengan panjang %d:\n",lis);
		reconstructPrint(lis_end,array,P);*/
		printf("%d\n",lis);
	}
	printf("*\n");
	return 0;
}