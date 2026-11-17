PRAGMA foreign_keys = ON;

--DROP TABLE IF EXISTS medico;

CREATE TABLE IF NOT EXISTS area (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    tipo VARCHAR(50) NOT NULL
);

CREATE TABLE IF NOT EXISTS medico (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    area_id INTEGER NOT NULL,
    nome VARCHAR(100) NOT NULL,
    fone VARCHAR(20),
    FOREIGN KEY (area_id) REFERENCES area (id)
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


--INSERT INTO area (tipo) VALUES ('Cardiologista'), ('Oftalmologia'), ('Pediatria');

/*
INSERT INTO medico (area_id, nome, fone) VALUES 
(1, 'Beatriz', '(47) 99999-9999'),
(3, 'José', '(47) 99999-9998'), 
(1, 'Ana', '(47) 99999-9997'), 
(2, 'Gustavo', '(47) 99999-9996'), 
(1, 'Paulo', ''), 
(3, 'Carlos', NULL);
*/

SELECT 
    medico.id, 
    medico.nome, 
    area.tipo AS area, 
    medico.fone 
FROM medico
JOIN area ON medico.area_id = area.id;

/*
sqlite3 meu_banco.db
.read consultorio.sql
*/