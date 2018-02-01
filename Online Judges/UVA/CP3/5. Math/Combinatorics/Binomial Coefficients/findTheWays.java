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
	public BigInteger nol = BigInteger.ZERO;
	public static void main(String[] args) {
		BigInteger n = BigInteger.ZERO;
		BigInteger m = BigInteger.ZERO;
		BigInteger selisih = BigInteger.ZERO;
		BigInteger one = BigInteger.ONE;
		String hasil;
		BigInteger temp;
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			n = sc.nextBigInteger();
			m = sc.nextBigInteger();
			selisih = n.subtract(m);
			BigInteger ans = one;
			BigInteger i = n;
			if(selisih.compareTo(m)==-1){
				//System.out.println("selisih lebih kecil");
				Factorial f = new Factorial(selisih);
				while(i.compareTo(n.subtract(selisih).add(one))==0 || i.compareTo(n.subtract(selisih).add(one))==1){
					ans = ans.multiply(i);
					i = i.subtract(one);
				}
				ans = ans.divide(f.count());
			}else{
				//System.out.println("selisih lebih besar");
				Factorial f = new Factorial(m);
				//System.out.println("sudah construct");
				while(i.compareTo(n.subtract(m).add(one))==0 || i.compareTo(n.subtract(m).add(one))==1){
					ans = ans.multiply(i);
					i = i.subtract(one);
					//System.out.println("i: "+i);
				}
				ans = ans.divide(f.count());
				//System.out.println("ans: "+ans);
			}
			hasil = ans.toString();
			System.out.println(hasil.length());
		}
	}
}