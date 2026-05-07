import java.util.Scanner;
import java.util.Random;

public class vetoresEmatrizes {
    public static void main(String[]args){
    Scanner sc = new Scanner(System.in);

        Random aleatorio = new Random();

        //Vetores (1 dimensão)
        int[] valoresA = new int[5];
        int tamanhoA = valoresA.length;
        for(int i=0;i<tamanhoA;i++){
                System.out.println(valoresA[i]);
            }
        // posição sempre começa em 0 e tamanho fixo (imutável)
        System.out.println("Tamanho do vetor [A] = "+tamanhoA);

        int[] algarismos = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        System.out.println("São "+algarismos.length+" algarismos que existem, são eles: ");
        for(int i=0;i<algarismos.length;i++){
                System.out.println(algarismos[i]);
            }

        System.out.println("Menu");
        System.out.println("1- Soma dos Elementos de um Array/Vetor");
        System.out.println("2- Maior e Menor Elemento de um vetor (aleatório)");
        System.out.println("3- Vetor com os primeiros N números primos");
        System.out.println("4- Vetor com 7 números inteiros mostrado em ordem inversa");
        System.out.println("5- Contagem de Elementos em um vetor com 15 números");
        System.out.printf("Escolha uma opção: ");
        int escolha = sc.nextInt();
        switch (escolha) {
            case 1:
                int soma = 0;
                for(int i=0;i<tamanhoA;i++){
                    System.out.println("Insira o "+(i+1)+"º valor inteiro: ");
                    valoresA[i] = sc.nextInt();
                    soma += valoresA[i];
                }
                System.out.println("Array inteiro: ");
                for(int i=0;i<tamanhoA;i++){
                    System.out.println(valoresA[i]);
                }
                System.out.println("Sua soma final é: "+soma);
                break;
            case 2:
                byte[] vetorAleatorio = new byte[10];
                byte menor=vetorAleatorio[0], maior=vetorAleatorio[0];
                System.out.println("10 números aleatórios saindo do forno:");
                aleatorio.nextBytes(vetorAleatorio);
                for(byte i=0;i<vetorAleatorio.length;i++){
                    System.out.print(vetorAleatorio[i]+" ");
                    if(i==0){
                        menor = vetorAleatorio[i];
                        maior = vetorAleatorio[i];
                    }
                    else{
                        if(vetorAleatorio[i]<menor){
                            menor = vetorAleatorio[i];
                        }
                        else if(vetorAleatorio[i]>maior){
                            maior = vetorAleatorio[i];
                        }
                    }
                }

                /*
                for(byte v: vetorAleatorio){
                    System.out.print(vetorAleatorio[v]+" ");
                }    
                 */

                System.out.println("\nO menor valor foi: "+menor);
                System.out.println("O maior valor foi: "+maior);

                break;
            case 3:
                    int tia;
                    int tamanho = 0;
                    int indice = 0;
                    System.out.printf("Insira o limite máximo do intervalo: ");
                    tia = sc.nextInt();
                    System.out.println("Os números que são primos entre o intervalo de 2 e "+tia+" são:");
                    for(int k=2; k<=tia; k++){
                        boolean primo = true;
                        for(int l=2; l<=Math.sqrt(k); l++){
                            if (k%l==0){
                                primo = false; 
                            }
                        }
                        if (primo==true){
                            tamanho +=1;
                        }
                    }
                    // no máximo 10 elementos, então para no 29
                    if (tamanho<=10){
                        int[] primos = new int [tamanho];
                        for(int k=2; k<=tia; k++){
                            boolean primo = true;
                            for(int l=2; l<=Math.sqrt(k); l++){
                                if (k%l==0){
                                    primo = false; 
                                }
                            }
                            if (primo==true){
                            primos[indice] = k;
                            indice++;
                            }
                        }
                        for(int i = 0; i < primos.length; i++){
                        System.out.print(primos[i] + " ");
                    }
                    }
                    else{
                        System.out.println("(O vetor não suporta mais que 10 elementos, então o máximo que armazenou foram os 10 primeiros)");
                        System.out.println("2 3 5 7 11 13 17 19 23 29");
                    }
                break;
                case 4:
                    byte[] vetor7a = new byte[7];
                    byte[] vetor7b = new byte[7];
                    System.out.println("7 números aleatórios saindo do micro-ondas:");
                    aleatorio.nextBytes(vetor7a);
                    System.out.println("Ordem normal: ");
                    for(byte i=0;i<vetor7a.length;i++){
                        System.out.print(vetor7a[i]+" ");
                    }
                    System.out.println("\nOrdem inversa: ");
                    for(byte i=0;i<vetor7a.length;i++){
                        vetor7b[i] = vetor7a[6-i];
                        System.out.print(vetor7b[i]+" ");
                    }
                    break;
                case 5:
                    int par=0;
                    int[] vetor15 = new int[15];
                    for(byte i=0;i<vetor15.length;i++){
                        vetor15[i] = aleatorio.nextInt(11);
                        System.out.print(vetor15[i]+" ");
                        if(vetor15[i]%2==0){
                            par++;
                        }
                    }
                    System.out.println("\nExistem "+par+" números pares nesse vetor");
                    System.out.println("Existem "+(15-par)+" números impares nesse vetor");
                    break;
            default:
                break;
        }

    sc.close();
    }
}
