#include <math.h>
#include <cstdio>

using namespace std;
#define EPS 1e-9
int main(){
	double hi, lo;
	double mid;
	int i;
	bool found;
	double ans;
	int p,q,r,s,t,u;
	while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF){
		//printf("p: %d q: %d",p,q);
		hi = 1.0; lo = 0.0;
		found =false;
		for(i=0;i<40;i++){
			//printf("i: %d\n",i);
			mid = (hi+lo)/2.0;
			ans = (double)p*exp(-1*mid) + (double)q*sin(mid) + (double)r * cos(mid) + (double)s*tan(mid) + (double)t*mid*mid + (double)u;
			//printf("mid: %.4lf ans: %.4lf\n",mid,ans);
			if(fabs(0-ans)<=EPS){found=true; break;}
			if(ans<0){hi = mid;}
			else if(ans>0){lo = mid;}
			
		}
		if(!found){printf("No solution\n");}
		else{printf("%.4lf\n",mid);}
	}
	

	return 0;
}