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

const int maxn = 3e5 + 4;

string kata;
int n;
int dx[] = {-1,1};

int hitungJumlahHole(){
	string temp = kata;
	queue<int> q;
	int cnt = 0;
	
	for(int i=0;i<n;i++){
		if(temp[i]=='0'){
			cnt++;
			q.push(i);
			while(!q.empty()){
				int front = q.front(); q.pop();
				temp[front] = '1';
				for(int j=0;j<2;j++){
					int xbaru = front+dx[j];
					if(xbaru>=0 && xbaru<n){
						if(temp[xbaru] == '0'){
							q.push(xbaru);
						}
					}
				}
			}
		}
	}
	return cnt;
}

bool isVisited[maxn];

int findArea(int idx, char kar){
	queue<int> q;
	q.push(idx);
	isVisited[idx] = true;
	int cnt = 0;
	while(!q.empty()){
		int front = q.front(); q.pop();
		cnt++;
		for(int i=0;i<2;i++){
			int xbaru = front + dx[i];
			if(xbaru>=0 && xbaru<n){
				if(isVisited[xbaru]){continue;}
				if(kata[xbaru] == kar){
					isVisited[xbaru] = true;
					q.push(xbaru);
				}
			}
		}
	}
	return cnt;
}

int main(){
	int i,j;
	ll x,y;
	
	scanf("%d %lld %lld",&n,&x,&y);
	ll ans = 0;
	cin>>kata;
	int banyakArea = hitungJumlahHole();
	queue<int> q;
	
	memset(isVisited, false, sizeof isVisited);
	int bil = 0;
	for(i=0;i<n;i++){
		if(kata[i] == '0'){
			bil |= 1;
		}else{
			bil |= 2;
		}
	}

	if(kata[0] == '1'){
		q.push(0);
		isVisited[0] = true;
		while(!q.empty()){
			int front = q.front(); q.pop();
			for(int i=0;i<2;i++){
				int xbaru = front + dx[i];
				if(xbaru>=0 && xbaru<n){
					if(kata[xbaru] == '1'){
						if(!isVisited[xbaru]){
							isVisited[xbaru] = true;
							q.push(xbaru);
						}
						
					}
				}
			}
		}
	}

	if(kata[n-1] == '1'){
		q.push(n-1);
		isVisited[n-1] = true;
		while(!q.empty()){
			int front = q.front(); q.pop();
			for(int i=0;i<2;i++){
				int xbaru = front + dx[i];
				if(xbaru>=0 && xbaru<n){
					if(kata[xbaru] == '1'){
						if(!isVisited[xbaru]){
							isVisited[xbaru] = true;
							q.push(xbaru);
						}
						
					}
				}
			}
		}	
	}
	vi listTidakValid;
	for(i=0;i<n;i++){
		if(isVisited[i]){continue;}
		if(kata[i] == '1') {
			int banyak = findArea(i,kata[i]);
			listTidakValid.pb(banyak);
		}
	}

	sort(listTidakValid.begin(), listTidakValid.end());
	for(i=0;i<listTidakValid.size();i++){
		int banyakDiReverse = listTidakValid[i];
		ll biaya1 = (ll)x + y*((ll)banyakArea-1LL);
		ll biaya2 = (ll)banyakArea*y;
		// printf("banyakDiReverse: %d\n",banyakDiReverse);
		// printf("biaya1: %lld biaya2: %lld\n",biaya1,biaya2);
		// printf("banyakArea: %d\n",banyakArea);
		if(biaya1 < biaya2){
			ans+=((ll)x);
			banyakArea--;
			if(banyakArea==1){
				ans+=y;
				printf("%lld\n",ans);
				return 0;
			}
		}else{
			ans+=biaya2;
			printf("%lld\n",ans);
			return 0;
		}
	}
	
	if(ans==0){
		if(bil==1 || bil==3){
			ans = y;
		}
	}

	printf("%lld\n",ans);
	return 0;
};