package aulas.aula05;

import java.util.Scanner;

// teste

public class exFlags {
    public static void main(String[] args) {
    
        try (Scanner sc = new Scanner(System.in)) {
            while (true) { 
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
            case '1': {
                int contador1 = 0;
                boolean resultado1 = false;
                System.out.printf("\nAvaliação de Cálculo");
                System.out.println("Quanto é 5+2*3? ");
                int resposta1 = sc.nextInt();
                System.out.println("Quanto é 4+10/2*3? ");
                int resposta2 = sc.nextInt();
                System.out.println("Suas respostas foram: "+resposta1+" e "+resposta2);
                if (resposta1 == 11 && resposta2 == 19){
                    resultado1 = true;
                    contador1 = +2;
                }
                else{
                    resultado1 = false;
                    if (resposta1 == 11 && resposta2 != 19 || resposta1 != 11 && resposta2 == 19){
                        contador1 = +1;
                    }
                }
                
                if (resultado1 == true){
                    System.out.println("Você acertou as duas questões, parabéns, você foi aprovado em Cálculo");
                }
                else{
                    System.out.println("Você não acertou as duas questões de cálculo, seus acertos foram "+contador1+", infelizmente, você NÃO foi aprovado em Cálculo");
                }
                
                int contador2 = 0;
                System.out.printf("\nAgora a avaliação de Operadores Lógicos");
                boolean logica1 = false;
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
                if (resposta3.equals("v") && resposta4.equals("f")){
                    logica1 = true;
                    contador2 = +2;
                }
                else{
                    logica1 = false;
                    if((resposta3.equals("v") && resposta4.equals("v"))||(resposta3.equals("f") && resposta4.equals("f"))){
                        contador2 = +1;
                    }
                    else{
                        
                    }
                    
                }
                
                System.out.println("Suas respostas foram: "+resposta3+" e "+resposta4);
                if (logica1 == true){
                    System.out.println("Você acertou as duas questões, parabéns, você foi aprovado em Operadores Lógicos");
                }
                else{
                    System.out.println("Você não acertou as duas questões de cálculo, seus acertos foram "+contador2+", infelizmente, você NÃO foi aprovado em Operadores Lógicos");
                }
                System.out.println("Seu resultado final foi de "+(contador1+contador2)*25+"% de acertos totais, foram "+(contador1+contador2)+"/4 acertos");
                
                }
                

                case '2' -> {
                    System.out.println("Insira um número correspondente a um mês do ano para saber a estação no hemisfério Sul (1-12): ");
                    String mes = sc.next();

                    switch (mes) {
                        case "12" -> System.out.println(mes+"º mês é Dezembro e é Verão");
                        case "1" -> System.out.println(mes+"º mês é Janeiro e é Verão");
                        case "2" -> System.out.println(mes+"º mês é Fevereiro e é Verão");
                        case "3" -> System.out.println(mes+"º mês é Março e é Outono");
                        case "4" -> System.out.println(mes+"º mês é Abril e é Outono");
                        case "5" -> System.out.println(mes+"º mês é Maio e é Outono");
                        case "6" -> System.out.println(mes+"º mês é Junho e é Inverno");
                        case "7" -> System.out.println(mes+"º mês é Julho e é Inverno");
                        case "8" -> System.out.println(mes+"º mês é Agosto e é Inverno");
                        case "9" -> System.out.println(mes+"º mês é Setembro e é Primavera");
                        case "10" -> System.out.println(mes+"º mês é Outubro e é Primavera");
                        case "11" -> System.out.println(mes+"º mês é Novembro e é Primavera");
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
                    if (vip.equals("s")){
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
                    else if (confirma || valor>200){
                        desconto = valor*0.05;
                    }
                    else{


                    }
                    System.out.println("Seu valor inicial da compra de "+valor+" teve desconto de "+(desconto/valor)*100+"% ("+desconto+") e foi para o valor final de "+Math.rint(100*(valor-desconto))/100);

                }

                
                case 'S' -> {
                    System.out.printf("\nPrograma encerrado");
                    sc.close();
                    return;
                }


                default -> {
                    System.out.println("\nOpção inválida");
                }
                
        }
        
    }
    
}
}
}