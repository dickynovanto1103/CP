import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		BigInteger banyak1,banyak2,dummy,sisaDigit,banyakPerulangan,ans,modul;
		int tc;
		int n,k;
		Scanner sc = new Scanner(System.in);
		tc = sc.nextInt();
		modul = BigInteger.valueOf(1000000007);
		BigInteger sepuluh = BigInteger.TEN;
		while(tc-->0){
			n = sc.nextInt();
			k = sc.nextInt();
			dummy = sc.nextBigInteger();
			banyak1 = sepuluh.pow(n);
			// ll sisaDigit = n-k;
			// ll banyakPengulangan = (n - k + 1);
			// ll banyak2 = ((banyakPengulangan%mod)*(modPow(10LL,sisaDigit)%mod))%mod;
			// ll ans = banyak1-banyak2;
			sisaDigit = BigInteger.valueOf(n-k);
			banyakPerulangan = BigInteger.valueOf(n-k+1);
			banyak2 = banyakPerulangan.multiply(sepuluh.pow(n-k));
			ans = banyak1.subtract(banyak2);
			ans = ans.mod(modul);
			System.out.println(ans);
		}
		
		
	}
}