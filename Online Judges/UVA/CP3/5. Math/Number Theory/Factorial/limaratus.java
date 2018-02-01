import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		BigInteger a;
		Scanner sc = new Scanner(System.in);
		BigInteger sum;
		BigInteger[] arr = new BigInteger[1010];
		BigInteger one = BigInteger.ONE;
		BigInteger nol = BigInteger.ZERO;
		arr[0] = one;
		arr[1] = one;
		for(int i=2;i<=1000;i++){arr[i] = arr[i-1].multiply(BigInteger.valueOf(i));}
		while(sc.hasNext()){
			a = sc.nextBigInteger();
			System.out.println(a+"!");
			sum = arr[a.intValue()];
			
			System.out.println(sum);
		}
	}
}