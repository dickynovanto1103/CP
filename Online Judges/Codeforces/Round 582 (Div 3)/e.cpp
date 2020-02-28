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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isOk(string s, string a, string b){
	return s.find(a) == -1 && s.find(b) == -1;
}

bool isSama(string a) {
	return a[0] == a[1];
}

char getMissing(string a) {
	int i,j;
	for(i=0;i<3;i++){
		char kar = i + 'a';
		bool found = false;
		for(j=0;j<2;j++){
			if(a[j] == kar){found = true; break;}
		}
		if(!found){return kar;}
	}
	return 'a';
}

int main(){
	int n,i,j;
	string a,b;
	scanf("%d",&n);
	cin>>a>>b;
	
	string temp = "";
	string ans;
	int cntSama = 0;
	if(isSama(a)){cntSama++;}
	if(isSama(b)){cntSama++;}
	if(cntSama == 2) {
		printf("YES\n");
		for(i=0;i<n;i++){
			printf("abc");
		}
		printf("\n");
	}else if(cntSama == 1) {
		if(isSama(a)){
			char miss = getMissing(b);

			string pertama;
			pertama.pb(b[1]);
			pertama += miss;

			string kedua;
			kedua.pb(miss);
			kedua += b[0];
			bool found = false;
			if(pertama == a || pertama == b || kedua == a || kedua == b){

			}else{
				found = true;
				string rev = b;
				reverse(rev.begin(), rev.end());
				string jawab = rev + miss;
				printf("YES\n");
				for(i=0;i<n;i++){cout<<jawab;}
				printf("\n");
				return 0;
			}

		}else if(isSama(b)) {
			char miss = getMissing(a);

			string pertama;
			pertama.pb(a[1]);
			pertama += miss;

			string kedua;
			kedua.pb(miss);
			kedua += a[0];
			bool found = false;
			if(pertama == a || pertama == b || kedua == a || kedua == b){

			}else{
				found = true;
				string rev = a;
				reverse(rev.begin(), rev.end());
				string jawab = rev + miss;
				printf("YES\n");
				for(i=0;i<n;i++){cout<<jawab;}
				printf("\n");
				return 0;
			}
		}
	}else{
		for(int tt=0;tt<n;tt++){
			bool valid = false;	
			char kata[] = {'a', 'b', 'c'};
			do {
				string s;
				for(i=0;i<3;i++){
					s += kata[i];
				}
				if(isOk(s, a, b)){
					printf("YES\n");
					for(i=0;i<3;i++){
						for(j=0;j<n;j++){
							printf("%c",s[i]);
						}	
					}
					printf("\n");
					return 0;
				}
			}while(next_permutation(kata, kata+3));	
		}
		printf("YES\n");
		cout<<ans<<endl;
	}
	
	
	

	
	return 0;
};