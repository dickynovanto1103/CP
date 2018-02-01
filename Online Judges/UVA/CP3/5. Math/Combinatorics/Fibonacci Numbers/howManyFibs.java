import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger[] fib = new BigInteger[500];
		fib[1] = BigInteger.ONE; fib[2] = BigInteger.valueOf(2);
		int i;
		for(i=3;i<=480;i++){
			fib[i] = fib[i-1].add(fib[i-2]);
		}
		BigInteger a,b;
		while(true){
			a = sc.nextBigInteger(); b = sc.nextBigInteger();
			//System.out.println("a: "+a+" b:"+b);
			if(a.compareTo(BigInteger.ZERO)==0 && b.compareTo(BigInteger.ZERO)==0){
				
				break;
			}
			int cnt = 0;
			for(i=1;i<=480;i++){
				int cmp1 = fib[i].compareTo(a), cmp2 = fib[i].compareTo(b);
				if(cmp1==0 || cmp1==1){
					if(cmp2==0 || cmp2==-1){
						cnt++;
					}
				}
			}
			System.out.println(cnt);
		}
		

	}
}