#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int cnt,i,j,k;
	char a[110][10];
	int idx[257];
	string kata[110];
	cnt=0;
	idx['r'] = 0;
	idx['o'] = 1;
	idx['y'] = 2;
	idx['g'] = 3;
	idx['b'] = 4;
	getline(cin,kata[0]);
	while(kata[cnt][0]!='#'){
		if(kata[cnt][0]=='e'){
			/*for(i=0;i<cnt;i++){
				for(j=0;j<5;j++){
					printf("a[%d][%d]= %c ",i,j,a[i][j]);
				}
				printf("\n");
			}*/
			//cari jawaban
			int ans, counter = 100000, temp;
			for(i=0;i<cnt;i++){
				temp=0;
				for(j=0;j<cnt;j++){
					for(k=0;k<5;k++){
						if(i==j) break;
						if(a[i][k]!=a[j][k]){temp++;}

					}
				}
				if(counter > temp){counter = temp; ans = i;}
			}
			cout<<ans+1<<endl;
			cnt=0;
		}
		else{
			//counter = 0;
			for(i=0;i<kata[cnt].length();i++){
				char kar = kata[cnt][i];
				if(kar ==',') continue;
				int bil = kar;

				if(bil>=97 && bil<=122){
					a[cnt][idx[kar]] = kata[cnt][i+2];
					//counter++;
				}
			}
			cnt++;
			
			//printf("cnt: %d\n",++cnt);
		}
		getline(cin,kata[cnt]);
	}
	return 0;
}