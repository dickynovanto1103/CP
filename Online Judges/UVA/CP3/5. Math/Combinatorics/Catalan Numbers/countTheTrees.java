import java.util.Scanner;
import java.math.BigInteger;

class Factorial {
	BigInteger n,i;
	public BigInteger dua = BigInteger.valueOf(2);
	public BigInteger one = BigInteger.ONE;
	public Factorial(BigInteger n){this.n = n;}
	public BigInteger count(){
		BigInteger ans = BigInteger.ONE;
		i = n;
		while(i.compareTo(dua)==0 || i.compareTo(dua)==1){
			//System.out.println("di count i: "+i);
			ans = ans.multiply(i);
			i = i.subtract(one);
		}
		return ans;
	}
}

class Main {
	public static void main(String[] args) {
		int n;
		BigInteger i, one = BigInteger.ONE, dua = BigInteger.valueOf(2);
		BigInteger[] a = new BigInteger[1010];
		a[0] = BigInteger.ONE;
		i = BigInteger.ONE;
		while(i.compareTo(BigInteger.valueOf(1001))!=0){
			int idx = i.intValue();
			//if(i.equals(BigInteger.TEN))System.out.println(i+"fac: "+f.count());
			a[idx] = dua.multiply(i).multiply(((dua.multiply(i)).subtract(one))).multiply(a[idx-1]).divide((i.add(one)).multiply(i));
			i = i.add(one);
			//System.out.println(a[idx]);
		}
		int j;
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			 j = sc.nextInt();
			 System.out.println(a[j]);
		}
		/*for(j=0;j<=10;j++){
			System.out.println(a[j]);
		}*/
		/*for(i=1;i<=10;i++){
			a[i] = (2*i*(2*i-1)*a[i-1])/((i+1)*i);
		}*/
	}
}