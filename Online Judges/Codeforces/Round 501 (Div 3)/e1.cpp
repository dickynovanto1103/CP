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
typedef pair<ii,int> iii;
typedef vector<ii> vii;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n,m;
string kata[1100];

struct pasangan{
	int kiri, kanan, atas, bawah;
};

string temp[1100];

bool isValid(int x, int y){
	return x>=0 && x<n && y>=0 && y<m;
}

void warnain(int x, int y, int code, int dalam){
	if(dalam == -1){return;}
	int xbaru = x+dx[code], ybaru = y + dy[code];
	temp[x][y] = '*';
	// printf("x: %d y: %d dalam: %d xbaru: %d ybaru: %d\n",x,y,dalam,xbaru,ybaru);
	if(isValid(xbaru,ybaru)){
		// printf("masuk sini\n");
		warnain(xbaru,ybaru,code, dalam-1);
	}
}

int main(){
	int i,j;
	
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){cin>>kata[i];}
	int k,l;

	pasangan pas[1100][1100];
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			pas[i][j].kiri = 0, pas[i][j].kanan = 0, pas[i][j].atas = 0, pas[i][j].bawah = 0;
		}
	}

	for(i=0;i<n;i++){
		int banyak = 0;
		for(j=0;j<m;j++){
			if(kata[i][j] == '*'){
				pas[i][j].kiri = banyak;
				banyak++;
			}else{
				banyak = 0;
			}
		}

		banyak = 0;
		for(j=m-1;j>=0;j--){
			if(kata[i][j] == '*'){
				pas[i][j].kanan = banyak;
				banyak++;
			}else{
				banyak = 0;
			}	
		}
	}

	for(j=0;j<m;j++){
		int banyak = 0;
		for(i=0;i<n;i++){
			if(kata[i][j] == '*'){
				pas[i][j].atas = banyak;
				banyak++;
			}else{
				banyak = 0;
			}
		}
		banyak = 0;
		for(i=n-1;i>=0;i--){
			if(kata[i][j] == '*'){
				pas[i][j].bawah = banyak;
				banyak++;
			}else{
				banyak = 0;
			}
		}
	}

	vector<iii> ans;

	for(i=0;i<n;i++){
		temp[i] = "";
		for(j=0;j<m;j++){
			temp[i]+=".";
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			pasangan a = pas[i][j];
			int minim = min(a.atas,min(a.bawah,min(a.kiri,a.kanan)));
			if(minim == 0){continue;}
			iii jawab;
			jawab.first.first = i; jawab.first.second = j; jawab.second = minim;
			ans.pb(jawab);
			// printf("yang dipush: %d %d %d\n",i,j,minim);
			for(k=0;k<4;k++){
				warnain(i,j,k,minim);
			}
		}
	}
	// printf("temp\n");
	// for(i=0;i<n;i++){
	// 	for(j=0;j<m;j++){
	// 		printf("%c",temp[i][j]);
	// 	}
	// 	printf("\n");
	// }

	bool valid = true;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(kata[i][j] != temp[i][j]){
				valid = false;
				break;
			}
		}
		if(!valid){break;}
	}
	if(!valid){printf("-1\n");}
	else{
		int ukuran = ans.size();
		printf("%d\n",ukuran);
		for(i=0;i<ukuran;i++){
			iii pas = ans[i];
			int x = pas.first.first, y = pas.first.second, dalam = pas.second;
			printf("%d %d %d\n",x+1,y+1,dalam);
		}
	}
	return 0;
};