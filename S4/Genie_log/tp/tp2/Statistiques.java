public class Statistiques {
	/**
	 * Calcule la moyenne des valeurs dans valeurs
	 * @param array valeurs
	 * @return moyenne des valeurs dans valeurs
	 */
    public double calculerMoyenne(int[] valeurs) {
        double res = 0;
        for(int i = 0; i < valeurs.length ; i++ ) {
        	res += valeurs[i];
        }
        return res/valeurs.length;
    }

    /**
     * Retourne la valeure maximum dans valeurs
     * @param valeurs
     * @return
     */
    public int maximum(int[] valeurs) {
        int tmp = valeurs[0];
        for(int i = 1; i < valeurs.length ; i++ ) {
        	if(tmp < valeurs[i]) {
        		tmp = valeurs[i];
        	}
        }
        return tmp;
    }
}
