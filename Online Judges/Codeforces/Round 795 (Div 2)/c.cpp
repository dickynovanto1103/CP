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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int strToInt(string s) {
	int ans = 0;
	for(int i=0;i<s.size();i++){
		char c = s[i];
		ans *= 10;
		ans += (c - '0');
	}
	return ans;
}

int compute(string s) {
	int ans = 0;
	int n = s.size();
	for(int i=0;i<n-1;i++){
		string newStr = s.substr(i, 2);
		ans += strToInt(newStr);
	}
	return ans;
}

string shiftToRight(int idx, string s){
	for(int i=idx;i<s.size() - 1;i++){
		swap(s[i], s[i+1]);
	}
	return s;
}

string shiftToLeft(int idx, string s) {
	for(int i=idx;i>=1;i--){
		swap(s[i], s[i-1]);
	}
	return s;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,swap;
		scanf("%d %d",&n,&swap);
		string s;
		cin>>s;
		int first1 = -1, last1 = -1;
		for(int i=0;i<n;i++){
			if(s[i] == '1'){
				if(first1 == -1) first1 = i;
				last1 = i;
			}
		}

		if(first1 == -1) {
			puts("0");
			continue;
		}

		if(first1 == last1) {
			int kanan = n - first1 - 1;
			int kiri = first1;
			if(kanan <= swap) {
				s = shiftToRight(first1, s);
				printf("1\n");
				continue;
			}

			if(kiri <= swap) {
				s = shiftToLeft(first1, s);
				printf("10\n");
				continue;
			}

			puts("11");
			continue;
		}

		// printf("hello\n");

		int kanan = n - last1 - 1;
		int kiri = first1;
		// printf("kanan: %d kiri: %d swap: %d\n", kanan, kiri, swap);
		if(kanan <= swap) {
			s = shiftToRight(last1, s);
			swap -= kanan;
		}

		if(kiri <= swap) {
			s = shiftToLeft(first1, s);
		}

		printf("%d\n", compute(s));
	}
	
	return 0;
};