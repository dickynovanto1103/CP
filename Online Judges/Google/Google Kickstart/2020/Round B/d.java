import java.util.Scanner;
import java.math.BigInteger;

class Main{
	
	public static void main(String[] args) {
		System.out.println("hello world");
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		System.out.println("tc: " + tc);
		Fac fac = new Fac();
		fac.genFac();
		

		for(int tt=1;tt<=tc;tt++){
			System.out.println("Case #" + tt + ": ");
			int n = sc.nextInt();
			int m = sc.nextInt();
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int d = sc.nextInt();
			System.out.println("n: " + n + " a: " + a);
		}
		
	}
}

class Fac{
	BigInteger fac[] = new BigInteger[200002];
	public void genFac() {
		int i,j;
		fac[0] = BigInteger.ONE;
		for(i=1;i<200002;i++){
			System.out.println("i:" + i);
			fac[i] = fac[i-1].multiply(BigInteger.valueOf(i));
		}
	}
}