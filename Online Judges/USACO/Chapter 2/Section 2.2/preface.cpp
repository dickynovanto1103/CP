/*
ID: dickyno1
LANG: C++14
TASK: preface
*/

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

int numList[] = {1, 5, 10, 50, 100, 500, 1000};
char romanList[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int specialNumList[] = {4, 9, 40, 90, 400, 900};
string specialRomanList[] = {"IV", "IX", "XL", "XC", "CD", "CM"};

string getRomanOfSimpleNum(int num) {
	for(int i=0;i<6;i++){
		if(specialNumList[i] == num) {
			return specialRomanList[i];
		}
	}

	int maksIdx = -1;
	for(int i=0;i<7;i++){
		if(num >= numList[i]){
			maksIdx = i;
		}else{
			break;
		}
	}

	string ans;

	for(int i=maksIdx;i>=0;i--){
		while(num >= numList[i]) {
			ans += romanList[i];
			num -= numList[i];
		}
	}

	return ans;
}

string convertNumToRoman(int n) {
	string ans;
	int bagi = 10;
	vector<string> list;
	while(n) {
		int mod = n % bagi;
		//process
		list.pb(getRomanOfSimpleNum(mod));

		n -= mod;
		bagi *= 10;
	}
	reverse(list.begin(), list.end());

	for(int i=0;i<list.size();i++){
		ans += list[i];
	}
	return ans;
}

int cnt[256];

int main(){
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);

	int n;
	int i,j;
	scanf("%d",&n);

	for(int i=1;i<=n;i++){
		string roman = convertNumToRoman(i);
		// cout<<i<<" "<<roman<<endl;
		for(int j=0;j<roman.size();j++){
			int c = roman[j];
			cnt[c]++;
			// printf("cnt[%c]: %d\n", c, cnt[c]);
		}
	}

	for(int i=0;i<7;i++){
		if(cnt[romanList[i]]) {
			printf("%c %d\n", romanList[i], cnt[romanList[i]]);
		}
	}
	
	return 0;
};