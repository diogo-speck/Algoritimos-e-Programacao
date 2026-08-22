/*
Introdução JavaScript

var, let e const | escopo, hoisting e imutabilidade

var
Escopo: Global ou de função (function scope). Não respeita blocos de código {}.
Hoisting: Variáveis declaradas com var são içadas (hoisted), ou seja, o JavaScript "move" a declaração para o topo da função ou do escopo global.
Valor: Pode ser reatribuído.

let
Escopo: De bloco (block scope), ou seja, só existe dentro de {}.
Hoisting: Também sofre hoisting, mas não pode ser acessada antes da declaração (tem “temporal dead zone”).
Valor: Pode ser reatribuído.

const
Escopo: De bloco.
Hoisting: Comportamento similar ao let.
Valor: Não pode ser reatribuído. No entanto, objetos e arrays declarados como const podem ter seus conteúdos alterados, apenas a referência não pode mudar.

*/

"use strict";
console.log("Hello World");
var isEven = require('is-even');
var isTen = require('is-ten');

if (isTen(10)) {
    console.log("hi")
};

if ("" == 0) {
    console.log(true)
  }

console.log(0.8 - 0.1)

const obj = { width: 10, height: 15 };
const area = obj.width * obj.heigth;
console.log(area)

console.log(console.log(4 / []));

console.log(eval("3 + 5"));

    
const greetMe = "Diogo";
console.log(`Olá ${greetMe}`);

function add(a, b) {
return a + b;
}

console.log(add("5", 3));

let v = true; // any
v = "string"; // no error as it can be "any" type
Math.round(v); // no error as it can be "any" type 