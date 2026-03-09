import java.lang.*;
public class ex2 {

	private static String mdp;
	private static int uC = 0;
	private static int nb_chiffre = 0;
	public ex2(String arg) {
		this.mdp = arg;
	}
		
	public static String getMdp() {
		return mdp;
	}

	public boolean longueure(){
		if( getMdp().length() < 4 && getMdp().length() > 12 ) {
			return true;
		}
		return false;
	}

	public int isUpper(int i){
		if(Character.isUpperCase(getMdp().charAt(i))) {
			uC ++;
		}
		return uC;
	}

	public boolean lettres(int i){
		if(!(Character.isAlphabetic(getMdp().charAt(i)))&& (!(Character.isDigit(getMdp().charAt(i))))) {
			return false;
		}
		return true;
	}

	public int nbChiffre(int i ){
		if(Character.isDigit(getMdp().charAt(i))) {
			nb_chiffre ++;
		}
		return nb_chiffre;
	}
	public String test() {
		int nb_chiffre = 0;
		for (int i = 0; i < getMdp().length();i++) {
			isUpper(i);
			lettres(i);
			nbChiffre(i);
		}
		if (!(uC >= 2 )) System.err.println("Manque de Upper Case");
		if (!(nb_chiffre <= 2)) System.err.println("Manque de chiffre");
		return "C'est bon !";
		
	}
	 	
	public static void main(String args[]) {
		ex2 e = new ex2("azAXe84rty");
		System.out.println(e.test());
	}
}
