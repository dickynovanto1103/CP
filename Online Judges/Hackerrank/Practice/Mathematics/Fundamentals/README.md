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
3. Filling Jars
	- Terdapat 2 solusi menyelesaikan problem ini:
		1. Menggunakan array sebanyak N elemen dan untuk setiap M query, dengan tiap query yaitu menambahkan semua elemen dari a sampai b sebanyak k, maka caranya adalah arr[a] += k; ans[b+1] -= k;. Lalu dilakukan prefix sum dan mentotal semua nilai dan mendapatkan rata-rata.
		2. Kita tidak peduli diletakkan pada elemen array dimana, kita hanya peduli dengan total bola yang ditaruh pada jars, sehingga hanya menjumlahkan setiap (b-a + 1) * k;, kemudian dicari rata-rata.
4. Possible Path
	- Kita harus tau properti gcd, salah satunya adalah gcd(a,b) = gcd(a + m * b, b) = gcd(a, b + m * a).
	- Dalam kasus problem ini, m = 1 atau -1, sehingga dengan dilakukan operasi tersebut, nilai GCD nya tetap sama, sehingga solusinya hanyalah dilakukan pengecekan gcd(a,b) == gcd(x,y)
	- Note: usaha yang saya lakukan awalnya adalah dengan melakukan simulasi BFS dari (a,b), lalu saya mencari pola dari setiap a, dan ditemukan pola, x selalu habis dibagi oleh gcd dan gcd(x,y) == gcd(a,b). Ternyata gcd(x,y) == gcd(a,b) sudahlah merupakan syarat cukup.
5. Sumar and Floating Rocks
	- This problem asks about the integral coordinate that can lie between 2 coordinate. How many is the integral coordinate?
	- We can use gradient, for example gradient: 1/2, that means that we can decrease / increase x by 1 and decrease / increase y by 2 to get another integral coordinate.
		- The corner case is always about infinite gradient, we need to take care of that. 