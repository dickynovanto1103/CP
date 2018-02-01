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

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
	int n,m,i,j,k,l;
	string kata[100];
	string perintah;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){cin>>kata[i];}
	int xStart, yStart, yEnd, xEnd;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(kata[i][j]=='S'){xStart = i; yStart = j;}
			else if(kata[i][j] == 'E'){xEnd = i; yEnd = j;}
		}
	}
	cin>>perintah;
	//printf("xStart: %d yStart: %d xEnd: %d yEnd: %d\n",xStart,yStart,xEnd,yEnd);
	int cnt = 0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(i==j){continue;}
			for(k=0;k<4;k++){
				if(j==k || k==i || i==j){continue;}
				for(l=0;l<4;l++){
					if(k==l || l==j || l==i){continue;}
					int x = xStart, y = yStart;
					bool valid = true;
					bool ketemu = false;
					for(int idx = 0;idx<perintah.length();idx++){
						char kar = perintah[idx];
						int xbaru, ybaru;
						if(kar=='0'){
							xbaru = x + dx[i]; ybaru = y+dy[i];

							x = xbaru; y = ybaru;
							if(!(x>=0 && x<n && y>=0 && y<m)){
								valid = false; break;
							}else{
								if(x==xEnd && y==yEnd){ketemu = true; break;}
								if(kata[x][y]=='#'){valid = false; break;}
							}
						}else if(kar=='1'){
							xbaru = x + dx[j]; ybaru = y+dy[j];

							x = xbaru; y = ybaru;
							if(!(x>=0 && x<n && y>=0 && y<m)){
								valid = false; break;
							}else{
								if(x==xEnd && y==yEnd){ketemu = true; break;}
								if(kata[x][y]=='#'){valid = false; break;}
							}
						}else if(kar=='2'){
							xbaru = x + dx[k]; ybaru = y+dy[k];

							x = xbaru; y = ybaru;
							if(!(x>=0 && x<n && y>=0 && y<m)){
								valid = false; break;
							}else{
								if(x==xEnd && y==yEnd){ketemu = true; break;}
								if(kata[x][y]=='#'){valid = false; break;}
							}
						}else if(kar=='3'){
							xbaru = x + dx[l]; ybaru = y+dy[l];

							x = xbaru; y = ybaru;
							if(!(x>=0 && x<n && y>=0 && y<m)){
								valid = false; break;
							}else{
								if(x==xEnd && y==yEnd){ketemu = true; break;}
								if(kata[x][y]=='#'){valid = false; break;}
							}
						}
					}
					if(ketemu){
						//printf("i: %d j: %d k: %d l: %d\n",i,j,k,l);
						cnt++;
					}
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
};