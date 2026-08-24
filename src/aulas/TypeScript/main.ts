/*
W3Schools = TypeScript Basic Generics

Pesquisar:

estruturas(if,else,for,for each,while,switch case, etc)
entrada e saída de dados;
funções
tipos de dados;
*/

import { isAbsolute } from "path";
import readline from "readline"; // Entrada de dados (precisa da biblioteca readline para criar uma interface no terminal)

console.log("Hello World")

if (0/2 === 0) { // Recomendado usar 3= para comparação de valor e tipo
    console.log(true)
  }
else{
  console.log(false)
}

for (let i in [2,3]){ // for
  console.log(i) // "0", "1"
}

for (let i of [2,3]){ // for each
  console.log(i) // 2, 3
}

var numbers = [1, 2, 3]; // array print
for (let _i = 0; _i < numbers.length; _i++) {
  var num = numbers[_i];
  console.log(num);
}

let a: number = 1;
while (a<5){
  switch (a) {
   case 1:
       console.log("\nUm");
       break;
   case 2:
       console.log("\nDois");
       break;
   case 3:
       console.log("\nTrês");
       break;
   default: 
       console.log("\nQuatro");
       break;
  }
  a++;
}


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
console.log(w as string); // Casting -> <string>w (react)
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
  year?: number; // Same as `number | undefined` (Union  (OR))
}

// Tuples (Typed Arrays)

let tupla: [number | string, string, string | number, string]; // (Union  (OR))

tupla = [3, "pratos de trigo para", 3, "tigres tristes"]; // Ordem importa, poderia ser "três" no lugar do 3
tupla.push('.'); // Não tem mais verificação, por isso é recomendado deixar readonly já que não são re-declaráveis

// TypeScript Object Types similar to JSON (JavaScript Object Notation)

const car: { type: string, mileage?: number } = { // atribuindo opcionalmente com undefined
  type: "Toyota"
};
car.mileage = 2000;

// Enum (string & numeric)

enum CardinalDirections {
  North = 0, // Redundante porque começa em 0, mas é mutável
  East = "East",
  South = 1,
  West = 'W'
}
let currentDirection = CardinalDirections[0];
// logs North
console.log(currentDirection);
currentDirection = CardinalDirections.West;
// logs W
console.log(currentDirection);

// Interfaces

interface Rectangle {
  height: number,
  width: number
}

interface ColoredRectangle extends Rectangle {
  color: string
}

const coloredRectangle: ColoredRectangle = {
  height: 20,
  width: 10,
  color: "red"
};


// Funções

function add(a:number=0, b:number=0, c?:number) {
  return a + b + (c||0);
}

type absolute = (value:number) => number;

const mod:absolute=(value)=> Math.abs(value);

class Person{
  private readonly name:string;
  public constructor(name: string) {
    this.name = name;
  }

  public getName(): string {
    return this.name;
  }

  public toString(): string {
    return `Name: ${this.getName}`;
  }
}
const p1 = new Person("Jane");
p1.getName();

class id extends Person{ // implements se não tiver que usar o método construtor, extends para usar os atributos
  public age: number; // por padrão é public

  public constructor(name: string, age: number) {
    super(name);
    this.age = age;
  }

  public override toString(): string { // override é opcional, mas é uma boa pratica
    return `${this.getName} (${this.age})`;
  }
}
const p2 = new id("Diogo", 18);
console.log(p2);





const terminal = readline.createInterface({ // Só se aplica a objetos, no caso instancia um quando chamada
  input: process.stdin,
  output: process.stdout
});

terminal.question('Digite seu nome: \n', (nome) =>{ // interface no terminal
  // Recebe uma string na função .question e atribui a uma variável
  console.log(`Seu nome é ${nome}`) // Saída de dados
  terminal.close();
}); // fechando o callback


// executar usando o comando: npx (node package executor) tsc (type script compiler) "src\aulas\TypeScript\main.ts"