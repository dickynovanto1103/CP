/*
ID: dickyno1
LANG: C++14
TASK: transform
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

void printMatrixOfString(vector<string> vs) {
	for(int i=0;i<vs.size();i++){
		cout<<vs[i]<<endl;
	}
}

vector<string> createEmptySquareOfString(int n) {
	vector<string> ans(n);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			ans[i] += " ";
		}
	}
	return ans;
}

vector<string> rotateClockWise(vector<string> vs) {
	int n = vs.size();
	int i,j;
	vector<string> ans = createEmptySquareOfString(n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			int newCol = n - 1 - i;
			int newRow = j;
			ans[newRow][newCol] = vs[i][j];
		}
	}

	return ans;
}

vector<string> reflect(vector<string> vs) {
	int n = vs.size();
	int i,j;
	vector<string> ans = createEmptySquareOfString(n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			int newCol = n - 1 - j;
			int newRow = i;
			ans[newRow][newCol] = vs[i][j];
		}
	}
	return ans;
}

bool isSame(vector<string> s1, vector<string> s2) {
	int n = s1.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s1[i][j] != s2[i][j]) {
				return false;
			}
		}
	}

	return true;
}

bool isRotatedNTimes(vector<string> s1, vector<string> s2, int n) {
	for(int i=0;i<n;i++){
		s1 = rotateClockWise(s1);
	}

	return isSame(s1, s2);
}

bool isReflected(vector<string> s1, vector<string> s2) {
	s1 = reflect(s1);
	return isSame(s1, s2);
}

bool isReflectedThenRotated(vector<string> s1, vector<string> s2) {
	s1 = reflect(s1);
	for(int i=0;i<3;i++) {
		s1 = rotateClockWise(s1);
		if(isSame(s1, s2)) {
			return true;
		}
	}

	return false;
}

int main(){
	int n,i,j;
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	while(scanf("%d",&n) != EOF) {
		cerr<<"Program starts with n: "<<n<<endl;
		vector<string> s1, s2;
		for(i=0;i<n;i++){
			string s;
			cin>>s;
			s1.pb(s);
		}

		for(i=0;i<n;i++){
			string s;
			cin>>s;
			s2.pb(s);
		}

		cerr<<"starting if statements"<<endl;
		if(isRotatedNTimes(s1, s2, 1)) {
			puts("1");
		}else if(isRotatedNTimes(s1, s2, 2)) {
			puts("2");
		}else if(isRotatedNTimes(s1, s2, 3)) {
			puts("3");
		}else if(isReflected(s1, s2)) {
			puts("4");
		}else if(isReflectedThenRotated(s1, s2)) {
			puts("5");
		}else if(isSame(s1, s2)) {
			puts("6");
		}else{
			cerr<<"in else, should go here"<<endl;
			// assert(false);
			printf("7\n");
		}
		cerr<<"finish"<<endl;
	}
	
	
	return 0;
};