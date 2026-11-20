#include <iostream>
#include <mysql.h>

using namespace std;

int main() {
    MYSQL *conexao = mysql_init(nullptr);
    if (conexao == nullptr) {
        cout << "Erro ao inicializar o conector." << endl;
        return 1;
    }

    // Desativa a exigência/verificação de certificado no MariaDB Connector/C
    my_bool ssl_verify = 0;
    mysql_options(conexao, MYSQL_OPT_SSL_VERIFY_SERVER_CERT, &ssl_verify);

    // Conecta especificando o banco de dados "coisas"
    if (!mysql_real_connect(conexao, "127.0.0.1", "root", "", "coisas", 3306, nullptr, 0)) {
        cout << "Erro de Conexao: " << mysql_error(conexao) << endl;
        mysql_close(conexao);
        return 1;
    }

    cout << "Conexao realizada com sucesso!" << endl;
    
    // Executa a consulta SELECT
    if (mysql_query(conexao, "SELECT * FROM objetos") != 0) {
        cout << "Erro ao consultar: " << mysql_error(conexao) << endl;
    } else {
        // Armazena o resultado retornado do banco
        MYSQL_RES *resultado = mysql_store_result(conexao);
        if (resultado != nullptr) {
            MYSQL_ROW linha;
            // Percorre todas as linhas retornadas
            while ((linha = mysql_fetch_row(resultado)) != nullptr) {
                // Imprime a primeira coluna (id)
                cout << "ID: " << linha[0] << endl;
            }
            // Libera a memória ocupada pelo resultado
            mysql_free_result(resultado);
        }
    }
    
    mysql_close(conexao);
    return 0;
}


// C:\Users\8640416\Downloads\msys2-base-x86_64-latest\msys64\ucrt64\bin\g++.exe main.cpp -o teste.exe -I"C:\Users\8640416\Downloads\msys2-base-x86_64-latest\msys64\ucrt64\include\mysql" -L"C:\Users\8640416\Downloads\msys2-base-x86_64-latest\msys64\ucrt64\lib" -lmariadb