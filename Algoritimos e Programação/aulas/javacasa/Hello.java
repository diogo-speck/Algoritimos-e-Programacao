package aulas.javacasa;

import java.util.Scanner;

public class Hello{
public static void main (String[]args){
Scanner sc = new Scanner(System.in); 
while (true){
    System.out.println("Treinando Java, deseja treinar também? ");
    String confirmacao = sc.nextLine();
    confirmacao = confirmacao.toLowerCase();
    // ex. SIM -> sim
    if (confirmacao.equalsIgnoreCase("sim")||(confirmacao.equals("ss"))||(confirmacao.equals("s"))||(confirmacao.equals("zim"))){
        System.out.println("Certo, aqui vai uma lista dos principais comandos: ");
        System.out.println("System.out.printf('Nome: %s, Idade: %d%n', 'Diogo', 18");
        System.out.println("Switch (variavel){case x:;}");
        System.out.println("for (tipo) i = valor; i (intervalo); i++(mais 1 toda vez do laço){executa uma ação em realação a i}");
        
    }
    else{
        System.out.println("Ok, sem problemas");
        System.out.println("Agora vou montar um perfil no Tinder para você então, para começar você precisa ter pelo menos 18 anos, para facilitar qual a sua idade? ");
        int idade1 = sc.nextInt();

        System.out.println("Confirma sua idade: ");
        idade1 = sc.nextInt();

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
        

    sc.close();
    }
}    
}