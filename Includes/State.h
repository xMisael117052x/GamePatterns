#pragma once
#include "Prerrequisites.h"



// Clase base
class EstadoPersonaje {
public:
	virtual void atacar() = 0;
	virtual void moverse() = 0;
};

class EstadoNormal : public EstadoPersonaje {
public:
	void atacar() override {
		cout << "Ataque normal" << endl;
	}

	void moverse() override {
		cout << "Movimiento normal" << endl;
	}
};

class EstadoHerido : public EstadoPersonaje {
public:
	void atacar() override {
		cout << "Ataque mas fuerza" << endl;
	}

	void moverse() override {
		cout << "Movimiento mas lento" << endl;
	}
};

class EstadoEnfurecido : public EstadoPersonaje {
public:
	void atacar() override {
		cout << "Ataque con furia" << endl;
	}

	void moverse() override {
		cout << "Movimiento mas rapido" << endl;
	}
};

class Personaje {
public:
	Personaje() : estado(new EstadoNormal()) {}

	void setEstado(EstadoPersonaje* nuevoEstado) {
		estado = nuevoEstado;
	}

	void atacar() {
		estado->atacar();
	}

	void moverse() {
		estado->moverse();
	}

private:
	EstadoPersonaje* estado;
};


class EstadoVehiculo {
public:
	virtual void acelerar() = 0;
	virtual void frenar() = 0;
};

class EstadoVelocidadNormal : public EstadoVehiculo {
public:
	void acelerar() override {
		cout << "Acelerando normal" << endl;
	}

	void frenar() override {
		cout << "Frenando normal" << endl;
	}
};

class EstadoVelocidadReducido : public EstadoVehiculo {
public:
	void acelerar() override {
		cout << "Acelerando reducido" << endl;
	}

	void frenar() override {
		cout << "Frenando reducido" << endl;
	}
};

class Vehiculo {
public:
	Vehiculo() : estado(new EstadoVelocidadNormal()) {}

	void setEstado(EstadoVehiculo* nuevoEstado) {
		estado = nuevoEstado;
	}

	void acelerar() {
		estado->acelerar();
	}

	void frenar() {
		estado->frenar();
	}

private:
	EstadoVehiculo* estado;
};
