package aulas.aula03;

import java.util.Scanner;

public class hello{
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
    }
        

    sc.close();
    }
}    
}