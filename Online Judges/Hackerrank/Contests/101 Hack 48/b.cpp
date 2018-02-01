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

const int maxn = 1e5 + 5;

int main(){
	int tc,i,j;
	string kata;
	scanf("%d",&tc);
	while(tc--){
		cin>>kata;
		int pjg = kata.length();
		stack<char> s;
		bool awal = true;
		bool isCollision[maxn];
		memset(isCollision, false,sizeof isCollision);
		vii listKoordinat;
		int cnt = 0;
		for(i=0;i<pjg-1;i++){
			char kar = kata[i];
			if(kata[i]=='r' && kata[i+1]=='l'){
				cnt+=2;
				isCollision[i] = isCollision[i+1] = true;
				listKoordinat.pb(ii(i,i+1));
			}else{
				if(kata[i]=='d' && kata[i+1]=='l'){
					isCollision[i] = true;
					listKoordinat.pb(ii(i,-1));
				}else if(kata[i]=='r' && kata[i+1]=='d'){
					isCollision[i+1] = true;
					listKoordinat.pb(ii(i+1,-1));
				}
			}
		}
		if(listKoordinat.size()==0){
			printf("0\n"); continue;
		}
		ii koorAwal = listKoordinat[0];
		int xawal = koorAwal.first;
		for(i=xawal-1;i>=0;i--){
			char kar = kata[i];
			if(kar=='r'){isCollision[i]=true; cnt++;}
		}
		ii koorAkhir = listKoordinat[listKoordinat.size()-1];
		int xakhir = koorAkhir.first;
		for(i=xakhir+1;i<pjg;i++){
			char kar = kata[i];
			if(isCollision[i]){continue;}
			if(kar=='l'){isCollision[i] = true; cnt++;}
		}
		for(i=xawal+1;i<xakhir;i++){
			char kar = kata[i];
			if(isCollision[i]){continue;}
			if(kar!='d'){isCollision[i] = true; cnt++;}
		}
		printf("%d\n",cnt);
	}
	return 0;
};