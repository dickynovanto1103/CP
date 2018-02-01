#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,bil,temp;
	string dir;
	
	while(scanf("%d",&n),n){
		bil=1;
		int pos[]={2,3,4,5};//posisi awal klo topnya 1
		while(n--){
			cin>>dir;
			if(dir=="north"){
				//printf("test\n");
				pos[0]=bil;
				temp=bil;
				bil=pos[3];
				pos[3]=7-temp;
			}else if(dir=="south"){
				pos[3]=bil;
				temp=bil;
				bil=pos[0];
				pos[0]=7-temp;
			}else if(dir=="east"){
				pos[2]=bil;
				temp=bil;
				bil=pos[1];
				pos[1]=7-temp;
			}else if(dir=="west"){
				pos[1]=bil;
				temp=bil;
				bil=pos[2];
				pos[2]=7-temp;
			}
		}
		printf("%d\n",bil);
	}
	return 0;
}