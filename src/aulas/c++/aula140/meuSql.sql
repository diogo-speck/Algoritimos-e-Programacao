DROP SCHEMA IF EXISTS teste;
CREATE SCHEMA IF NOT EXISTS teste;
USE teste;


-- 1. Tabela pessoa
CREATE TABLE IF NOT EXISTS pessoa (
    id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    nome VARCHAR(100) NOT NULL,
    cpf VARCHAR(14) UNIQUE, -- Tamanho ajustado para formato com pontuação (000.000.000-00)
    data_nascimento DATE NOT NULL,
    email VARCHAR(200) UNIQUE NOT NULL,
    fone VARCHAR(25),
    profissao VARCHAR(100) DEFAULT 'Desempregado'
);

-- Inserção de registro preenchendo todos os campos NOT NULL
INSERT INTO pessoa (nome, cpf, data_nascimento, email, fone, profissao) VALUES 
('Marcelo Silva', '932.927.456-23', '1985-05-20', 'marcelo@vet.com', '12 94567 8901', 'Médico'),
('Mauro Souza', '239.456.134-85', '1997-07-18', 'mauro@vet.com', '12 91238 2901', 'Veterinário');

#UPDATE pessoa SET profissao = 'Veterinário' WHERE profissao = 'Médico';

-- 2. Tabela animal
CREATE TABLE IF NOT EXISTS animal (
    id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    id_tutor INT NOT NULL,
    apelido VARCHAR(100) NOT NULL,
    peso DECIMAL(5,2) NOT NULL,
    CONSTRAINT existe CHECK (peso > 0),
    raca VARCHAR(100),
    especie VARCHAR(100),
    cor VARCHAR(100),
    sexo CHAR(1) NOT NULL,
    idade INT NOT NULL,
    CONSTRAINT fk_animal_tutor FOREIGN KEY (id_tutor) REFERENCES pessoa(id) ON DELETE CASCADE
);

INSERT INTO animal (id_tutor, apelido, peso, raca, especie, sexo, idade) VALUES 
('1', 'Biruta', 5.5, 'Cão', 'Vira-Lata', 'M', 6),
('2', 'Zezé', 3.5, 'Gato', 'Siamês', 'F', 3);

-- 3. Tabela consulta
CREATE TABLE IF NOT EXISTS consulta (
    id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    id_vet INT NOT NULL,
    id_animal INT NOT NULL,
    CONSTRAINT fk_paciente_animal FOREIGN KEY (id_animal) REFERENCES animal(id) ON DELETE CASCADE,
    dt DATE NOT NULL,
    horario TIME NOT NULL,
    marcada_em DATETIME DEFAULT now(),
    CONSTRAINT fk_consulta_vet FOREIGN KEY (id_vet) REFERENCES pessoa(id),
    CONSTRAINT fk_consulta_animal FOREIGN KEY (id_animal) REFERENCES animal(id) ON DELETE CASCADE
);

INSERT INTO consulta (id_vet, id_animal, dt, horario) VALUES 
(2, 1, '2026-11-13', '12:30'),
(1, 2, '2026-11-14', '17:00');



SELECT * FROM pessoa;
SELECT * FROM animal;

SELECT 
    c.id AS id_consulta,
    c.dt AS data_consulta,
    c.horario,
    p.nome AS nome_veterinario,
    a.apelido AS apelido_animal,
    a.especie
FROM consulta c
INNER JOIN pessoa p ON c.id_vet = p.id
INNER JOIN animal a ON c.id_animal = a.id;