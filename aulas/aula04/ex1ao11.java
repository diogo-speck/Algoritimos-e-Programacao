package aulas.aula04;

import java.util.Scanner;

public class ex1ao11 {
    public static void main(String[] args) {

        try (Scanner sc = new Scanner(System.in)) {
            int opcao;

            do {
                System.out.println("\n===== MENU =====");
                System.out.println("1 - Perfil +18");
                System.out.println("2 - Calcular média");
                System.out.println("3 - Nome, Média e Frequência");
                System.out.println("4 - Ano bissexto ou não");
                System.out.println("5 - Positivo, negativo ou zero");
                System.out.println("6 - Vogal ou consoante");
                System.out.println("7 - Calcular IMC");
                System.out.println("8 - Mês do Ano");
                System.out.println("9 - Calculadora");
                System.out.println("0 - Sair");
                System.out.print("Escolha: ");

                opcao = sc.nextInt();
                sc.nextLine(); 

                if (opcao == 1) {
                    perfilAdulto(sc);
                }
                if (opcao == 2) {
                    calcularMedia(sc);
                }
                if (opcao == 3) {
                    nomeMediaFreq(sc);
                }
                if (opcao == 4) {
                    anoBi(sc);
                }
                if (opcao == 5) {
                    posNegZero(sc);
                }
                if (opcao == 6) {
                    vogalConsoante(sc);
                }
                if (opcao == 7) {
                    imc(sc);
                }
                if (opcao == 8) {
                    mesAno(sc);
                }
                if (opcao == 9) {
                    calculadora(sc);
                }


            } while (opcao != 0);

            System.out.println("Programa encerrado.");
        }
    }
        // ===== OPÇÃO 1 =====
        public static void perfilAdulto(Scanner sc) {

        System.out.println("Agora vou montar um perfil no Tinder para você então, para começar você precisa ter pelo menos 18 anos, para facilitar qual a sua idade? ");

        System.out.println("Confirma sua idade: ");
        int idade1 = sc.nextInt();

        System.out.println("Agora vou precisar que você informe seu estado civil (solteiro, casado, separado, divorciado, viúvo): ");
        String estadoCivil = sc.next();

        if (idade1>=18 && estadoCivil.equalsIgnoreCase("solteiro")){
            System.out.println("Tá liberado a sapecagem!");
        }
        else{
            System.out.println("Infelizmente você não cumpriu os pré-requisitos (mas isso não impede você de mentir)");
            System.exit(0);
        }
        }

    // ===== OPÇÃO 2 =====
    public static void calcularMedia(Scanner sc) {

        double nota1, nota2, nota3, nota4, media;

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
        System.out.println("Digite a quarta nota: ");
        nota4 = sc.nextDouble();
        if (nota4<0){
            System.out.println("Não tem como você ter tirado uma nota negativa");
            return;
        }
        sc.nextLine();

        media = (nota1 + nota2 + nota3 +nota4) / 4;

        System.out.println("Média: " + media);
        if (media>=10){
            System.out.println("Aprovado com LOUVOR");
        }
        if (media>=8){
            System.out.println("Aprovado com MÉRITO");
        }
        if (media>=6){
            System.out.println("Aprovado com DESTAQUE");
        }
        else{
            System.out.println("Reprovado, média menor que 6");
        }
    }

    // ===== OPÇÃO 3 =====
    public static void nomeMediaFreq(Scanner sc) {
        System.out.println("Qual seu nome? ");
        String nome = sc.next();
        System.out.println("Qual sua média? ");
        float mediaa = sc.nextFloat();
        System.out.println("Qual sua frquência (em %)? ");
        float freq = sc.nextFloat();
        if (mediaa>=6 && freq>75){
            System.out.println(nome+" Aprovado");
        }
        else if (mediaa<6 && freq>75){
            System.out.println(nome+" Reprovado por média");
        }
        else if (mediaa>=6 && freq<75){
            System.out.println(nome+" Reprovado por frequência");
        }
        else {
            System.out.println(nome+" Reprovado por ambos");
        }
    }

    // ===== OPÇÃO 4 =====
    public static void anoBi(Scanner sc) {
        System.out.println("Informe um ano qualquer: ");
        int ano = sc.nextInt();
        if (ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0){
            System.out.println("O ano "+ano+" é bissexto");            
        }
        else{
            System.out.println("O ano "+ano+" não é bissexto");
        }
    }

    // ===== OPÇÃO 5 =====
    public static void posNegZero(Scanner sc) {
        System.out.println("Digite um valor inteiro: ");
        int valor = sc.nextInt();
        if (valor>0){
            System.out.println(valor+" é positivo");
        }
        else if (valor<0){
            System.out.println(valor+" é negativo");
        }
        else{
            System.out.println(valor+" é zero");
        }

    }

    // ===== OPÇÃO 6 =====
    public static void vogalConsoante(Scanner sc) {

    }
    // ===== OPÇÃO 7 =====
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

    // ===== OPÇÃO 8 =====
    public static void mesAno(Scanner sc) {

    }

    // ===== OPÇÃO 9 =====
    public static void calculadora(Scanner sc) {

    }

}