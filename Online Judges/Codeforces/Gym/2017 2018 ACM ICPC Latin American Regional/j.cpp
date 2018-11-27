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


int n,i,j,k,t;
char s[100003];
bool udah[100002];
int cnts[1000002];
bool isprime[100002];

void sieve(int n){
	int i,j;
	isprime[0] = isprime[1] = false;
	for(i=2;i*i<=n;i++){

	}
}

int main(){
	memset(cnts, 0, sizeof cnts);
	scanf("%s", s);
	n = strlen(s);
	vector<int> v;
	for(i=1;i<n;++i){
		++cnts[__gcd(i, n)];
	}
	for(i=0;i<n;++i)
		if(s[i]=='P')
			v.pb(i);
	if(v.size()==0)
		return printf("%d\n", n-1) & 0;
	v.pb(v.front());
	int cnt = 0;
	for(i=2;i<=sqrt(n);++i){
		if(n%i==0){
			memset(udah, false, i);
			for(j=1;j<v.size();++j)
				udah[v[j]%i] = true;
			if(*min_element(udah, udah+i) == false)
				cnt+= cnts[i];
			k = n/i;
			if(k!=i){
				memset(udah, false, k);
				for(j=1;j<v.size();++j)
					udah[v[j]%k] = true;
				if(*min_element(udah, udah+k) == false)
					cnt+=cnts[k];
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
};