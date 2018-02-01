#include <bits/stdc++.h>

using namespace std;

int main(){
	double a,b,c,d;
	for(a=0.01;a<=5.00;a+=0.01){
		for(b=a+0.01;b<=5.00;b+=0.01){
			for(c=b+0.01;c<=5.00;c+=0.01){
				
				d=20-a-b-c;
				if(a==0.5 && b==1.0 && c==2.5 && d==16.00){printf("%.2lf %.2lf %.2lf %.2lf\n",a,b,c,d);}
				//printf("%.2lf %.2lf %.2lf %.2lf\n",a,b,c,d);
				if(a*b*c*d==20){printf("%.2lf %.2lf %.2lf %.2lf\n",a,b,c,d);}
			}
		}
	}
	return 0;
}