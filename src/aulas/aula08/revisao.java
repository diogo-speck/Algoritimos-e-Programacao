package aulas.aula08;

import java.util.Scanner;

public class revisao {
   public static void main(String[]args){
    
    Scanner sc = new Scanner(System.in);

/* 
Anotações:

Java é usado para:
Mobile applications (specially Android apps) *
Desktop applications
Web applications
Web servers and application servers
Games *
Database connection
And much, much more!

Porquê usar Java?
Java works on different platforms (Windows, Mac, Linux, Raspberry Pi, etc.)
It is one of the most popular programming languages in the world
It has a large demand in the current job market
It is easy to learn and simple to use
It is open-source and free
It is secure, fast and powerful
It has huge community support (tens of millions of developers)
Java is an object oriented language which gives a clear structure to programs and allows code to be reused, lowering development costs
As Java is close to C++ and C#, it makes it easy for programmers to switch to Java or vice versa

Note: The curly braces {} mark the beginning and the end of a block of code
Finally, remember that each Java statement must end with a semicolon (;).

In a programming language, the programming instructions are called statements.

String - stores text, such as "Hello". String values are surrounded by double quotes
int - stores integers (whole numbers), without decimals, such as 123 or -123
float - stores floating point numbers, with decimals, such as 19.99 or -19.99
char - stores single characters, such as 'a' or 'B'. Char values are surrounded by single quotes
boolean - stores values with two states: true or false

   type variableName = value;

You can declare the variable as "final" or "constant", which means unchangeable and read-only
Note: By convention, final variables in Java are usually written in upper case (e.g. BIRTHYEAR). It is not required, but useful for code readability and common for many programmers.

Java Data Types
(Var?)

Uma String também é referenciado a um objeto em Java (não primitivo)

Non-primitive data types are called reference types because they refer to objects.

The main differences between primitive and non-primitive data types are:

Primitive types in Java are predefined and built into the language, while non-primitive types are created by the programmer (except for String).
Non-primitive types can be used to call methods to perform certain operations, whereas primitive types cannot.
Primitive types start with a lowercase letter (like int), while non-primitive types typically starts with an uppercase letter (like String).
Primitive types always hold a value, whereas non-primitive types can be null.
Examples of non-primitive types are Strings, Arrays, Classes etc.

In Java, there are two main types of casting:

Widening Casting (automatic) - converting a smaller type to a larger type size
byte -> short -> char -> int -> long -> float -> double

Narrowing Casting (manual) - converting a larger type to a smaller type size
double -> float -> long -> int -> char -> short -> byte

Java Operators

*/

      String nome = "Diogo";
      final String ID = "homem";
      int idade = 18;
      System.out.println("Olá "+nome+", você tem "+idade+" anos.");
      idade = 19;
      System.out.println("Daqui a algum tempo, "+nome+" terá "+idade+" anos.");
      System.out.println(nome+" é "+ID);
      // ID = "mulher"; *não funciona
      int x, y, z;
      x=y=z=1;
      System.out.println(x+y+z);
      System.out.println(x+""+y+""+z);
      System.out.println(x+" "+y+" "+z);

      int padrao;
      System.out.println("Insira um número: ");
      padrao = sc.nextInt();
      for(int n = 1; n <= padrao; n++) {
         for(int o = padrao; o >= n; o--) {      
             System.out.printf(n + " ");    
         }
         System.out.println();  
      }

      for(int n = 1; n <= padrao; n++) {
         for(int o = padrao; o >= n; o--) {      
             System.out.printf((padrao-o+1)+ " ");    
         }
         System.out.println();  
      }

      String sn;
      double membros=1, pai, mae, renda = 0, bens=0;
      final int SALARIOMIN = 1621;
      final double BENSMAX = 1499999.99;
      Boolean matricula=true;
      Boolean naturalidade=true;
      System.out.println("Você nasceu ou está a pelo menos 5 anos residindo em Santa Catarina? (s/n)");
      sn = sc.next();
      if (sn.toLowerCase().equals("n")){
         naturalidade = false;
      }
      else{
         System.out.println("Você está matriculado em uma instituição de ensino superior participante do programa? obs. Univali é participante (s/n)");
         sn = sc.next();
         if (sn.toLowerCase().equals("n")){
            matricula = false;
         }
         else{
            System.out.println("Quants membros tem em sua família? ");
            membros = sc.nextDouble();
            System.out.println("Quanto seu pai ganha por mês? ");
            pai = sc.nextDouble();
            System.out.println("Quanto sua mãe ganha por mês? ");
            mae = sc.nextDouble();
            System.out.println("Quanto seu grupo familiar tem de valor em bens? ");
            bens = sc.nextDouble();
            renda = mae+pai;
            /* 
            System.out.println(naturalidade);
            System.out.println(matricula);
            System.out.println(renda/membros);
            System.out.println(bens);
            */
            if (naturalidade&&matricula&&((renda/membros)<4*SALARIOMIN)&&bens<BENSMAX){
               System.out.println("Você está qualificado para participar do programa Universidade Gratuita");
            }
         }
      }
      if (!(naturalidade&&matricula&&((renda/membros)<4*SALARIOMIN)&&bens<BENSMAX)){
               System.out.println("Você não está qualificado para participar do programa Universidade Gratuita");
            }
      
   
      /*
      Diferença de float e double em Java

      double dobrar;
      dobrar = 2.99f*2;
      System.out.println(dobrar);
      dobrar = 2.99*2;
      System.out.println(dobrar);

      Casos de ponto flutuantes, usar BigDecimal (mais precisão)
      */
      
      // int sequencia = 100000000000000;
      long sequencia = 100000000000000L;
      System.out.println(sequencia);
      float f1 = 35e3f;
      System.out.println(f1);

      // caracteres ASCII
      for(int a=1;a<=128;a++){
         char b = (char)a;
         System.out.println(b+" ");
      }

      // Encurtando o número
      System.out.println("Digite um número (0-9) com quantas casas quiser depois da vírgula: (0.1 nesse padrão) ");
      double numero = sc.nextDouble();
      int numeroint = (int) numero;
      System.out.println("Seu número ficou assim: "+numeroint);


    sc.close();
   }
}