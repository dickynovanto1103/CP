import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i;
		BigInteger[] a = new BigInteger[1000];
		a[0] = BigInteger.ONE;
		for(i=1;i<1000;i++){
			a[i] = a[i-1].multiply(BigInteger.valueOf(i));
		}
		//System.out.println(a[999]);
		int k,n;
		int bil;
		BigInteger sum;
		while(sc.hasNext()){
			k = sc.nextInt();
			sum = a[k];
			n = sc.nextInt();
			for(i=0;i<n;i++){
				bil = sc.nextInt();
				sum = sum.divide(a[bil]);
			}
			System.out.println(sum);
		}
		

	}
}