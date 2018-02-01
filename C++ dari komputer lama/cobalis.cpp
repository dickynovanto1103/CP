#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;
#define MAX_N 100000


void printArray(int a[],int end){
	int i;
	for(i=0;i<end;i++){
		if(i){printf(", %d",a[i]);}
		else{printf("LIS is now: [%d",a[i]);}
	}
	printf("]\n");
}

void reconstructPrint(int end,int a[],int p[]){
	int x=end;
	stack<int> s;
	for(;p[x]>=0;x=p[x]) s.push(a[x]);
	printf("[%d",a[x]);//x sudah di awal
	for(;!s.empty();s.pop()){printf(", %d",s.top());}
	printf("]\n");
}

int main(){
	int n = 11, A[] = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};
	int L[MAX_N],L_id[MAX_N],P[MAX_N];
	int idx,lis,lis_end,i;
	lis=0;
	for(i=0;i<n;i++){
		idx=lower_bound(L,L+lis,A[i])-L;//cari indeks dimana nilai indeks awal L yang lebih besar atau sama dengan A[i]
		//kalau A[i] lebih besar dr apapun elemen di L, mengembalikan nilai indeks terakhir L
		L[idx]=A[i];
		L_id[idx]=i;
		P[i]= idx ? L_id[idx-1] : -1;
		if(idx+1 > lis){
			lis=idx+1;
			lis_end=i;
		}
		printf("Considering element A[%d] = %d\n",i,A[i]);
		printf("LIS ending at A[%d] is of length %d: ",i,lis);
		reconstructPrint(i,A,P);
		printArray(L,lis);
	}
	printf("Final LIS is: ");
	reconstructPrint(lis_end,A,P);
	return 0;
}