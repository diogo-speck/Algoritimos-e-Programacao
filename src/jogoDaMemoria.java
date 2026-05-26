import java.util.Random;
import java.util.Scanner;

public class jogoDaMemoria {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    
        Random aleatorio = new Random();
        
        char confere='a';
        char confere2='a';
        boolean acertou = false;
        int linha=0, coluna=0, linha2=0, coluna2=0,jogador=1;
        int pontos1=0, pontos2=0;
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
            int trocai = aleatorio.nextInt(7);
            int trocaj = aleatorio.nextInt(7);
            for (int i=0;i<7;i++){
                for (int j=0;j<7;j++){
                    save = tabuleiro[i][j];
                    tabuleiro[i][j] = tabuleiro [trocai][trocaj];
                    tabuleiro [trocai][trocaj] = save;
                }
            }
        }

        for (int i=0;i<7;i++){
            System.out.println();
            for (int j=0;j<7;j++){
            System.out.print(tabuleiro[i][j]+" ");
            }
        }
        
        System.out.println("\n\nBem-vindo ao jogo da memória ");
        do {
            acertou = false;
            System.out.print("Turno do Jogador "+jogador);
            System.out.println("\nSeu tabuleiro: ");
            for (int i=0;i<7;i++){
                System.out.println();
                for (int j=0;j<7;j++){
                    System.out.print(adivinhar[i][j]+" "); 
                }
            }
            
            confere = 'a';
            confere2 = 'a';
            
            for (int turno=0;turno<2;turno++){
                System.out.println("\n\nDigite as coordenadas da linha do tabuleiro (a partir de 1 até 7 ex. 1 para linha 1): ");
                linha = sc.nextInt()-1;
                System.out.println("Digite as coordenadas da coluna do tabuleiro (a partir de 1 até 7 ex. 1 para coluna 1): ");
                coluna = sc.nextInt()-1;
                System.out.println("Você escolheu a coordenada "+(linha+1)+"x"+(coluna+1));

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
                    adivinhado[linha][coluna] = adivinhar[linha][coluna];
                    adivinhar[linha2][coluna2] = tabuleiro[linha2][coluna2];
                    adivinhado[linha2][coluna2] = adivinhar[linha2][coluna2] ;
                    acertou = true;
                }
                else if (confere=='*'||confere2=='*') {
                    System.out.print("\n\nVocê encontrou a carta curinga, perca seu turno");
                    if (confere=='*'){
                        adivinhar[linha2][coluna2] = '*';
                        adivinhado[linha2][coluna2] = '*';
                    }
                    else{
                        adivinhar[linha][coluna] = '*';
                        adivinhado[linha][coluna] = '*';
                    }
                    acertou = false;
                    break;
                }
                else{
                    acertou = false;
                    if (adivinhar[linha][coluna]!=adivinhado[linha][coluna]){
                        adivinhar[linha][coluna] = '#';
                        adivinhado[linha][coluna] = '#';
                    }
                    if (adivinhar[linha2][coluna2]!=adivinhado[linha2][coluna2]){
                        adivinhar[linha2][coluna2] = '#';
                        adivinhado[linha2][coluna2] = '#';
                    }
                }
            
            }

            if (acertou){
                    if (jogador==1){
                        pontos1+=1;
                    }
                    if (jogador==2){
                        pontos2+=1;
                    }
                
                if ((pontos1+pontos2)<24){
                    System.out.println("\n\nVocê acertou um par \nJogue novamente");
                }
            }
            if(!acertou){
                System.out.println("\n\nVocê errou o par \nTurno do próximo jogador");
                if(jogador==1){
                    jogador++;
                }
                else{
                    jogador--;
                }
            }
            System.out.println("\n\n(Placar) Jogador 1: "+pontos1+" | Jogador 2: "+pontos2);
            
        } while ((pontos1+pontos2)<24);
        if (pontos1>pontos2){
            System.out.println("Jogador 1 GANHOU com "+pontos1+" pontos");
        }
        else if (pontos1<pontos2){
            System.out.println("Jogador 2 GANHOU com "+pontos2+" pontos");
        }
        else{
            System.out.println("EMPATE");
        }

        sc.close();
    }
}