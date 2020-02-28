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
#define debug if(false)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isBigger(string a, string b) {
	int pjg = a.length();
	int i,j;
	for(i=0;i<pjg;i++){
		if(a[i] > b[i]){
			return true;
		}else if(a[i] < b[i]){
			return false;
		}
	}
	return false;
}

string plus1(string a) {
	int pjg = a.length();
	int i,j;
	int carry = 0;
	if(a[pjg-1] == '9'){
		carry = 1;
		a[pjg-1] = '0';
	}else{
		a[pjg-1]++;
	}
	for(i=pjg-2;i>=0;i--){
		if(carry){
			if(a[i] == '9'){
				a[i] = '0';
				carry = 1;
			}else{
				a[i]++;
				carry = 0;
				break;
			}
		}else{
			break;
		}
	}
	if(carry){
		string ans = "1";
		for(i=0;i<pjg-1;i++){
			ans += '0';
		}
		return ans;
	}else{
		return a;
	}
}

int main(){
	int n,i,j;
	string s;
	scanf("%d",&n);
	cin>>s;
	int pjg = s.length();
	if(pjg % n == 0){
		string ans = "";
		string temp;
		for(i=0;i<n;i++){
			ans += s[i];
		}
		temp = ans;
		while(ans.length() < pjg){
			ans += temp;
		}
		
		if(isBigger(ans, s)){
			cout<<ans<<endl;
		}else{
			string a = plus1(temp);
			debug printf("a: "); debug cout<<a<<endl;
			bool bigger = isBigger(a, temp);

			temp = a;
			if(bigger){
				while(a.length() < pjg){
					a += temp;
				}	
			}else{
				while(a.length() <= pjg){
					a += temp;
				}	
			}
			
			cout<<a<<endl;
		}
	}else{
		string ans = "1";
		for(i=1;i<n;i++){
			ans += '0';
		}
		string temp = ans;
		while(ans.length() < pjg){
			ans += temp;
		}
		cout<<ans<<endl;
	}
	return 0;
};