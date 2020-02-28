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
int maks[100001];
int diff[100001];
int mindiff[100001];
int asli[100001];
int suff[100001];
int nextt[100001];
void awal() {
	int pjg = temp.length();
	memset(suff, 0, sizeof suff);
	int banyak1 = 0;

	for(int i=pjg-1;i>=0;i--){
		if(temp[i] == '1'){
			suff[i] = ++banyak1;
		}
	}
	vi list0;
	char cur = 'a';
	for(int i=0;i<pjg;i++){
		if(temp[i] == '0' && cur != '0') {
			list0.pb(i);
		}
		cur = temp[i];
	}
	for(int i=0;i<pjg;i++){
		if(temp[i] == '1') {
			int idx = lower_bound(list0.begin(), list0.end(), i) - list0.begin();
			if(idx == list0.size()){
				nextt[i] = pjg;
			}else{
				nextt[i] = list0[idx];
			}
		}
	}
	int zero = 0;
	int res = 0;
	for(int i=0;i<pjg;i++){
		if(suff[i]){
			res = max(res, zero + suff[i]);
			asli[i] = zero + suff[i];
		}else{
			zero++;
			res = max(res, zero);
			asli[i] = zero;

		}
		maks[i] = res;
		diff[i] = maks[i] - asli[i];
	}
	mindiff[pjg-1] = diff[pjg-1];
	for(int i=pjg-2;i>=0;i--){
		mindiff[i] = min(mindiff[i+1], diff[i]);
	}
}

bool valid(int idx, int pengurangan) {
	int pjg = temp.length();
	int idxnext = nextt[idx];
	if(mindiff[idxnext] - pengurangan >= 0) {
		return true;
	}else{
		return false;
	}
}

int main(){
	
	cin>>s;
	temp = s;
	awal();

	bool process = true;
	int n = s.length();
	for(int i=0;i<n;i++){
		printf("maks[%d]: %d\n",i,maks[i]);
		printf("asli[%d]: %d\n",i, asli[i]);
		printf("diff[%d]: %d mindiff: %d\n",i,diff[i], mindiff[i]);
	}
	int pengurangan = 0;
	for(int i=0;i<n;i++){
		if(s[i] == '1' && process) {
			s[i] = '0';
			//cek masih sama apa ngga
			if(valid(i, pengurangan)) {
				pengurangan++;
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