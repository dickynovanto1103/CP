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
#define maxn 100010

void print_array(int a[], int n){
	for(int i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");
}

void reconstruct_print(int end, int a[], int p[]){
	int x = end;
	stack<int> s;
	for(; p[x]>=0; x=p[x]){s.push(a[x]);}
	printf("[%d",a[x]);
	for(;!s.empty();s.pop()){printf(", %d",s.top());}
	printf("]\n");
}
int main() {
	int n,i,a[maxn];
	int L[maxn], L_id[maxn], P[maxn];

	int lis = 0, lis_end = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	reverse(a,a+n);
	for(i=0;i<n;i++){
		int pos = lower_bound(L,L+lis,a[i]) - L;
		L[pos] = a[i];
		L_id[pos] = i;
		P[i] = pos? L_id[pos-1] : -1;
		if(pos+1 > lis){
			lis = pos+1;
			lis_end = i;
		}
		//end of main LIS algo
		/*printf("Considering element A[%d] = %d\n", i, a[i]);
	    printf("LIS ending at A[%d] is of length %d: ", i, pos + 1);
	    reconstruct_print(i, a, P);
	    printf("sinikah\n");
	    print_array(L, lis);
	    printf("\n");*/
	}
	printf("%d\n",lis);
	return 0;
}