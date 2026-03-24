package aulas.javacasa;

import java.util.Scanner;

public class Hello{
public static void main (String[]args){
Scanner sc = new Scanner(System.in); 
    System.out.println("Treinando Java, deseja treinar também? ");
    String confirmacao = sc.nextLine();
    confirmacao = confirmacao.toLowerCase();
    // ex. SIM -> sim
    if (confirmacao.equalsIgnoreCase("sim")||(confirmacao.equals("ss"))||(confirmacao.equals("s"))||(confirmacao.equals("zim"))){
        System.out.println("Certo, aqui vai uma lista dos principais comandos: ");
    }
    else{
        System.out.println("Ok, sem problemas");
    }
    
sc.close();
}
}
