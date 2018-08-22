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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n;
const int maxn = 1e5 + 5;
string kata;

string hapus0Depan(string ans){
	reverse(ans.begin(), ans.end());
	while(ans.back() == '0' && !ans.empty()){
		ans.pop_back();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

string getAns(int mod, int dikunjungi){
	int isVisited = 0;
	int i;
	string ans = "";
	for(i=n-1;i>=0;i--){
		int bil = (kata[i] - '0')%3;
		if(bil%3 == mod){
			if(isVisited == (dikunjungi-1)){
				break;	
			}else{
				isVisited++;
				continue;
			}
		}
		ans += kata[i];
	}
	int idx = i-1;
	for(i=idx;i>=0;i--){
		ans += kata[i];
	}
	if(ans.empty()){
		ans = "z";
	}
	reverse(ans.begin(),ans.end());
	// printf("ans jd: "); cout<<ans<<endl;
	ans = hapus0Depan(ans);
	if(ans.empty()){
		ans = "0";
	}else{
		if(ans == "z"){ans = "";}
	}
	return ans;
}

int main(){
	cin>>kata;
	int i,j;
	n = kata.length();
	int sum = 0;
	int cnt1 = 0, cnt2 = 0;
	for(i=0;i<n;i++){
		int bil = (kata[i] - '0')%3;
		if(bil == 1){
			cnt1++;
		}else if(bil == 2){
			cnt2++;
		}
		sum += bil;
		sum%=3;
	}
	string ans = "";
	if(sum == 0){
		cout<<kata<<endl;
	}else if(sum == 1){
		if(cnt1 == 0){
			string ans1 = "", ans2 = "";
			if(cnt2 >= 2){
				ans1 = getAns(2,2);
			}
			
			ans = (ans1.length() > ans2.length() ? ans1: ans2);
			if(ans == ""){printf("-1\n");}
			else{cout<<ans<<endl;}
		}else{
			string ans1 = "", ans2 = "";
			if(cnt2 >= 2){
				ans1 = getAns(2,2);
			}
			ans2 = getAns(1, 1);
			
			ans = (ans1.length() > ans2.length() ? ans1: ans2);
			if(ans == ""){printf("-1\n");}
			else{cout<<ans<<endl;}
			
		}
	}else{
		if(cnt2==0){
			if(cnt1 >= 2){
				ans = getAns(1, 2);
				if(ans == ""){printf("-1\n");}
				else{cout<<ans<<endl;}
			}else{
				printf("-1\n");
			}
		}else{
			string ans1 = "", ans2 = "";
			if(cnt1 >= 2){
				ans1 = getAns(1, 2);
			}
			ans2 = getAns(2, 1);

			ans = (ans1.length() > ans2.length() ? ans1: ans2);
			if(ans == ""){printf("-1\n");}
			else{cout<<ans<<endl;}
			
		}
	}
	return 0;
};