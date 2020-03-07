### What have I learnt
1. Uang Kembalian
	- Jika jumlah tiap uang koin tak terhingga, maka kita tidak peduli dengan indeks dari koin, sehingga kita dapat mengurangi state menjadi hanya 1 dimensi, yaitu total nilai uang, sehingga dp[n] = minimal jumlah uang koin untuk total nilai uang = n
	- Jika tiap uang koin hanya dapat dipakai sekali, maka indeks menjadi penting, sehingga state DP nya menjadi: dp[idx][n] = minimal uang koin yang diperlukan jika sudah mempertimbangkan uang koin hingga indeks idx dan nilai uangnya sebanyak n
2. Knapsack
	- Problem ini problem klasik knapsack, hanya saja kita tidak diminta nilai knapsacknya, namun diminta barang apa aja yang harus diambil untuk mencapai nilai knapsack tersebut
	- Permasalahannya adalah: pengambilan barang tidak dapat diambil sembarangan, kriterianya adalah weight dari barang-barang yang diambil harus minimal, jika tie, maka harus diutamakan untuk mengambil batu yang indeksnya lebih kecil (leksikografis terkecil)
	- Solusi:
		- Problem Knapsack harus menggunakan DP 2 dimensi: dp[idx][weight]: nilai maksimum yang dapat didapatkan jika sudah consider hingga barang ke-idx dan total weight barang yang diambil yaitu weight.
		- Pengambilan barang yang meminimalkan total berat barang dapat didapatkan dengan iterasi di indeks ke-n dan dengan nilai dp maksimal, kita bisa dapatkan weight minimal
		- Dengan menggunakan weight minimal, kita dapat melakukan iterasi di semua indeks object untuk mendapatkan indeks minimal dengan knapsack value maksimal
		- Best Practice: jika kita peduli dengan path finding untuk solusi DP, maka kita perlu mencatat parentnya, maka kita tidak boleh sekedar menggunakan max operation
			- (Salah)
			<pre><code>dp[i + 1][j] = max(dp[i][j], dp[i + 1], j); 
			//karena siapa tau nilai dp[i][j] > dp[i + 1][j] dan kita perlu mencatat parent[i][j]</code></pre>
			- (Benar)
			<pre><code>if(dp[i + 1][j] < dp[i][j]): then
            dp[i + 1][j] = dp[i][j]; par[i + 1][j] = par[i][j];</code></pre> 
		- Untuk mendapatkan semua object yang diambil (path finding), kita dapat menggunakan teknik trace back dari nilai parent tersebut