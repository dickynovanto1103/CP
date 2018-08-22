#include <bits/stdc++.h>
using namespace std;
int n,m,row[105],col[105],total,arr[105][105];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &col[i]);
        total ^= col[i];
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &row[i]);
        total ^= row[i];
    }
    if(total != 0)printf("NO\n");
    else{
        printf("YES\n");
        for(int i = 0; i < n-1; i++){
            arr[i][0] = col[i];
            for(int j = 1; j < m; j++){
                arr[i][j] = 0;
            }
            total ^= col[i];
        }
        arr[n-1][0] = row[0] ^ total;
        total = arr[n-1][0];
        for(int j = 1; j < m; j++){
            arr[n-1][j] = row[j];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                printf("%d", arr[i][j]);
                if(j == m-1)printf("\n");
                else printf(" ");
            }
        }
    }
}