import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger a,ans,b;

		int tc = sc.nextInt();
		String hasil;
		int i;
		while(tc-->0){
			a = sc.nextBigInteger();
			b = sc.nextInt();
			ans = a.modPow(b,1000);
			hasil = ans.toString();
			for(i=0;i<3;i++){
				System.out.print(hasil.charAt(i));
			}
			int pjg = hasil.length();
			System.out.print("...");
			for(i=pjg-3;i<pjg;i++){System.out.print(hasil.charAt(i));}
			System.out.println();
		}
	}
}