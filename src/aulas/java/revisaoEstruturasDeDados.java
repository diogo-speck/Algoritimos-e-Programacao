import java.util.Scanner;

public class revisaoEstruturasDeDados {
    public static void main(String[] args) {

        try (Scanner sc = new Scanner(System.in)) {

            String out = "";
            System.out.println("Insira valores inteiros espaçados: ");
            String[] numeros = sc.nextLine().split(" "); // retira os espaços vazios " " e separa os elementos individualmente
            System.out.println("Insira um valor inteiro para multiplicar os números informados:");
            int n = Integer.parseInt(sc.nextLine()); // transforma uma String em Int

            for (String valor : numeros) {
                int numero = Integer.parseInt(valor); // transforma o array de String em array de Int
                out += (numero * n) + " "; // multiplica os valores informados pelo valor inteiro informado
            }

            System.out.println("Resultado: \n"+out);
            System.out.println("Você digitou "+numeros.length+" números espaçados");

            /* Exemplo de soma de um número convertido de uma String para Int: 
            String texto = "60";
            int teste = Integer.parseInt(texto);
            System.out.println(teste + 7);
            */


        }
    }
}

class Node {
    
}