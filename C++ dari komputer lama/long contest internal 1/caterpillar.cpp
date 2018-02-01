#include <cstdio>

using namespace std;

int main(){
	int h1,h2,a,b;
	scanf("%d %d %d %d",&h1,&h2,&a,&b);
	int i,cnt=0,selisih=h2-h1;
	int tinggi=h1;
	int tinggiawal=h1;
	bool found=true;
	while(tinggi<h2 && found){
		tinggi+=8*a;
		if(tinggi>=h2){break;}
		tinggi-=12*b;
		tinggi+=4*a;
		if(tinggi<=tinggiawal){found=false; break;}//tidak dapat bertambah tingginya
		else{cnt++;}
	}
	if(!found){printf("-1\n");}
	else{printf("%d\n",cnt);}
	
	return 0;
}