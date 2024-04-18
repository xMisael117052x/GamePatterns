#pragma once
#include "Prerrequisites.h"

// Clase que representa la parte compartida del objeto
class FlyWeight {
public:
	virtual void draw(int x, int y) = 0;
};

// Clase concreta que representa el objeto que se comparte
class ConcreteFlyWeight : public FlyWeight {
public:
	ConcreteFlyWeight(char _symbol) : m_symbol(_symbol) {}

	void draw(int x, int y) override {
		cout << m_symbol << " drawn at " << x << ", " << y << endl;
	}

private:
	char m_symbol;
};

// Fabrica que gestionara la creacion de recursos
class FlyWeightFactory {
public:
	FlyWeight* getFlyWeight(char _symbol) {
		if (m_flyweights.find(_symbol) == m_flyweights.end()) {
			m_flyweights[_symbol] = new ConcreteFlyWeight(_symbol);
		}

		return m_flyweights[_symbol];
	}

private:
	unordered_map<char, FlyWeight*> m_flyweights;
};