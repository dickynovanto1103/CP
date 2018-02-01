#include <bits/stdc++.h>

using namespace std;

struct p{
	int numsolve;
	int time;
};

struct data{
	int jumlah;
	int awal;
	int akhir;
};

bool acompare(p lhs, p rhs){return lhs.numsolve > rhs.numsolve;}
bool bcompare(p lhs, p rhs){return lhs.time < rhs.time;}
p a[300000];


int main(){
	int n,q,i,j,k,begin,end,jumlah;
	int ans[300000];
	scanf("%d %d",&n,&q);
	for(i=0;i<n;i++){scanf("%d %d",&a[i].numsolve,&a[i].time);}

	//sort dulu

	sort(a,a+n,acompare);
	printf("setelah disort\n");
	for(i=0;i<n;i++){printf("%d %d\n",a[i].numsolve,a[i].time);}
	int cur = a[0].numsolve, curidx=0;
	for(i=0;i<n;i++){
		if(cur!=a[i].numsolve){
			sort(a+curidx,a+i,bcompare);
			cur=a[i].numsolve; curidx=i;
		}
	}
	sort(a+curidx,a+n,bcompare);
	printf("setelah disort\n");
	for(i=0;i<n;i++){printf("%d %d\n",a[i].numsolve,a[i].time);}
	int cura,curb,idx;
	cura = a[0].numsolve; curb=a[0].time;
	begin=end=0; jumlah=1;
	for(i=1;i<n;i++){
		while(a[i].numsolve==cura && a[i].time==curb && i<n){
			jumlah++;end=i;
			i++;
		}
		printf("yang akan diisi adalah indeks %d ke %d\n",begin,end);
		for(j=begin;j<=end;j++){ans[j]=jumlah;}
		begin=end=i; jumlah=0;
		cura = a[i].numsolve; curb=a[i].time;
		i--;
	}
	if(n==1){ans[0]=1;}
	printf("hasil ans:\n");
	for(i=0;i<n;i++){printf("%d\n",ans[i]);}
	printf("jawaban asli:\n");
	for(i=0;i<q;i++){
		scanf("%d",&k);
		k--;
		printf("%d\n",ans[k]);
	}
	return 0;
}