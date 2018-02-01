#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string kata[5];

bool compute(int x, int y){
	int i,j;
	//secara horizontal
	for(i=0;i<4;i++){
		int cnt = 0;
		for(j=0;j<4;j++){
			if(kata[i][j]=='x'){cnt++;}
		}
		if(cnt==4){return true;}
	}
	//vertikal
	for(j=0;j<4;j++){
		int cnt = 0;
		for(i=0;i<4;i++){
			if(kata[i][j]=='x'){cnt++;}
		}
		if(cnt==4){return true;}
	}

	//diagonal kanan bawah
	int cnt = 0;
	for(i=0;i<4;i++){
		j=i;
		if(kata[i][j] == 'x'){cnt++;}
	}
	if(cnt==4){return true;}
	//diagonal kiri bawah
	cnt = 0;
	for(j=3;j>=0;j--){
		i=3-j;
		if(kata[i][j]=='x'){cnt++;}
	}
	if(cnt==4){return true;}

	return false;
}

int main(){
	char kar;
	
	int i,j;
	scanf("%c",&kar);
	while(kar!='$'){
		for(i=0;i<4;i++){cin>>kata[i];}
		// printf("listkata:\n");
		// for(i=0;i<4;i++){
		// 	cout<<kata[i]<<endl;
		// }
		//secara horizontal
		int ans = 0;
		for(i=0;i<4;i++){
			int cnt = 0;
			for(j=0;j<4;j++){
				if(kata[i][j]=='x'){cnt++;}
			}
			if(cnt==3){ans++;}
		}
		//vertikal
		for(j=0;j<4;j++){
			int cnt = 0;
			for(i=0;i<4;i++){
				if(kata[i][j]=='x'){cnt++;}
			}
			if(cnt==3){ans++;}
		}

		//diagonal kanan bawah
		int cnt = 0;
		for(i=0;i<4;i++){
			j=i;
			if(kata[i][j] == 'x'){cnt++;}
		}
		if(cnt==3){ans++;}
		//diagonal kiri bawah
		cnt = 0;
		for(j=3;j>=0;j--){
			i=3-j;
			if(kata[i][j]=='x'){cnt++;}
		}
		if(cnt==3){ans++;}
		bool udah = false;
		if(ans==1){
			//cek klo ditambahin x..bakal menang atau ga
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(kata[i][j]=='.'){
						//taruh x
						kata[i][j] = 'x';
						bool benar = compute(i,j);
						kata[i][j] = '.';
						if(benar){printf("(%d,%d)\n",i,j); udah = true; break;}
					}
				}
				if(udah){break;}
			}
			
		}else if(ans==0){
			printf("#####\n");
		}else{
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(kata[i][j]=='.'){printf("(%d,%d)\n",i,j); udah = true; break;}
				}
				if(udah){break;}
			}
		}


		scanf("\n%c",&kar);
	}
	return 0;
};