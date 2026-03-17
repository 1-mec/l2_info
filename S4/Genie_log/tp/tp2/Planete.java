// la doc devrait mentionner des documents externes qui donnent les valeurs
// des masses relatives

public enum Planete {


    MERCURE, VENUS, TERRE, MARS, JUPITER, SATURNE, URANUS, NEPTUNE;

    /**
     * Fonction qui déduit la masse relative à chaque planetes
     * {@link <a href="https://fr.wikipedia.org/wiki/Jupiter_(plan%C3%A8te)"> Planete</a>}
     * @see Planete 
     * @param void
     * @return double
     * 
     */
    public double masseRelativeTerre() {
        switch (this) {
            case TERRE:
                return 1.0;
            case MERCURE:
                return 0.055;
            // TODO Complétez avec les autres planètes
        }
        return 0;
    }
}
