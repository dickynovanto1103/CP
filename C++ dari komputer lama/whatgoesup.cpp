#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

#define MAX_N 100000

void reconstructPrint(int end,int a[], int p[]){
	int x=end;
	stack <int> s;
	for(;p[x]>=0;x=p[x]) s.push(a[x]);
	printf("%d\n",a[x]);
	for(;!s.empty();s.pop()) printf("%d\n",s.top());
}

int main(){
	int temp,i,lis,lis_end,pos;
	int L[MAX_N],P[MAX_N],L_id[MAX_N],a[MAX_N];
	i=0;
	while(scanf("%d",&temp)!=EOF){
		a[i]=temp;
		i++;
	}
	int ukuran=i;
	//for(i=0;i<a.size();i++){printf("%d ",a[i]);}
	lis=0; lis_end=0;
	for(i=0;i<ukuran;i++){
		pos=lower_bound(L,L+lis,a[i])-L;
		//printf("at i = %d, pos = %d, dan lis sekarang %d\n",i,pos,lis);
		L[pos]=a[i];
		L_id[pos]=i;
		P[i] = pos ? L_id[pos-1] : -1;

		if(pos+1 >= lis){//update lis
			lis=pos+1;
			lis_end=i;
		}

		/*printf("Considering element a[%d] = %d\n", i, a[i]);
	    printf("LIS ending at a[%d] is of length %d: ", i, pos + 1);
	    reconstructPrint(i, a, P);
	    print_array(L, lis);
	    printf("LIS end adalah %d\n",lis_end);
	    printf("\n");*/
	}
	printf("%d\n-\n",lis);
	reconstructPrint(lis_end,a,P);
	return 0;
}