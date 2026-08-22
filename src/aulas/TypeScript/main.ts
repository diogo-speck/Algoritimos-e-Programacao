/*
Object Types

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

terminal.question('Digite seu nome: ', (nome) =>{ // interface no terminal
  // Recebe uma string na função .question e atribui a uma variável
  console.log(`Seu nome é ${nome}`) // Saída de dados
  terminal.close();
}); // fechando o callback


var text = '{ "employees" : [' +
'{ "firstName":"John" , "lastName":"Doe" },' +
'{ "firstName":"Anna" , "lastName":"Smith" },' +
'{ "firstName":"Peter" , "lastName":"Jones" } ]}'; 

var obj = JSON.parse(text); // Converte String em objetos


// Tipos primitivos

let isActive: boolean = true; // Boolean

// O tipo number pode ser qualquer valor numérico
let decimal: number = 6; // Decimal
let hex: number = 0xf00d; // Hexadecimal
let binary: number = 0b1010; // Binary
let octal: number = 0o744; // Octal
let float: number = 3.14; // Floating point
let scientific: number = 2**16; // Scientific Notation

// O tipo String pode ser definido com "" '' ``(backticks)
let color: string = "blue";
let object: string = 'car';
let place: string = `road`;
let frase: string = `A ${color+" "+object} in the ${place}`;

const doisNa32 = BigInt(4294967296); // BigInt serve para representar número muito grandes até 2^53 - 1

// O tipo Symbol usa chaves e constantes
const uniqueKey: symbol = Symbol("descrição")
const simbulo = {
  [uniqueKey]: "Muitos detalhes"
};


// Tipos especiais


// Arrays
let notas: number[] = [10, 9,5, 9,8];
notas.push(7); // .append

// Any

const employe = {
  name: "Alice",
  age: 30,
  employed: true
}; 

const data = JSON.parse('{ "name": "Alice", "age": 30 }'); // tipos diferentes -> any
console.log(data)
console.log(employe.name)

// Unknown

let w: unknown = 1;
w = "string"; // no error
w = {
  runANonExistentMethod: () => {
    console.log("I think therefore I am");
  }
}

function processValue(value: unknown) {
  if (typeof value === 'string') {
    // value is now treated as string
    console.log(value.toUpperCase());
  } else if (Array.isArray(value)) {
    // value is now treated as any[]
    console.log(value.length);
  }
}

// Never

function throwError(message: string): never{
  throw new Error(message);
}

// Undefined & null

let y: undefined = undefined;
let z: null = null;

interface User {
  year?: number; // Same as `number | undefined`
}

// Tuples (Typed Arrays)

let tupla: [number, string, number, string];

tupla = [3, "pratos de trigo para", 3, "tigres tristes"]; // Ordem importa
tupla.push('.'); // Não tem mais verificação, por isso é recomendado deixar readonly já que não são re-declaráveis



// executar usando o comando: npx (node package executor) tsc (type script compiler) "src\aulas\TypeScript\main.ts"