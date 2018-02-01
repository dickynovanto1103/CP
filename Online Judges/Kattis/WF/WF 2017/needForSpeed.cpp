#include <bits/stdc++.h>

using namespace std;
#define inf 1e12
#define mininf -1e12
#define eps 1e-9
int main(){
    double t;
    int i,n;
    double d[1010], s[1010];
    while(scanf("%d %lf",&n,&t)!=EOF){
    	double minim = inf;
	    for(i=0;i<n;i++){
	        scanf("%lf %lf",&d[i],&s[i]);
	        minim = min(minim,s[i]);
	    }
	    double hi = inf, lo = minim*-1, mid;
	    //printf("hi: %lf lo: %lf\n",hi,lo);
	    double ans = lo;

	    for(int j=1;j<=500;j++){
	        mid = (hi+lo)/2.0;
	        ans = 0.0;
	        
	        for(i=0;i<n;i++){ans += d[i]/(s[i]+mid);}

	        if(ans>0){
	            if(ans<t){hi = mid;}
	            else if(ans>t){lo = mid;}
	        }else{
	            if(ans>t){hi = mid;}
	            else if(ans<t){lo = mid;}   
	        }
	        if(fabs(ans-t)<=eps){break;}
	        
	    }
	    //cout<<mid<<endl;
	    printf("%.9lf\n",mid);	
    }
    
    return 0;
}