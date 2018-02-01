import java.util.Scanner;
import java.math.BigInteger;
import java.util.TreeMap;

class Main{
	public static void main(String[] args) {
		BigInteger[] a = new BigInteger[21];
		int i;
		a[0] = BigInteger.ONE; a[1] = BigInteger.ONE;
		for(i=2;i<=20;i++){a[i] = a[i-1].multiply(BigInteger.valueOf(i));}

		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		BigInteger ans;
		int[] karBeda = new int[21];

		TreeMap<Character,Integer> mapper = new TreeMap<Character,Integer>();
		for(int tt=1;tt<=tc;tt++){
			System.out.print("Data set "+tt+": ");
			String kata = sc.next();
			int pjg = kata.length();
			ans = a[pjg];

			//proses kata"yg berbeda
			int cnt = 0;
			for(i=0;i<=20;i++){karBeda[i] = 0;}
			for(i=0;i<pjg;i++){
				Character c = new Character(kata.charAt(i));
				if(!mapper.containsKey(c)){mapper.put(c,cnt); karBeda[cnt]++; cnt++;}
				else{
					int idx = mapper.get(c);
					/*System.out.println("kar: "+c);
					System.out.println("idx: "+idx);*/
					karBeda[idx]++;
					//System.out.println("karbeda[idx] jadi "+karBeda[idx]);
				}
			}
			for(i=0;i<cnt;i++){
				ans = ans.divide(a[karBeda[i]]);
			}
			System.out.println(ans);
			//for(i=0;i<=20;i++){System.out.println("i: "+i+" karBeda[i] = "+karBeda[i]);}
			mapper.clear();
		}
	}
}	