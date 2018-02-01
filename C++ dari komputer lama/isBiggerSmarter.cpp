#include <bits/stdc++.h>

using namespace std;
#define maxn 1010
struct data{
	int idx;
	int w;
	int iq;
};

bool acompare(data lhs, data rhs){return lhs.iq > rhs.iq;}

void print_array(const char *s, int a[], int n) {
  for (int i = 0; i < n; ++i) {
    if (i) printf(", ");
    else printf("%s: [", s);
    printf("%d", a[i]);
  }
  printf("]\n");
}

void reconstructPrint(int end, data a[], int p[]){
	int x=end;
	stack <int> s;
	for(;p[x]>=0;x=p[x]) s.push(a[x].idx);
	printf("%d\n",a[x].idx);
	for(;!s.empty();s.pop()) printf("%d\n",s.top());
}

int main(){
	data a[maxn],L[maxn],L_id[maxn],LTemp[maxn];
	int i,n,temp[maxn],temp_id[maxn],P[maxn];
	i=0;
	while(scanf("%d %d",&a[i].w, &a[i].iq)!=EOF){
		a[i].idx=i;
		i++;
	}
	n=i;
	printf("before sorted");
	for(i=0;i<n;i++){printf("i: %d, w: %d, iq: %d\n",a[i].idx,a[i].w,a[i].iq);}
	sort(a,a+n,acompare);
	printf("sorted:\n");
	for(i=0;i<n;i++){printf("i: %d, w: %d, iq: %d\n",a[i].idx,a[i].w,a[i].iq);}
	int lis,lis_end,pos;
	lis=0;lis_end=0;
	for(i=0;i<n;i++){
		pos=lower_bound(temp,temp+lis,a[i].w)-temp;
		temp[pos]=a[i].w;
		temp_id[pos]=i;
		P[i]=pos ? temp_id[pos-1] : -1;
		L[pos].w=a[i].w;
		L[pos].idx=a[i].idx;
		L[pos].iq=a[i].iq;
		if(pos+1 > lis){
			lis=pos+1;
			lis_end=i;
		}
		/*printf("Considering element a[%d].w = %d\n", i, a[i].w);
	    printf("LIS ending at A[%d] is of length %d: ", i, pos + 1);
	    reconstructPrint(i, a, P);
	    print_array("L is now", temp, lis);
	    printf("\n");*/
	}
	/*printf("%d\nlis:\n",lis);
	reconstructPrint(lis_end,a,P);*/
	int indeks[maxn];
	//untuk menyimpan LIS sementara
	int x=lis_end;
	stack <int> s;
	for(;P[x]>=0;x=P[x]) s.push(a[x].idx);
	i=0;
	indeks[i]=a[x].idx;
	i++;
	for(;!s.empty();s.pop()){indeks[i]=s.top();i++;}
	n=i;
	data LIS[maxn];
	for(i=0;i<n;i++){LIS[i].idx=indeks[i]; LIS[i].w=L[indeks[i]].w; LIS[i].iq=L[indeks[i]].iq;}
	printf("LIS sementara\n");
	for(i=0;i<n;i++){printf("i: %d, w: %d, iq: %d\n",LIS[i].idx,LIS[i].w,LIS[i].iq);}

	n=lis;
	int temp1[maxn],temp1_id[maxn],P1[maxn];
	lis=0;lis_end=0;
	for(i=0;i<n;i++){
		pos=lower_bound(temp1,temp1+lis,L[i].iq)-temp1;
		temp1[pos]=L[i].iq;
		temp1_id[pos]=i;
		P1[i]=pos ? temp1_id[pos-1] : -1;
		L[pos].w=L[i].w;
		L[pos].idx=L[i].idx;
		L[pos].iq=L[i].iq;
		if(pos+1 > lis){
			lis=pos+1;
			lis_end=i;
		}
		printf("Considering element L[%d].iq = %d\n", i, L[i].iq);
	    printf("LIS ending at A[%d] is of length %d: ", i, pos + 1);
	    reconstructPrint(i, L, P);
	    print_array("L is now", temp1, lis);
	    printf("\n");
	}
	printf("%d\nlis:\n",lis);
	reconstructPrint(lis_end,L,P1);
	return 0;
}