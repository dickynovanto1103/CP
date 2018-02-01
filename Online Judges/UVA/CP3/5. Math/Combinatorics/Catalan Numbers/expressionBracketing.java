import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {
		BigInteger i, one = BigInteger.ONE, dua = BigInteger.valueOf(2);
		BigInteger[] a = new BigInteger[30];
		a[0] = BigInteger.ONE;
		i = BigInteger.ONE;
		while(i.compareTo(BigInteger.valueOf(27))!=0){
			int idx = i.intValue();
			//if(i.equals(BigInteger.TEN))System.out.println(i+"fac: "+f.count());
			a[idx] = dua.multiply(i).multiply(((dua.multiply(i)).subtract(one))).multiply(a[idx-1]).divide((i.add(one)).multiply(i));
			i = i.add(one);
			//System.out.println(a[idx]);
		}
		BigInteger[] b = new BigInteger[30];
		b[1] = BigInteger.ONE; b[2] = BigInteger.ONE;
		BigInteger tiga = BigInteger.valueOf(3);
		i = tiga;
		while(i.compareTo(BigInteger.valueOf(27))!=0){
			int idx = i.intValue();
			//if(i.equals(BigInteger.TEN))System.out.println(i+"fac: "+f.count());
			//System.out.println("idx: "+idx);
			BigInteger temp1 = (dua.multiply(i)).subtract(tiga);
			BigInteger kurang3 = i.subtract(tiga);
			b[idx] = ((tiga.multiply(temp1).multiply(b[idx-1])).subtract((kurang3).multiply(b[idx-2])).divide(i));
			i = i.add(one);
			//System.out.println(a[idx]);
		}
		/*System.out.println("super catalan:");
		int j;
		for(j=1;j<=26;j++){
			System.out.println(b[j]);
		}*/
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int j = sc.nextInt();
			BigInteger ans = b[j].subtract(a[j-1]);
			System.out.println(ans);
		}
	}
}