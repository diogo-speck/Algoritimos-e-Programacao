#include <filesystem>
#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db = nullptr;
    sqlite3_stmt* stmt = nullptr;

    // 1. Abrir conexão
    std::filesystem::create_directories("databases");

    int rc = sqlite3_open("databases/meu_banco.db", &db);

    
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

    std::cout << "Tabela criada/verificada!\n";

    // 3. Inserir registro
    const char* inserir =
        "INSERT INTO clientes (nome) VALUES (?);";

    rc = sqlite3_prepare_v2(db, inserir, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao preparar INSERT: "
                  << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return 1;
    }

    sqlite3_bind_text(stmt, 1, "Novo Cliente", -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);

    if (rc == SQLITE_DONE) {
        std::cout << "Cliente inserido! ID: "
                  << sqlite3_last_insert_rowid(db) << '\n';
    } else {
        std::cerr << "Erro ao inserir: "
                  << sqlite3_errmsg(db) << '\n';
    }

    sqlite3_finalize(stmt);
    stmt = nullptr;

    // 4. Consultar registros
    const char* consultar =
        "SELECT id, nome FROM clientes;";

    rc = sqlite3_prepare_v2(db, consultar, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao preparar SELECT: "
                  << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return 1;
    }

    std::cout << "\nClientes cadastrados:\n";

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);

        const unsigned char* nome =
            sqlite3_column_text(stmt, 1);

        std::cout << "ID: " << id
                  << " | Nome: " << nome << '\n';
    }

    if (rc != SQLITE_DONE) {
        std::cerr << "Erro ao consultar: "
                  << sqlite3_errmsg(db) << '\n';
    }

    sqlite3_finalize(stmt);

    // 5. Fechar conexão
    sqlite3_close(db);

    std::cout << "\nConexao encerrada!\n";

    return 0;
}
