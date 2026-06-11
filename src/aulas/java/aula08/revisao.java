package aula08;

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

The Math.max(x,y) method can be used to find the highest value of x and y
The Math.min(x,y) method can be used to find the lowest value of x and y
The Math.abs(x) method returns the absolute (positive) value of x (módulo)
Note: The Math.pow() (math functions em geral) method always returns a double, even if the result is a whole number.

Para arredondar:
Math.round(x) - rounds to the nearest integer
Mas também tem o ceil (para cima) e o floor (para baixo)


Java Booleans

equal to (==) operator to evaluate an expression
Note: It is up to you whether you store the result of a comparison in a boolean variable or use the comparison directly.
Storing the result can make your code easier to read, especially if you want to reuse it.

Java If ... Else

Equal to: a == b
If an if statement has only one line of code, you can write it without curly braces { }
else does not have a condition - it runs when the if condition is false.

Ternary Operator (Short Hand if...else)
variable = (condition) ?(if) expressionTrue :(else)  expressionFalse;
Nested Ternary
Mais trabalhoso, mas é possível colocar mais de 1 condição

Java Switch (só int, String e enum?)

The switch expression is evaluated once.
The result is compared with each case value.
If there is a match, the matching block of code runs.
The break statement stops the switch after the matching case has run.
The default statement runs if there is no match.
A break can save a lot of execution time because it "ignores" the execution of all the rest of the code in the switch block.

Java While Loop

Porque usar i como variável? It's a counter variable and a common choice in simple loops because it's short, traditional, and stands for 'index' or 'iterator'.
A diferença de while e do/while é que ele executa sempre pelo menos 1 vez

Java For Loop

It is also possible to place a loop inside another loop. This is called a nested loop.
The "inner loop" will be executed one time for each iteration of the "outer loop":
for-each Loop = for (type variableName : arrayName)

Java Break and Continue

break statement can be used in switch and loops, such as for
The continue statement breaks one iteration (in the loop), if a specified condition occurs, and continues with the next iteration in the loop.

Java Arrays

You can access an array element by referring to the index number.
To find out how many elements an array has, use the length property
Tip: The shortcut syntax (without new) is most often used when the values are known at the start. Use 'new' with a size when you want to create an empty array and fill it later.
The colon (:) is read as "in". So you can read the loop as: "for each variable in array"
However, it only gives you the values, not their positions (indexes) in the array.
So, if you need both the position (index) of each element and its value, a regular for loop is the right choice.

Terminei o tutorial do java, Java Methods em diante será em outro arquivo de revisão
*/

      
      String nome = "Diogo";
      final String ID = "homem";
      int idade = 18;
      System.out.println("Olá "+nome+", você tem "+idade+" anos.");
      if (idade>=18){System.out.println("Com "+idade+" anos está liberado");}
      else{System.out.println("Com "+idade+" anos NÃO está liberado");}
      idade = 19;
      System.out.println("Daqui a algum tempo, "+nome+" terá "+idade+" anos.");
      System.out.println(nome+" é "+ID);
      int dia = 1;
      switch (dia) {
          default:
              System.out.println("Hoje é dia de resenha");
      }
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
      int contagem = 3;
      while (contagem>0) {
         System.out.println("Conectando...");
         contagem--;         
      }
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

      double cara = Math.random();
      System.out.println("\nEscolha cara ou coroa (c/k): ");
      String coroa = sc.next().toLowerCase();
      if (coroa.equals("cara")||coroa.equals("c")){
         if (cara<0.5){
            System.out.println("Você PERDEU, caiu coroa");
         }
         else{
            System.out.println("Você GANHOU, caiu cara");
         }
      }
      else if (coroa.equals("coroa")||coroa.equals("k")){
         if (cara<0.5){
            System.out.println("Você GANHOU, caiu coroa");
         }
         else{
            System.out.println("Você PERDEU, caiu cara");
         }
      }
      else{
         System.out.printf("Você não escolheu nem cara, nem coroa, mas por curiosidade caiu ");
         if (cara<0.5){
            System.out.print("coroa");
         }
         else{
            System.out.print("cara");
         }
      }
      
      // gerando números aleatórios com input do usuário sem importar Random
      System.out.println("\nAté qual número natural você quer que os números aleatórios gerem: ");
      int max = sc.nextInt();
      System.out.println("Quantos números aleatórios você quer gerar nesse intervalo: ");
      int vezes = sc.nextInt();
      for (int i=0; i<vezes;i++){
         int randomNum = (int)(Math.random() * (max+1)); // começa sempre fechado em 0 e aberto na constante multiplicada por 1, por isso arredonda para baixo usando int para ignorar as casas decimais
         System.out.print(randomNum+" ");
      }
      
      int vouf = (int)(Math.random() * 2);
      /*
      System.out.println(vouf);
      if (vouf==0){
         verdade = false;
      }
      else{
         verdade = true;
      }
      */
      verdade = (vouf==0)? false : true;
      System.out.println((vouf==0)? false : true);

      int [][] matriz = new int[3][];
      for (Object teste : matriz) {
          System.out.println(teste);
      } 

      /*
      switch (matriz) {
          default:
              System.out.println("Não é possível colocar um array dentro de um switch");
      }
      */
      Enum semTipo;
      while (true) { 
          break;
      }

      String [] lista = new String [5];
      for(int i=0;i<5;i++){
         System.out.println("Insira algo na posição "+(i+1)+" da lista (0 para sair): ");
         lista[i]=sc.next();
         if (lista[i].equals("0")){
            break;
         }
      }
      for(String i : lista){
         System.out.print(i+" ");
      }

    sc.close();
   }
}