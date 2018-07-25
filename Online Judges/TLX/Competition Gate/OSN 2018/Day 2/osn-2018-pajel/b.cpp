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

char mat[501][501];
bool isFillable[501][501], isSource[501][501];
int n;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void bfs(int i, int j, char kar) {
	queue<ii> q;
	q.push(ii(i,j));
	while(!q.empty()){
		ii front = q.front(); q.pop();
		int x = front.first, y = front.second;
		for(int i=0;i<4;i++){
			int xbaru = x+dx[i], ybaru = y + dy[i];
			if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<n){
				if(isFillable[xbaru][ybaru]){
					if(mat[xbaru][ybaru] == '-'){
						mat[xbaru][ybaru] = kar;
						q.push(ii(xbaru,ybaru));
					}
				}
			}
		}
	}

}

int main(){
	
	int p,i,j;
	scanf("%d %d",&n,&p);
	
	for(i=0;i<=500;i++){
		for(j=0;j<=500;j++){
			mat[i][j] = '-';	
			isFillable[i][j] = true;
			isSource[i][j] = false;
		}
	}

	string arr1[510], arr2[510];

	for(i=0;i<n;i++){
		string kata;
		cin>>kata;
		arr1[i] = kata;
		if(kata=="-"){
			
		}else if(kata=="0"){
			for(j=0;j<n;j++){
				isFillable[j][i] = false;
			}
		}
		else{
			int jarak = kata[0] - '0';
			char kar = kata[1];
			mat[jarak-1][i] = kar;
			isSource[jarak-1][i] = true;
			for(j=0;j<n;j++){
				isFillable[j][i] = false;
			}
		}
	}

	for(i=0;i<(n);i++){
		string kata1, kata2;
		cin>>kata1>>kata2;

		if(kata1=="-"){
			
		}else{
			int jarak = kata1[0] - '0';
			char kar = kata1[1];
			mat[i][jarak-1] = kar;	
			isSource[i][jarak-1] = true;
			for(j=0;j<n;j++){
				isFillable[i][j] = false;
			}
		}

		if(kata2=="-"){
			
		}else{
			int jarak = kata2[0] - '0';
			char kar = kata2[1];
			mat[i][n-(jarak)] = kar;
			isSource[i][n - jarak] = true;
			for(j=0;j<n;j++){
				isFillable[i][j] = false;
			}
		}

		if(kata1 == "0" || kata2=="0"){
			for(j=0;j<n;j++){
				isFillable[i][j] = false;
			}	
		}else{
			
			int idxAwal = 0, idxAkhir = n-1;
			if(kata1!="-"){
				int jarak = kata1[0] - '0';
				idxAwal = jarak-1;
			}
			if(kata2!="-1"){
				int jarak = kata2[0] - '0';
				idxAkhir = n-jarak;
			}

			for(j=idxAwal;j<=idxAkhir;j++){
				if(!isFillable[i][j]){continue;}
				isFillable[i][j] = true;
			}
		}

	}

	for(i=0;i<n;i++){
		string kata;
		cin>>kata;
		arr2[i] = kata;
		if(kata=="-"){
			
		}else if(kata=="0"){
			for(j=0;j<n;j++){
				isFillable[j][i] = false;
			}
		}
		else{
			int jarak = kata[0] - '0';
			char kar = kata[1];
			mat[n-(jarak)][i] = kar;
			isSource[n - jarak][i] = true;
			for(j=0;j<n;j++){
				isFillable[j][i] = false;
			}
		}
	}

	//consider atas bawah
	for(i=0;i<n;i++){
		string kata1 = arr1[i], kata2 = arr2[i];
		if(kata1 == "0" || kata2=="0"){
			for(j=0;j<n;j++){
				isFillable[j][i] = false;
			}	
		}else{
			
			int idxAwal = 0, idxAkhir = n-1;
			if(kata1!="-"){
				int jarak = kata1[0] - '0';
				idxAwal = jarak-1;
			}
			if(kata2!="-1"){
				int jarak = kata2[0] - '0';
				idxAkhir = n-jarak;
			}

			for(j=idxAwal;j<=idxAkhir;j++){
				if(!isFillable[j][i]){continue;}
				isFillable[j][i] = true;
			}
		}
	}
	

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(isSource[i][j]){
				bfs(i,j,mat[i][j]);
			}
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%c",mat[i][j]);
		}
		printf("\n");
	}

	return 0;
};