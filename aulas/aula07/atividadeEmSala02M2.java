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

                    break;
                case 5:

                    break;
                case 6:

                    break;
                case 7:

                    break;

                default:
                    sc.close();
        }
    }
}