#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second

void cut(pll &a, pll b){
	if(a.fi > b.se || a.se < b.fi) a=pll(1,0);
	else if(a.fi <= b.fi && a.se>=b.se) a=b;
	else if(a.fi >= b.fi && a.se>=b.se) a.se=b.se;
	else if(a.fi <= b.fi && a.se <=b.se) a.fi=b.fi;
}

int main(){
	int n,c,d;
	pll interval;
	scanf("%d",&n);
	interval=pll(LLONG_MIN,LLONG_MAX);
	while(n--){
		//if(interval.fi>interval.se) break;
		scanf("%d %d",&c,&d);
		if(d==1){cut(interval,pll(1900,LLONG_MAX));}
		else{cut(interval,pll(LLONG_MIN,1899));}
		if(interval.fi>interval.se) break;
		if(interval.fi > LLONG_MIN) interval.fi+=c;
		if(interval.se < LLONG_MAX) interval.se+=c;
	}
	if(interval.fi> interval.se){printf("Impossible\n");}
	else if(interval.se>=LLONG_MAX){printf("Infinity\n");}
	else{printf("%I64d\n",interval.se);}
	return 0;
}