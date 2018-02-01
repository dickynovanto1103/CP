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

struct pas{
	char kar;
	int nilai;
};

bool cmp(pas a, pas b){
	return a.nilai > b.nilai;
}

int main(){
	int n,k,i,j;
	string kata;
	scanf("%d %d",&n,&k);
	cin>>kata;
	set<char> s;
	set<char>::iterator it;
	int counter[256];
	memset(counter,0,sizeof counter);
	for(i=0;i<n;i++){
		s.insert(kata[i]); counter[kata[i]]++;
	}
	vector<pas> listPas;
	for(it=s.begin();it!=s.end();it++){
		char kar = *it;
		pas a;
		a.kar = kar;
		a.nilai = counter[kar];
		listPas.pb(a);
	}

	sort(listPas.begin(), listPas.end(), cmp);
	int sisa = k;
	ll total = 0;
	for(i=0;i<listPas.size();i++){
		char kar = listPas[i].kar;
		int nilai = listPas[i].nilai;
		total += ((ll)min(sisa,nilai)*(ll)min(sisa,nilai));
		sisa-=min(sisa,nilai);
		if(sisa<=0){break;}
	}
	printf("%lld\n",total);
	return 0;
};