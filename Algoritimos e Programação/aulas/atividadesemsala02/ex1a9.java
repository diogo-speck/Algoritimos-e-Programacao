package aulas.atividadesemsala02;

import java.text.DecimalFormat;
import java.util.Scanner;

public class ex1a9 {
    public static void main(String[] args) {

        try (Scanner sc = new Scanner(System.in)) {
            int opcao;

            do {
                System.out.println("\n===== MENU =====");
                System.out.println("1 - Calcular média");
                System.out.println("2 - Calculadora do perímetro e a área de um círculo");
                System.out.println("3 - Número Real, parte fracionada e arredondamento");
                System.out.println("4 - Operações de um número");
                System.out.println("5 - Resolver Equação Quadrática");
                System.out.println("6 - Calcular Salário");
                System.out.println("7 - Calcular a altura de uma escada");
                System.out.println("8 - Distribuir Ração");
                System.out.println("9 - Calcular o IMC");
                System.out.println("0 - Sair");
                System.out.print("Escolha: ");

                opcao = sc.nextInt();
                sc.nextLine(); 

                if (opcao == 1) {
                    calcularMedia(sc);
                }

                if (opcao == 2) {
                    calcularCirculo(sc);
                }

                if (opcao == 3) {
                    numeroReal(sc);
                }

                if (opcao == 4) {
                    operacoes(sc);
                }

                if (opcao == 5) {
                    equacaoQuadratica(sc);
                }

                if (opcao == 6) {
                    calcularSalario(sc);
                }

                if (opcao == 7) {
                    alturaEscada(sc); // espaço para você implementar
                }

                if (opcao == 8) {
                    distribuirRacao(sc); // espaço para você implementar
                }

                if (opcao == 9) {
                    imc(sc); // espaço para você implementar
                }

            } while (opcao != 0);

            System.out.println("Programa encerrado.");
        }
    }

    // ===== OPÇÃO 1 =====
    public static void calcularMedia(Scanner sc) {

        double nota1, nota2, nota3, media;

        System.out.println("\nDigite a primeira nota: ");
        nota1 = sc.nextDouble();
        if (nota1<0){
            System.out.println("Não tem como você ter tirado uma nota negativa");
            return;
        }
        System.out.println("Digite a segunda nota: ");
        nota2 = sc.nextDouble();
        if (nota2<0){
            System.out.println("Não tem como você ter tirado uma nota negativa");
            return;
        }
        System.out.println("Digite a terceira nota: ");
        nota3 = sc.nextDouble();
        if (nota3<0){
            System.out.println("Não tem como você ter tirado uma nota negativa");
            return;
        }
        sc.nextLine();

        media = (nota1 + nota2 + nota3) / 3;

        System.out.println("Média: " + media);
    }

    // ===== OPÇÃO 2 =====
    public static void calcularCirculo(Scanner sc) {

        double raio, perimetro, area;

        System.out.println("\nDigite o raio do círculo: ");
        raio = sc.nextDouble();
        if (raio<0){
            System.out.println("Não tem como existir um raio negativo");
            return;
        }
        perimetro = 2*Math.PI*raio;

        area = Math.PI*Math.pow(raio,2);

        System.out.println("O Perímetro do seu círculo é aproximadamente: " + (String.format("%.2f", perimetro)));
        System.out.println("A Área do seu círculo é aproximadamente: " + (String.format("%.2f",area)));
        System.out.println("Por curiosidade o valor de π é aproximadamente: " + Math.PI);
    }

    // ===== OPÇÃO 3 =====
    public static void numeroReal(Scanner sc) {

        double numeroReal,fracionario; 
        int arredondamento;

        System.out.println("\nDigite um número racional de até 16 casas decimais após a vírgula para mostrar a parte inteira, fracionária e o arredondamento dele aproximadamente: ");
        numeroReal = sc.nextDouble();
        System.out.println("O seu número real é: " + numeroReal);
        arredondamento = (int)numeroReal;
        System.out.println("A parte inteira seu número é: " + arredondamento);
        fracionario = ((Math.rint(numeroReal*100)-Math.rint(arredondamento*100))/100);
        if (fracionario > 0.5){
        arredondamento = arredondamento + 1;}
        if (fracionario<-0.5){
        arredondamento = arredondamento -1;
        }
        System.out.println("O seu número fracionário é: " + (fracionario));
        System.out.println("O seu número arredondado é: " + arredondamento);
    }

