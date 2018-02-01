#include <cstdio>

using namespace std;

int main(){
	int h,m,tc,i,test=1,bil;
	scanf("%d",&tc);
	while(tc--){
		printf("Case #%d: ",test++);
		scanf("%d %d",&h,&m);
		bil=45;
		if(m<45){bil-=m; h--; m=60-bil;}
		else{m-=45;}
		if(h<0){h=23;}
		printf("%d %d\n",h,m);
	}
	return 0;
}