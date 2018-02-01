import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		int[] ans = new int[6];
		ans[0] = 76; ans[1] = 16; ans[2] = 56; ans[3] = 96; ans[4] = 36;
		BigInteger n;
		BigInteger lima = BigInteger.valueOf(5);
		BigInteger nol = BigInteger.ZERO;
		BigInteger one = BigInteger.ONE;
		while(tc-->0){
			n = sc.nextBigInteger();
			//System.out.println(enam.modPow(n,seratus));
			if(n.equals(nol)){
				System.out.println(1);
			}else if(n.equals(one)){System.out.println(66);}
			else{
				n = n.mod(lima);
				System.out.println(ans[n.intValue()]);	
			}
			
		}
		
	}
}