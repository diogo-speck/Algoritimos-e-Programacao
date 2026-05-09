package aulas.aula08;

import java.util.Scanner;

public class revisao {

    public static String saudacaoPersonalizada(String name, String local) {
         return "Olá ".concat(name).concat("! Bem-vindo à ").concat(local).concat("!");
      }
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

byte	Stores whole numbers from -128 to 127
short	Stores whole numbers from -32,768 to 32,767
int	Stores whole numbers from -2,147,483,648 to 2,147,483,647
long	Stores whole numbers from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
float	Stores fractional numbers. Sufficient for storing 6 to 7 decimal digits
double	Stores fractional numbers. Sufficient for storing 15 to 16 decimal digits
boolean	Stores true or false values
char	Stores a single character/letter or ASCII values

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

Java divides the operators into the following groups:

Arithmetic operators (mathematical operations)
Assignment operators (=+ encurtador)
Comparison operators (Booleans >= == <=)
Logical operators (true or false values with logical && || !)
Bitwise operators (mexe nos bits diretamente >>=)

Order of Operations:
Left to right
()  Parentheses
*, /, %  Multiplication, Division, Modulus
+, -  Addition, Subtraction
>, <, >=, <=  Comparison
==, != Equality
&& Logical AND
||  Logical OR
=  Assignment


Java Strings

A String in Java is actually an object, which means it contains methods that can perform certain operations on strings.
For example, you can find the length of a string with the length() method
You can use the charAt() method to access a character at a specific position in a string
To compare two strings, you can use the equals() method:

Concatenation

Se caso tentar concatenar qualquer variável com String, virará uma String
\\

Java Math

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
      String c="";
      for(int a=1;a<=128;a++){
         char b = (char)a;
         System.out.print(b+" ");
         c=c+b;
      }
      System.out.println("São "+c.length()+" caracteres");

      // Encurtando o número
      System.out.println("Digite um número (0-9) com quantas casas quiser depois da vírgula: (0.1 nesse padrão) ");
      double numero = sc.nextDouble();
      int numeroint = (int) numero;
      System.out.println("Seu número ficou assim: "+numeroint);


      // Operações BitWise
      System.out.printf("Insira um valor inteiro: ");
      int valor = sc.nextInt();
      int save = valor;
      System.out.println(valor);
      valor &= 63;
      System.out.println("and &= "+valor); // Confere cada digito binário e imprime os iguais 1111111
      valor = save;
      valor |= 63; // Soma binário básicamente deixando 1 quando dá 1111111 (adiciona 63 se for maior que 63)
      System.out.println("or |= "+valor);
      valor = save;
      valor ^= 63;
      System.out.println("xor ^= "+valor); // Subtrai binários em módulo básicamente tirando 1 quando dá 1111111
      valor = save;
      valor >>= 1;
      System.out.println(">>= "+valor); // Desloca bits 1 posição à DIREITA (divide por 2) Shift
      valor = save;
      valor <<= 1;
      System.out.println("<<= "+valor); // Desloca bits 1 posição à ESQUERDA (multiplica por 2)

      // sc.next();
      System.out.println();
      System.out.println("Escreva um texto: ");
      String horizontal = sc.next();
      System.out.println("Seu texto na vertical: ");
      for (int h=0; h<horizontal.length(); h++) {
         System.out.println(horizontal.charAt(h));
      }
      
      /*
      for (char u : horizontal.toCharArray()) {
      System.out.println(u);
      }
      */

      String mensagem = saudacaoPersonalizada("usuário", "empresa");
      System.out.println(mensagem);
      // Saída: Olá usuário! Bem-vindo à empresa!
      /*
      public - Torna o método acessível
      static - Permite chamar da main() sem instanciar* a classe (criar um objeto)
      String - Define o tipo de retorno explicitamente

      "método static" = parece função, mas não é, é método
      */

      boolean verdade = true;
      String vf = " ";
      vf = verdade+vf+verdade;
      System.out.println("\\92 & |124 \""+vf+"\"");
      String txt = "teste";
      System.out.println("\n\t"+txt+"\b"+txt);

      //Transformar qualquer palavra em palíndromo
      System.out.println("Insira uma palavra para fazer um palíndromo: ");
      String palindromo = sc.next();
      System.out.println("Palavra palíndromada: ");
      for (int p=0; p<palindromo.length(); p++) {
         System.out.print(palindromo.charAt(palindromo.length()-p-1));
      }
      if (palindromo.length()>2){
         System.out.printf("\b"+palindromo);
      }
      else{
         System.out.printf(palindromo);
      }
      

    sc.close();
   }
}