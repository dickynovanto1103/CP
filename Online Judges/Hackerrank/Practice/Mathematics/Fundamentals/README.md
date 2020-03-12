### Things to Learn
1. Reverse Game
	- If we are reversing array of size n, n times with the order of explained in the problem, then we will got the pattern of a[n-1], a[0], a[n-2], a[1], ...
2. Russian Peasant
	- Problem: (a + bi)^k = c + di, dengan i bilangan imajiner. cari c % m dan d % m
	- Observasi: (a + bi)^k, k >= 0, selalu menghasilkan format berbentuk sama, yaitu (x + yi)
		1. Nilai k besar, hingga 10^18, sehingga tidak memungkinkan untuk menggunakan binomial coefficient (tidak ada observasi yang tepat dari ini).
		2. Jika setelah dipangkatkan menghasilkan bentuk yang serupa, maka kita dapat mempertimbangkan solusi matrix exponentiation
			- pengali: Nilai pengali didapatkan sekian setelah observasi dengan (a + bi)^2
				[a -b]
				[b  a]
			- dikali:
				[0 8]
				[0 2]
	- Dari problem ini juga belajar bagaimana melakukan power dengan cara iteratif. Ide: nilai power dijadikan binary number, dan jika power % 2 == 1, dikalikan dengan nilai pengali, sedangkan nilai pengali pada setiap iterasi dikuadratkan, karena nilai binary dari kanan ke kiri: selalu dalam bentuk 2 pangkat: 1,2,4,..., sehingga total exponent bila ditambah perlu seperti nilai power itu, sehingga base^1 x base^2 x base^4 ... = base^power