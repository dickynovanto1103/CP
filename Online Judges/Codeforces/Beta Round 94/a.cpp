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

vector<int> ListTime[8][8];
set<ii> s;
multiset<ii> listS;
multiset<ii>::iterator it2;
set<ii>::iterator it;
string kata[8];

bool isValid(int r, int c){

	if(r >= 0 && r<8 && c >= 0 && c<8) {
		if(listS.count(ii(r,c))){return false;}
		else{return true;}
	}else{
		return false;
	}
}


int dx[] = {-1,0,1,0,-1,1,1,-1};
int dy[] = {0,1,0,-1,1,1,-1,-1};

void goDown(int r, int c){
	int time = 0;
	if(r == 7){
		kata[r][c] = '.';
	}else{
		listS.insert(ii(r+1, c));
	}
	it2 = listS.find(ii(r,c));
	listS.erase(it2);
}

void simulateMaria() {
	vii listTambahan;
	int i;
	for(it = s.begin(); it!=s.end();it++){
		ii front = *it;
		int x = front.first, y = front.second;
		for(i=0;i<8;i++){
			int xbaru = x + dx[i], ybaru = y+dy[i];
			if(isValid(xbaru, ybaru)) {
				listTambahan.pb(ii(xbaru, ybaru));
			}
		}
	}
	for(i=0;i<listTambahan.size();i++){
		s.insert(listTambahan[i]);
	}
}

void simulateStatue() {
	int i;
	vii listTambahan;

	for(it = listS.begin(); it!=listS.end();it++){
		listTambahan.pb(*it);
		
	}
	for(i=0;i<listTambahan.size();i++){
		ii front = listTambahan[i];
		int x = front.first, y = front.second;
		goDown(x,y);
	}
	for(it=listS.begin();it!=listS.end();it++){
		ii front = *it;
		if(s.count(*it)){
			s.erase(*it);
		}
	}
}

int main(){
	

	int i,j;
	for(i=0;i<8;i++){
		cin>>kata[i];
	}	

	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			char kar = kata[i][j];
			if(kar == 'S'){
				listS.insert(ii(i,j));
			}else if(kar == 'A' || kar == 'M'){
				kata[i][j] = '.';
			}
		}
	}

	
	s.insert(ii(7,0));

	for(i=0;i<8;i++){
		simulateMaria();
		simulateStatue();
	}

	if(s.empty()){printf("LOSE\n");}
	else{printf("WIN\n");}

	return 0;
};