    // ===== OPÇÃO 4 =====
    public static void operacoes(Scanner sc) {

        double positivo,quadrado,cubo,raiz2,raiz3;

        System.out.println("\nDigite um número racional, positivo, maior que zero e que tenha até 16 casas decimais após a vírgula: ");
        positivo = sc.nextDouble();
        if (positivo>0){
        quadrado = Math.pow(positivo,2);
        cubo = Math.pow(positivo,3);
        raiz2= Math.sqrt(positivo);
        raiz3= Math.cbrt(positivo);


        System.out.println("\nO seu número ao quadrado é aproximadamente: " + (String.format("%.2f", quadrado)));
        System.out.println("\nO seu número ao cubo é aproximadamente: " + (String.format("%.2f", cubo)));
        System.out.printf("\nA raiz quadrada de %.2f é aproximadamente: %.2f", positivo, raiz2);
        System.out.println();
        System.out.printf("\nA raiz cúbica de %.2f é aproximadamente: %.2f", positivo, raiz3);
        System.out.println();
        }
        else{
        System.out.println("\nDigite um valor positivo maior que zero");
        return;
        }
    }

    // ===== OPÇÃO 5 =====

    public static void equacaoQuadratica(Scanner sc) {
        double A, B, C, delta;

        System.out.println("\nDigite o valor de A: ");
        A = sc.nextDouble();
        System.out.println("\nDigite o valor de B: ");
        B = sc.nextDouble();
        System.out.println("\nDigite o valor de C: ");
        C = sc.nextDouble();

        // Verifica se é uma equação quadrática válida
        if (A == 0) {
            System.out.println("O valor de A não pode ser zero em uma equação quadrática.");
            return;
        }

        delta = Math.pow(B, 2) - 4 * A * C;

        if (delta > 0) {
            // Duas raízes reais distintas
            double x1 = (-B + Math.sqrt(delta)) / (2 * A);
            double x2 = (-B - Math.sqrt(delta)) / (2 * A);
            System.out.println("Duas raízes reais: x1 = " + x1 + ", x2 = " + x2);
        } else if (delta == 0) {
            // Uma raiz real dupla
            double x = -B / (2 * A);
            System.out.println("Uma raiz real dupla: x = " + x);
        } else {

            // Raízes imaginárias
            double parteReal = -B / (2 * A);
            double parteImaginaria = Math.sqrt(-delta);
            System.out.println("Raízes imaginárias:");
            if (parteImaginaria%1!=0){
            System.out.println("x1 = " + parteReal + " + (√" + delta + "i /"+(2 * A)+")");
            System.out.println("x2 = " + parteReal + " + (√" + delta + "i /"+(2 * A)+")");
            }
            else{
            System.out.println("x1 = " + parteReal + " + " + parteImaginaria/(2 * A) + "i");
            System.out.println("x2 = " + parteReal + " - " + parteImaginaria/(2 * A) + "i");
            }
        }
    }

    // ===== OPÇÃO 6 =====
    public static void calcularSalario(Scanner sc) {
        double valorbase, gratificacao, imposto, valorfinal;

        DecimalFormat df = new DecimalFormat("0.00"); // duas casas decimais

        System.out.println("Olá funcionário, por favor insira o valor base do seu salário: ");
        valorbase = sc.nextDouble();
        if (valorbase<0){
            System.out.println("Eu suponho que não tenha como ganhar um salário negativo, por favor insira seu salário positivamente (não se preocupe, não guardo informações confidenciais)");
            return;
        }
        else{
        gratificacao = valorbase * 0.05;
        imposto = valorbase * 0.07;
        valorfinal = valorbase + gratificacao - imposto;

        System.out.println("Salário base: R$ " + df.format(valorbase));
        System.out.println("Gratificação (5%): R$ " + df.format(gratificacao));
        System.out.println("Imposto (7%): R$ " + df.format(imposto));
        System.out.println("Salário final: R$ " + df.format(valorfinal));
        }
    }
    
