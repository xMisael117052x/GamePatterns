#pragma once
#include "Prerrequisites.h"


// Interfaz de comando
class Command {
public:
	virtual void ejecutar() = 0;
	virtual void deshacer() = 0;
};

// Clase receptora
class Luz {
public:
	void encender() {
		cout << "Luz encendida" << endl;
	}

	void apagar() {
		cout << "Luz apagada" << endl;
	}
};

// Comandos concreto
class ComandoEncenderLuz : public Command {
public:
	ComandoEncenderLuz(Luz& luz) : m_luz(luz) {}

	void ejecutar() override {
		m_luz.encender();
	}

	void deshacer() override {
		m_luz.apagar();
	}

private:
	Luz& m_luz;
};

class ComandoApagarLuz : public Command {
public:
	ComandoApagarLuz(Luz& luz) : m_luz(luz) {}

	void ejecutar() override {
		m_luz.apagar();
	}

	void deshacer() override {
		m_luz.encender();
	}

private:
	Luz& m_luz;
};

// Invocador
class ControlRemoto {
public:
	void presionarBoton(Command* comando) {
		comando->ejecutar();
		m_historial.push_back(comando);
	}

	void deshacer() {
		if (!m_historial.empty()) {
			m_historial.back()->deshacer();
			m_historial.pop_back();
		}
	}

private:
	vector<Command*> m_historial;
};



// Crea una clase base Operacion con funciones virtuales
// ejecutar y deshacer
class Operacion {
public:
	virtual void ejecutar() = 0;
	virtual void deshacer() = 0;
};

// Implmenta clases dereivadas como Suma, Resta,
// Multiplicacion y Division que hereden de operacion
class Suma : public Operacion {

public:
	Suma(int a, int b) : m_a(a), m_b(b) {}

	void ejecutar() override {
		cout << "Suma: " << m_a + m_b << endl;
	}

	void deshacer() override {
		cout << "Resta: " << m_a - m_b << endl;
	}

private:
	int m_a, m_b;
};

class Resta : public Operacion {

public:
	Resta(int a, int b) : m_a(a), m_b(b) {}

	void ejecutar() override {
		cout << "Resta: " << m_a - m_b << endl;
	}

	void deshacer() override {
		cout << "Suma: " << m_a + m_b << endl;
	}

private:
	int m_a, m_b;
};

class Multiplicacion : public Operacion {

public:
	Multiplicacion(int a, int b) : m_a(a), m_b(b) {}

	void ejecutar() override {
		cout << "Multiplicacion: " << m_a * m_b << endl;
	}

	void deshacer() override {
		cout << "Division: " << m_a / m_b << endl;
	}

private:
	int m_a, m_b;
};

class Division : public Operacion {

public:
	Division(int a, int b) : m_a(a), m_b(b) {}

	void ejecutar() override {
		cout << "Division: " << m_a / m_b << endl;
	}

	void deshacer() override {
		cout << "Multiplicacion: " << m_a * m_b << endl;
	}

private:
	int m_a, m_b;
};

// Crear una clase calculadora que tenga un puntero a operacion 
// y funciones para realizar operaciones y deshacerlas

class Calculadora {

public:
	void realizarOperacion(Operacion* operacion) {
		operacion->ejecutar();
		m_historial.push_back(operacion);
	}

	void deshacerOperacion() {
		if (!m_historial.empty()) {
			m_historial.back()->deshacer();
			m_historial.pop_back();
		}
	}

	void reahacerOperacion() {
		if (!m_historial.empty()) {
			m_historial.back()->ejecutar();
			m_historial.pop_back();
		}
	}

private:
	vector<Operacion*> m_historial;
};