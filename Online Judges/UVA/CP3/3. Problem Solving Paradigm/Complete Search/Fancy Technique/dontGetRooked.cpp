#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;

bool cek(string a[5], int r, int c, int n){
	bool found = true;
	int i,j;
	//cek ke atas
	for(i=r-1;i>=0;i--){
		if(a[i][c]=='X'){break;}
		else if(a[i][c]=='f'){return false; break;}
	}
	//cek ke bawah
	
	for(i=r+1;i<n;i++){
		if(a[i][c]=='X'){break;}
		else if(a[i][c]=='f'){return false; break;}
	}	
	
	
	//cek ke kiri
	for(j=c-1;j>=0;j--){
		if(a[r][j]=='X'){break;}
		else if(a[r][j]=='f'){return false; break;}
	}
	//cek ke kanan
	for(j=c+1;j<n;j++){
		if(a[r][j]=='X'){break;}
		else if(a[r][j]=='f'){return false; break;}
	}
	return true;
}

int main(){
	int n,i,j,k;
	string a[5], temp[5];
	map<ii,int> mapper;
	map<int,ii> mapper2;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){cin>>a[i]; temp[i] = a[i];}

		int cnt = 0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(a[i][j]=='.'){
					ii pair = ii(i,j);
					mapper[pair] = cnt; mapper2[cnt] = pair; cnt++;
				}
			}
		}
		int ans = 0;
		for(int tt=0;tt<(1<<cnt);tt++){
			for(k=0;k<n;k++){temp[k] = a[k];}
			int counter = 0;
			for(j=0;j<cnt;j++){
				if(tt & (1<<j)){
					counter++;
					ii pair = mapper2[j];
					int x = pair.first, y = pair.second;
					if(temp[x][y]=='.'){temp[x][y] = 'f';}
				}
			}
			//cek bertabrakan atau ga
			bool found = true;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(temp[i][j]=='f'){
						found = cek(temp,i,j,n);
						if(!found){break;}
					}
				}
				if(!found){break;}
			}
			if(found){ans = max(ans, counter);}
			//reset matriks
		}
		printf("%d\n",ans);
		mapper.clear(); mapper2.clear();
	}
	return 0;
}