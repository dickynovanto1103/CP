import java.util.Scanner;
import java.math.BigInteger;
class Main {
	public static void main(String[] args) {
		BigInteger a;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		//a = BigInteger.valueOf(3).pow(n);
		BigInteger r = BigInteger.valueOf(3).modPow(BigInteger.valueOf(n),BigInteger.valueOf(1000000006));
		BigInteger ans = BigInteger.valueOf(3).modPow(r,BigInteger.valueOf(1000000007));
		System.out.println(ans);
	}
}