import java.math.BigDecimal;
import java.util.Scanner;

class Main {
	public static int md(int n, int m) {
	    if (n>m) n %= m;
	    if (n==0) n = m;
	    return n;
	}

	public static void main(String args[]) {
		int n,k;
		double t;
		BigDecimal[] x,y;
		x = new BigDecimal[3000]; y = new BigDecimal[3000];
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt(); k = sc.nextInt();
		for (int i=1;i<=n;++i) {
			t = sc.nextDouble();
			x[i] = new BigDecimal(t);
			t = sc.nextDouble();
			y[i] = new BigDecimal(t);
		}
		BigDecimal ans, d;
		ans = new BigDecimal(0);
		for (int i=1;i<=n+1-k;++i) {
			d = new BigDecimal(k*(k-1));
			for (int j=n-k-i+2;j<=n-k;++j) d = d.multiply(new BigDecimal(j));
	        for (int j=n-i;j<=n;++j) d = d.divide(new BigDecimal(j), 12, BigDecimal.ROUND_HALF_EVEN);
	        for (int j=1;j<=n;++j) {
	        	ans = ans.add(d.multiply(x[j]).multiply(y[md(j-i+n, n)].subtract(y[md(i+j, n)])));
	        }
	    }
	    ans = ans.divide(new BigDecimal(2));
	    double ansd = ans.doubleValue();
	    System.out.printf("%.12f\n", ansd);
	}
};