    // ===== OPÇÃO 7 =====
    public static void alturaEscada(Scanner sc) {
        System.out.println("Olá, qual seria a altura que você desejaria subir com a escada? (em metros) ");
        double altura, degrau, quantidade;

        altura = sc.nextDouble();
        if (altura<0){
        System.out.println("Por favor insira uma altura positiva");
        return;
        }
        System.out.println("E qual seria a altura que você desejaria que cada degrau tivesse? (ex: 0.1 para 0,1 metros) ");
        degrau = sc.nextDouble();
        if (degrau<0){
        System.out.println("Por favor insira uma altura positiva");
        return;
        }
        quantidade = altura/degrau;
        System.out.println("\nSua escada terá "+quantidade+" degraus com "+degrau+" metros de espelho, totalizando "+altura+" metros de altura");

    }

    // ===== OPÇÃO 8 =====
    public static void distribuirRacao(Scanner sc) {
        System.out.println("Olá Pedro, por favor insira a quantidade de ração no seu saco (em KG): ");
        double racaoKG, racaoG, umGato, umDia,dias;
        
        racaoKG = sc.nextDouble();
        racaoG = racaoKG * 1000;

        System.out.println("A quantidade total de ração no seu saco é "+(String.format("%.0f",racaoKG)+ "KG ou "+(String.format("%.0f", racaoG)+ " gramas")));
        System.out.println("Quantas gramas cada gato seu come por dia? (Cada gato come em média 50 gramas por dia) ");
        
        umGato = sc.nextDouble();
        umDia = umGato *2;

        System.out.println("Por quantos dias deseja alimentar seus 2 gatos? ");
        
        dias = sc.nextDouble();

        System.out.println("Após 1 dia seus 2 gatos terão comido em média "+umDia+ " gramas");
        if (racaoG-umDia<0){
            System.out.println("Infelizmente você terá que comprar mais ração");
        }
        else{
        System.out.println("Após 1 dia sobrará em média "+(racaoG-umDia)+ " gramas no saco de ração");
        System.out.println("Após 5 dias seus 2 gatos terão comido em média "+umDia*5+ " gramas");
        if (racaoG-umDia*5<0){
            System.out.println("Infelizmente você terá que comprar mais ração");
        }
        else{
        System.out.println("Após 5 dias sobrará em média "+(racaoG-umDia*5)+ " gramas no saco de ração");
        System.out.println("Após "+dias+ " dia(s) seus 2 gatos terão comido em média "+ umDia*dias+ " gramas");
        if (racaoG-umDia*dias<0){
            System.out.println("Infelizmente você terá que comprar mais ração");
        }
        else{
        System.out.println("Após "+dias+ " dia(s) sobrará em média "+(racaoG-umDia*dias)+ " gramas no saco de ração");
            }
        }    
        }
    }

    // ===== OPÇÃO 9 =====
    public static void imc(Scanner sc) {
        System.out.println("Olá indivíduo, nessa etapa iremos calcular seu índice de massa corporal, por favor insira seu peso (em KG): ");
        double pesoKG = sc.nextDouble();
        System.out.println("Agora insira sua altura (em metros): ");
        double alturaM = sc.nextDouble();
        double imc = pesoKG/Math.pow(alturaM,2);

        System.out.printf("Seu IMC é aproximadamente %.2f kg/m²",(imc));
        if (imc<16){
            System.out.println("\nVocê está classificado com magreza grave");
        }
        if (imc>=16 & imc<17){
            System.out.println("\nVocê está classificado com magreza moderada");
        }
        if (imc>=17 & imc<18.5){
            System.out.println("\nVocê está classificado com magreza leve");
        }
        if (imc>=18.5 & imc<25){
            System.out.println("\nVocê está saudável");
        }
        if (imc>=25 & imc<30){
            System.out.println("\nVocê está classificado com sobrepeso");
        }
        if (imc>=30 & imc<35){
            System.out.println("\nVocê está classificado com obesidade grau 1");
        }
        if (imc>=35 & imc<40){
            System.out.println("\nVocê está classificado com obesidade grau 2");
        }
        if (imc>=40){
            System.out.println("\nVocê está classificado com obesidade grau 3");
        }

    }
}