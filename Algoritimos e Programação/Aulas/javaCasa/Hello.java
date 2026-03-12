package Aulas.javaCasa;

import java.util.Scanner;

public class Hello {

    public static void main(String[] args) {

        Scanner entrada = new Scanner(System.in);
        int opcao;

        do {

            System.out.println("\n===== MENU =====");
            System.out.println("1 - Calcular média");
            System.out.println("2 - Calculadora lógica");
            System.out.println("3 - Respostas da Atividade (32 a 34)");
            System.out.println("4 - Sair");
            System.out.print("Escolha: ");

            opcao = entrada.nextInt();
            entrada.nextLine();

            if (opcao == 1) {
                calcularMedia(entrada);
            }

            if (opcao == 2) {
                calcularLogica(entrada);
            }

            if (opcao == 3) {
                respostasatividade(entrada);
            }

        } while (opcao != 4);

        System.out.println("Programa encerrado.");
        entrada.close();
    }

    public static void calcularMedia(Scanner entrada) {

        double nota1, nota2, nota3, media;

        System.out.println("\nDigite a primeira nota:");
        nota1 = entrada.nextDouble();

        System.out.println("Digite a segunda nota:");
        nota2 = entrada.nextDouble();

        System.out.println("Digite a terceira nota:");
        nota3 = entrada.nextDouble();

        entrada.nextLine();

        media = (nota1 + nota2 + nota3) / 3;

        System.out.println("Média: " + media);
    }

    public static void calcularLogica(Scanner entrada) {

        System.out.println("\nDigite a expressao lógica.");
        System.out.println("Use: verdadeiro, falso, e, ou, nao");

        String expressao = entrada.nextLine().toLowerCase();

        String[] partes = expressao.split(" ");

        boolean resultado = false;

        if (partes.length == 2) {

            boolean valor = converter(partes[1]);

            if (partes[0].equals("nao")) {
                resultado = !valor;
            }

        } else if (partes.length == 3) {

            boolean a = converter(partes[0]);
            boolean b = converter(partes[2]);

            if (partes[1].equals("e")) {
                resultado = a && b;
            }

            if (partes[1].equals("ou")) {
                resultado = a || b;
            }
        }

        System.out.println("Resultado: " + resultado);
    }

    public static void respostasatividade(Scanner scanner) {

        boolean[] respostasCorretas = {false, false, true};

        String[] perguntas = {
                "32) falso ou verdadeiro e nao verdadeiro",
                "33) falso e verdadeiro ou falso",
                "34) falso e verdadeiro ou verdadeiro"
        };

        int acertos = 0;

        for (int i = 0; i < perguntas.length; i++) {

            System.out.println(perguntas[i]);
            System.out.print("Digite V para Verdadeiro ou F para Falso: ");

            String resposta = scanner.nextLine().toUpperCase();

            boolean respostaUsuario = resposta.equals("V");

            if (respostaUsuario == respostasCorretas[i]) {
                System.out.println("Correto!\n");
                acertos++;
            } else {
                System.out.println("Errado!\n");
            }
        }

        System.out.println("Você acertou " + acertos + " de 3 questões.");
    }

    public static boolean converter(String palavra) {

        if (palavra.equals("verdadeiro")) {
            return true;
        }

        return false;
    }
}