#include <bits/stdc++.h>

using namespace std;
int dr[3] = {0,-1,0};
int dc[3] = {-1,0,1};
bool found;
void solve(char kar, int r, int c, int n, int m, string a[], string kata){
	int i;
	if(found){return;}
	if(kar=='#'){
		found = true; 
		int ukuran = kata.length();
		for(i=0;i<ukuran-1;i++){//untuk menghindari trailing space
			printf("%c",kata[i]);
		}
		printf("\n");

		return;
	}
	for(i=0;i<3;i++){
		int x = r+dr[i], y = c+dc[i];
		if(x>=0 && x<n && y>=0 && y<m){
			
			if(kar=='@'){
				if(a[x][y]=='I'){
					if(i==0){kata+="left ";}
					else if(i==1){kata+="forth ";}
					else if(i==2){kata+="right ";}
					solve(a[x][y],x,y,n,m,a, kata);
				}
			}else if(kar=='I'){
				if(a[x][y]=='E'){
					if(i==0){kata+="left ";}
					else if(i==1){kata+="forth ";}
					else if(i==2){kata+="right ";}
					solve(a[x][y],x,y,n,m,a, kata);
				}
			}else if(kar=='E'){
				if(a[x][y]=='H'){
					if(i==0){kata+="left ";}
					else if(i==1){kata+="forth ";}
					else if(i==2){kata+="right ";}
					solve(a[x][y],x,y,n,m,a, kata);
				}
			}else if(kar=='H'){
				if(a[x][y]=='O'){
					if(i==0){kata+="left ";}
					else if(i==1){kata+="forth ";}
					else if(i==2){kata+="right ";}
					solve(a[x][y],x,y,n,m,a, kata);
				}
			}else if(kar=='O'){
				if(a[x][y]=='V'){
					if(i==0){kata+="left ";}
					else if(i==1){kata+="forth ";}
					else if(i==2){kata+="right ";}
					solve(a[x][y],x,y,n,m,a, kata);
				}
			}else if(kar=='V'){
				if(a[x][y]=='A'){
					if(i==0){kata+="left ";}
					else if(i==1){kata+="forth ";}
					else if(i==2){kata+="right ";}
					solve(a[x][y],x,y,n,m,a, kata);
				}
			}else if(kar=='A'){
				if(a[x][y]=='#'){
					if(i==0){kata+="left ";}
					else if(i==1){kata+="forth ";}
					else if(i==2){kata+="right ";}
					solve(a[x][y],x,y,n,m,a, kata);
				}
			}
		}
	}
	
}

int main(){
	int r,c,tc,i,j;
	string a[9];
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&r,&c);
		for(i=0;i<r;i++){cin>>a[i];}
		//cari @ dan # catat indeksnya
		int rawal,cawal,rakhir,cakhir;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(a[i][j]=='@'){rawal = i; cawal = j;}
				else if(a[i][j]=='#'){rakhir = i; cakhir = j;}
			}
		}
		//printf("rawal: %d rakhir: %d cawal: %d cakhir: %d\n",rawal,rakhir,cawal,cakhir);
		char kar = '@';
		string kata = "";
		found = false;
		solve(kar,rawal,cawal,r,c, a, kata);
	}
	return 0;
}