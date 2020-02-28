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

string s, temp;
int maks[2001];
int suff[2001];
void awal() {
	int pjg = temp.length();
	memset(suff, 0, sizeof suff);
	int banyak1 = 0;
	for(int i=pjg-1;i>=0;i--){
		if(temp[i] == '1'){
			suff[i] = ++banyak1;
		}
	}
	int zero = 0;
	int res = 0;
	for(int i=0;i<pjg;i++){
		if(suff[i]){
			res = max(res, zero + suff[i]);
		}else{
			zero++;
			res = max(res, zero);
		}
		maks[i] = res;
	}
}

bool valid() {
	int pjg = temp.length();
	memset(suff, 0, sizeof suff);
	int banyak1 = 0;
	for(int i=pjg-1;i>=0;i--){
		if(s[i] == '1'){
			suff[i] = ++banyak1;
		}
	}
	int zero = 0;
	int res = 0;
	for(int i=0;i<pjg;i++){
		if(suff[i]){
			res = max(res, zero + suff[i]);
		}else{
			zero++;
			res = max(res, zero);
		}
		// if(maks[i] != res){
		// 	return false;
		// }
	}
	return res == maks[pjg-1];
	// if(res != maks[pjg-1]){
	// 	return
	// }
	// return true;
}

int main(){
	
	cin>>s;
	temp = s;
	awal();

	bool process = true;
	int n = s.length();
	// for(int i=0;i<n;i++){
	// 	printf("maks[%d]: %d\n",i,maks[i]);
	// }
	for(int i=0;i<n;i++){
		if(s[i] == '1' && process) {

			s[i] = '0';
			//cek masih sama apa ngga
			if(valid()) {

			}else{
				// printf("i: %d ga valid\n",i);
				s[i] = '1';
				process = false;
			}
		}else{
			process = true;
		}
	}
	cout<<s<<endl;
	return 0;
};