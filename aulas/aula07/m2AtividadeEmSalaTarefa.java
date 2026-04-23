import java.util.ArrayList;
import java.util.Scanner;

public class m2AtividadeEmSalaTarefa {
    public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    
    System.out.println("Escolha a atividade:");
    System.out.println("1 - Leitura de números inteiros com múltiplas condições de paradas");
    System.out.println("2 - Pesquisa de satisfação");
    System.out.println("3 - Menu de Cadastro");
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
            System.out.println("A soma final foi "+soma+" e a quantidade de elementos válidos informados foi "+lista.size()+". Logo a média desses valores foi aproximadamente "+(String.format("%.2f",media)));
            System.out.println("Os elementos, em ordem, foram: "+lista);
            break;            
            
            case 2:
                String avaliar;
                int clientes, contador=0, nota, notas=0;
                double mediaa;
                ArrayList<Integer> vezes = new ArrayList<>();
                System.out.println("Deseja nos avaliar? (s/n) ");
                avaliar = sc.next().toLowerCase();
                if (avaliar.equals("s")){
                    System.out.printf("Quantos clientes vão nos avaliar? ");
                    clientes = sc.nextInt();
                    if (clientes > 0){

                        /*
                        int[] numeros = [];
                        clientes = numeros.length;
                        */
                        
                        for (int i = 1; i < clientes+1; i++) {
                            System.out.println("Escolha uma nota entre 1 e 5 cliente "+i);
                            nota = sc.nextInt();
                            if (nota>=1 && nota<=5){
                                contador+=1;
                                vezes.add(nota);
                                notas = notas+nota;
                            }
                            else{
                                while (!(nota>=1 && nota<=5)) { 
                                    System.out.println("Por favor, coloque a nota dentro do intervalo de 1 e 5 cliente "+i);
                                    nota = sc.nextInt();
                                }
                            }
                        }
                        mediaa = Math.round((double) notas / contador);
                        System.out.println("Foram registradas "+vezes.size()+" respostas válidas");
                        System.out.println("A média da nossa avaliação foi de aproximadamente "+mediaa);
                        
                        for (int j=1; j<=5;j++){
                            int conferir=0;
                            for (int n : vezes){
                                if (n==j){
                                    conferir++;
                                }
                            }
                            System.out.println("A nota "+j+" foi colocada "+conferir+"x vez(es)");
                        }
                        
                        /*
                        System.out.println(vezes.contains(1));
                        vezes.forEach( (n) -> { System.out.println(n); } );
                        */
                    }
                    else{
                    System.out.println("Ok, perguntamos outra hora então.");
                    }

                }
                else{
                    System.out.println("Ok, perguntamos outra hora então.");
                }
            break;            
            
            case 3:
                int opcao;
                String cadastro, consulta;
                ArrayList<String> coisas = new ArrayList<>();
                do { 
                    System.out.println("--------Menu--------");
                    System.out.println("1 - CADASTRAR");
                    System.out.println("2 - CONSULTAR");
                    System.out.println("3 - ATUALIZAR/LIMPAR");
                    System.out.println("4 - EXCLUIR/DELETAR");
                    System.out.println("5 - SAIR");
                    System.out.printf("Escolha: ");
                    opcao = sc.nextInt();
                    
                    switch (opcao) {
                        case 1:
                            System.out.println("Você tem "+coisas.size()+" coisa(s) cadastradas, sendo ela(s):");
                            System.out.println(coisas);
                            System.out.println("Digite algo para cadastrar");
                            cadastro = sc.next();
                            if (coisas.contains(cadastro)){
                                System.out.println("'"+cadastro+"' já está cadastrado");
                            }
                            else{
                            coisas.add(cadastro);
                            System.out.println("Cadastro '"+cadastro+"' efetuado com sucesso");
                            System.out.println(coisas);
                            }
                            break;
                        case 2:
                            System.out.println("Você tem "+coisas.size()+" coisa(s) cadastradas, sendo ela(s):");
                            System.out.println(coisas);
                            System.out.println("Digite o que deseja consultar: ");
                            consulta = sc.next();
                            if (coisas.contains(consulta)){
                                System.out.println("'"+consulta+"' está cadastrado");
                            }
                            else{
                                System.out.println("'"+consulta+"' não está cadastrado");
                            }
                            System.out.println("Consulta realizada");
                            break;
                        case 3:
                            System.out.println("Você tem "+coisas.size()+" coisa(s) cadastradas, sendo ela(s):");
                            System.out.println(coisas);
                            System.out.println("Deseja atualizar/limpar seu cadastro? (s/n): ");
                            consulta = sc.next().toLowerCase();
                            if (consulta.equals("s")){
                                coisas.clear();
                                System.out.println("Ok, cadastro atualizado/limpo");
                                System.out.println(coisas);
                            }
                            break;
                        case 4:
                            System.out.println("Você tem "+coisas.size()+" coisa(s) cadastradas, sendo ela(s):");
                            System.out.println(coisas);
                            System.out.println("Digite o que deseja excluir/deletar: ");
                            consulta = sc.next();
                            if (coisas.contains(consulta)){
                                coisas.remove(consulta);
                                System.out.println("Exclusão realizada");
                                System.out.println("'"+consulta+"' foi removido");
                            }
                            else{
                                System.out.println("'"+consulta+"' não está cadastrado");
                            }
                            System.out.println("Seu cadastro agora está assim:");
                            System.out.println(coisas);

                            break;
                        default:
                            if (opcao!=5){
                            System.out.println("Opção inválida! Tente novamente");
                            }
                            break;
                    }


                } while (opcao!=5);
                System.out.println("Finalizando o programa...");
            default: 
                sc.close();
        }
    }
}