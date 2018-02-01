import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static BigInteger[] a;

	public static void main(String[] args) {
		a = new BigInteger[155];
		int i,j;
		a[0] = BigInteger.ONE;
		a[1] = BigInteger.valueOf(2);
		for(i=2;i<=150;i++){a[i] = a[i-1].add(a[i-2]);}
		//for(i=0;i<=100;i++){System.out.println(a[i]);}
		Scanner sc = new Scanner(System.in);
		BigInteger sum1, sum2, sum;
		int tc = 1;
		while(sc.hasNext()){
			if(tc==2){System.out.println();}
			String s1 = sc.next();
			String s2 = sc.next();
			int pjg1 = s1.length(), pjg2 = s2.length();
			j=0;
			sum1 = BigInteger.ZERO; sum2 = BigInteger.ZERO;
			for(i=pjg1-1;i>=0;i--){
				int bil = s1.charAt(i);
				if(bil==49){sum1 = sum1.add(a[j]);}
				//sum1 = sum1.add()
				j++;
			}
			j=0;
			for(i=pjg2-1;i>=0;i--){
				int bil = s2.charAt(i);
				if(bil==49){sum2 = sum2.add(a[j]);}
				//sum1 = sum1.add()
				j++;
			}
			sum = sum1.add(sum2);
			String ans = BigIntegerToString(sum);
			//System.out.println("ans: "+ans);
			for(i=0;i<=150;i++){
				if(ans.charAt(i)=='1'){break;}
			}
			if(i==151){System.out.print(0);}
			int idx = i;
			for(i=idx;i<=150;i++){
				System.out.print(ans.charAt(i));
			}
			System.out.println();
			tc = 2;
		}

	}
	public static String BigIntegerToString(BigInteger sum){
		String kata = new String();

		for(int i=150;i>=0;i--){
			int perbandingan = sum.compareTo(a[i]);
			if(perbandingan==1 || perbandingan==0){
				kata+="1";
				sum = sum.subtract(a[i]);
			}else{
				kata+="0";	
			}
			
		}
		
		return kata;
	}

}