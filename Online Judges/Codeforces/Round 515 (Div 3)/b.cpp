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

const int maxn = 1010;

int a[maxn], temp[maxn];

bool isKeisiSemua(int n){
	for(int i=0;i<n;i++){
		if(a[i] == 0){return false;}
	}
	return true;
}

int main(){
	int n,r,i,j;
	
	scanf("%d %d",&n,&r);
	vi list0,list1, templist1, templist0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		temp[i] = a[i];
		list0.pb(i);
		if(a[i] == 0){

		}else{
			list1.pb(i);
		}
	}
	templist0 = list0;
	templist1 = list1;
	reverse(list0.begin(), list0.end());
	//cek untuk masing"1..apakah dia bisa menghangatkan paling kiri
	int ukuran1 = list1.size(), ukuran0 = list0.size();
	int lastIdx = 0;
	int cnt1 = 0;
	for(i=0;i<n;i++){
		a[i] = 0;
	}
	int lastCoba = -1;
	for(i=0;i<ukuran1;i++){
		int idx = list1[i];
		int kiri = idx - r + 1;
		// printf("idx: %d kiri: %d dibandingkan dengan idx 0 di %d\n",idx,kiri,list0.back());
		if(list0.empty()){break;}
		if(list0.back() >= kiri){
			lastIdx = i;

			// printf("lastIdx jadi: %d\n",idx);
			if(i == (ukuran1-1)){
				cnt1++;
				for(j=idx - r + 1; j<=(idx + r -1);j++){
					if(!(j >= 0 && j<n)){continue;}
					if(a[j] == 0){
						a[j] = 1;
						
						if(list0.size()){
							list0.pop_back();	
						}
					}
				}
			}
		}else{
			cnt1++;
			// printf("cnt1 bertambah jadi %d\n", cnt1);
			int idx1 = list1[lastIdx];
			if(lastCoba == idx1){break;}
			else{lastCoba = idx1;}
			// printf("idx1: %d\n",idx1);
			// printf("idx1: %d\n",idx1);
			// printf("dari %d ke %d\n",idx1 - r + 1, idx1 + r - 1);
			for(j = idx1 - r + 1; j<= (idx1 + r -1);j++){
				if(!(j >= 0 && j<n)){continue;}
				if(a[j] == 0){
					a[j] = 1;
					// printf("dimark 1 idx: %d\n",j);
					// printf("yang dipop idx: %d\n",list0.back());
					if(list0.size()){
						list0.pop_back();	
					}
				}
			}
			i--;
			// printf("i: %d\n",i);
		}
	}
	int ans;
	if(!isKeisiSemua(n)){
		ans = inf;
	}else{
		ans = cnt1;
	}

	if(ans == inf){
		printf("-1\n");
	}else{
		printf("%d\n",ans);
	}
	return 0;
};