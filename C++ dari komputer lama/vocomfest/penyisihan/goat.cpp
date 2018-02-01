#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>

using namespace std;

struct koor{
	int x;
	int y;
};

bool acompare(koor a, koor b){return a.x < b.x;}
bool bcompare(koor a, koor b){return a.y < b.y;}

int main(){
	int tc,n,r,test=1,i,j;
	double jarak;
	koor a[10010];
	scanf("%d",&tc);
	while(tc--){
		printf("Case #%d: ",test++);
		scanf("%d %d",&n,&r);
		for(i=0;i<n;i++){scanf("%d %d",&a[i].x,&a[i].y);}
		sort(a,a+n,acompare);
		int curbil = a[0].x, curidx = 0;
		for(i=0;i<n;i++){
			if(curbil!=a[i].x){sort(a+curidx,a+i,bcompare); curidx = i; curbil = a[i].x;}
		}
		sort(a+curidx,a+i,bcompare);
		double x,y,minx,miny;
		bool found = false, pastisalah;
		for(i=0;i<n-1;i++){
			//pastisalah = false;
			for(j=i+1;j<n;j++){
				jarak = hypot(a[i].x - a[j].x, a[i].y - a[j].y);
				//printf("i: %d j: %d jarak: %.2lf\n",i,j,jarak);
				if(jarak<=2.0*(double)r){
					found=true; 
					minx = min(a[i].x, a[j].x);
					miny = min(a[i].y, a[j].y);
					x = (double)abs(a[i].x - a[j].x)/2.0 + minx;
					y = (double)abs(a[i].y - a[j].y)/2.0 + miny;
					break;
				}
				//else{pastisalah=true; break;}
			}
			if(found){break;}
		}
		if(found){
			printf("%.1lf %.1lf\n",x,y);	
		}else{printf("-1\n");}
		
	}
	return 0;
}
