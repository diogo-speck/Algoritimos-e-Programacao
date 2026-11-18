PRAGMA foreign_keys = ON;

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




INSERT INTO area (tipo) VALUES ('Cardiologista'), ('Oftalmologia'), ('Pediatria');


INSERT INTO medico (area_id, nome, fone) VALUES 
(1, 'Beatriz', '(47) 99999-9999'),
(3, 'José', '(47) 99999-9998'), 
(1, 'Ana', '(47) 99999-9997'), 
(2, 'Gustavo', '(47) 99999-9996'), 
(1, 'Paulo', ''), 
(3, 'Carlos', NULL);



INSERT INTO paciente (nome, fone) VALUES
('Marina', '(47) 99999-9995'),
('Marcos', '(47) 99999-9994'),
('Maicon', '(47) 99999-9993'),
('Roberta', '(47) 99999-9992'),
('Joaquim', '(47) 99999-9991'),
('Bianca', NULL),
('Pedro', '');



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




UPDATE paciente
SET fone = '(47) 99845 4454' 
WHERE id IN (6, 2);


DELETE FROM consulta
WHERE id = 3;




SELECT 
    medico.id, 
    medico.nome, 
    area.tipo AS area, 
    medico.fone 
FROM medico
JOIN area ON medico.area_id = area.id;

SELECT * FROM paciente;

SELECT 
    consulta.id AS ID, 
    medico.nome AS Médico, 
    paciente.nome AS Paciente, 
    consulta.data_hora_inicio AS inicia, 
    consulta.data_hora_fim AS termina 
FROM consulta
JOIN medico ON medico.id = consulta.medico_id
JOIN paciente ON paciente.id = consulta.paciente_id;


SELECT medico.nome AS Médico, COUNT(medico_id) 'Consultas' 
FROM consulta 
JOIN medico ON medico.id = consulta.medico_id 
GROUP BY medico.nome
ORDER BY medico.nome ASC;

SELECT 
    area.tipo AS Especialidade, 
    COUNT(consulta.id) AS Consultas
FROM consulta
JOIN medico ON medico.id = consulta.medico_id
JOIN area ON area.id = medico.area_id
GROUP BY area.id, area.tipo;

SELECT 
    strftime('%d/%m/%Y', MIN(consulta.data_hora_inicio)) AS 'Data Formatada',
    TIME(MIN(consulta.data_hora_inicio)) AS 'Primeiro Horario',
    TIME(MAX(consulta.data_hora_fim)) AS 'Último Horario',
    (unixepoch(MAX(consulta.data_hora_fim)) - unixepoch(MIN(consulta.data_hora_inicio))) / 3600 AS 'Horas de Trabalho'
FROM consulta
GROUP BY DATE(consulta.data_hora_inicio)
ORDER BY consulta.data_hora_inicio ASC;

SELECT 
    medico.nome AS 'Funcionário do Mês',
    area.tipo AS Especialidade, 
    COUNT(consulta.id) AS Consultas
FROM consulta
JOIN medico ON medico.id = consulta.medico_id
JOIN area ON area.id = medico.area_id
GROUP BY medico.id, medico.nome, area.tipo
ORDER BY Consultas DESC
LIMIT 1;

SELECT 
    consulta.id AS ID, 
    medico.nome AS Médico, 
    paciente.nome AS Paciente, 
    consulta.data_hora_inicio AS Inicia, 
    consulta.data_hora_fim AS Termina 
FROM consulta
JOIN medico ON medico.id = consulta.medico_id
JOIN paciente ON paciente.id = consulta.paciente_id
WHERE consulta.data_hora_inicio >= '2026-12-08 00:00:00' AND consulta.data_hora_inicio < '2026-12-09 00:00:00'
ORDER BY consulta.data_hora_inicio ASC;

