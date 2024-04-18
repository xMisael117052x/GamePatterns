#pragma once
#include "Prerrequisites.h"

enum Bytecode {
	JUMP = 1,
	ATTACK = 2,
	BLOCK = 3,
	SPECIAL = 4
};

// Clase que interpreta el bytecode
class BytecodeInterpreter {
public:
	void interpret(Bytecode bytecode) {
		switch (bytecode) {
		case JUMP:
			cout << "Jump!" << endl;
			break;
		case ATTACK:
			cout << "Attack!" << endl;
			break;
		case BLOCK:
			cout << "Block!" << endl;
			break;
		case SPECIAL:
			cout << "Special!" << endl;
			break;
		default: 
			cout << "Invalid bytecode" << endl;
		}
	}
};