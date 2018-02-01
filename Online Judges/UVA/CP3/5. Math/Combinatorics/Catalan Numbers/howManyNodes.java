import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		int n;
		BigInteger i, one = BigInteger.ONE, dua = BigInteger.valueOf(2);
		BigInteger[] a = new BigInteger[305];
		a[0] = BigInteger.ONE;
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			i = BigInteger.ONE;
			BigInteger bil = sc.nextBigInteger();
			while(i.compareTo(BigInteger.valueOf(300))!=0){
				int idx = i.intValue();
				//if(i.equals(BigInteger.TEN))System.out.println(i+"fac: "+f.count());
				a[idx] = dua.multiply(i).multiply(((dua.multiply(i)).subtract(one))).multiply(a[idx-1]).divide((i.add(one)).multiply(i));
				//System.out.println(a[idx]);
				if(a[idx].equals(bil)){System.out.println(idx);break;}
				i = i.add(one);
				//System.out.println(a[idx]);
			}	
		}
		
	}
}