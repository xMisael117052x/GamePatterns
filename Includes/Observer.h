#pragma once
#include "Prerrequisites.h"



// Clase base
class Observer {
public:
	virtual void update(int temperature) = 0;
};

// Clase Sujeto
class TemperatureSensor {
public:
	void addObserver(Observer* observer) {
		observers.push_back(observer);
	}

	void notifyObservers() {
		for (Observer* observer : observers) {
			observer->update(temperature);
		}
	}

	void setTemperature(int temp) {
		temperature = temp;
		notifyObservers();
	}

private:
	int temperature;
	vector<Observer*> observers;
};

// Classe Observer concreta
class DisplayDevice : public Observer {
public:
	void update(int temperature) {
		cout << "Temperature: " << temperature << endl;
	}
};



// Clase base
class MessageObserver {
public:
	virtual void notify(string message) = 0;
};

// Clase Sujeto
class MessageService {
public:
	void addObserver(MessageObserver* observer) {
		observers.push_back(observer);
	}

	void notifyObservers() {
		for (MessageObserver* observer : observers) {
			observer->notify(message);
		}
	}

	void setMessage(string msg) {
		message = msg;
		notifyObservers();
	}

private:
	string message;
	vector<MessageObserver*> observers;
};

// Classe Observer concreta
class SoundNotification : public MessageObserver {
public:
	void notify(string message) {
		cout << "Sonido: " << message << endl;
	}
};

class VibrationNotification : public MessageObserver {
public:
	void notify(string message) {
		cout << "Vibracion: " << message << endl;
	}
};

class ScreenNotification : public MessageObserver {
public:
	void notify(string message) {
		cout << "Pantalla: " << message << endl;
	}
};