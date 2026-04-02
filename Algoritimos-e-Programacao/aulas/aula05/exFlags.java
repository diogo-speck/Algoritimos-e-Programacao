package aulas.aula05;

import java.util.Scanner;

public class exFlags {
    public static void main(String[] args) {

        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("\n===== MENU =====");
            System.out.println("1 - Avaliação de Cálculo e Operadores Lógicos");
            System.out.println("2 - Mês do Ano e sua estação correspondente");
            System.out.println("3 - Dia da semana");
            System.out.println("4 - Verificação de Triângulo");
            System.out.println("5 - Verificação de Entrada a um brinquedo");
            System.out.println("6 - Compra e promoção");
            System.out.println("S - Sair");
            System.out.println("Escolha uma opção: ");
            String opcao = sc.next();

            char d = Character.toUpperCase(opcao.charAt(0));

        switch(d){
            case '1' -> {
                boolean resultado1 = false;
                boolean resultado2 = false;
                System.out.printf("\nAvaliação de Cálculo");
                System.out.println("Quanto é 5+2*3? ");
                int resposta1 = sc.nextInt();
                System.out.println("Quanto é 4+10/2*3? ");
                int resposta2 = sc.nextInt();
                System.out.println("Suas respostas foram: "+resposta1+" e "+resposta2);
                if (resposta1 == 11){
                    resultado1 = true;
                    
                }
                if (resposta2 == 19){
                    resultado2 = true;
                }
                
                if (resultado1 == true && resultado2 == true){
                    System.out.printf("\nVocê acertou as duas questões, parabéns, você foi aprovado em Cálculo");
                }
                else{
                    System.out.printf("\nVocê não acertou as duas questões de cálculo, infelizmente, você NÃO foi aprovado em Cálculo");
                }
                
                System.out.printf("\nAgora a avaliação de Operadores Lógicos");
                boolean logica1 = true;
                boolean logica2 = true;
                System.out.println("(10 > 5) && (3 < 1 || 8 > 2) é verdadeiro ou falso? (v/f)");
                String resposta3 = sc.next();
                System.out.println("true || false && !(true) é verdadeiro ou falso? (v/f)");
                String resposta4 = sc.next();
                
                resposta3 = resposta3.toLowerCase();
                resposta4 = resposta4.toLowerCase();
                
                /*
                switch(resposta3){
                case "v":
                logica1 = true;
                
                case "f":
                logica1 = false;
                
                default:
                }
                
                switch(resposta4){
                case "v":
                logica2 = false;
                
                case "f":
                logica2 = true;
                
                default:
                }
                */
                if (resposta4 == "v"){
                    logica2 = true;
                }
                else{
                    logica2 = false;
                }
                
                if (resposta4 == "v"){
                    logica2 = true;
                }
                else{
                    logica2 = false;
                }
                
                System.out.println("Suas respostas foram: "+resposta3+" e "+resposta4);
                if (logica1 == true && logica2 == true){
                    System.out.println("Você acertou as duas questões, parabéns, você foi aprovado em Operadores Lógicos");
                }
                else{
                    System.out.println("Você não acertou as duas questões de cálculo, infelizmente, você NÃO foi aprovado em Operadores Lógicos");
                }

                }


                case '2' -> {
                    System.out.println("Insira um número correspondente a um mês do ano para saber a estação no hemisfério Sul (1-12): ");
                    String mes = sc.next();

                    switch (mes) {
                        case "12", "1", "2" -> System.out.println(mes+"º mês é Verão");
                        case "3","4","5" -> System.out.println(mes+"º mês é Outono");
                        case "6","7","8" -> System.out.println(mes+"º mês é Inverno");
                        case "9","10","11" -> System.out.println(mes+"º mês é Primavera");
                        default -> System.out.println("Mês inválido");
                    }
                    
                }


                case '3' -> {
                    System.out.println("Insira um número correspondente a um dia da semana para saber o dia correspondente (1(Dom)-7(Sáb)): ");
                    String dia = sc.next();

                    switch (dia) {
                        case "1"-> System.out.println(dia+"º dia é Domingo");
                        case "2"-> System.out.println(dia+"º dia é Segunda-Feira");
                        case "3"-> System.out.println(dia+"º dia é Terça-Feira");
                        case "4"-> System.out.println(dia+"º dia é Quarta-Feira");
                        case "5"-> System.out.println(dia+"º dia é Quinta-Feira");
                        case "6"-> System.out.println(dia+"º dia é Sexta-Feira");
                        case "7"-> System.out.println(dia+"º dia é Sábado");
                        default -> System.out.println("Dia da semana inválido!");
                    }
                    
                }


                case '4' -> {
                    boolean formaTriangulo = false;
                    System.out.println("Insira o valor do 1º lado do triângulo hipotético: ");
                    double lado1 = sc.nextDouble();
                    System.out.println("Insira o valor do 2º lado do triângulo hipotético: ");
                    double lado2 = sc.nextDouble();
                    System.out.println("Insira o valor do 3º lado do triângulo hipotético: ");
                    double lado3 = sc.nextDouble();

                    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1){
                        formaTriangulo = true;
                    }
                    else{
                        formaTriangulo = false;
                    }

                    if (formaTriangulo){
                        System.out.println(lado1+", "+lado2+", "+lado3+", forma triângulo");
                    }
                    else{
                        System.out.println(lado1+", "+lado2+", "+lado3+", não forma triângulo");
                    }
                    
                }


                case '5' -> {
                    System.out.println("Insira a sua altura em metros: ");
                    double altura = sc.nextDouble();
                    boolean liberado = false;
                    System.out.println("Insira a sua idade em anos: ");
                    double idade = sc.nextDouble();

                    if(altura>=1.4 && idade>=10){
                        liberado = true;
                    }
                    else{
                        liberado = false;
                    }

                    if(liberado){
                        System.out.println("Entrada permitida!");
                    }
                    else{
                        System.out.println("Entrada não permitida!");
                    }
                    
                }case '6' -> {
                    System.out.println("Insira o valor da sua compra: ");
                    double valor = sc.nextDouble();
                    System.out.println("Você é cliente VIP? (s/n) ");
                    String vip = sc.next();
                    vip = vip.toLowerCase();
                    boolean confirma = false;
                    double desconto = 0;
                    if (vip == "v"){
                        confirma = true;
                    }
                    else{
                        confirma = false;
                    }

                    /*
                    O sistema de desconto funciona da seguinte forma:
                        Cliente VIP E compra maior que 200 - 10% de desconto
                        Cliente VIP OU compra maior que 200 - 5% de desconto
                        Nenhuma das condições 
                    */
                    if (confirma && valor>200){
                        desconto = valor*0.1;
                    }
                    if (confirma || valor>200){
                        desconto = valor*0.05;
                    }
                    else{

                    }
                    System.out.println("Seu valor inicial da compra de "+valor+" teve desconto de "+(desconto/valor)*100+"% e foi para o valor final de "+(valor-desconto));

                }

                
                case 'S' -> {
                    System.out.printf("\nPrograma encerrado");
                    sc.close();
                }


                default -> {
                    System.out.println("\nOpção inválida");
                }
        }
    }
}
}