import java.util.Random;
import java.util.Scanner;

public class vetoresEmatrizes {
    public static void main(String[]args){
    Scanner sc = new Scanner(System.in);

        Random aleatorio = new Random();

        //Vetores (1 dimensão)
        int[] valoresA = new int[5];
        int tamanhoA = valoresA.length;

        // posição sempre começa em 0 e tamanho fixo (imutável)
        System.out.println("Tamanho do vetor [A] = "+tamanhoA);

        for(int i=0;i<tamanhoA;i++){
                System.out.print(valoresA[i]+" ");
            }

        int[] algarismos = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        System.out.println("\nExistem "+algarismos.length+" algarismos, são eles: ");
        for(int i=0;i<algarismos.length;i++){
                System.out.print(algarismos[i]+" ");
            }

        System.out.println("\nMenu");
        System.out.println("1- Soma dos Elementos de um Array/Vetor");
        System.out.println("2- Maior e Menor Elemento de um vetor (aleatório)");
        System.out.println("3- Vetor com os primeiros N números primos");
        System.out.println("4- Vetor com 7 números inteiros mostrado em ordem inversa");
        System.out.println("5- Contagem de Elementos em um vetor com 15 números/Par ou Ímpar");
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
                    System.out.print(valoresA[i]+" ");
                }
                System.out.println("\nSua soma final é: "+soma);
                break;
            case 2:
                byte[] vetorAleatorio = new byte[10];
                byte menor=vetorAleatorio[0], maior=vetorAleatorio[0];
                System.out.println("\n10 números aleatórios saindo do forno:");
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

                // tentativa de organizar em ordem crescente (Bubble Sort)
                boolean troca;
                byte save;
                do {
                    troca = false;
                    for(byte i = 0; i < vetorAleatorio.length - 1; i++) {
                        if(vetorAleatorio[i] > vetorAleatorio[i + 1]) {
                            save = vetorAleatorio[i];
                            vetorAleatorio[i] = vetorAleatorio[i + 1];
                            vetorAleatorio[i + 1] = save;
                            troca = true;
                        }
                    }
                } while(troca);
                System.out.println("\nArray ordenado em ordem crescente:");
                for(byte v : vetorAleatorio) {
                    System.out.print(v + " ");
                }
                byte[] vetorInverso = new byte[10];
                System.out.println("\nOrdem inversa/decrescente: ");
                    for(byte i=0;i<vetorAleatorio.length;i++){
                        vetorInverso[i] = vetorAleatorio[9-i];
                        System.out.print(vetorInverso[i]+" ");
                    }

                /*
                Existe também a opção mais fácil importando o Arrays.sort
                import java.util.Arrays;
                Arrays.sort(vetorAleatorio);

                Ideia mais para frente, fazer o cálculo do desvio padrão
                */
                
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
                    if(indice<=1){
                        System.out.println("Não há números primos nesse intervalo");
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
                    boolean parouimpar = false;
                    String parImpar = "";
                    do { 
                        System.out.println("Escolha par ou impar: (p/i)");
                        parImpar = sc.next().toLowerCase();
                        if (parImpar.equals("p")||parImpar.equals("par")){
                            parImpar = "par";
                            parouimpar = true;
                        }
                        else if (parImpar.equals("i")||parImpar.equals("impar")||parImpar.equals("ímpar")) {
                            parImpar = "impar";
                            parouimpar = true;
                        }
                    } while (!parouimpar);
                    
                    int par=0;
                    int[] vetor15 = new int[15];
                    System.out.println("Vetor gerado: ");
                    for(byte i=0;i<vetor15.length;i++){
                        vetor15[i] = aleatorio.nextInt(11);
                        System.out.print(vetor15[i]+" ");
                        if(vetor15[i]%2==0){
                            par++;
                        }
                    }
                    System.out.println("\nExistem "+par+" números pares nesse vetor");
                    System.out.println("Existem "+(15-par)+" números impares nesse vetor");
                    if(par>=8){
                        if(parImpar.equals("par")){
                            System.out.println("Você GANHOU, teve mais número pares");
                        }
                        if(parImpar.equals("impar")){
                            System.out.println("Você PERDEU, teve mais número pares");
                        }
                    }
                    else{
                        if(parImpar.equals("par")){
                            System.out.println("Você PERDEU, teve mais número ímpares");
                        }
                        if(parImpar.equals("impar")){
                            System.out.println("Você GANHOU, teve mais número ímpares");
                        }
                    }
                    break;
            default:
                break;
        }

    sc.close();
    }
}
