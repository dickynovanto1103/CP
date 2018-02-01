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

int main(){
	priority_queue<int, vi, less<int> > pqBawah;
	
	priority_queue<int, vi, greater<int> > pqAtas;
	int n;
	scanf("%d",&n);
	while(n--){
		int bil;
		scanf("%d",&bil);
		if(pqBawah.empty()){
			pqBawah.push(bil);
		}else{
			int front = pqBawah.top();
			if(bil<=front){
				pqBawah.push(bil);
				if(abs((int)pqBawah.size()-(int)pqAtas.size())>=2){
					pqBawah.pop();
					pqAtas.push(front);
				}
			}else{
				pqAtas.push(bil);
				if(abs((int)pqBawah.size()-(int)pqAtas.size())>=2){
					int atas = pqAtas.top(); pqAtas.pop();
					pqBawah.push(atas);
				}
			}

		}
		double ans;
		if(pqBawah.size()==pqAtas.size()){
			ans = ((double) pqBawah.top() + (double)pqAtas.top()) / 2.0;
		}else if(pqBawah.size()>pqAtas.size()){
			ans = (double)pqBawah.top();
		}else{
			ans = (double)pqAtas.top();
		}
		printf("%.1lf\n",ans);
	}
	/*printf("prioqueue 1\n");
	while(!pq1.empty()){
		int bil = pq1.top(); pq1.pop();
		printf("%d\n",bil);
	}
	printf("prioqueue 2\n");
	while(!pq2.empty()){
		int bil = pq2.top(); pq2.pop();
		printf("%d\n",bil);
	}*/
	return 0;
};