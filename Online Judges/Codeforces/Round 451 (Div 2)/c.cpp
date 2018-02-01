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

set<string> s[25];
set<string>::iterator it2;

bool isSuffix(string a, string b){
	int pjg1 = a.length(), pjg2 = b.length();
	int idx = 0;
	int i;
	for(i=pjg2-pjg1;i<pjg2;i++){
		if(b[i]!=a[idx]){return false;}
		idx++;
	}
	return true;
}

int main(){
	int n,i,j;
	map<string,int> mapper;
	map<string,int>::iterator it;
	string kata;
	int cnt = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int banyak;
		cin>>kata>>banyak;
		it = mapper.find(kata);
		if(it==mapper.end()){
			mapper[kata] = cnt++;
		}
		int idx = mapper[kata];
		for(j=0;j<banyak;j++){
			string number;
			cin>>number;
			s[idx].insert(number);
		}

	}
	for(it=mapper.begin();it!=mapper.end();it++){
		string orang = it->first;
		int idx = it->second;
		vector<string> listNomor;
		//printf("idx: %d\n",idx);
		for(it2=s[idx].begin();it2!=s[idx].end();it2++){
			listNomor.pb(*it2);
			//cout<<*it2<<endl;
		}
		int ukuran = listNomor.size();
		for(i=0;i<ukuran;i++){
			string kata1 = listNomor[i];
			for(j=i+1;j<ukuran;j++){
				string kata2 = listNomor[j];
				bool isHapus;
				if(s[idx].count(kata1) && s[idx].count(kata2)){
					if(kata1.length()<kata2.length()){
						isHapus = isSuffix(kata1,kata2);
						if(isHapus){s[idx].erase(kata1);}
					}else if(kata1.length()>kata2.length()){
						isHapus = isSuffix(kata2,kata1);
						if(isHapus){s[idx].erase(kata2);}
					}	
				}
				
			}
		}
	}
	printf("%d\n",(int)mapper.size());
	for(it=mapper.begin();it!=mapper.end();it++){
		int idx = it->second;
		int ukuran = s[idx].size();
		cout<<it->first<<" "<<ukuran;
		for(it2=s[idx].begin();it2!=s[idx].end();it2++){
			cout<<" "<<*it2;
		}
		printf("\n");
	}
	return 0;
};