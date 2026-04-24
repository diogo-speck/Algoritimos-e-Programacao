import java.util.Scanner;
public class atividadeEmSala02M2 {
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Escolha a atividade:");
        System.out.println("1 - Impressão sequencial decrescente");
        System.out.println("2 - Soma de números em intervalo");
        System.out.println("3 - Fatorial");
        System.out.println("4 - Sequência de Fibonacci");
        System.out.println("5 - Exibir números primos em um intervalo");
        System.out.println("6 - Verificação de número perfeito:");
        System.out.println("7 - Padrão numérico crescente");
        System.out.printf("Escolha: ");
        int escolha = sc.nextInt();
            switch (escolha) {
                case 1:
                    for (int a=20; a >=1; a--)
                        System.out.println(a);
                    break;
                case 2:
                    int soma = 0;
                    System.out.println("Informe um valor inteiro: ");
                    int n1 = sc.nextInt();
                    System.out.println("Informe outro valor inteiro: ");
                    int n2 = sc.nextInt();
                    if (n1>n2){
                        for (int b=n2; b<=n1; b++){
                            //System.out.println(b);
                            soma = soma+b;
                        }
                    }
                    else if (n1<n2){
                        for (int b=n2; b>=n1; b--){
                            //System.out.println(b);
                            soma = soma+b;
                        }
                    }
                    else{
                        System.out.println("Não há números inteiros dentro desse intervalo");
                    }
                    System.out.println("Soma de todos os números dentro desse intervalo = "+soma);
                    break;
                case 3:
                    System.out.println("Digite um número inteiro positivo: ");
                    int numero = sc.nextInt();
                    int fatorial=1;
                    for (int c=1; c<=numero; c++){
                        //System.out.println(c);
                        fatorial = fatorial*c;
                    }
                    System.out.println("O fatorial do número "+numero+" é "+fatorial);
                    break;
                case 4:
                    int termos, f=0, g=1, h;
                    System.out.printf("Insira quantos termos você quer que a sequência tenha: ");
                    termos = sc.nextInt();
                    if (termos <= 0){
                        System.out.println("Digite um número inteiro maior que zero");
                        break;
                    }
                    else if (termos == 1){
                        System.out.println(f);
                    }
                    else{
                        System.out.println(f);
                        System.out.println(g);
                        if (termos > 2){
                            for (int d=0; d<=termos-2; d++){
                                h=f+g;
                                System.out.println(h);
                                f=g;
                                g=h;
                            }
                        }
                    }
                    break;
                case 5:
                    int tio;
                    System.out.printf("Insira o limite máximo do intervalo: ");
                    tio = sc.nextInt();
                    System.out.println("Os números que são primos entre o intervalo de 2 e "+tio+" são:");
                    for(int k=2; k<=tio; k++){
                        boolean primo = true;
                        for(int l=2; l<=Math.sqrt(k); l++){
                            if (k%l==0){
                                primo = false; 
                            }
                        }
                        if (primo==true){
                            System.out.printf(k+" ");
                        }
                    }
                    break;
                case 6:
                    int imperfeito, m=2;
                    double perfeitos=0;
                    System.out.printf("Insira um número inteiro maior que zero: ");
                    imperfeito = sc.nextInt();
                    for (m=2;m>=2;m++){
                        perfeitos = Math.pow(2, m-1)*(Math.pow(2, m)-1);
                        //System.out.println(perfeitos);
                        if (perfeitos>=imperfeito){
                            break;
                        }
                    }
                    double imperfeitoDouble = (double) imperfeito;
                    if (perfeitos==imperfeitoDouble){
                        System.out.println(imperfeito+" é um número perfeito");
                    }
                    else{
                        System.out.println(imperfeito+" não é um número perfeito");
                    }
                    break;
                case 7:
                    System.out.printf("Insira um número inteiro positivo e veja a mágica acontecer: ");
                    int padrao = sc.nextInt();
                    
                    /* Padrão errado kkkkk

                    for(int n=1; n<=padrao; n++){
                        for(int o=1; o<=n; o++){
                            System.out.printf(n+" ");
                        }
                        System.out.println();
                    }
                    */

                    for(int n = 1; n <= padrao; n++) {
                        for(int o = 1; o <= n; o++) {      
                            System.out.printf(o + " ");    
                        }
                        System.out.println();          
                    }
                    break;

                default:
                    sc.close();
        }
    }
}