#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,m;
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
string kata[30];


int floodFill(int x, int y){
	int ans = 1,i,j;
	kata[x][y] = '*';
	for(i=0;i<8;i++){
		int xbaru = x+dx[i], ybaru = y+dy[i];
		if(xbaru>=0 && xbaru<n && ybaru>=0 && ybaru<m){
			if(kata[xbaru][ybaru]=='1'){
				ans+=floodFill(xbaru,ybaru);
			}
		}
	}
	return ans;
}

int main() {
	int tc,i,j;
	scanf("%d",&tc);
	cin>>ws;
	int test = 1;
	while(tc--){
		if(test==2){printf("\n");}
		n=0;
		//printf("test %d:\n",test++);
		getline(cin,kata[n]);
		//cout<<kata[n]<<endl;;
		if(kata[n]==""){continue;}
		else{
			//printf("masuk sini\n");
			while(kata[n]!=""){
				n++;
				getline(cin,kata[n]);
				//cout<<kata[n]<<endl;
			}
		}
		//printf("n: %d\n",n);
		m = kata[0].length();
		int ans = 0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(kata[i][j]=='1'){ans=max(ans,floodFill(i,j));}
			}
		}
		printf("%d\n",ans);
		test = 2;
	}
	return 0;
}