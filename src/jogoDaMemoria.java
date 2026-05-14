import java.util.Random;
import java.util.Scanner;

public class jogoDaMemoria {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    
        Random aleatorio = new Random();

        char tabuleiro[][] = new char [7][7];
        for(int i=0;i<tabuleiro.length;i++){
            System.out.println();
            for(int j=0;j<tabuleiro.length;j++){
                System.out.println(tabuleiro[i][j]);
            }
        }


        sc.close();
    }
}