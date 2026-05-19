import java.util.Random;
import java.util.Scanner;

public class jogoDaMemoria {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    
        Random aleatorio = new Random();
        
        /*
        Lista de coisas que tem que arrumar:
        - Selecionando a mesma posição em seguida conta como ponto
        - Mostrar um placar quando 1 jogador fazer ponto
        */
        
        char confere='a';
        char confere2='a';
        boolean acertou = false;
        int linha, coluna, escolha, linha2=0, coluna2=0;
        int contador = 0, pontos1=0, pontos2=0;
        char adivinhado[][] = new char [7][7];
        char adivinhar[][] = new char [7][7];
        for (int i=0;i<7;i++){
            System.out.println();
            for (int j=0;j<7;j++){
                adivinhar[i][j]= '#';
                adivinhado[i][j]= '#';
            }
        }
        char[][] tabuleiro = {
            {'A','B','C','D','E','F','G'},
            {'H','I','J','K','L','M','N'},
            {'O','P','Q','R','S','T','U'},
            {'V','W','X','A','B','C','D'},
            {'E','F','G','H','I','J','K'},
            {'L','M','N','O','P','Q','R'},
            {'S','T','U','V','W','X','*'}
        };        
        char save;
        for (int z=0;z<25;z++){
            int trocai = aleatorio.nextInt(6);
            int trocaj = aleatorio.nextInt(6);
            for (int i=0;i<7;i++){
                for (int j=0;j<7;j++){
                    save = tabuleiro[i][j];
                    tabuleiro[i][j] = tabuleiro [trocai][trocaj];
                    tabuleiro [trocai][trocaj] = save;
                }
            }
        }
        // só pra saber o gabarito
        for (int i=0;i<7;i++){
            System.out.println();
            for (int j=0;j<7;j++){
            System.out.print(tabuleiro[i][j]+" ");
            }
        }
        
        System.out.println("\nBem-vindo ao jogo da memória");
        do {
            System.out.println("Seu tabuleiro: ");
            for (int i=0;i<7;i++){
                System.out.println();
                for (int j=0;j<7;j++){
                    System.out.print(adivinhar[i][j]+" "); 
                }
            }

            for (int turno=0;turno<2;turno++){
                System.out.println("\nDigite as coordenadas da linha do tabuleiro (a partir de 1 até 7 ex. 1 para linha 1): ");
                linha = sc.nextInt();
                System.out.println("Digite as coordenadas da coluna do tabuleiro (a partir de 1 até 7 ex. 1 para coluna 1): ");
                coluna = sc.nextInt();
                System.out.println("Você escolheu a coordenada "+linha+"x"+coluna);
                linha -=1;
                coluna -=1;

                for(int i=0;i<7;i++){
                    System.out.println();
                    for(int j=0;j<7;j++){
                        if (i==linha&&j==coluna){
                            System.out.print(tabuleiro [i][j]+" ");
                            if (turno==0){
                                confere =tabuleiro [i][j];
                                linha2 = linha;
                                coluna2 = coluna;
                                adivinhar [i][j] = tabuleiro [i][j];
                            }
                            if (turno==1&&(adivinhar [i][j]!=tabuleiro [i][j])){
                                confere2 =tabuleiro [i][j];
                                adivinhar [i][j] = tabuleiro [i][j];
                            }
                        }
                        else{
                            System.out.print(adivinhar [i][j]+" ");
                        }
                       
                    }
                }
                if (confere == confere2 && (linha != linha2 || coluna != coluna2)){
                    adivinhar[linha][coluna] = tabuleiro[linha][coluna];
                    adivinhado[linha][coluna] = adivinhar[linha][coluna] ;
                    adivinhar[linha2][coluna2] = tabuleiro[linha2][coluna2];
                    adivinhado[linha2][coluna2] = adivinhar[linha2][coluna2] ;
                    acertou = true;
                }
                else{
                    adivinhar[linha][coluna] = adivinhado[linha][coluna];
                    acertou = false;
                }
            
            }

            if (acertou){
                System.out.println("\nQual jogador fez ponto, o jogador 1 ou o jogador 2 (1/2): ");
                escolha = sc.nextInt();
                if (escolha==1){
                    pontos1+=1;
                }
                else{
                    pontos2+=1;
                }
                System.out.println("\nJogue novamente");
                contador +=1;
            }
            else{
                System.out.println("\nTurno do próximo jogador");
            }
        
            
        } while (contador<12);
        if (pontos1>pontos2){
            System.out.println("Jogador 1 ganhou com "+pontos1+" pontos");
        }
        if (pontos1<pontos2){
            System.out.println("Jogador 2 ganhou com "+pontos2+" pontos");
        }
        else{
            System.out.println("Empate");
        }




        // System.out.println(gerador.nextInt());
        // intervalo letras maiúsculas ASCII @100 - 130X

        /* Aqui gera aleatório mais do que 2 vezes
        for(int i=0;i<tabuleiro.length;i++){
            System.out.println();
            for(int j=0;j<tabuleiro.length;j++){
                int intervalo = aleatorio.nextInt(25);
                intervalo +=64; // ver depois
                char z = (char)intervalo;                    
                tabuleiro[i][j] = z;
                System.out.print(tabuleiro[i][j]);
            }
        }
        */        
        

        /* Intervalo de @ até X
        for(int j=64;j<89;j++){
            char z = (char) j;
                System.out.print(z);
        }
        */

        /* printar matriz
        for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){
                System.out.println(varialvel [i][j]);
            }
        }
        */

        sc.close();
    }
}