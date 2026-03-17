// cette classe est capable de réaliser des calculs sur des nombres entiers
// signés. Si le résultat n'est pas représentable sur un entier signé, la
// fonction retourne une exception "ComputingErrorException". Pour cela,
// la machine s'appuie sur les constantes Integer.MAX_VALUE et Integer.MIN_VALUE
// en vérifiant si l'addition ou la soustraction vont donner un résultat plus
// grand ou plus petit. Ex, si "ref"-A >= B alors A+B <= ref, donc le calcul
// est correct

public class Calculatrice {

    /**
     * Addition des entier a et b
     * @param a -> int
     * @param b -> int
     * @return somme de a+b
     * @throws ComputingErrorException
     */
    public int additionner(int a, int b) throws ComputingErrorException {
        return a + b;
    }
    /**
     * Soustraction des entiers a et b
     * @author Monsieur Moulard
     * @param a -> int
     * @param b -> int
     * @return soustraction de a par b
     * @throws ComputingErrorException
     */
    public int soustraire(int a, int b) throws ComputingErrorException {
        return a - b;
    }
}
