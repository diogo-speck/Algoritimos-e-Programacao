import java.util.Random;
import java.util.Scanner;

public class alternativa01Prova{

    public static void main(String[]args){

    Scanner sc = new Scanner(System.in);{

    System.out.println("Candidato 1");
    System.out.println("Candidato 2");
    System.out.println("Quantos eleitores vão votar? ");
    int eleitores = sc.nextInt();
    int candidato1 = 0;
    int candidato2 = 0;
        
    for (int i = 1; i < eleitores+1; i++) {
        System.out.println("Eleitor "+i+", qual seu voto? (1 ou 2)");
        int voto = sc.nextInt();
        if (voto == 1){
            candidato1 = candidato1+1;
        }
        if (voto == 2){
            candidato2 = candidato2+1;
        }
        else{
            System.out.println("Seu voto não foi em nenhum dos candidatos, logo foi em branco e assumimos que você concorda com o resultado final independentemente");
        }
    }

    System.out.println("Resultado Final:");
    System.out.println("Candidato 1: "+candidato1+" voto(s)");
    System.out.println("Candidato 2: "+candidato2+" voto(s)");
    if (candidato1>candidato2){
        System.out.println("Candidato 1 venceu");
    }
    if (candidato2>candidato1){
        System.out.println("Candidato 2 venceu");
    }
    if (candidato2==candidato1){

        System.out.println("Houve um empate, o conselho decidirá quem ganhou");
        Random random = new Random();
        int escolha = random.nextInt(2)+1;
        if (escolha == 1){
            System.out.println("Candidato 1 venceu");
        }
        else{
            System.out.println("Candidato 2 venceu");
        }
    }

    }
    sc.close();
    }

}