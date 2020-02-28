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

bool isOperator(char c) {
	return c == '|' || c == '&' || c == '^';
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		string s;
		cin>>s;
		int n = s.length();
		stack<char> st;
		//dua kali evaluasi..pertama andaikan x = 1
		for(i=0;i<n;i++){
			if(s[i] == '(') {
				continue;
			}else if(s[i] == ')'){
				int bil1 = st.top() - '0'; st.pop();
				char op = st.top(); st.pop();
				int bil2 = st.top() - '0'; st.pop();
				int ans;
				if(op == '^'){
					ans = bil1 ^ bil2;
				}else if(op == '|') {
					ans = bil1 | bil2;
				}else{
					ans = bil1 & bil2;
				}
				st.push(ans + '0');
			}else if(isOperator(s[i]) || s[i] == '0' || s[i] == '1') {
				st.push(s[i]);
			}else if(s[i] == 'x') {
				st.push('1');
			}else if(s[i] == 'X'){
				st.push('0');
			}
		}
		assert(st.size() == 1);
		int hasil1 = st.top() - '0'; st.pop();
		//x = 0;
		for(i=0;i<n;i++){
			if(s[i] == '(') {
				continue;
			}else if(s[i] == ')'){
				int bil1 = st.top() - '0'; st.pop();
				char op = st.top(); st.pop();
				int bil2 = st.top() - '0'; st.pop();
				int ans;
				if(op == '^'){
					ans = bil1 ^ bil2;
				}else if(op == '|') {
					ans = bil1 | bil2;
				}else{
					ans = bil1 & bil2;
				}
				st.push(ans + '0');
			}else if(isOperator(s[i]) || s[i] == '0' || s[i] == '1') {
				st.push(s[i]);
			}else if(s[i] == 'x') {
				st.push('0');
			}else if(s[i] == 'X'){
				st.push('1');
			}
		}
		assert(st.size() == 1);
		int hasil2 = st.top() - '0'; st.pop();
		if(hasil1 == hasil2){printf("0\n");}
		else{
			printf("1\n");
		}
	}
	return 0;
};