#include <bits/stdc++.h>

using namespace std;
#define inf 1000000009
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

const int maxn = 1e5 + 5;

multiset<int> s, diff;
multiset<int>::iterator it;

void delFromS(int el){
	it = s.find(el);
	s.erase(it);
}

void delFromDiff(int el) {
	it = diff.find(el);
	diff.erase(it);
}

void insertToS(int el){
	s.insert(el);
}

void insertToDiff(int el){
	diff.insert(el);
}

int getBefore(int el){
	it = s.find(el);
	if(it == s.begin()){
		return -inf;
	}
	it--;
	int elemen = *it;
	assert(el >= elemen);
	return elemen;
}

int getAfter(int el){
	it = s.find(el);
	++it;
	if(it == s.end()){
		return -inf;
	}
	int elemen = *it;
	assert(elemen >= el);
	return elemen;
}

void pDiff(){
	int cnt = 0;
	for(it=diff.begin();it!=diff.end();it++){
		printf("diff[%d]: %d\n",cnt++,*it);
	}
}

void pS(){
	int cnt = 0;
	for(it=s.begin();it!=s.end();it++){
		printf("s[%d]: %d\n",cnt++,*it);
	}
}

int main(){
	int n,q,i,j;
	scanf("%d %d",&n,&q);
	int a[maxn], temp[maxn];
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		// printf("a[%d]: %d\n",i,a[i]);
		temp[i] = a[i];
		s.insert(a[i]);
	}
	sort(a, a+n);
	for(i=0;i<n-1;i++){
		diff.insert(a[i+1] - a[i]);
	}
	while(q--){
		int tipe;
		scanf("%d",&tipe);
		// printf("tipe: %d\n",tipe);
		// for(i=0;i<n;i++){
		// 	printf("temp[%d]: %d\n",i, temp[i]);
		// }
		// pS(); pDiff();
		if(tipe == 1){
			int idx, val;
			scanf("%d %d",&idx,&val);
			idx--;
			int valLama = temp[idx];

			int bef = getBefore(valLama);
			int af = getAfter(valLama);

			if(bef != -inf){
				// printf("halo bef: %d\n", bef);
				delFromDiff(valLama - bef);
				
			}
			if(af != -inf){
				delFromDiff(af - valLama);
				// printf("halo\n");
			}
			if(bef != -inf && af != -inf){
				insertToDiff(af - bef);
			}
			
			delFromS(valLama);

			//insert baru

			insertToS(val);
			bef = getBefore(val);
			af = getAfter(val);
			// printf("insert val: %d bef: %d af: %d\n",val, bef, af);

			if(bef != -inf){insertToDiff(val - bef);}
			if(af != -inf){insertToDiff(af - val);}

			if(bef != -inf && af != -inf){
				delFromDiff(af - bef);
			}
			

			temp[idx] = val;
		}else{
			printf("%d\n",(*(--s.end()) - *s.begin()) - (*diff.begin()));
		}
	}
	return 0;
};