import java.util.*;
import java.math.BigInteger;

class Solution{
	public static void main(String[] args) {
		int tc,i,j;
		Scanner sc = new Scanner(System.in);
		tc= sc.nextInt();
		for(int tt=1;tt<=tc;tt++){
			System.out.print("Case #"+tt+": ");
			int l;
			BigInteger n;
			n = sc.nextBigInteger(); l = sc.nextInt();
			BigInteger a[] = new BigInteger[201];
			for(i=0;i<l;i++){
				a[i] = sc.nextBigInteger();
			}
			TreeSet<BigInteger> s = new TreeSet<BigInteger>();
			BigInteger ans[] = new BigInteger[201];

			for(i=0;i<(l-1);i++){
				BigInteger gcd = a[i].gcd(a[i+1]);
				if(gcd.compareTo(a[i]) == -1 && gcd.compareTo(a[i+1]) == -1){
					//coba 2 kemungkinan
					ans[i+1] = gcd;
					s.add(ans[i+1]);
					ans[i] = a[i].divide(gcd);
					s.add(ans[i]);
					BigInteger cur = ans[i];
					for(j=i-1;j>=0;j--){
						ans[j] = a[j].divide(cur);
						cur = ans[j];
						s.add(cur);
					}
					cur = ans[i+1];
					for(j=i+2;j<=l;j++){
						ans[j] = a[j-1].divide(cur);
						cur = ans[j];
						s.add(cur);
					}
					break;
				}
			}
			Map<BigInteger, Character> mapper = new HashMap<BigInteger, Character>();
			Iterator<BigInteger> it = s.iterator();
			Character c = 'A';
			while(it.hasNext()) {
				BigInteger bil = it.next();
				mapper.put(bil, c++);
			}
			for(i=0;i<=l;i++){
				System.out.print(mapper.get(ans[i]));
			}
			System.out.println();
		}
	}
}