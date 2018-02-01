import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger[] t = new BigInteger[25];
		t[0] = sc.nextBigInteger();
		t[1] = sc.nextBigInteger();
		int n = sc.nextInt();
		for(int i=2;i<=n;i++){
			t[i] = t[i-2].add(t[i-1].pow(2));
		}
		/*for(int i=0;i<n;i++){
			if(i>0){System.out.print(" ");}
			System.out.print(t[i]);
		}
		System.out.println();*/
		System.out.println(t[n-1]);
	}
}