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

vi a,listBintang;
string kata;
bool isValid(string kataSekarang){
	int pjg = a.size();
	for(int i=0;i<pjg;i++){
		int idx = a[i];
		if(kata[idx]!=kataSekarang[idx]){return false;}
	}
	return true;
}

int main(){
	int n,i,j,m;
	
	string listKata[1010];
	scanf("%d",&n);
	cin>>kata;
	set<char> s, belum;
	set<char>::iterator it;
	for(i=0;i<n;i++){
		if(kata[i]!='*'){a.pb(i); s.insert(kata[i]);}
		else{listBintang.pb(i);}
	}

	scanf("%d",&m);
	for(i=0;i<m;i++){
		cin>>listKata[i];
	}
	//printf("kata: "); cout<<kata<<endl;
	vi listIdxValid;
	for(i=0;i<m;i++){
		if(!isValid(listKata[i])){continue;}
		string word = listKata[i];
		bool foundValid = true;
		for(j=0;j<listBintang.size();j++){
			int idx = listBintang[j];
			//printf("idx: %d\n", idx);
			// belum.insert(word[idx]);
			// printf("yang diinsert kar: %c\n",word[idx]);
			if(s.count(word[idx])){
				foundValid = false;
				break;
			}
		}
		if(foundValid){
			listIdxValid.pb(i);
			for(j=0;j<listBintang.size();j++){
				int idx = listBintang[j];
				belum.insert(word[idx]);
				//printf("yang diinsert kar: %c\n",word[idx]);
			}
		}
	}
	int ans = 0;
	for(it=belum.begin(); it!=belum.end(); it++){
		char kar = *it;
		//printf("kar: %c\n",kar);
		int ukuranKataValid = listIdxValid.size();
		int ukuranKosong = listBintang.size();
		bool foundValid = true;
		for(i=0;i<ukuranKataValid;i++){
			int idx = listIdxValid[i];
			string word = listKata[idx];
			for(j=0;j<ukuranKosong;j++){
				int idx1 = listBintang[j];
				if(word[idx1]==kar){break;}
			}
			if(j==ukuranKosong){foundValid = false; break;}
		}
		if(foundValid){
			//printf("karakter: %c benar\n",kar);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
};