#include <cstdio>
#include <vector>
using namespace std;

vector <int> arr[20];

int main(){
	int i,j,n,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for (int j = 0; j < n; j++)
		{

			scanf("%d",&temp);
			arr[i].push_back(temp);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}