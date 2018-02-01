#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int tc,n,i,test=1,cnt,cnt_card;
	int a[55];
	int terbuang[55];
	scanf("%d",&tc);
	queue<int> q;
	while(tc--){
		cnt=0;
		printf("Case #%d:\n",test++);
		scanf("%d",&n);

		cnt_card = n;
		for(i=1;i<=n;i++){q.push(i);}
		cnt=0;
		while(cnt_card>=2){
			terbuang[cnt] = q.front(); cnt++; q.pop();
			int bil = q.front(); q.pop(); q.push(bil);
			cnt_card--;
		}
		for(i=0;i<cnt;i++){
			if(i==0){printf("%d",terbuang[i]);}
			else{printf(" %d",terbuang[i]);}
		}
		printf("\n%d\n",q.front()); q.pop();
	}
	return 0;
}