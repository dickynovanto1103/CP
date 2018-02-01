#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,r,i,j;
	int a[1100];
	double listJawaban[1100];
	scanf("%d %d",&n,&r);
	for(i=0;i<n;i++){
		//printf("i: %d\n",i);
		scanf("%d",&a[i]);
		//if(i==0){ continue;}
		listJawaban[i]=(double)r;
		double ans = (double)r;
		bool foundAns = false;
		for(j=i-1;j>=0;j--){

			int selisih = (2*r*2*r - (a[j]-a[i])*(a[j]-a[i]));
			if(selisih<0){continue;}
			//printf("i: %d j: %d selisih: %d\n",i,j,selisih);
			double jawab = sqrt(selisih) + listJawaban[j];
			//printf("jawab: %.2lf\n",jawab);
			listJawaban[i] = max(listJawaban[i],jawab);
			foundAns = true;
		}
		//if(foundAns){listJawaban[i] = (double)r;}
	}
	// /printf("halo\n");
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%.10lf",listJawaban[i]);
	}
	printf("\n");
	return 0;
};