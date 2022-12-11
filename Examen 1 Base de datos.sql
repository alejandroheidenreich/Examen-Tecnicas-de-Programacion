-- A
CREATE DATABASE Transportista
GO

USE Transportista
GO

-- B
CREATE TABLE Camioneros (
	--C
	Id_Camioneros INT IDENTITY(1,1) NOT NULL PRIMARY KEY,
	Nombre VARCHAR(50),
	Direccion VARCHAR(50),
	Telefono VARCHAR(50),
	Sueldo INT
);

SELECT * FROM Camioneros

CREATE TABLE Camiones (
	--C
	Matricula INT NOT NULL PRIMARY KEY,
	Marca VARCHAR(50),
	Modelo VARCHAR(50),
	Potencia VARCHAR(50),
	Tipo VARCHAR(50)
);

SELECT * FROM Camiones

CREATE TABLE Paquete (
	--C
	Id_Paquete INT IDENTITY NOT NULL PRIMARY KEY,
	Descripcion VARCHAR(50),
	Destinatario VARCHAR(50),
	Direccion VARCHAR(50),
	Id_Camioneros INT FOREIGN KEY REFERENCES Camioneros(Id_Camioneros),
	Id_Ciudades INT FOREIGN KEY REFERENCES Ciudades(Id_Ciudades)
);

SELECT * FROM Paquete

CREATE TABLE Detalle_De_Paquetes (
	--C
	Id_Detalle_De_Paquetes INT IDENTITY(1,1) NOT NULL PRIMARY KEY,
	Id_Camioneros INT FOREIGN KEY REFERENCES Camioneros(Id_Camioneros),
	Matricula INT FOREIGN KEY REFERENCES Camiones(Matricula)
);

SELECT * FROM Detalle_De_Paquetes

CREATE TABLE Ciudades(
	--C
	Id_Ciudades INT IDENTITY(1,1) NOT NULL PRIMARY KEY,
	nombre VARCHAR(50)
);

SELECT * FROM Ciudades

--D
INSERT INTO Camiones (Matricula,Marca,Modelo,Potencia,Tipo) VALUES (666999,'SCANIA','Serie S','500hp','Camion');
INSERT INTO Camiones (Matricula,Marca,Modelo,Potencia,Tipo) VALUES (777111,'FIAT','619 N/T','300hp','Camion');
INSERT INTO Camiones (Matricula,Marca,Modelo,Potencia,Tipo) VALUES (333888,'IVECO','Tector','730hp','Camion');

INSERT INTO Camioneros(Nombre,Direccion,Telefono,Sueldo) VALUES ('DOMINGUEZ','Av. La Plata 965','4872-6231',55000);
INSERT INTO Camioneros(Nombre,Direccion,Telefono,Sueldo) VALUES ('MARTINEZ','Av. Boedo 5741','4669-9669',45000);
INSERT INTO Camioneros(Nombre,Direccion,Telefono,Sueldo) VALUES ('DOMINGUEZ','Juan Agustin Garcia 1560','4512-9783',95000);

INSERT INTO Ciudades(Nombre) VALUES ('MENDOZA');
INSERT INTO Ciudades(Nombre) VALUES ('MISIONES');
INSERT INTO Ciudades(Nombre) VALUES ('SALTA');

--E
INSERT INTO Detalle_De_Paquetes(Id_Camioneros,Matricula) VALUES (1,777111);
INSERT INTO Paquete(Descripcion,Destinatario,Direccion,Id_Camioneros,Id_Ciudades) VALUES ('XBOX','Juan Cruz','Av. Dorrego 1234',1,2);

--F
INSERT INTO Detalle_De_Paquetes(Id_Camioneros,Matricula) VALUES (2,333888);
INSERT INTO Paquete(Descripcion,Destinatario,Direccion,Id_Camioneros,Id_Ciudades) VALUES ('Heladera','Eduardo','Av. Rivadavia 333',2,1);

--G
UPDATE Camiones SET Matricula = 8795 WHERE Marca='SCANIA';

--H
SELECT SUM(Camioneros.Sueldo) FROM Camioneros

--I
SELECT Camioneros.Nombre, COUNT(Paquete.Id_Camioneros) AS Paquetes FROM Camioneros LEFT JOIN Paquete ON (Camioneros.Id_Camioneros = Paquete.Id_Camioneros) GROUP BY Camioneros.Nombre ORDER BY Paquetes

--J
DELETE Paquete WHERE Paquete.Id_Paquete=2