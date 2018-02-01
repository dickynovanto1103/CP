import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger[] fib = new BigInteger[850];
		fib[1] = BigInteger.ZERO;
		int i;
		for(i=2;i<=800;i++){
			fib[i] = fib[i-1].multiply(BigInteger.valueOf(i));
			if(i%2==0){fib[i] = fib[i].add(BigInteger.ONE);}
			else{fib[i] = fib[i].subtract(BigInteger.ONE);}
		}
		while(true){
			int idx = sc.nextInt();
			if(idx==-1){break;}
			System.out.println(fib[idx]);
		}
		

	}
}