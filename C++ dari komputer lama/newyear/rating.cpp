#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second

void cut(pll &pair1,pll pair2){
	if(pair1.fi > pair2.se || pair1.se < pair2.fi) pair1=pll(1,0);
	else if(pair1.fi <= pair2.fi && pair1.se >= pair2.se ) pair1=pair2;
	else if(pair1.fi >= pair2.fi && pair1.se >= pair2.se ) pair1.se=pair2.se;
	else if(pair1.fi <=pair2.fi && pair1.se <=pair2.se) pair1.fi=pair2.fi;
}

int main(){
	int c,d,atas,bawah;
	pll interval;
	int n,i;
	bool found;
	interval=pll(LLONG_MIN,LLONG_MAX);//set initial value
	scanf("%d",&n);
	while(n--){
		if(interval.fi>interval.se) break;
		scanf("%d %d",&c,&d);
		printf("c: %d, d: %d\n",c,d);
		printf("interval.fi: %lld\ninterval.se: %lld\n",interval.fi,interval.se);
		if(d==1){printf("pair2.fi: 1900\npair2.se: max\n");}
		else{printf("pair2.fi: min\npair2.se: 1899\n");}
		if(d==1){cut(interval,pll(1900,LLONG_MAX));}
		else{cut(interval,pll(LLONG_MIN,1899));}
		printf("menjadi interval.fi: %lld\ninterval.se: %lld\n",interval.fi,interval.se);
		
		if(interval.fi > interval.se) break;
		if(interval.fi > LLONG_MIN) interval.fi+=c;
		if(interval.se < LLONG_MAX) interval.se+=c;
		printf("sekarang: interval.fi: %lld\ninterval.se: %lld\n",interval.fi,interval.se);
	}
	if(interval.fi > interval.se){printf("Impossible\n");}
	else if(interval.se >=LLONG_MAX){printf("Infinity\n");}
	else{printf("%I64d\n",interval.se);}
	
	return 0;
}
/*
3
-7 1 
pair1.fi=min
pair1.se=max
pair2.fi=1900
pair2.se=max
5 2
pair1.fi=1898
pair1.se=1904
pair2.fi=min
pair2.se=1899
8 2
pair1.fi=1905
pair1.se=1907
pair2.fi=min
pair2.se=1899
1907
2

57 1
pair1.fi=min
pair1.se=max
pair2.fi=1900
pair2.se=max

pair1.fi=1957
pair1.se=max
pair2.fi=1900
pair2.se=max
22 2
pair1.fi=1957
pair1.se=max
pair2.fi=min
pair2.se=1899

pair1.fi=1957
pair1.se=max
pair2.fi=min
pair2.se=1899
impossible

4
27 2
pair1.fi=min
pair1.se=max
pair2.fi=min
pair2.se=1899

pair1.fi=min
pair1.se=1899
pair2.fi=min
pair2.se=1899

pair1.fi=min
pair1.se=1926
pair2.fi=min
pair2.se=1899
13 1
pair1.fi=min
pair1.se=1926
pair2.fi=1900
pair2.se=max

pair1.fi=1900
pair1.se=1926
pair2.fi=1900
pair2.se=max

pair1.fi=1913
pair1.se=1939
pair2.fi=1900
pair2.se=max
-50 1
pair1.fi=1913
pair1.se=1939
pair2.fi=1900
pair2.se=max

pair1.fi=1913
pair1.se=1939
pair2.fi=1900
pair2.se=max
8 2
if(pair1.fi > pair2.se || pair1.se < pair2.fi) pair1=pll(1,0);
	else if(pair1.fi <= pair2.fi && pair1.se >= pair2.se ) pair1=pair2;
	else if(pair1.fi >= pair2.fi && pair1.se >= pair2.se ) pair1.se=pair2.se;
	else if(pair1.fi <=pair2.fi && pair1.se <=pair2.se) pair1.fi=pair2.fi;
*/