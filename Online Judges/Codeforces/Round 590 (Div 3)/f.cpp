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

int ans = 1;
string s;

void reset(int* counter, int* cnt) {
	for(int i=0;i<20;i++){
		counter[i] = cnt[i];
	}
}

bool can(int mid) {
	int i,j;
	int cnt[20];
	memset(cnt, 0, sizeof cnt);
	int cntMoreThan1 = 0;
	int n = s.length();
	for(i=0;i<mid;i++){
		int idx = s[i] - 'a';
		cnt[idx]++;
		if(cnt[idx] == 2) {
			cntMoreThan1++;
		}
	}

	int kiri = 0, kanan = mid-1;
	while(cntMoreThan1 && kanan < n-1) {
		cnt[s[kiri] - 'a']--;
		if(cnt[s[kiri] - 'a'] == 1) {
			cntMoreThan1--;
		}
		kiri++;
		kanan++;
		cnt[s[kanan] - 'a']++;
		if(cnt[s[kanan] - 'a'] == 2) {
			cntMoreThan1++;
		}
	}
	if(cntMoreThan1){
		return false;
	}else{
		//sudah kebentuk dari kiri sampe kanan
		// printf("mid: %d\n",mid);
		ans = max(ans, mid);
		int counter[20];
		int temp[20];
		reset(counter, cnt);
		memset(temp, 0, sizeof temp);
		int l = 0;
		for(i=0;i<kiri;i++){
			counter[s[i] - 'a']++;
			temp[s[i] - 'a']++;
			if(counter[s[i] - 'a'] == 2) {
				assert(i-l >= 0);
				ans = max(ans, mid + i - l);
				if(temp[s[i] - 'a'] == 1) {
					l = i+1;
				}else{
					l = i;
					i--;
				}
				memset(temp, 0, sizeof temp);
				reset(counter, cnt);
			}
		}
		assert(i-l >= 0);
		ans = max(ans, mid + i - l);
		int r = n-1;
		reset(counter, cnt);
		memset(temp, 0, sizeof temp);
		for(i=n-1;i>kanan;i--){
			// printf("i: %d\n",i);
			counter[s[i] - 'a']++;
			temp[s[i] - 'a']++;
			if(counter[s[i] - 'a'] == 2) {
				assert(r-i >= 0);
				ans = max(ans, mid + r - i);
				if(temp[s[i] - 'a'] == 1) {
					r = i-1;	
				}else{
					r = i;
					i++;
				}
				memset(temp, 0, sizeof temp);
				reset(counter, cnt);
			}
		}
		assert(r-i >= 0);
		ans = max(ans, mid+r-i);
		return true;
	}
}

int main(){
	
	while(cin>>s){
		ans = 1;
		int n = s.length();
		int kiri = 1, kanan = n, mid;
		while(kiri <= kanan) {
			mid = (kiri+kanan)/2;
			if(can(mid)) {
				kiri = mid+1;
			}else{
				kanan = mid-1;
			}
		}
		printf("%d\n",ans);	
	}
	
	return 0;
};