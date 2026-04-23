import java.util.ArrayList;
import java.util.Scanner;

public class m2AtividadeEmSalaTarefa {
    public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    
    System.out.println("Escolha a atividade:");
    System.out.println("1 - Leitura de números inteiros com múltiplas condições de paradas");
    System.out.println("2 - Pesquisa de satisfação");
    System.out.println("3 - ");
    System.out.printf("Escolha: ");
    int escolha = sc.nextInt();
        switch (escolha) {
            case 1:
                int inteiro;
                double media, soma=0, contagem=0;
                ArrayList<Integer> lista = new ArrayList<>();
            do { 
                try {
                    System.out.println("Digite um número inteiro: ");
                    inteiro = sc.nextInt(); 
                    lista.add(inteiro);
                    contagem+=1;
                    soma = soma+inteiro;
                } catch (Exception e) {
                    System.out.println("Entrada inválida");
                    sc.nextLine();
                }
                
            } while (!(contagem>=10 && soma>100));
            media = soma/contagem;
            System.out.println("A soma final foi "+soma+" e a quantidade de elementos válidos informados foi "+lista.size()+". Logo a média desses valores foi "+media);
            System.out.println("Os elementos, em ordem, foram: "+lista);
            break;            
            
            case 2:
                String avaliar;
                int clientes, contador=0, nota, notas=0;
                int conferir = 0;
                ArrayList<Integer> vezes = new ArrayList<>();
                System.out.println("Deseja nos avaliar? (s/n) ");
                avaliar = sc.next();
                if (avaliar.equals("s")){
                    System.out.printf("Quantos clientes vão nos avaliar? ");
                    clientes = sc.nextInt();
                    /*
                    int[] numeros = [];
                    clientes = numeros.length;
                     */
                    for (int i = 1; i < clientes+1; i++) {
                        System.out.println("Escolha uma nota entre 1 e 5 cliente "+i);
                        nota = sc.nextInt();
                        if (nota>=1 || nota<=5){
                            notas = notas+nota;
                            contador+=1;
                            vezes.add(nota);
                        }
                        else{
                            while (nota>=1 || nota<=5) { 
                                System.out.println("Por favor, coloque a nota dentro do intervalo de 1 e 5 cliente "+i);
                                nota = sc.nextInt();
                            }
                            notas = notas+nota;
                            contador+=1;
                            vezes.add(nota);
                        }
                    
                    }
                    System.out.println("A quantidade de respostas registradas foram "+contador);
                    System.out.println("A média da nossa avaliação foi "+notas/contador);
                    
                    System.out.println(vezes.contains(1));
                    vezes.forEach( (n) -> { System.out.println(n); } );

                    

                }
                else{
                    System.out.println("Ok, perguntamos outra hora então.");
                }

            default: 
                sc.close();
        }
    }
}