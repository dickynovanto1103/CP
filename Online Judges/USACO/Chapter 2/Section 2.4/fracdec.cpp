/*
ID: dickyno1
LANG: C++14
TASK: fracdec
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

int occurs[100010];

string cleanup(string s) {
	int i;
	int idxBuka = -1, idxTutup = -1;
	for(i=0;i<s.size();i++){
		if(s[i] == '(') {
			idxBuka = i;
		}else if(s[i] == ')') {
			idxTutup = i;
		}
	}

	assert(idxBuka != -1 && idxTutup != -1);

	bool ok = false;
	for(i=idxBuka+1;i < idxTutup;i++){
		if(s[i] != '0') {
			ok = true;
			break;
		}
	}

	if(!ok) {
		// cout<<"s is not ok:"<<s<<" idxBuka: "<<idxBuka<<endl;
		return s.substr(0, idxBuka);
	}
	return s;
}

void printS(string s) {
	for(int i=0;i<s.size();i++){
		printf("%c", s[i]);
		if(i%76 == 75) {
			printf("\n");
		}
	}
	puts("");
}

string convertBilToStr(int bil) {
	if(bil == 0){
		return "0";
	}
	string s;
	while(bil) {
		int digit = bil % 10;
		s += digit + '0';
		bil /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main(){
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);

	int a,b;
	while(scanf("%d %d",&a,&b) != EOF) {
		// printf("a: %d b: %d\n", a, b);
		if(a % b == 0){
			printf("%d.0\n", a/b);
			continue;
		}
		memset(occurs, 0, sizeof occurs);
		string s;
		bool first = true;
		int len = 1;

		while(!occurs[a]) {
			occurs[a] = len;
			if(a < b) {
				if(first) {
					s += "0.";
					first = false;
				}
				a *= 10;
			}
			int bil = a / b;
			string conversion = convertBilToStr(bil);
			// cout<<"bil: "<<bil<<" converted: "<<conversion<<endl;
			s += conversion;
			// cout<<"bil: "<<bil<<" s sekarang: "<<s<<endl;
			if(first) {
				s += '.';
				first = false;
			}
			a = a % b;
			len++;
		}
		int panjangCycle = len - occurs[a];
		// printf("panjangCycle: %d s size: %d\n", panjangCycle, (int)s.size());
		// 0.149253731343283582895522388597

		//change s first to add the parantheses
		string newS;
		for(int i=0;i<s.size();i++){
			newS += s[i];
			if(i == (s.size() - panjangCycle - 1)) {
				newS += '(';
			}
		}
		newS += ')';
		// cout<<"newS:"<<newS<<endl;

		newS = cleanup(newS);
		printS(newS);
		// cout << s<<" newS:"<<newS<< " len: "<<len<<" panjangCycle: "<<panjangCycle<<endl;
	}
	
	return 0;
};
328632975046141