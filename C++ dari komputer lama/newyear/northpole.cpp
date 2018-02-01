#include <bits/stdc++.h>

using namespace std;

struct p{
	int x;
	int y;
};

int main(){
	string kata;
	bool found;
	int a,jarak;
	int n,i,cnt;
	p pos;
	found=true;
	pos.x=pos.y=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		cin>>a>>kata;
		if(i==1){
			if(kata!="South"){found=false;}
			else{
				if(a>20000){found=false;}
				else{pos.y+=a;}
			}
		}else{
			if(pos.y==0){
				if(kata!="South"){found=false;}
				else{
					if(a<=20000){pos.y+=a;}
					else{found=false;}
				}
			}else if(pos.y==20000){
				if(kata!="North"){found=false;}
				else{
					if(a<=20000){pos.y-=a;}
					else{found=false;}
				}
			}else{
			if(kata=="North"){
				jarak=pos.y;
				if(jarak<a){found=false;}
				else{pos.y-=a;}
			}else if(kata=="South"){
				jarak=20000-pos.y;
				if(jarak<a){found=false;}
				else{pos.y+=a;}
			}
		}
		}
	}
	if(!found){
		printf("NO\n");
	}else{
		if(pos.y!=0){found=false;}else{found=true;}
		if(found){
			printf("YES\n");
		}else{
			printf("NO\n");	
		}	
	}
	
	return 0;
}