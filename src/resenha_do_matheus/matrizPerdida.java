package resenha_do_matheus;
import java.util.Random;
import java.util.Scanner;

public class matrizPerdida{
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    /*
    Crie um programa que leia dois números inteiros M e N. 
    Em seguida, leia uma matriz com M linhas e N colunas contendo números inteiros 
    (podendo haver repetições). Depois, leia um número inteiro X que pertence à matriz. 
    Para cada ocorrência de X, mostre os valores à esquerda, acima, à direita e abaixo de X, 
    quando existirem, conforme o exemplo.

    3x4
    [{10,8,15,12}, 
    {21,11,23,8}, 
    {14,5,3,19}]
    8
    0,1
    Left: 10
    Right: 15
    Down: 11
    1,3
    Left: 23
    Right: 12
    Down: 19

    esquerda j-1
    direita j+1
    baixo n+1
    cima n-1
    */
   
    Random aleatorio = new Random();
    System.out.println("Insira a ordem M da matriz: ");
    int m = sc.nextInt();
    System.out.println("Insira a ordem N da matriz: ");
    int n = sc.nextInt();
    int [][] matriz  = new int [m][n];
    for (int i=0; i<m;i++){
        System.out.println();
            for (int j=0; j<n;j++){
                matriz[i][j] = aleatorio.nextInt(10);
                System.out.print(matriz[i][j]+" ");
            }
    }
    int contador = 0;
    System.out.println("\n");
    System.out.println("Qual número você quer analisar? ");
    int num = sc.nextInt();
    for (int i=0; i<m;i++){
            for (int j=0; j<n;j++){
                if (matriz[i][j]==num){
                    contador+=1;
                    System.out.print("\n"+num+" está na posição "+(i+1)+"x"+(j+1));
                    if (j>0){ 
                        System.out.print(" e a sua esquerda está o "+matriz[i][j-1]);
                    }
                    if (i<m-1){ 
                        System.out.print(" e em baixo está o "+matriz[i+1][j]);
                    }
                    if (j<n-1){ 
                        System.out.print(" e a direita está o "+matriz[i][j+1]);
                    }
                    if (i>0) {
                        System.out.print(" e em cima está o "+matriz[i-1][j]);
                    }
                }
            }
    }
    System.out.println("\nTiveram "+contador+" números "+num);
    
    

   

    sc.close();
}
}