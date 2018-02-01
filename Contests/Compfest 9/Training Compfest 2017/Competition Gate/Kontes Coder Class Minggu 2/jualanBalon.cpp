#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<char> listKar[25];
queue<int> q0,q1,q2;

bool isAllEmpty(){
	return (q0.empty() && q1.empty() && q2.empty());
}
int main() {
	int tc,n,i,j;
	int kelompok[270];
	kelompok['m'] = kelompok['k'] = kelompok['b'] = 0; 
	kelompok['a'] = kelompok['p'] = 1;
	kelompok['h'] = 2;

	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Kasus #%d\n",tt);
		scanf("%d",&n);
		cin>>ws;
		string kata;
		for(i=0;i<n;i++){
			getline(cin,kata);
			int ukuran = kata.length();
			for(j=0;j<ukuran;j++){
				if(kata[j]!=' '){listKar[i].pb(kata[j]);}
			}
			reverse(listKar[i].begin(),listKar[i].end());
		}
		/*for(i=0;i<n;i++){
			printf("listKar ke: %d:",i);
			for(j=0;j<listKar[i].size();j++){
				printf(" %c",listKar[i][j]);
			}
			printf("\n");
		}*/
		
		for(i=0;i<n;i++){//nata antrian di awal
			int ukuran = listKar[i].size();
			char kar = listKar[i][ukuran-1];
			if(kelompok[kar]==0){q0.push(i);}
			else if(kelompok[kar]==1){q1.push(i);}
			else if(kelompok[kar]==2){q2.push(i);}
		}
		/*printf("q0 awal:\n");
		while(!q0.empty()){
			printf("%d ",q0.front()); q0.pop();
		}
		printf("\n");
		printf("q1 awal:\n");
		while(!q1.empty()){
			printf("%d ",q1.front()); q1.pop();
		}
		printf("\n");
		printf("q2 awal:\n");
		while(!q2.empty()){
			printf("%d ",q2.front()); q2.pop();
		}
		printf("\n");*/
		vi ans;
		vi::iterator it;
		while(true){
			for(i=0;i<3;i++){
				int idx=-1;
				int dari = -1;
				if(i==0){
					if(!q0.empty()){idx = q0.front(); q0.pop(); dari = 0;}	
				}else if(i==1){
					if(!q1.empty()){idx = q1.front(); q1.pop(); dari = 1;}
				}else{
					if(!q2.empty()){idx = q2.front(); q2.pop(); dari = 2;}
				}
				if(idx==-1){continue;}//ga perlu diproses klo lagi ga ada antrian di line itu
				//cek apakah dia pelanggan terakhir
				
				ans.pb(idx);
				int cnt = 0;
				int ukuran = listKar[idx].size();
				char kar = listKar[idx][ukuran-1];
				int batas;
				bool KosongSekitar = false;
				for(j=0;j<3;j++){
					//if(j!=dari){
					if(j==0){if(!q0.empty()){break;}}
					else if(j==1){if(!q1.empty()){break;}}
					else{if(!q2.empty()){break;}}
					//}
				}
				if(j<3){batas = 5;}
				else{batas = inf;}
				while(cnt<batas && kelompok[kar]==i){
					listKar[idx].pop_back();
					ukuran = listKar[idx].size();
					if(ukuran==0){break;}
					kar = listKar[idx][ukuran-1];
					cnt++;
				}
				ukuran = listKar[idx].size();
				if(ukuran>0){
					kar = listKar[idx][ukuran-1];
					if(kelompok[kar]==0){q0.push(idx);}
					else if(kelompok[kar]==1){q1.push(idx);}
					else{q2.push(idx);}
				}
				if(isAllEmpty()){break;}
				

			}
			if(isAllEmpty()){break;}
		}
		//it=unique(ans.begin(),ans.end());
		//ans.resize(distance(ans.begin(),it));
		int ukuran = ans.size();
		for(i=0;i<ukuran;i++){
			printf("Pembeli #%d\n",ans[i]+1);
		}
		ans.clear();
	}
	return 0;
}