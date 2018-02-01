import java.util.Scanner;
import java.math.BigInteger;

class efekDomino {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		BigInteger[] ans = new BigInteger[1010];
		ans[1] = BigInteger.ONE;
		for(int i=2;i<=1000;i++){
			int pengali = i/2 +1;
			ans[i] = BigInteger.valueOf(pengali).multiply(ans[i-1]);
		}
		for(int i=0;i<tc;i++){
			int idx = sc.nextInt();
			System.out.println(ans[idx]);
		}
	}
}