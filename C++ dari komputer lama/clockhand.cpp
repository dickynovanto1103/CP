#include <bits/stdc++.h>

using namespace std;

int main(){
	int j,m;
	double a,b,ans;
	while(scanf("%d:%d",&j,&m),(j||m)){
		b = m/60.0 * 360.0;
		a = j*30;
		a = a+ m/60.0 * 30.0;
		ans = abs(a-b);	
		ans = min(ans,abs(b-a));
		if(ans > 180){ans = 360-ans;}
		if(ans==360){ans=0;}
		printf("%.3lf\n",ans);
		//jika selisih = 360 ..sudut = 0;
	}
	return 0;
}