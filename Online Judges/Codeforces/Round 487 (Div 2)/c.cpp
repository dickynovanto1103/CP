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

ii pas[5];
char a[51][51];

bool cmp(ii a, ii b){
	return a.first > b.first;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

ii cariSlotKosong(){
	int i,j;
	for(i=0;i<49;i+=2){
		for(j=0;j<49;j++){
			if(a[i][j] == '.'){return ii(i,j);}	
		}
	}
}

int main(){
	int i,j;
	for(i=0;i<4;i++){
		int bil;
		scanf("%d",&bil);
		pas[i].first = bil; pas[i].second = i;
	}

	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			a[i][j] = '.';
		}
	}
	sort(pas, pas+4, cmp);

	set<ii> s[5];

	for(i=0;i<4;i++){
		int banyak = pas[i].first;
		char kar = pas[i].second + 'A';
		//cari slot
		ii titikAwal = cariSlotKosong();
		int xAwal = titikAwal.first, yAwal = titikAwal.second;
		for(j=xAwal;j<49;j+=2){
			for(int k=yAwal;k<49;k+=2){
				a[j][k] = kar;
				banyak--;
				if(banyak==0){break;}
			}
			if(banyak==0){break;}
		}
	}

	if(pas[3].first == 1){
		char kar = pas[3].second + 'A';
		for(i=0;i<50;i++){
			for(j=0;j<50;j++){
				if(a[i][j] == '.'){
					a[i][j] = kar;
				}
			}
		}
	}else{
		
		for(i=0;i<50;i++){
			for(j=0;j<50;j++){
				char kar = a[i][j];
				if(kar=='.'){continue;}
				for(int k=0;k<4;k++){
					int xbaru = i+dx[k], ybaru = j + dy[k];
					if(xbaru>=0 && xbaru<50 && ybaru>=0 && ybaru<50){
						if(a[xbaru][ybaru] == '.'){s[kar-'A'].insert(ii(xbaru,ybaru));}
					}
				}
			}
		}
	}
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			char kar = a[i][j];
			if(kar=='.'){continue;}
			ii dasar = ii(i,j);
			queue<ii> q;
			q.push(dasar);
			while(!q.empty()){
				ii front = q.front(); q.pop();
				int x = front.first, y = front.second;
				kar = a[x][y];
				dasar = ii(x,y);
				for(int k=0;k<4;k++){
					int xbaru = x+dx[k], ybaru = y + dy[k];
					if(xbaru>=0 && xbaru<50 && ybaru>=0 && ybaru<50){
						if(a[xbaru][ybaru] == '.'){
							if(s[kar-'A'].count(ii(xbaru,ybaru))){
								if((abs(xbaru-dasar.first) + abs(ybaru-dasar.second)) ==1){
									a[xbaru][ybaru] = kar;
									q.push(ii(xbaru,ybaru));
									for(int l=0;l<4;l++){
										int absisBaru = xbaru + dx[l], ordinatBaru = ybaru + dy[l];
										if(absisBaru>=0 && absisBaru<50 && ordinatBaru>=0 && ordinatBaru<50) {
											if(a[absisBaru][ordinatBaru] == '.'){
												s[kar-'A'].insert(ii(absisBaru,ordinatBaru));
											}
										}
									}
								}
							}else{
								a[xbaru][ybaru] = kar;
								q.push(ii(xbaru,ybaru));
								for(int l=0;l<4;l++){
									int absisBaru = xbaru + dx[l], ordinatBaru = ybaru + dy[l];
									if(absisBaru>=0 && absisBaru<50 && ordinatBaru>=0 && ordinatBaru<50) {
										if(a[absisBaru][ordinatBaru] == '.'){
											s[kar-'A'].insert(ii(absisBaru,ordinatBaru));
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("50 50\n");
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}

	return 0;
};