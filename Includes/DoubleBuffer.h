#pragma once
#include "Prerrequisites.h"


class DoubleBuffer {
public:
	DoubleBuffer() : buffer1(10), buffer2(10), activeBuffer(&buffer1) {}

	//Simular la actualiacion en el buffer activo
	void updateData() {
		for (int i = 0; i < activeBuffer->size(); i++) {
			//Actualizar los datos
			(*activeBuffer)[i] = i * 2;
		}
	}

	void swapBuffers() {
		activeBuffer = (activeBuffer == &buffer1) ? &buffer2 : &buffer1;
	}

	void printActive() {
		cout << "Datos en el buffer activo: " << endl;
		for (int val : *activeBuffer) {
			cout << val << " ";
		}
		cout << endl;
	}
private:
	vector<int> buffer1;
	vector<int> buffer2;
	vector<int>* activeBuffer;

};

//Practica de Double Buffer
class GameObject {
public:
	string  name;
	int posX;
	int posY;

public:
	GameObject(const string& name, int posX, int posY)
		: name(name), posX(posX), posY(posY) {}

	void UpdatePosition(int newX, int newY) {
		posX = newX;
		posY = newY;
	}

	void PrintInfo() const {
		cout << "Objeto: " << name << " | Posicion: (" << posX << ", " << posY << ")\n";
	}
};

class Game {
public:
	Game() : buffer1(), buffer2(), activeBuffer(&buffer1) {}

	void addGameObject(const GameObject& obj) {
		activeBuffer->push_back(obj);
	}

	void initializeBuffer() {
		buffer1.push_back(GameObject("Player", 10, 10));
		buffer1.push_back(GameObject("Enemy", 20, 20));
	}

	void updateGameObject() {
		//Simulacion de actualizacion de objetos en el buffer activo
		for (auto& obj : *activeBuffer) {
			obj.UpdatePosition(obj.posX + 1, obj.posY + 1);
		}
	}
	void swapBuffers() {
		activeBuffer = (activeBuffer == &buffer1) ? &buffer2 : &buffer1;
	}
	void printActiveObjects() const {
		cout << "Objetos en el buffer activo: " << endl;
		for (const auto& obj : *activeBuffer) {
			obj.PrintInfo();
		}
		cout << endl;
	}
private:
	vector<GameObject> buffer1;
	vector<GameObject> buffer2;
	vector<GameObject>* activeBuffer;
};

