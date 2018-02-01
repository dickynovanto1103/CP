#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector<iii> ans;
int main() {
	int n,a[110][110],i,j,k;
	while(scanf("%d",&n)!=EOF){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		//depan ke belakang
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				for(k=j+1;k<=n;k++){
					if(a[i][j] == 1 && a[j][k] == 1 && a[k][i] == 1){
						iii kata = make_pair(ii(i,j),k);
						
						ans.push_back(kata);
						//printf("yang dipush: %d %d %d\n",kata.first.first, kata.first.second, kata.second);
						//printf("kata yang dipush: "); cout<<kata<<endl;
					}
					if(a[k][j] == 1 && a[j][i] == 1 && a[i][k] == 1){
						iii kata = make_pair(ii(k,j),i);
						ans.push_back(kata);
						//printf("yang dipush: %d %d %d\n",kata.first.first, kata.first.second, kata.second);
						//printf("kata yang dipush: "); cout<<kata<<endl;
					}
				}
			}
		}
		sort(ans.begin(),ans.end());
		int ukuran = ans.size();
		for(i=0;i<ukuran;i++){
			printf("%d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second);
		}
		printf("total:%d\n\n",ukuran);
		ans.clear();
	}
	
	return 0;
}