import java.util.Scanner;
import java.util.ArrayList;
import java.util.Random;

public class EstruturasDeRepeticao {
    public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    
    System.out.println("Escolha a atividade:");
    System.out.println("1 - Exemplo 01 (Validação de nota)");
    System.out.println("2 - Exemplo 02 (Soma até condição de parada)");
    System.out.println("3 - Exemplo 03 (Sistema de login)");
    System.out.println("4 - Exemplo 04 (Média de valores até condição)");
    System.out.println("5 - Exemplo 05 (Adivinhação de número)");
    System.out.printf("Escolha: ");
    int escolha = sc.nextInt();
    
    switch (escolha) {
        case 1:
            int valor;
            do { 
                System.out.println("Insira um valor entre 0 e 10: ");
                valor = sc.nextInt();
            } while (valor <= 0 || valor >= 10);
            System.out.println("O valor "+valor+" foi aprovado");
            break;
        case 2:
            int a = 0;
            int soma = 0;
            //int[] lista = {};
            ArrayList<Integer> lista = new ArrayList<>();
            String numeros = " ";
            do { 
                System.out.println("Insira um valor inteiro para a soma (se quiser parar a soma digite 0)");
                a = sc.nextInt();
                soma = soma+a;
                if (a == 0){
                    break;
                }
                else{
                numeros = numeros+" "+a+" ";
                lista.add(a);
                }
            } while (a != 0);
            //System.out.println(lista);
            if (soma == 0){
                System.out.println("Sua soma final foi "+soma);
            }
            else{
                System.out.println("Os valores inseridos foram "+numeros);
                System.out.println("Sua soma final foi "+soma);
            }
            break;
        case 3:
            String user = "admin";
            String usert;
            String senha = "123";
            String senhat;
            int tentativas = 0;
            do { 
                System.out.println("Insira o seu usuário: ");
                usert = sc.next();
                System.out.println("Insira a sua senha: ");
                senhat = sc.next();
                tentativas +=1;
                if (usert.equals(user) && senhat.equals(senha)){
                    System.out.println("Logado");
                    break;
                }
                if(tentativas == 2){
                    System.out.println("Esqueceu a senha?");
                    usert = sc.next();
                    System.out.println("Seu usuário é "+user);
                    System.out.println("Sua senha é "+senha);
                }
                else{
                    System.out.println("Usuário ou senha incorretos, tente novamente");
                }

            } while (tentativas<3);
            if (tentativas==3){
            System.out.println("Você atingiu o limite de 3 tentativas, tente amanhã");
            }
            break;
        case 4:
            double v1;
            double media = 0;
            int contador = 0;
            do { 
                System.out.println("Digite um número para adcionar a conta da média (para sair digite um número negativo): ");
                v1 = sc.nextDouble();
                contador = contador+1;
                if (v1>=0){
                media = media+v1;
                }
            } while (v1>=0);
                if(contador == 1){
                    System.out.println("Sua média foi 0, pois você não colocou nenhum valor positivo");
                }
                else{
                contador = contador-1;
                media = media/contador;
                System.out.println("Sua média foi "+media+" e a quantidade de valores foi "+contador);
                }    
                break;
        case 5:
            Random random = new Random();
            int aleatorio = random.nextInt(100)+1;
            int picka = 0;
            int pickb;
            int vezes = 0;
            int min = 1;
            int max = 100;
            do {
                if (vezes>0){
                    System.out.printf(", você errou");
                }
                pickb=picka;
                if (vezes == 0){
                    min = 1;
                    max = 100;
                }
                else{
                    if(picka < aleatorio){
                        min = pickb + 1;
                    }
                    else if(picka > aleatorio){
                        max = pickb - 1;
                    }
                }
                System.out.printf("\nEscolha um número entre %d e %d: ", min, max);
                picka = sc.nextInt();

                if (picka<aleatorio){
                    System.out.printf("O número aleatório é MAIOR");
                }
                if (picka>aleatorio){
                    System.out.printf("O número aleatório é MENOR");
                }
                vezes++;
            } while (aleatorio!=picka);
                System.out.println("Parabéns, você acertou em "+vezes+" tentativa(s), o número era "+aleatorio);
                break;

            
        default:
            sc.close();
    }
    }
}