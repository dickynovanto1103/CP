#include <cstdio>

using namespace std;
typedef long long ll;
int main(){
	ll a,b;
	ll x,y,cnt,car,idx=1;
	while(scanf("%lld %lld",&a,&b),(a||b)){
		cnt=car=0;
		//printf("ke: %lld\n",idx++);
		//printf("a : %lld b: %lld\n",a,b);
		while(b>0 || a>0){
			x = b%10;
			y = a%10;
			a/=10;
			b/=10;
			//printf("x: %lld, y: %lld, car: %lld\n",x,y,car);
			if(x+y+car > 9){cnt++; car=1;}
			else{car=0;}
			//printf("cnt: %lld\n",cnt);
		}
		
		if(cnt==0){printf("No carry operation.\n");}
		else if(cnt==1){printf("1 carry operation.\n");}
		else{printf("%lld carry operations.\n",cnt);}
	}
}