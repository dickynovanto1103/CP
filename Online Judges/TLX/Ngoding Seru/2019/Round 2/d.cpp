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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,char> ic;
typedef pair<int,int> ii;
typedef pair<ic,ii> iiii;
typedef vector<ii> vii;
typedef vector<iiii> viiii;

string s;

int bitBiru[2010], bitKuning[2010];

int query(int idx, bool isBiru) {
	int ans = 0;
	for(int i=idx;i>=1;i-=(i&-i)){
		if(isBiru){
			ans += bitBiru[i];
		}else{
			ans += bitKuning[i];
		}
		
	}
	return ans;
}

void update(int idx, bool isBiru, int val){
	for(int i=idx;i>=1;i+=(i&-i)){
		if(isBiru){
			bitBiru[i] += val;
		}else{
			bitKuning[i] += val;
		}
		
	}
}

bool isBiruKiriSemua(int n, int cntBiru){
	int cnt = 0;
	int i,j;
	for(i=0;i<n;i++){
		if(s[i] == 'B'){cnt++;}
		else if(s[i] == 'K'){
			if(cntBiru == cnt){return true;}
			else{return false;}
		}
	}
	return true;
}

bool isValid(int x, int y){
	if(s[x] == '-' && s[y] == '-'){return false;}
	if(s[x] != '-' && s[y] != '-'){return false;}
	int i,j;

	if(s[x] == 'K'){
		for(i=x;i<y;i++){
			if(s[i] == 'B'){return true;}
		}	
	}else if(s[x] == 'B'){
		for(i=x-1;i>y;i--){
			if(s[i] == 'K'){return true;}
		}
	}else if(s[y] == 'K'){
		for(i=y;i<x;i++){
			if(s[i] == 'B'){return true;}
		}
	}else if(s[y] == 'B'){
		for(i=y-1;i>x;i--){
			if(s[i] == 'K'){return true;}
		}
	}
	
	

	return false;
}

priority_queue<iiii, viiii, greater<iiii> > pq;

void update(int x, int n){
	int i,j;
	bool sudahLewatBiru = false, sudahLewatKuning = false;
	// printf("x: %d n: %d\n",x,n);
	// printf("fokus push kuning\n");
	for(i=x-1;i>=0;i--){
		char kar = s[i];
		if(kar == 'B'){sudahLewatBiru = true; continue;}
		if(kar == 'K' && sudahLewatBiru){
			pq.push(iiii(ic(x-i, s[i]), ii(x,i)));
			// printf("dipush: %d x: %d y: %d\n",x-i, x, i);
		}
	}
	// printf("fokus push biru\n");
	for(i=x+1;i<n;i++){
		char kar = s[i];
		if(kar == 'K'){sudahLewatKuning = true; continue;}
		if(kar == 'B' && sudahLewatKuning){
			pq.push(iiii(ic(i-x, s[i]), ii(x,i)));
			// printf("dipush: %d x: %d y: %d\n",i-x, x, i);
		}	
	}
	// for(i=0;i<n;i++){
	// 	if(i == x){continue;}
	// 	if(i < x){
	// 		if(s[i] == 'K'){
	// 			pq.push(iiii(ic(x-i, s[i]), ii(x, i)));
	// 		}
	// 	}else{
	// 		if(s[i] == 'B'){
	// 			pq.push(iiii(ic(i-x, s[i]), ii(x, i)));
	// 		}
	// 	}
	// }
}

int main(){
	int n,i,j;
	
	scanf("%d",&n);

	cin>>s;
	
	int cntBiru = 0;

	for(i=0;i<n;i++){
		char kar = s[i];
		if(kar == 'B'){cntBiru++;}
		else if(kar == '-'){
			for(j=i+1;j<n;j++){
				//cari yang biru
				if(s[j] == 'B'){
					pq.push(iiii(ic(j-i, s[j]), ii(i,j)));
				}
			}
			for(j=i-1;j>=0;j--){
				if(s[j] == 'K'){
					pq.push(iiii(ic(i-j, s[j]), ii(i,j)));
				}
			}
		}
	}

	ll ans = 0;

	while(!isBiruKiriSemua(n, cntBiru)) {
		iiii front = pq.top(); pq.pop();

		int jarak = front.first.first;
		ii pas = front.second;
		int x = pas.first, y = pas.second;
		if(!isValid(x,y)){continue;}
		ans += jarak;
		// printf("x: %d y: %d ans jd: %lld jarak: %d\n",x,y, ans, jarak);
		swap(s[x], s[y]);
		// printf("s jadi: "); cout<<s<<endl;
		if(s[x] == '-'){
			// printf("update x -\n");
			update(x, n);
		}else if(s[y] == '-'){
			// printf("update y -\n");
			update(y, n);
		}
		
	}
	printf("%lld\n",ans);
	return 0;
};