#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db = nullptr;
    sqlite3_stmt* stmt = nullptr;

    // 1. Conectar ao banco
    int rc = sqlite3_open("meu_banco.db", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao conectar: "
                  << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return 1;
    }

    std::cout << "Conectado ao SQLite!\n";

    // 2. Criar tabela
    const char* criarTabela =
        "CREATE TABLE IF NOT EXISTS clientes ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "nome TEXT NOT NULL"
        ");";

    rc = sqlite3_exec(db, criarTabela, nullptr, nullptr, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao criar tabela: "
                  << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return 1;
    }

    // 3. Inserir cliente
    const char* inserir =
        "INSERT INTO clientes (nome) VALUES (?);";

    rc = sqlite3_prepare_v2(db, inserir, -1, &stmt, nullptr);

    if (rc == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, "Novo Cliente",
                          -1, SQLITE_TRANSIENT);

        rc = sqlite3_step(stmt);

        if (rc != SQLITE_DONE) {
            std::cerr << "Erro ao inserir: "
                      << sqlite3_errmsg(db) << '\n';
        } else {
            std::cout << "Cliente inserido!\n";
        }
    }

    sqlite3_finalize(stmt);
    stmt = nullptr;

    // 4. Consultar clientes
    const char* consultar =
        "SELECT id, nome FROM clientes;";

    rc = sqlite3_prepare_v2(db, consultar, -1, &stmt, nullptr);

    if (rc == SQLITE_OK) {
        while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);

            const unsigned char* nome =
                sqlite3_column_text(stmt, 1);

            std::cout << "ID: " << id
                      << " | Nome: " << nome << '\n';
        }
    }

    sqlite3_finalize(stmt);

    // 5. Encerrar conexão
    sqlite3_close(db);

    std::cout << "\nConexao encerrada!\n";

    return 0;
}
