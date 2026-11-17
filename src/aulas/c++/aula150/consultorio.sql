PRAGMA foreign_keys = ON;

CREATE TABLE IF NOT EXISTS area (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    tipo VARCHAR(50) NOT NULL
);

CREATE TABLE IF NOT EXISTS medico (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    especialidade_id INTEGER NOT NULL,
    nome VARCHAR(100) NOT NULL,
    fone VARCHAR(20),
    FOREIGN KEY (especialidade_id) REFERENCES area (id)
);

CREATE TABLE IF NOT EXISTS paciente (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome VARCHAR(100) NOT NULL,
    fone VARCHAR(20)
);

CREATE TABLE IF NOT EXISTS consulta (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    medico_id INTEGER NOT NULL,
    paciente_id INTEGER NOT NULL,
    data_hora_inicio TEXT,  -- formato ISO8601
    data_hora_fim TEXT,
    FOREIGN KEY (medico_id) REFERENCES medico (id),
    FOREIGN KEY (paciente_id) REFERENCES paciente (id)
);
