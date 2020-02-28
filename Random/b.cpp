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

bool isPalindrome(const string& s, int start, int end) {
	int i,j;

	while(start <= end){
		if(s[start] != s[end]){
			return false;
		}else{
			start++; end--;
		}
	}
	return true;
}

int main(){
	string s;
	cin>>s;
	int n,i,j;
	n = s.length();
	if(n <= 2){
		printf("YES\n");
		return 0;
	}
	int left = 0, right = n-1;
	bool valid = true;
	while(left <= right) {
		if(s[left] != s[right]){
			bool temp = isPalindrome(s, left+1, right) | isPalindrome(s, left, right-1);
			valid = temp;
			break;
		}else{
			left++; right--;
		}
	}
	if(valid){printf("YES\n");}
	else{printf("NO\n");}
	return 0;
};