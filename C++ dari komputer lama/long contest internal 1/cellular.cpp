#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
#define inf 2000000000
//typedef long long ll;
int main(){
	int i,j,n,m,a[100000],b[100000],c[100000],hi,lo,nilailo,nilaihi;
	bool found = false;
	int64_t ans=-1,jawaban;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	for(i=0;i<m;i++){scanf("%d",&b[i]);}
	/*hi = inf; lo = max(abs(a[n-1]-b[n-1]),abs(a[0]-b[0]));
	while(!found){
		j=0;
		for(i=0;i<m;i++){
			down = b[i]-hi ; up = b[i]+hi;
			while(j<n){
				if(!(a[j]>=down && a[j]<=up)){break;}
				else{j++;}
			}
			//dpt j dimana

			if(j==n){ //semua tercover
				mid = (hi+lo)/2;
				hi = mid; i=-1;//reset from i=0 again
			}
			//klo ga ketemu cari lain
		}	
	}*/
	for(i=0;i<n;i++){c[i]=inf;}//jawaban jarak dr kota a[i] ke cellular terdekat
	//pakai lower&upper bound
	/*for(i=0;i<m;i++){
		lo = lower_bound(a,a+n,b[i])-a;
		if(a[lo]>b[i] && lo>0){lo--;}//biar dpt yg lebih kecil
		if(lo==n){lo--;}
		hi = upper_bound(a,a+n,b[i])-a;
		if(hi==n){hi--;}
		if(hi>0 && a[hi-1]==b[i]){hi--;}
		//printf("pertama hi: %d lo: %d\n",hi,lo);
		//printf("untuk b[i] = %d lo: %d hi: %d\n",b[i],lo,hi);
		c[hi]=min(c[hi],abs(a[hi]-b[i])); c[lo]=min(c[lo],abs(a[lo]-b[i]));
		//printf("c[hi]: %d c[lo]: %d\n",c[hi],c[lo]);
		//int64_t temp = max(abs(a[hi]-b[i]),abs(a[lo]-b[i]));
		//ans=max(ans,max((int64_t)abs(a[hi]-b[i]),(int64_t)abs(a[lo]-b[i])));
		//printf("untuk b[%d]=%d, selisih: %I64d\n",i,b[i],temp);
	}*/
	for(i=0;i<n;i++){
		
			lo = lower_bound(b,b+m,a[i])-b;
			if(b[lo]>a[i] && lo>0){lo--;}//biar dpt yg lebih kecil
			if(lo==m){lo--;}
			hi = upper_bound(b,b+m,a[i])-b;
			if(hi==m){hi--;}
			if(hi>0 && b[hi-1]==a[i]){hi--;}
			//printf("hi: %d lo: %d\n",hi,lo);
			//printf("untuk b[i] = %d lo: %d hi: %d\n",b[i],lo,hi);
			c[i]=min(c[i],abs(b[hi]-a[i])); c[i]=min(c[i],abs(b[lo]-a[i]));
			//printf("c[i]: %d\n",c[i]);
		
	}
	/*printf("list jarak:\n");
	for(i=0;i<n;i++){printf("%d ",c[i]);}
	printf("\n");*/
	for(i=0;i<n;i++){
		ans = max(ans,(int64_t)c[i]);
	}
	//printf("\n");
	
	printf("%I64d\n",ans);
	return 0;
}