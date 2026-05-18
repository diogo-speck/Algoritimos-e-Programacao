package aulas.aula08;

import java.util.Scanner;

public class atividadeEmSala03M2 {
    public static void main(String[]args){
    
    Scanner sc = new Scanner(System.in);

        System.out.println("Bem vindo ao programa de Multiplicação de Matrizes");
        System.out.println("Qual a quantidade de linhas da matriz 1: ");
        int linhas1 = sc.nextInt();
        System.out.println("Qual a quantidade de colunas da matriz 1: ");
        int colunas1 = sc.nextInt();
        System.out.println("Qual a quantidade de linhas da matriz 2: ");
        int linhas2 = sc.nextInt();
        System.out.println("Qual a quantidade de colunas da matriz 2: ");
        int colunas2 = sc.nextInt();
        int [][] matriz = new int [linhas1][colunas2];
        int [][] matriz1 = new int [linhas1][colunas1];
        int [][] matriz2 = new int [linhas2][colunas2];
        if (colunas1==linhas2){
            System.out.println("A ordem da sua matriz após a multiplicação será "+linhas2+"x"+colunas1);
            for(int i=0;i<linhas1;i++){
                for(int j =0;j<colunas1;j++){
                    System.out.println("Informe o elemento "+(i+1)+"x"+(j+1)+" da matriz 1: ");
                        matriz1[i][j]=sc.nextInt();
                    }
            }
            for(int i=0;i<linhas2;i++){
                for(int j =0;j<colunas2;j++){
                    System.out.println("Informe o elemento "+(i+1)+"x"+(j+1)+" da matriz 2: ");
                        matriz2[i][j]=sc.nextInt();
                    }                  
            }
            System.out.println("\nSua matriz resultante da multiplicação é essa:");
            for(int i=0;i<linhas1;i++){
                System.out.println();
                for(int j =0;j<colunas2;j++){
                    for(int y=0;y<colunas1;y++){
                        matriz[i][j]+=matriz1[i][y]*matriz2[y][j];
                    }
                    System.out.print(matriz[i][j]+" ");
                }
            }
        }
        else{
            System.out.println("Suas matrizes são impossíveis de multiplicar porquê apresentam ordens incompatíveis");
        }


    sc.close();
    }
}
