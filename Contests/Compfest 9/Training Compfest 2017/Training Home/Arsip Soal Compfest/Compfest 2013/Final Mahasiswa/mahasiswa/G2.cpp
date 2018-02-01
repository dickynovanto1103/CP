/* 
 * CompFest 2013 - Competitive Programming
 * DNA Misterius
 * Author : Cakra Wishnu Wardhana
 * Code   : William Gozali
 * Template by Ashar Fuadi
 */

#include <cstdio>
#include <cstring>

#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define RESET(c,v) memset(c, v, sizeof(c))

#define pb push_back
#define mp make_pair
#define MAXN 132000

struct node{
	int minv, prop;
};

node stri[2*MAXN];
int bitt[MAXN];
int nkasus;
int n;
int jq,a;
int ar[MAXN];
char sc[MAXN];

inline int GET_MIN(int x){
	return stri[x].minv + stri[x].prop;
}

void build(int nod, int ki, int ka){
	if (ki == ka){
		stri[nod].minv = ar[ki];
		stri[nod].prop = 0;
	}else{
		int tgh = (ki + ka) >> 1;
		
		build(2*nod+1, ki, tgh);
		build(2*nod+2, tgh+1, ka);
		
		stri[nod].minv = min(stri[2*nod+1].minv, stri[2*nod+2].minv);
		stri[nod].prop = 0;
	}
}	

void update(int nod, int ki, int ka, int a, int b, int val){
	if ((a <= ki) && (ka <= b)){
		stri[nod].prop += val;
	}else{
		int tgh = (ki + ka) >> 1;
		
		// propagate	
		if (stri[nod].prop != 0){
			stri[2*nod+1].prop += stri[nod].prop;
			stri[2*nod+2].prop += stri[nod].prop;
			stri[nod].prop = 0;
		}
		
		if (a <= tgh) update(2*nod+1, ki, tgh, a, b, val);
		if (b >  tgh) update(2*nod+2, tgh+1, ka, a, b, val);
		
		// merge
		stri[nod].minv = min(GET_MIN(2*nod+1), GET_MIN(2*nod+2));
	}
}

inline void bit_update(int x, int v){
	for (int i = x; i < MAXN; i += i & -i)
		bitt[i] += v;
}
inline int bit_query(int x){
	int ret = 0;
	for (int i = x; i; i -= i & -i)
		ret += bitt[i];
	return ret;
}

int main()
{
	scanf("%d", &nkasus);
	REP(jt,nkasus){
	  	scanf("%s", sc);
	  	
	  	n = strlen(sc);
		RESET(bitt,0);
	  	REP(i,n){
			ar[i] = (sc[i] == '(') ? 1 : -1;
			bit_update(i+1, ar[i]);
		}
		
		FOR(i,1,n-1){
			ar[i] += ar[i-1];
		}
		
		build(0, 0, n-1);
		
		scanf("%d", &jq);
		while (jq != -1){
			if (jq == 0){
				printf("%c",(GET_MIN(0)>=0 && bit_query(n)==0) ? 'Y' : 'T');
			}else{
				scanf("%d", &a);
				
				if (sc[a] == '('){
					sc[a] = ')';
					update(0, 0, n-1, a, n-1, -2);
					bit_update(a+1, -2);
				}else{
					sc[a] = '(';
					update(0, 0, n-1, a, n-1, 2);
					bit_update(a+1, 2);
				}
			}
			scanf("%d", &jq);
		}
		printf("\n");
	}
}
