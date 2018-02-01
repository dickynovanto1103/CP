import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args){
		BigInteger a[] = new BigInteger[260];
		a[0] = BigInteger.ONE;
		
		int i;
		for(i=1;i<=259;i++){
			a[i] = BigInteger.ZERO;
		}
		for(i=0;i<=250;i++){
			//System.out.println("i: "+i+" isi array: "+a[i]);
			a[i+1] = a[i+1].add(a[i]);
			a[i+2] = a[i+2].add(a[i]);
			a[i+2] = a[i+2].add(a[i]);
		}

		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int idx = sc.nextInt();
			System.out.println(a[idx]);
		}
	}
}