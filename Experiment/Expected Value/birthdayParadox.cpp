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

int main(){
	double pNoBirthdayAtSameDay = 1;
	for(int i=1;i<70;i++){
		pNoBirthdayAtSameDay *= (365.0 - i) / 365.0;
	}
	printf("%.9lf\n", pNoBirthdayAtSameDay);
	printf("%.9lf\n", 1- pNoBirthdayAtSameDay);
	
	return 0;
};