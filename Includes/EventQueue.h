#pragma once
#include "Prerrequisites.h"

// Definir un evento simple
struct Event {
	enum Type { KEY_PRESS, MOUSE_CLICK } type;
	int data;
	Event(Type t, int d) : type(t), data(d) {};
};

class EventQueue {
public:
	void pushEvent(const Event& e) { events.push(e); }

	void processEvents() {
		while (!events.empty()) {
			Event e = events.front();
			events.pop();

			// Procesar el evento actual
			switch (e.type) {
			case Event::KEY_PRESS:
				cout << "Key pressed: " << e.data << endl;
				break;
			case Event::MOUSE_CLICK:
				cout << "Mouse clicked: " << e.data << endl;
				break;
			}
		}
	}

private:
	queue<Event> events;
};