#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,a,b,c,d,i,j,k,l,m;
	int sum;
	scanf("%d",&tc);
	for(i=1;i<=tc;i++){
		printf("Case #%d: ",i);
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(a==b && b==c && c==d){
			printf("%d = %d = %d = %d\n",a,b,c,d);
		}else{
			//berdasarkan jumlah sama dengan
			if(a==(b+c+d)){printf("%d = %d + %d + %d\n",a,b,c,d);}
			else if(a==(b+c-d)){printf("%d = %d + %d - %d\n",a,b,c,d);}
			else if(a==(b-c+d)){printf("%d = %d - %d + %d\n",a,b,c,d);}
			else if(a==(b-c-d)){printf("%d = %d - %d - %d\n",a,b,c,d);}
			else if((a+b)==(c+d)){printf("%d + %d = %d + %d\n",a,b,c,d);}
			else if((a+b)==(c-d)){printf("%d + %d = %d - %d\n",a,b,c,d);}
			else if((a-b)==(c+d)){printf("%d - %d = %d + %d\n",a,b,c,d);}
			else if((a-b)==(c-d)){printf("%d - %d = %d - %d\n",a,b,c,d);}
			else if((a+b+c)==d){printf("%d + %d + %d = %d\n",a,b,c,d);}
			else if((a+b-c)==d){printf("%d + %d - %d = %d\n",a,b,c,d);}
			else if((a-b+c)==d){printf("%d - %d + %d = %d\n",a,b,c,d);}
			else if((a-b-c)==d){printf("%d - %d - %d = %d\n",a,b,c,d);}
			else if(a==b && b==(c+d)){printf("%d = %d = %d + %d\n",a,b,c,d);}
			else if(a==b && b==(c-d)){printf("%d = %d = %d - %d\n",a,b,c,d);}
			else if((a==(b+c)) && (b+c)==d){printf("%d = %d + %d = %d\n",a,b,c,d);}
			else if((a==(b-c)) && (b-c)==d){printf("%d = %d - %d = %d\n",a,b,c,d);}
			else if((a+b)==c && c==d){printf("%d + %d = %d = %d\n",a,b,c,d);}
			else if((a-b)==c && c==d){printf("%d - %d = %d = %d\n",a,b,c,d);}
		}
	}
	return 0;
}
