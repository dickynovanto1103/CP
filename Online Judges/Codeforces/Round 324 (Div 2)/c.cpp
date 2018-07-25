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

int numOfDiff(string a, string b){
	int pjg = a.length();
	int cnt = 0;
	for(int i=0;i<pjg;i++){
		if(a[i] != b[i]){cnt++;}
	}
	return cnt;
}

int main(){
	int n,t,i,j;
	string ans = "";
	int bedaAwal = 0;
	scanf("%d %d",&n,&t);
	bedaAwal = t;
	string kata1,kata2;
	cin>>kata1>>kata2;
	for(i=0;i<n;i++){ans+='a';}
	vi listIdxBeda, listIdxSama;
	for(i=0;i<n;i++){
		if(kata1[i] == kata2[i]){
			listIdxSama.pb(i);
		}else{
			listIdxBeda.pb(i);
		}
	}

	if(t==0){
		if(kata1 == kata2){cout<<kata1<<endl;}
		else{printf("-1\n");}
		return 0;
	}

	int ukuranBeda = listIdxBeda.size();
	srand(time(NULL));
	
	//ambil 2"terus sampe sama
	int idxAwal = 0;
	bool sudahSama = false;
	// printf("ukuranBeda: %d ukuranSama: %d\n", ukuranBeda, (int)listIdxSama.size());
	while(true){
		if(ukuranBeda <= t){sudahSama = true; break;}
		if(idxAwal == (listIdxBeda.size()-1)){//tepat diujung
			sudahSama = true; break;
		}
		int idx1 = listIdxBeda[idxAwal], idx2 = listIdxBeda[idxAwal+1];
		
		ans[idx1] = kata1[idx1]; ans[idx2] = kata2[idx2];
		// printf("ans[%d] jd: %c ans[%d] jd: %c\n",idx1,ans[idx1], idx2,ans[idx2]);
		// printf("ans[%d]: %\n", );
		ukuranBeda-=2; t--;
		idxAwal+=2;
		// printf("ukuranBeda: %d t: %d\n",ukuranBeda, t);
		if(t==0){break;}
		if(ukuranBeda == t){sudahSama = true; break;}
	}
	// printf("idxAwal: %d\n",idxAwal, );
	if(sudahSama){
		for(i=idxAwal;i<listIdxBeda.size();i++){
			if(t==0){break;}

			int idx = listIdxBeda[i];
			// printf("idx: %d\n",idx);
			char kar1 = kata1[idx], kar2 = kata2[idx];

			char karBaru = (rand() % 26) + 'a';
			while(karBaru == kar1 || karBaru == kar2){
				karBaru = (rand() % 26) + 'a';
			}
			ans[idx] = karBaru;
			// printf("karBaru: %c\n",karBaru);
			t--;
			if(t==0){break;}
		}
	}
	int idxTerakhirSama = -1;
	while(true){
		if(t==0){break;}
		for(i=0;i<listIdxSama.size();i++){
			int idx = listIdxSama[i];
			// printf("idx: %d\n",idx);
			char kar = kata1[idx];
			char karBaru = (kar + 1);
			if(karBaru>'z'){karBaru = 'a';}
			ans[idx] = karBaru;
			// printf("karBaru: %c\n",karBaru);
			t--;
			idxTerakhirSama = i;
			if(t==0){break;}
		}
		break;
	}

	for(i=idxTerakhirSama+1;i<listIdxSama.size();i++){
		// printf("i: %d\n",i);
		int idx = listIdxSama[i];
		char kar = kata1[idx];
		ans[idx] = kar;
	}
	
	// cout<<ans<<endl;
	// printf("ans sementara: "); cout<<ans<<endl;
	int diff1 = numOfDiff(ans, kata1);
	int diff2 = numOfDiff(ans, kata2);
	if(diff1 == diff2 && diff1 == bedaAwal){
		cout<<ans<<endl;
	}else{
		printf("-1\n");
	}
	
	return 0;
};