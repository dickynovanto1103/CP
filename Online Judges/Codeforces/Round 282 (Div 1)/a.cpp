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
#define debug if(false)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	string s;
	while(cin>>s){
		int n,i,j;
		n = s.length();
		int pref[100001];
		int idxLast = -1;
		for(i=n-1;i>=0;i--){
			if(s[i] == '#'){idxLast = i; break;}
		}
		int cntpagar = 0;
		bool valid = true;
		for(i=0;i<n;i++){
			if(s[i] == '('){
				pref[i] = 1;
			}else if(s[i] == ')'){
				pref[i] = -1;
			}else if(s[i] == '#'){
				pref[i] = -1;
				cntpagar++;
			}
			if(i){pref[i] += pref[i-1];}
			if(pref[i] < 0){valid = false; break;}
		}
		int tambah = pref[n-1];
		for(i=idxLast;i<n;i++){
			pref[i] -= pref[n-1];
			if(pref[i] < 0){valid = false; break;}
		}
		if(!valid){
			printf("-1\n"); continue;
		}

		for(i=0;i<cntpagar-1;i++){
			printf("1\n");
		}
		debug printf("idxLast: %d pref[%d]: %d\n",idxLast, idxLast, pref[idxLast]);
		printf("%d\n\n",1+tambah);	
	}
	

	return 0;
};