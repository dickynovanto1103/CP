import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		BigInteger[] a = new BigInteger[5010];
		a[0] = BigInteger.ZERO; a[1] = BigInteger.ONE;
		//System.out.println(a[0]);
		//System.out.println(a[1]);
		for(int i=2;i<=5000;i++){
			a[i] = BigInteger.ZERO;
			a[i] = a[i].add(a[i-1]); a[i] = a[i].add(a[i-2]);
			//System.out.println(a[i]);
		}
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int idx = sc.nextInt();
			System.out.println("The Fibonacci number for "+idx+" is "+a[idx]);	
		}
		
	}
}