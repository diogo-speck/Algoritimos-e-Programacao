# SQLite C++

Projeto de estudo e experimentação da biblioteca SQLite utilizando C++ e a API oficial em C.

O objetivo é demonstrar como integrar SQLite em aplicações C++, incluindo conexão com banco de dados, criação de tabelas, inserção e consulta de registros.

A implementação utiliza a distribuição oficial **SQLite Amalgamation**, incorporada ao projeto, e o **CMake** para garantir uma compilação independente de sistema operacional e IDE.

## Características

- C++17.
- SQLite oficial por meio da API C.
- CMake como sistema de build.
- Compilação multiplataforma.
- Compatibilidade planejada com Windows, Linux e macOS.
- Não exige instalação externa do SQLite.
- Código-fonte disponível para compilação local.

## Estrutura do projeto

```text
sqlite-cpp/
├── include/
│   └── sqlite3.h
├── lib/
│   └── sqlite3.c
├── src/
│   └── main.cpp
├── databases/
├── CMakeLists.txt
├── README.md
└── .gitignore
```

| Diretório/arquivo | Descrição |
|---|---|
| `include/` | Cabeçalhos da biblioteca SQLite |
| `lib/` | Implementação da biblioteca SQLite |
| `src/` | Código-fonte da aplicação C++ |
| `databases/` | Bancos de dados utilizados nos exemplos |
| `CMakeLists.txt` | Configuração de compilação |
| `.gitignore` | Arquivos e diretórios ignorados pelo Git |

Os bancos de dados gerados durante os testes são locais e não fazem parte do versionamento.

---

# 1. Requisitos

O projeto utiliza ferramentas de compilação convencionais. Não é necessário instalar SQLite separadamente.

| Ferramenta | Finalidade |
|---|---|
| Git | Obter o código-fonte |
| CMake 3.16 ou superior | Configurar a compilação |
| Compilador C | Compilar a implementação SQLite |
| Compilador C++17 | Compilar a aplicação |

Compiladores compatíveis:

| Sistema operacional | Compilador recomendado |
|---|---|
| Windows | Microsoft Visual C++ (MSVC) |
| Linux | GCC ou Clang |
| macOS | Clang |

Uma IDE não é obrigatória. A compilação pode ser realizada diretamente pelo terminal.

---

# 2. Obtendo o projeto

Existem duas maneiras principais de obter os arquivos.

## Opção A — Clonar o repositório

O projeto está localizado dentro do repositório:

[Algoritimos-e-Programacao](https://github.com/diogo-speck/Algoritimos-e-Programacao)

A implementação está na branch `sql`, dentro da pasta `sqlite-cpp`.

Para clonar somente essa branch:

```bash
git clone --single-branch --branch sql https://github.com/diogo-speck/Algoritimos-e-Programacao.git
```

Entre no diretório do projeto:

```bash
cd Algoritimos-e-Programacao/sqlite-cpp
```

O código-fonte estará pronto para configuração e compilação.

## Opção B — Baixar uma Release

Também é possível obter o projeto sem utilizar Git.

Acesse a página de releases:

[GitHub Releases](https://github.com/diogo-speck/Algoritimos-e-Programacao/releases)

1. Localize a versão desejada.
2. Baixe o arquivo disponibilizado na release ou a opção `Source code (zip)`.
3. Extraia o arquivo.
4. Localize a pasta `sqlite-cpp`.
5. Abra um terminal nessa pasta.

**Observação:** o arquivo `Source code (zip)` gerado automaticamente pelo GitHub contém o repositório da versão publicada, não somente a pasta `sqlite-cpp`. Caso uma release disponibilize um pacote específico do projeto, prefira esse pacote.

Se ainda não houver uma release publicada, utilize a opção de clonagem ou o download do código-fonte da branch `sql`.

---

# 3. Windows — Compilação com MSVC

O Windows utiliza o compilador Microsoft Visual C++ (MSVC), disponibilizado pelo Visual Studio ou pelo Visual Studio Build Tools.

Não é necessário instalar a IDE completa do Visual Studio.

## 3.1. Instalar o Visual Studio Build Tools

Acesse:

[Visual Studio Downloads](https://visualstudio.microsoft.com/pt-br/downloads/)

Localize a opção **Build Tools for Visual Studio** e faça o download.

Durante a instalação:

1. Selecione a carga de trabalho **Desenvolvimento para desktop com C++** (*Desktop development with C++*).
2. Verifique se os seguintes componentes estão selecionados:
   - MSVC C++ Build Tools (x64/x86).
   - Windows SDK.
   - Ferramentas do C++.
   - CMake tools for Windows, caso disponível como componente opcional.
3. Conclua a instalação.

O MSVC será responsável pela compilação do código C e C++.

## 3.2. Instalar o CMake

Acesse:

[CMake — Download](https://cmake.org/download/)

Baixe o instalador para Windows.

Durante a instalação, recomenda-se selecionar a opção de adicionar o CMake ao `PATH` do sistema.

Isso permite executar `cmake` diretamente pelo terminal.

Após a instalação, abra um novo terminal e verifique:

```powershell
cmake --version
```

## 3.3. Abrir o terminal correto

Para utilizar o MSVC, abra o:

**Developer PowerShell for VS**

Ele é disponibilizado pela instalação do Visual Studio Build Tools.

Esse terminal configura automaticamente as variáveis necessárias para localizar o compilador Microsoft.

Verifique:

```powershell
cl
```

Se o compilador estiver disponível, será exibida uma mensagem de identificação do Microsoft C/C++ Compiler.

Verifique também:

```powershell
cmake --version
```

## 3.4. Clonar o projeto

No Developer PowerShell:

```powershell
git clone --single-branch --branch sql https://github.com/diogo-speck/Algoritimos-e-Programacao.git
```

Entre na pasta:

```powershell
cd Algoritimos-e-Programacao\sqlite-cpp
```

Caso tenha baixado uma release, basta abrir o terminal na pasta extraída `sqlite-cpp`.

## 3.5. Configurar a compilação

Execute:

```powershell
cmake -S . -B build
```

O CMake detectará automaticamente o compilador MSVC e configurará o ambiente de compilação.

Não é necessário informar manualmente o caminho do compilador.

## 3.6. Compilar em Release

Execute:

```powershell
cmake --build build --config Release --parallel
```

Os arquivos compilados serão gerados no diretório `build`.

Com o gerador padrão do Visual Studio, o executável estará em:

```text
build/
└── Release/
    └── sqlite_test.exe
```

## 3.7. Executar

No PowerShell:

```powershell
.\build\Release\sqlite_test.exe
```

O programa criará automaticamente a pasta `databases`, caso ela ainda não exista, e utilizará o arquivo `meu_banco.db`.

---

# 4. Linux — Compilação com GCC ou Clang

Em distribuições Linux, é necessário ter um compilador C/C++, CMake e as ferramentas básicas de build.

## 4.1. Instalar as dependências

Em distribuições baseadas em Debian ou Ubuntu, como Ubuntu, Linux Mint e Debian:

```bash
sudo apt update
sudo apt install build-essential cmake
```

O pacote `build-essential` disponibiliza ferramentas como GCC, G++ e Make.

Para verificar a instalação:

```bash
gcc --version
g++ --version
cmake --version
```

## 4.2. Clonar o projeto

```bash
git clone --single-branch --branch sql https://github.com/diogo-speck/Algoritimos-e-Programacao.git
```

Entre no diretório:

```bash
cd Algoritimos-e-Programacao/sqlite-cpp
```

## 4.3. Configurar e compilar

Configure o projeto no modo Release:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
```

Compile:

```bash
cmake --build build --parallel
```

## 4.4. Executar

```bash
./build/sqlite_test
```

O banco de dados será criado em `databases/meu_banco.db`.

---

# 5. macOS — Compilação com Clang

No macOS, o compilador Clang é disponibilizado pelas ferramentas de desenvolvimento da Apple.

## 5.1. Instalar as ferramentas de desenvolvimento

Abra o Terminal e execute:

```bash
xcode-select --install
```

Isso instala as ferramentas de linha de comando do Xcode, incluindo o compilador Clang.

Verifique:

```bash
clang --version
clang++ --version
```

## 5.2. Instalar o CMake

Uma das opções é utilizar o Homebrew:

[Homebrew](https://brew.sh/)

Depois de instalar o Homebrew:

```bash
brew install cmake
```

Verifique:

```bash
cmake --version
```

## 5.3. Clonar o projeto

```bash
git clone --single-branch --branch sql https://github.com/diogo-speck/Algoritimos-e-Programacao.git
```

Entre na pasta:

```bash
cd Algoritimos-e-Programacao/sqlite-cpp
```

## 5.4. Configurar e compilar

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
```

## 5.5. Executar

```bash
./build/sqlite_test
```

---

# 6. Resultado esperado

Ao executar a aplicação pela primeira vez, a saída será semelhante a:

```text
Conectado ao SQLite!
Tabela criada/verificada!
Cliente inserido! ID: 1

Clientes cadastrados:
ID: 1 | Nome: Novo Cliente

Conexao encerrada!
```

A cada execução, um novo registro será inserido.

Exemplo de uma segunda execução:

```text
Conectado ao SQLite!
Tabela criada/verificada!
Cliente inserido! ID: 2

Clientes cadastrados:
ID: 1 | Nome: Novo Cliente
ID: 2 | Nome: Novo Cliente

Conexao encerrada!
```

Isso acontece porque o arquivo do banco de dados é persistente. Os registros anteriores continuam armazenados entre as execuções.

Para iniciar novamente do zero, feche o programa e exclua:

```text
databases/meu_banco.db
```

Na próxima execução, o banco e a tabela serão criados novamente.

---

# 7. Utilizando outra IDE

O projeto não depende de uma IDE específica.

É possível utilizar:

- Visual Studio.
- Visual Studio Code.
- VSCodium.
- CLion.
- Qt Creator.
- Outros editores e ambientes compatíveis com CMake.

O requisito principal é que o ambiente consiga executar o CMake e disponibilize um compilador C e C++ compatível.

A compilação também pode ser feita exclusivamente pelo terminal.

---

# 8. Solução de problemas

## CMake não encontrado

Mensagem:

```text
cmake: command not found
```

ou:

```text
'cmake' is not recognized as an internal or external command
```

Verifique