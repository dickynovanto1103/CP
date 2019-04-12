#include <stdio.h>

void add(int *a, int n, int tambah) {
	int i,j;
	for(i=0;i<n;i++){
		a[i] += tambah;
	}
}

int main() {
	int a[123];
	
	int i,j;
	int n = 4;
	for(i=0;i<n;i++){
		a[i] = 2;
	}
	add(a, n, 2);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}