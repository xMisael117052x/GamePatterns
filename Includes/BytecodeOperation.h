#pragma once
#include "Prerrequisites.h"

// Interfaz para las operaciones

class BytecodeOperation {
public:
	virtual void execute() = 0;
};

// Implementacion concreta de una operacion de bytecode : Saludo
class GreetingOperation : public BytecodeOperation {
public:
	void execute() {
		cout << "Hello, it is a pleasure to meet you" << endl;
	}
};

class FarewellOperation : public BytecodeOperation {
public:
	void execute() {
		cout << "Goodbye, see you soon" << endl;
	}
};