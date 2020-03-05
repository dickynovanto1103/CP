### What have I learnt
1. Uang Kembalian
	- Jika jumlah tiap uang koin tak terhingga, maka kita tidak peduli dengan indeks dari koin, sehingga kita dapat mengurangi state menjadi hanya 1 dimensi, yaitu total nilai uang, sehingga dp[n] = minimal jumlah uang koin untuk total nilai uang = n
	- Jika tiap uang koin hanya dapat dipakai sekali, maka indeks menjadi penting, sehingga state DP nya menjadi: dp[idx][n] = minimal uang koin yang diperlukan jika sudah mempertimbangkan uang koin hingga indeks idx dan nilai uangnya sebanyak n
 