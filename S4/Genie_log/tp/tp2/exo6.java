
public class exo6 {
	
	/**
	 * utilise résoudre
	 * @param args
	 */
	public static void main(String[] args) {

		resoudre(-2, 2, 3);

	}
	
	/**
	 * Résoud un polynome du 2nd degré
	 * @param i
	 * @param j
	 * @param k
	 */
	public static void resoudre(double i, double j, double k) {

		double d = delta(i,j,k);
		if (d<0)
			System.out.println("pas de solutions");

		if (d==0.) {
			double s = -j / (2 * i);
			System.out.println("une solution : " + s);
		}

		if (d>0) {
			double s1 = ( -j - Math.sqrt(d) ) / (2 * i);
			double s2 = ( -j + Math.sqrt(d) ) / (2 * i);
			System.out.println("solution 1 : " + s1);
			System.out.println("solution 2 : " + s2);
		}
	}
	
	/**
	 * 
	 * @param i
	 * @param j
	 * @param k
	 * @return renvoit le delta avec les i j et k
	 */
	private static double delta(double i, double j, double k) {
		return ( j * j - 4 * i * k );
	}

}
