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

const int maxn = 2e5 + 5;
int counterSubstring[maxn];
int counterChar[256];
int counterTemp[256];
map<string, int> mapper;
map<string, int>::iterator it;

int main(){
	int tc,i,j;
	string a,b;
	scanf("%d",&tc);
	while(tc--){
		memset(counterChar,0,sizeof counterChar);
		memset(counterSubstring,0,sizeof counterSubstring);
		memset(counterTemp,0,sizeof counterTemp);
		mapper.clear();
		cin>>a>>b;
		int pjgA = a.length(), pjgB = b.length();
		for(i=0;i<a.length();i++){
			char kar = a[i];
			counterChar[kar]++;
		}
		//iterasi dulu sampe sepanjang a
		for(i=0;i<a.length();i++){
			char kar = b[i];
			counterTemp[kar]++;
		}
		
		bool isValid = true;
		for(i=97;i<=122;i++){
			if(counterChar[i]!=counterTemp[i]){isValid = false; break;}
		}
		int idx = 0;
		if(isValid){
			string kata = b.substr(0,pjgA);
			// printf("kata: "); cout<<kata<<endl;
			it = mapper.find(kata);
			if(it==mapper.end()){
				mapper[kata] = idx;
				counterSubstring[idx]++;
				idx++;
			}else{
				int indeks = mapper[kata];
				counterSubstring[indeks]++;
			}
		}
		int idxAwal = 0, idxAkhir = pjgA-1;
		while(idxAkhir<(pjgB-1)){
			idxAkhir++;
			char karAkhir = b[idxAkhir];
			counterTemp[karAkhir]++;
			char karAwal = b[idxAwal];
			counterTemp[karAwal]--;
			idxAwal++;

			bool isValid = true;
			for(i=97;i<=122;i++){
				if(counterChar[i]!=counterTemp[i]){isValid = false; break;}
			}
			if(isValid){
				string kata = b.substr(idxAwal,pjgA);
				// printf("kata hasil seleksi: "); cout<<kata<<endl;
				it = mapper.find(kata);
				if(it==mapper.end()){
					mapper[kata] = idx;
					counterSubstring[idx]++;
					idx++;
				}else{
					int indeks = mapper[kata];
					counterSubstring[indeks]++;
				}
			}
		}
		int maks = 0;
		string kataMaks;
		for(it=mapper.begin();it!=mapper.end();it++){
			string kata = it->first;
			int idx = it->second;
			if(maks < counterSubstring[idx]){
				maks = counterSubstring[idx];
				kataMaks = kata;
			}else if(maks == counterSubstring[idx]){
				kataMaks = min(kataMaks,kata);
			}
		}
		if(maks==0){
			printf("-1\n");
		}else{
			// printf("maks: %d\n",maks);
			cout<<kataMaks<<endl;
		}
		
	}
	return 0;
};