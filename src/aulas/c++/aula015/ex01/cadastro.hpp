#pragma once
#include <iostream>
#include <string>

struct Aluno {
    std::string nome;
    int matricula;
    double nota1;
    double nota2;
};

double calcularMedia(const Aluno& aluno);
void imprimirAluno(const Aluno& aluno);


double calcularMedia(const Aluno& aluno){
    return (aluno.nota1+aluno.nota2)/2;
}

void imprimirAluno(const Aluno& aluno){
    std::cout << aluno.nome << " é aluno(a) com matrícula " << aluno.matricula << " e tirou " << aluno.nota1 << " na nota 1 e " << aluno.nota2 << " na nota 2" << std::endl;
}