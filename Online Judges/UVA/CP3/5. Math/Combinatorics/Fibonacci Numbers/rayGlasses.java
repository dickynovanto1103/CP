import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		BigInteger[] a = new BigInteger[1010];
		a[0] = BigInteger.ONE;
		a[1] = BigInteger.valueOf(2);
		int i;
		for(i=2;i<=1000;i++){
			a[i] = BigInteger.ZERO;
			a[i] = a[i-1].add(a[i-2]);
		}
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int idx = sc.nextInt();
			System.out.println(a[idx]);
		}
	}
}