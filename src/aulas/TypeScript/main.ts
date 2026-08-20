/*
getstarted

Pesquisar:

entrada e saída de dados;
tipos de dados;
estruturas(if,else,for,for each,while,switch case, etc)
funções
*/

import readline from "readline"; // Entrada de dados (precisa da biblioteca readline para criar uma interface no terminal)

console.log("Hello World")

if (0/2 === 0) { // Recomendado usar 3= para comparação de valor e tipo
    console.log(true)
  }

const terminal = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

terminal.question("Digite seu nome: ", (nome) =>{ // interface no terminal
  // Recebe uma string na função .question e atribui a uma variável
  console.log(`Seu nome é ${nome}`) // Saída de dados
  terminal.close();
}); // fechando o callback






// executar usando o comando: npx tsx "src\aulas\TypeScript\main.ts"