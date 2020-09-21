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

const int maxn = 3e5 + 1;

int a[maxn], leftGe[maxn], rightGe[maxn], leftLe[maxn], rightLe[maxn];
int dp[maxn];

void findLessEqualInLeft(int n) {
	stack<ii> s;
	for(int i=1;i<=n;i++){
		while(!s.empty() && s.top().first > a[i]) {
			s.pop();
		}
		if(s.empty()){leftLe[i] = -1;}
		else{
			leftLe[i] = s.top().second;
		}
		s.push(ii(a[i], i));
	}
}

void findGreaterEqualInLeft(int n) {
	stack<ii> s;
	for(int i=1;i<=n;i++){
		while(!s.empty() && s.top().first < a[i]) {
			s.pop();
		}
		if(s.empty()){leftGe[i] = -1;}
		else{
			leftGe[i] = s.top().second;
		}
		s.push(ii(a[i], i));
	}
}

void findLessEqualInRight(int n) {
	stack<ii> s;

	for(int i=n;i>=1;i--){
		while(!s.empty() && s.top().first > a[i]) {
			s.pop();
		}
		if(s.empty()){rightLe[i] = -1;}
		else{
			rightLe[i] = s.top().second;
		}
		s.push(ii(a[i], i));
	}
}

void findGreaterEqualInRight(int n) {
	stack<ii> s;
	for(int i=n;i>=1;i--){
		while(!s.empty() && !(s.top().first >= a[i])) {
			s.pop();
		}
		if(s.empty()){rightGe[i] = -1;}
		else{
			rightGe[i] = s.top().second;
		}
		s.push(ii(a[i], i));
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i] = i - 1;
	}
	
	//we need to find the nearest greater / lesser than the current element...we can use stack and maintain the left and right greater / lesser index
	findLessEqualInRight(n);
	findLessEqualInLeft(n);
	findGreaterEqualInRight(n);
	findGreaterEqualInLeft(n);
	for(i=1;i<=n;i++){
		if(leftGe[i] != -1){
			dp[i] = min(dp[i], dp[leftGe[i]] + 1);
		}
		if(leftLe[i] != -1) {
			dp[i] = min(dp[i], dp[leftLe[i]] + 1);
		}
		if(rightGe[i] != -1) {
			dp[rightGe[i]] = min(dp[rightGe[i]], dp[i] + 1);
		}
		if(rightLe[i] != -1) {
			dp[rightLe[i]] = min(dp[rightLe[i]], dp[i] + 1);
		}
	}

	printf("%d\n",dp[n]);

	return 0;
};