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
typedef pair<string, string> ss;
typedef vector<ii> vii;

ss getLeftAndRight(string s, char denominator) {
	string left, right;
	bool isLeft = true;
	for(char c: s) {
		if(c == denominator) {
			isLeft = false;
			continue;
		}

		if(isLeft) {
			left += c;
		}else{
			right += c;
		}
	}

	return ss(left, right);
}

unordered_map<char, int> values = {
	{'M', 1000},
	{'D', 500},
	{'C', 100},
	{'L', 50},
	{'X', 10},
	{'V', 5},
	{'I', 1},
};

int rToA(string s) {
	int res = 0;
	for(int i=0;s[i];i++){
		if(s[i+1] && values[s[i+1]] > values[s[i]]) {
			res += values[s[i + 1]] - values[s[i]];
			i++;
		}else{
			res += values[s[i]];
		}
	}

	return res;
}

bool isBeginZero(string s, unordered_map<char, int> mapper) {
	return mapper[s[0]] == 0;
}

int correctAns = 0;

int formInteger(string s, unordered_map<char, int> mapper) {
	int ans = 0;
	for(char c: s) {
		ans *= 10;
		ans += mapper[c];
	}

	// cout<<s<<" "<<ans<<endl;

	return ans;
}

void printBinary(int mask) {
	for(int i=0;i<10;i++){
		if(mask & (1<<i)) {
			printf("1");
		}else{
			printf("0");
		}
	}
	puts("");
}

void getRes(string s1, string s2, string right, vector<char> chars, int lenUniqueChars, int mask, int startIdx) {
	if(correctAns == 2) {
		return;
	}

	if(__builtin_popcount(mask) == lenUniqueChars) {
		vi ones;
		for(int i=0;i<10;i++) {
			//assign chars to number
			if(mask & (1<<i)) {
				ones.pb(i);
			}
		}

		do {
			// printBinary(mask);
			// printf("mask: %d, printing el:", mask);
			unordered_map<char, int> mapper;
			for(int i=0;i<chars.size();i++) {
				char c = chars[i];
				mapper[c] = ones[i];
				// printf(" %d", ones[i]);
				// printf("mapper[%c]: %d\n", c, mapper[c]);
			}
			// puts("");

			if(isBeginZero(s1, mapper) || isBeginZero(s2, mapper) || isBeginZero(right, mapper)) {
				// printf("continue here\n");
				continue;
			}

			if(formInteger(s1, mapper) + formInteger(s2, mapper) == formInteger(right, mapper)) {
				correctAns++;
				// printf("correctAns: %d\n", correctAns);
				// for(int el: ones) {
				// 	printf("%d ", el);
				// }
				// puts("");
				// for(auto const& pair: mapper) {
				// 	printf("char: %c mapped to integer: %d\n", pair.first, pair.second);
				// }
				if(correctAns == 2) {
					break;
				}
			}
			
		}while(next_permutation(ones.begin(), ones.end()));

		return;
	}

	for(int i=startIdx;i<10;i++){
		if(!(mask & (1<<i))) {
			getRes(s1, s2, right, chars, lenUniqueChars, mask | (1<<i), i);
			if(correctAns == 2) {
				break;
			}
		}
	}
}

void tryAllCombination(string s1, string s2, string right) {
	set<char> chars;
	set<char>::iterator it;
	for(char c: s1) {
		chars.insert(c);
	}

	for(char c: s2) {
		chars.insert(c);
	}

	for(char c: right) {
		chars.insert(c);
	}

	vector<char> uniqueChars;
	for(it=chars.begin();it != chars.end();it++) {
		uniqueChars.pb(*it);
	}

	int lenOfUniqueChards = uniqueChars.size();
	// printf("lenOfUniqueChards: %d\n", lenOfUniqueChards);

	getRes(s1, s2, right, uniqueChars, lenOfUniqueChards, 0, 0);
}


void solve(){
	string exp;
	while(cin>>exp, exp != "#") {
		ss leftAndRight = getLeftAndRight(exp, '=');
		ss leftValues = getLeftAndRight(leftAndRight.first, '+');
		// cout<<"TEST "<<leftAndRight.first<<"="<<leftAndRight.second<<endl;
		// cout<<"TESTING "<<leftValues.first<<"+"<<leftValues.second<<endl;

		string ans1;
		if(rToA(leftValues.first) + rToA(leftValues.second) == rToA(leftAndRight.second)) {
			ans1 = "Correct";
		}else{
			ans1 = "Incorrect";
		}

		correctAns = 0;
		tryAllCombination(leftValues.first, leftValues.second, leftAndRight.second);
		cout<<ans1<<" ";
		if(correctAns == 2) {
			puts("ambiguous");
		}else if(correctAns == 1) {
			puts("valid");
		}else{
			puts("impossible");
		}
	}
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};