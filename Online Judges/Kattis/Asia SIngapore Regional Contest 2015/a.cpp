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
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	string moves;
	string kata[201];
	cin>>moves;
	for(i=0;i<n;i++){cin>>kata[i];}
	ii koor = ii(-1,-1);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(kata[i][j] == 'R'){
				koor.fi = i, koor.se = j;
				break;
			}
		}
		if(koor != ii(-1,-1)){break;}
	}
	set<ii> s;
	s.insert(koor);
	int pjg = moves.length();
	ii koorSama;
	while(true){

		for(i=0;i<pjg;i++){
			char kar = moves[i];
			int x = koor.fi, y = koor.se;
			if(kar == '^' && kata[x-1][y] != '#'){
				koor.fi--;
			}else if(kar == 'v' && kata[x+1][y]!='#'){
				koor.fi++;
			}else if(kar == '>' && kata[x][y+1] != '#'){
				koor.se++;
			}else if(kar == '<' && kata[x][y-1] != '#'){
				koor.se--;
			}
		}
		if(s.find(koor) == s.end()){
			s.insert(koor);
		}else{
			koorSama = koor;
			break;
		}
	}

	//udah ketemu titik cycle
	int ans = 0;
	vector<ii> v;
	v.pb(koor);
	while(true){
		for(i=0;i<pjg;i++){
			char kar = moves[i];
			int x = koor.fi, y = koor.se;
			if(kar == '^' && kata[x-1][y] != '#'){
				koor.fi--;
				ans++;
				v.pb(koor);
			}else if(kar == 'v' && kata[x+1][y]!='#'){
				koor.fi++;
				ans++;
				v.pb(koor);
			}else if(kar == '>' && kata[x][y+1] != '#'){
				koor.se++;
				ans++;
				v.pb(koor);
			}else if(kar == '<' && kata[x][y-1] != '#'){
				koor.se--;
				ans++;
				v.pb(koor);
			}
		}
		if(koor == koorSama){
			v.pop_back();
			break;
		}
		
	}
	if(v.size() == 0){printf("1\n");}
	else{
		reverse(v.begin(), v.end());
		int ukuran = v.size();
		for(i=1;i<ukuran;i++){
			if(i*2 > ukuran){break;}
			if(ukuran%i != 0){continue;}
			int panjang = i;
			bool isValid = true;
			int iterasi = ukuran/i;
			for(j=1;j<iterasi;j++){
				int idx = j*i;
				for(int k=0;k<i;k++){
					int next = idx + k;
					if(v[k] != v[next]){isValid = false; break;}
				}
				if(!isValid){break;}
			}
			if(isValid){printf("%d\n",i); return 0;}
		}
		printf("%d\n",ukuran);
	}
	return 0;
};