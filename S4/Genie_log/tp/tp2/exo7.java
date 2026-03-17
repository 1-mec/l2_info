import java.util.Arrays;

public class exo7 {

	int[][] tab;

	/**
	 * 
	 * @param L
	 * @param C
	 */
	public exo7(int L, int C) {

		tab = new int[L][C];

		for (int l = 0; l<L; l++) 
			for (int c = 0; c<C; c++) 
				tab[l][c] = (int)(Math.random()*10)+1;
	}
	/**
	 * affiche le tableau en String
	 */
	public void affiche() {
		System.out.println(Arrays.deepToString(tab));
	}

	/**
	 * 
	 * @param n
	 * @return true ou false selon si n est trouvé ou pas
	 */
	public boolean Recherche1(int n) {

		boolean TROUVE = false;
		int l = 0;
		while(l<tab.length) {
			int c = 0;
			while (c<tab[0].length) {
				if (tab[l][c] == n)	TROUVE = true;			
				c++;
			}
			l++;
		}
		return TROUVE;
	}
	/**
	 * Compte le nombre d'élément qui sont = à n
	 * @param n
	 * @return int
	 */
	public int Compte(int n) {
		int nombre = 0;
		for (int[] ligne : tab) { for (int elem : ligne) { if (elem == n) nombre ++;} }
		return nombre;		
	}

	/**
	 * initie une matrice
	 * @param n
	 * @return tableau à 2 entrées de int
	 */
	public int[][] Localise(int n) {

		int nombre = Compte(n);
		int[][]pos = new int[nombre][2];
		int k=0;
		int l=0;
		for (int[] ligne : tab) {
			int c = 0;
			for (int elem : ligne) {
				if (elem == n) {
					pos[k][0] = l;
					pos[k][1] = c;
					k++;
				}
				c++;
			}
			l++;
		}
		return pos;
	}

	/**
	 * utilise toutes les fonctions
	 * @param args
	 */
	public static void main(String[] args) {

		exo7 T = new exo7(3,5);

		T.affiche();

		if (T.Recherche1(5))
			System.out.println(" -> 5 est dans le tableau");
		else
			System.out.println(" -> 5 n'est pas dans le tableau");

		if (T.Recherche1(5))
			System.out.println(" -> 5 est présent " + T.Compte(5)+" fois");

		if (T.Recherche1(5)) {
			System.out.println(" -> position(s) du 5 : " +
					Arrays.deepToString(T.Localise(5)));
		}
	}
}