SELECT 
    id AS ID, 
    strftime('%d/%m', consulta.data_hora_inicio) AS Marcada,
    strftime('%d/%m', consulta.data_hora_fim) AS Término,
    (unixepoch(consulta.data_hora_fim)-unixepoch(consulta.data_hora_inicio))/60 AS 'Intervalo (min)'
FROM consulta
WHERE consulta.data_hora_inicio >= '2026-12-09 00:00:00' AND consulta.data_hora_inicio < '2026-12-10 00:00:00'
ORDER BY consulta.data_hora_inicio ASC;


SELECT 
    consulta.id AS id,
    paciente.nome AS 'Dr.Gustavo'
FROM consulta 
JOIN medico ON medico.id = consulta.medico_id
JOIN paciente ON paciente.id = consulta.paciente_id
WHERE medico_id = 4
ORDER BY consulta.data_hora_inicio ASC;


SELECT 
    medico.nome AS medico,
    DATE(consulta.data_hora_inicio) AS data_consulta,
    COUNT(consulta.id) AS total_consultas
FROM consulta
JOIN medico ON medico.id = consulta.medico_id
GROUP BY medico.id, medico.nome, DATE(consulta.data_hora_inicio)
ORDER BY data_consulta ASC, medico.nome ASC;


SELECT 
    consulta.id AS ID, 
    medico.nome AS Médico, 
    paciente.nome AS Paciente, 
    consulta.data_hora_inicio AS inicia, 
    consulta.data_hora_fim AS termina 
FROM consulta
JOIN medico ON medico.id = consulta.medico_id
JOIN paciente ON paciente.id = consulta.paciente_id
WHERE strftime('%H:%M', consulta.data_hora_inicio) >= '13:00'; -- TIME(consulta.data_hora_inicio) >= '13:00'


SELECT 
    consulta.id AS ID, 
    paciente.nome AS Paciente, 
    medico.nome AS Médico, 
    consulta.data_hora_inicio AS inicia, 
    consulta.data_hora_fim AS termina 
FROM consulta
JOIN medico ON medico.id = consulta.medico_id
JOIN paciente ON paciente.id = consulta.paciente_id
WHERE paciente_id = 7
ORDER BY consulta.data_hora_inicio ASC;

SELECT 
    c1.id AS id_consulta1,
    c2.id AS id_consulta2,
    p.nome AS paciente,
    m1.nome AS medico_consulta1,
    c1.data_hora_inicio AS inicio_c1,
    c1.data_hora_fim AS fim_c1,
    m2.nome AS medico_consulta2,
    c2.data_hora_inicio AS inicio_c2,
    c2.data_hora_fim AS fim_c2
FROM consulta c1
JOIN consulta c2 -- Self Join
    ON c1.paciente_id = c2.paciente_id 
   AND c1.id < c2.id -- Evita comparar a consulta com ela mesma e registros duplicados
JOIN paciente p ON p.id = c1.paciente_id
JOIN medico m1 ON m1.id = c1.medico_id
JOIN medico m2 ON m2.id = c2.medico_id
WHERE c1.paciente_id = 7
  AND c1.data_hora_inicio < c2.data_hora_fim 
  AND c1.data_hora_fim > c2.data_hora_inicio;


SELECT 
    nome,
    LENGTH(nome) AS letras 
FROM paciente
ORDER BY letras, nome ASC;


SELECT nome AS 'Médicos com P' FROM medico WHERE nome LIKE 'P%';


SELECT 
    medico.id, 
    medico.nome || ' (' || area.tipo || ') ' AS Profissionais
FROM medico
JOIN area ON medico.area_id = area.id;


UPDATE area SET tipo = '<3' WHERE tipo = 'Cardiologista';
UPDATE area SET tipo = 'O-o' WHERE tipo = 'Oftalmologia';
UPDATE area SET tipo = 'o0o' WHERE tipo = 'Pediatria';


/*
sqlite3 meu_banco.db
.read consultorio.sql
*/