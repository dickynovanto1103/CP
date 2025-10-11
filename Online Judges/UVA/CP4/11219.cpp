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

bool isBirthdayValid(tuple<int,int,int> cur, tuple<int,int,int> birth) {
	if(get<2>(birth) > get<2>(cur)) {
		return false;
	}

	if(get<2>(birth) == get<2>(cur) && get<1>(birth) > get<1>(cur)) {
		return false;
	}

	if(get<2>(birth) == get<2>(cur) && get<1>(birth) == get<1>(cur) && get<0>(birth) > get<0>(cur)) {
		return false;
	}

	return true;
}

int getAge(tuple<int,int,int> cur, tuple<int,int,int> birth) {
	int diffYear = get<2>(cur) - get<2>(birth);
	if(get<1>(cur) < get<1>(birth)) {
		return diffYear - 1;
	}

	if(get<1>(cur) == get<1>(birth) && get<0>(cur) < get<0>(birth)) {
		return diffYear - 1;
	}

	return diffYear;
}

void solve(){
	tuple<int, int, int> cur, birth;
	int d,m,y;
	scanf("%d/%d/%d",&d,&m,&y);
	cur = make_tuple(d,m,y);
	scanf("%d/%d/%d",&d,&m,&y);
	birth = make_tuple(d,m,y);

	if(!isBirthdayValid(cur, birth)) {
		puts("Invalid birth date");
		return;
	}

	int age = getAge(cur, birth);
	if(age > 130) {
		puts("Check birth date");
		return;
	}

	printf("%d\n", age);
}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		solve();
	}

	return 0;
};