import java.util.ArrayList;
import java.util.Scanner;

public class EstruturasDeRepeticao {
    public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    
    System.out.println("Escolha a atividade:");
    System.out.println("1 - Exemplo 01 (While)");
    System.out.println("2 - Exemplo 02 (While)");
    System.out.println("3 - Exemplo 03 (While)");
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


        default:
            sc.close();
    }
    }
}