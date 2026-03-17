import java.util.*;
public class ex1{	
	private static String test;

	private static int res = 0;
	
	public ex1(String str) {
		test  = str;
		String p = getTest();
        for (int i = 0; i < test.length(); i++ ) {
        	if(p.charAt(i) == '0') {
        		res ++;
        	}
        }
	}
	
    public static String getTest() {
		return test;
	}
    
    public static int getRes() {
		return res;
	}

	public static void setRes(int res) {
		ex1.res = res;
	}
	
	public static String getPair() {
        int res_ult = test.length() - getRes() ;
        if ((res_ult %2) == 0) {
        	return "c'est pair !";
        } else {
        	return "c'est impaire";
        }
	}
	

	public static void main(String[] args) {
        System.out.println("bonjour monde");
        ex1 t = new ex1("01111111010101010100");
        System.out.println(t.getPair());
    }
}