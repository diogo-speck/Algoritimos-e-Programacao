package aulas.trabalhosEmGrupo;

import java.util.Scanner;
import java.util.Random;

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String opcao;

        do {
            System.out.println();
            System.out.println("Deseja jogar Pedra, Papel e Tesoura? (s/n) ");
            opcao = sc.next();

            if (opcao.equalsIgnoreCase("s")) {
                System.out.printf("\n======MENU======");
                System.out.printf("\n1 - Pedra");
                System.out.printf("\n2 - Papel");
                System.out.printf("\n3 - Tesoura");
                System.out.printf("\n0 - Voltar ao menu");
                System.out.printf("\nEscolha: ");

                while (!sc.hasNextInt()) {
                    System.out.println("Por favor, digite uma escolha válida");
                    sc.next();
                }
                int escolhaUsuario = sc.nextInt();

                if (escolhaUsuario == 0) {
                    continue; // volta ao menu principal
                }

                Random gerador = new Random();
                int escolhaComputador = gerador.nextInt(3) + 1;

                switch (escolhaUsuario) {
                    case 1: // Pedra
                        if (escolhaComputador == 1){ 
                            System.out.println("Empate");
                            System.out.println("Computador escolheu:\n"+
                                                "    _____\n" +
                                                "---' ____)\n" +
                                                "    (_____)\n" +
                                                "    (_____)\n" +
                                                "    (____)\n" +
                                                "    (___)\n"
                                                );
                            System.out.println("    _____             _____ \n" +
                                                "---' ____)       ---' ____) \n" +
                                                "    (_____)          (_____) \n" +
                                                "    (_____)          (_____) \n" +
                                                "    (____)           (____) \n" +
                                                "    (___)            (___) \n"
                                                );
                        }
                        else if (escolhaComputador == 2){ 
                            System.out.println("Você perdeu");
                            System.out.println("Computador escolheu:\n"+
                                                "    _______ \n" +
                                                "---'   ____)____ \n" +
                                                "          ______) \n" +
                                                "           _______) \n" +
                                                "          _______) \n" +
                                                "-----.__________) \n"
                                                );
                            System.out.println("    _____              _______ \n" +
                                                "---' ____)        ---'   ____)___ \n" +
                                                "    (_____)                ______) \n" +
                                                "    (_____)                 _______) \n" +
                                                "    (____)                 _______) \n" +
                                                "    (___)          ---.________) \n"
                                                );
                        }
                        else{ 
                            System.out.println("Você venceu");
                            System.out.println("Computador escolheu:\n"+
                                                "    ______ \n" +
                                                "---'  ____)_____ \n" +
                                                "           ______) \n" +
                                                "         __________) \n" +
                                                "        (____) \n" +
                                                "---.__(___) \n"
                                                );
                            System.out.println("    _____              ______ \n" +
                                                "---' ____)        ---'  ____)_____ \n" +
                                                "    (_____)                  ______) \n" +
                                                "    (_____)                __________) \n" +
                                                "    (____)                 (____) \n" +
                                                "    (___)          ---.__(___) \n"
                                                );
                        }
                            break;
                    case 2: // Papel
                        if (escolhaComputador == 1){ 
                            System.out.println("Você venceu");
                            System.out.println("Computador escolheu:\n"+
                                                "    _____\n" +
                                                "---' ____)\n" +
                                                "    (_____)\n" +
                                                "    (_____)\n" +
                                                "    (____)\n" +
                                                "    (___)\n"
                                                );
                            System.out.println("     _____                 ____\n" +
                                                "---' ____)____        ---' ____)\n" +
                                                "        ______)           (_____)\n" +
                                                "         _______)         (_____)\n" +
                                                "        _______)          (____)\n" +
                                                "---.__________)           (___)\n"
                                                );
                        }
                        else if (escolhaComputador == 2){ 
                            System.out.println("Empate");
                            System.out.println("Computador escolheu:\n"+
                                                "    _______ \n" +
                                                "---'   ____)____ \n" +
                                                "          ______) \n" +
                                                "           _______) \n" +
                                                "          _______) \n" +
                                                "-----.__________) \n"
                                                );
                            System.out.println("     _____                 _____\n" +
                                                "---' ____)____        ---' ____)____\n" +
                                                "        ______)               ______)\n" +
                                                "         _______)              _______) \n" +
                                                "        _______)              _______)\n" +
                                                "---.__________)       ---.__________)\n"
                                                );
                        }
                        else{ 
                            System.out.println("Você perdeu");
                            System.out.println("Computador escolheu:\n"+
                                                "    ______ \n" +
                                                "---'  ____)_____ \n" +
                                                "           ______) \n" +
                                                "         __________) \n" +
                                                "        (____) \n" +
                                                "---.__(___) \n"
                                                );
                            System.out.println("     _____                 ______ \n" +
                                                "---' ____)____        ---'  ____)_____ \n" +
                                                "        ______)                  ______)\n" +
                                                "         _______)                 ______) \n" +
                                                "        _______)              (____) \n" +
                                                "---.__________)       ---.__(___) \n"
                                                );
                        }
                            break;
                    case 3: // Tesoura
                        if (escolhaComputador == 1){ 
                            System.out.println("Você perdeu");
                            System.out.println("Computador escolheu:\n"+
                                                "    _____\n" +
                                                "---' ____)\n" +
                                                "    (_____)\n" +
                                                "    (_____)\n" +
                                                "    (____)\n" +
                                                "    (___)\n"
                                                );
                            System.out.println("     ______                   ____\n" +
                                                "---'  ____)_____         ---' ____)\n" +
                                                "           ______)           (_____)\n" +
                                                "            ______)          (_____)\n" +
                                                "        (____)               (____)\n" +
                                                "---.__(___)                  (___)\n"
                                                );
                        }
                        else if (escolhaComputador == 2){ 
                            System.out.println("Você venceu");
                            System.out.println("Computador escolheu:\n"+
                                                "    _______ \n" +
                                                "---'   ____)____ \n" +
                                                "          ______) \n" +
                                                "           _______) \n" +
                                                "          _______) \n" +
                                                "-----.__________) \n"
                                                );
                            System.out.println("     ______             \"    _______ \n" +
                                                "---'  ____)_____        ---'     ____)____ \n" +
                                                "           ______)                   ______) \n" +
                                                "            ______)                  _______) \n" +
                                                "        (____)                     _______)\n" +
                                                "---.__(___)             -----.__________) \n"
                                                );
                        }
                        else{ 
                            System.out.println("Empate");
                            System.out.println("Computador escolheu:\n"+
                                                "    ______ \n" +
                                                "---'  ____)_____ \n" +
                                                "           ______) \n" +
                                                "         __________) \n" +
                                                "        (____) \n" +
                                                "---.__(___) \n"
                                                );
                            System.out.println("     ______                  ______\n" +
                                                "---'  ____)_____        ---'  ____)_____ \n" +
                                                "           ______)                 ______) \n" +
                                                "            ______)                  ______)\n" +
                                                "        (____)                  (____)\n" +
                                                "---.__(___)             ---.__(___)\n"
                                                );
                        }
                            break;
                    default:
                        System.out.println("Opção inválida! Escolha 1, 2, 3 ou 0");
                }
            } else if (opcao.equalsIgnoreCase("n")) {
                System.out.println("Ok, programa encerrado");
                break;
            } else {
                System.out.println("Por favor, digite s para sim ou n para não");
            }

        } while (true);

        sc.close();
    }
}