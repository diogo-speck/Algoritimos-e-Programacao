PRAGMA foreign_keys = ON;

--DROP TABLE IF EXISTS consulta;

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

/*
INSERT INTO paciente (nome, fone) VALUES
('Marina', '(47) 99999-9995'),
('Marcos', '(47) 99999-9994'),
('Maicon', '(47) 99999-9993'),
('Roberta', '(47) 99999-9992'),
('Joaquim', '(47) 99999-9991'),
('Bianca', NULL),
('Pedro', '');
*/

/*
INSERT INTO consulta (medico_id, paciente_id, data_hora_inicio, data_hora_fim) VALUES
(1, 4, '2026-12-08 10:00:00', '2026-12-08 11:30:00'),
(1, 5, '2026-12-08 11:30:00', '2026-12-08 12:00:00'),
(1, 6, '2026-12-08 13:30:00', '2026-12-08 14:30:00'),

(2, 2, '2026-12-08 08:00:00', '2026-12-08 10:00:00'),
(2, 3, '2026-12-08 10:00:00', '2026-12-08 11:00:00'),
(2, 1, '2026-12-08 11:00:00', '2026-12-08 12:00:00'),


(5, 7, '2026-12-09 08:30:00', '2026-12-09 09:00:00'),

(4, 7, '2026-12-09 09:00:00', '2026-12-09 10:00:00'),
(4, 5, '2026-12-09 11:00:00', '2026-12-09 12:00:00'),
(4, 6, '2026-12-09 13:30:00', '2026-12-09 14:30:00'),
(4, 2, '2026-12-09 14:30:00', '2026-12-09 15:00:00');
*/




SELECT 
    medico.id, 
    medico.nome, 
    area.tipo AS area, 
    medico.fone 
FROM medico
JOIN area ON medico.area_id = area.id;

SELECT * FROM paciente;

SELECT 
    consulta.id, 
    medico.nome AS medico, 
    paciente.nome AS paciente, 
    consulta.data_hora_inicio, 
    consulta.data_hora_fim 
FROM consulta
JOIN medico ON medico.id = consulta.medico_id
JOIN paciente ON paciente.id = consulta.paciente_id;




/*
sqlite3 meu_banco.db
.read consultorio.sql
*/