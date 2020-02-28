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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isAlphabet(char a){
	return a >= 'a' && a <= 'z' && a>='A' && a<= 'Z';
}

int main(){
	int banyak = 0;
	string ka;
	getline(cin,ka);
	int i,j;
	for(i=0;i<ka.length();i++){
		if(ka[i] == ' '){
			banyak++;
		}
	}
	banyak++;
	int n;
	scanf("%d",&n);
	// printf("banyak: %d n: %d\n",banyak, n);
	string s[101];
	vi v;
	for(i=0;i<n;i++){
		cin>>s[i];
		v.pb(i);
	}
	vi satu, dua;
	int idx = -1;
	bool isSatu = true;
	for(i=0;i<n;i++){
		for(j=0;j<banyak;j++){
			idx++;
			idx %= v.size();
			// printf("idx jd: %d\n",v[idx]);
		}
		if(isSatu){
			satu.pb(v[idx]);
			isSatu = false;
		}else{
			dua.pb(v[idx]);
			isSatu = true;
		}
		// printf("hapus idx :%d\n",v[idx]);
		v.erase(v.begin() + idx);
		idx--;
		// printf("sekarang: ");
		// for(j=0;j<v.size();j++){
		// 	printf("%d ",v[j]);
		// }
		// printf("\n");
	}
	printf("%d\n",(int)satu.size());
	for(i=0;i<satu.size();i++){
		cout<<s[satu[i]]<<endl;
	}
	printf("%d\n",(int)dua.size());
	for(i=0;i<dua.size();i++){
		cout<<s[dua[i]]<<endl;
	}
	return 0;
};