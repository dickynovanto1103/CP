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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string intToBin(int n) {
	string ans = "";
	while(n){
		int mod = n%2;
		ans += mod + '0';
		n/=2;
	}
	int pjg = ans.size();
	reverse(ans.begin(), ans.end());
	int selisih = 5 - pjg;
	for(int i=0;i<selisih;i++){
		ans = '0' + ans;
	}
	return ans;
}

int main(){
	int tc,n,b,f;
	int i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&n,&b,&f);
		vi broken;
		string query[11];
		for(i=0;i<f;i++){
			query[i] = "";
			for(j=0;j<n;j++){
				query[i] += '0';
			}
		}

		for(i=0;i<n;i++){
			int angka = i%(1<<f);
			// printf("angka: %d\n",angka);
			for(j=0;j<f;j++){
				if(angka & (1<<j)) {
					query[j][i] = '1';
				}
			}
		}
		// for(i=0;i<f;i++){
		// 	cout<<query[i]<<endl;
		// }
		string jawab[11];
		for(i=0;i<f;i++){
			// printf("i: %d\n",i);
			cout<<query[i]<<endl;
			fflush(stdout);
			cin>>jawab[i];
			if(jawab[i] == "-1"){return 0;}
		}
		int idx = 0;
		for(i=0;i<n;i++){
			//apakah ke i rusak?
			bool isSama = true;
			for(j=0;j<f;j++){
				if(jawab[j][idx] != query[j][i]){isSama = false; break;}
			}
			if(!isSama){broken.pb(i);}
			else{idx++;}
		}

		for(i=0;i<broken.size();i++){
			if(i){printf(" ");}
			printf("%d",broken[i]);
		}
		printf("\n");
		fflush(stdout);
		int verdict;
		cin>>verdict;
		if(verdict == -1){return 0;}
		else{continue;}
	}
	return 0;
};