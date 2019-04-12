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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		string s, t;
		cin>>s>>t;
		printf("Case %d: ",tt);
		int cnt1 = 0, cnt0 = 0;
		for(i=0;i<t.length();i++){
			if(t[i] == '1'){cnt1++;}
			else{cnt0++;}
		}
		int nol = 0, satu = 0;
		for(i=0;i<s.length();i++){
			if(s[i] == '1'){satu++;}
			else if(s[i] == '0'){nol++;}
		}
		if(satu > cnt1){printf("-1\n"); continue;}
		int ans = 0;
		for(i=0;i<s.length();i++){
			if(s[i] == '?'){
				ans++;
				if(t[i] == '0'){
					if(nol < cnt0){
						s[i] = '0';
						nol++;
					}else if(satu < cnt1){
						s[i] = '1';
						satu++;
					}else{
						s[i] = '0';
						nol++;
					}
				}else{
					if(satu < cnt1){
						s[i] = '1';
						satu++;
					}else{
						s[i] = '0';
						nol++;
					}
				}
			}
		}
		vi list0, list1;
		int pjg = s.length();
		for(i=0;i<pjg;i++){

			if(s[i] != t[i]){
				if(s[i] == '0'){list0.pb(i);}
				else{list1.pb(i);}
			}
		}
		assert(list0.size() >= list1.size());
		int pjg0 = list0.size(), pjg1 = list1.size();
		int minim = min(pjg0, pjg1);
		ans += minim;
		pjg0 -= minim; pjg1 -= minim;
		ans += pjg0; ans += pjg1;
		printf("%d\n",ans);
	}
	return 0;
};