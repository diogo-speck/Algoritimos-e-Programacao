package aula08;

import java.util.Scanner;
import java.util.Random;

public class matrizes {
    
    public static void main(String[]args){
    Scanner sc = new Scanner(System.in);

        Random randomico = new Random();

        /*
        int [][] matrix = new int [5][5];
        for (int i=0; i<matrix.length;i++){
            System.out.println();
            for (int j=0; j<matrix.length;j++){
                System.out.print(matrix[i][j]+" ");
        }
        }
        int [][][] _3d = new int [3][3][3];
        for (int i=0; i<_3d.length;i++){
            System.out.println();
            for (int j=0; j<_3d.length;j++){
                System.out.println();
                for (int k=0; k<_3d.length;k++){
                    System.out.print(_3d[i][j][k]+" ");
                }
            }
        }
        */
       
        System.out.println("\n1 - Soma de matrizes");
        System.out.println("2 - Soma dos valores da diagonal principal de uma matriz aleatória");
        System.out.println("3 - Matriz Identidade");
        System.out.println("4 - Verificação de Simetria");
        System.out.println("5 - Matriz transposta");
        int escolha = sc.nextInt();

        switch (escolha) {
            case 1:
                int [][] ordem2 = new int [2][2];
                int [][] ordem2_ = new int [2][2];
                for (int n=1;n<3;n++){
                    System.out.println("Insira o valor do elemento ");
                    for (int i=0; i<ordem2.length;i++){
                        for (int j=0; j<ordem2.length;j++){
                            System.out.print((i+1)+" "+(j+1)+" da "+n+"ª matriz: ");
                            if (n==1){
                                ordem2 [i][j] = sc.nextInt();
                            }
                            else{
                                ordem2_ [i][j] = sc.nextInt();
                            }
                        }
                    }   
                }
                System.out.println("A soma das suas matrizes quadradas de ordem 2 (2x2) ficou assim: ");
                for (int i=0; i<ordem2.length;i++){
                    if (i>0){
                        System.out.println();
                    }
                    for (int j=0; j<ordem2.length;j++){
                        ordem2[i][j]= ordem2[i][j]+ordem2_[i][j];
                        System.out.print(ordem2[i][j]+" ");
                    }
                }   
                break;

            case 2:
                int diagonal=0;
                byte [][] ordem3 = new byte [3][3];
                System.out.println("Matriz gerada aleatóriamente: ");
                for (int i=0; i<ordem3.length;i++){
                    randomico.nextBytes(ordem3[i]);
                    for (int j=0; j<ordem3.length;j++){
                        randomico.nextBytes(ordem3[j]);
                    }
                }   
                for (int i=0; i<ordem3.length;i++){
                    if (i>0){
                        System.out.println();
                    }
                    for (int j=0; j<ordem3.length;j++){
                        System.out.print(ordem3[i][j]+" ");
                        if (i==j){
                            diagonal += ordem3[i][j];
                        }
                    }
                }   
                System.out.println("\nA soma da diagonal da matriz quadrada aleatória de ordem 3 (3x3) é "+diagonal);
                break;

                case 3:
                    System.out.println("Digite a ordem desejada da matriz identidade: ");
                    int ordem = sc.nextInt();
                    int [][] ordemN = new int [ordem][ordem];
                    for (int i=0; i<ordemN.length;i++){
                        if (i>0){
                            System.out.println();
                        }
                        for (int j=0; j<ordemN.length;j++){
                            if (i==j){
                                System.out.print(1+" ");
                            }
                            else{
                                System.out.print(ordemN[i][j]+" ");
                            }
                        }
                    }   

                    break;

                case 4:
                    // Pede uma matriz de ordem N e pede todos os elementos dela
                    System.out.println("Digite a ordem desejada da matriz: ");
                    ordem = sc.nextInt();
                    ordemN = new int [ordem][ordem];
                    for (int i=0;i<ordem;i++){
                        for (int j=0; j<ordemN.length;j++){
                            System.out.print("Insira o valor do elemento ["+(i+1)+" "+(j+1)+"]: ");
                            ordemN [i][j] = sc.nextInt();
                        }
                    }
                    System.out.println("Sua matriz ficou assim: ");
                    for (int i=0;i<ordem;i++){
                        if (i>0){
                            System.out.println();
                        }
                        for (int j=0; j<ordemN.length;j++){
                            System.out.print(ordemN [i][j]+" ");
                        }
                    }

                    // Verificação da Simetria
                    boolean simetrica = true;
                    for (int i=0;i<ordem;i++){
                        for (int j=0; j<ordemN.length;j++){
                            if(ordemN [i][j] != ordemN [j][i]){
                                simetrica = false;
                            }
                        }
                    }
                    if (simetrica == true){
                        System.out.println("\nSua matriz é simétrica");
                    }
                    else{
                        System.out.println("\nSua matriz não é simétrica");
                    }

                    break;

                case 5:
                    System.out.println("Digite quantas linhas terá a matriz: ");
                    int linha = sc.nextByte();
                    System.out.println("Digite quantas colunas terá a matriz: ");
                    int coluna = sc.nextByte();
                    int [][] transposta = new int [linha][coluna];
                    System.out.println("Matriz gerada aleatóriamente: ");
                    for (int i=0; i<linha;i++){
                        System.out.println();
                        for (int j=0; j<coluna;j++){
                            transposta[i][j] = (byte) randomico.nextInt(256); 
                            System.out.print(transposta[i][j]+" "); 
                        }
                    }   
                    System.out.println("\n\nMatriz transposta: ");
                    for (int i=0; i<coluna;i++){
                        System.out.println();
                        for (int j=0; j<linha;j++){
                            System.out.print(transposta[j][i]+" "); 
                        }
                    }   

                    break;
            default:
                break;
        }

    sc.close();
    }

}
