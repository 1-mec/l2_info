// conventions :
// incrément est positif
// décrément est négatif
// la vitesse est comprise entre 0 et 180

public interface Vehicule {

    /**
     * incrémentation de incrément de la vitesse du véhicule
     * @param increment = int
     * @return void
     * 
     */
    void accelerer(int increment);
    
    /**
     * freinage de decrement de la vitesse du véhicule
     * @param decrement = int
     * @return void 
     */
    void freiner(int decrement);

    /**
     * Fonction qui nous retourne la vitesse du véhicule
     * @return int de la vitesse
     * 
     */
    int getVitesseActuelle();

}
