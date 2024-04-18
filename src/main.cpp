#include "Prerrequisites.h"
#include <Command.h>
#include <FlyWeight.h>
#include <Observer.h>
#include <State.h>
#include <Bytecode.h>
#include <BytecodeOperation.h>
#include <Component.h>
#include <EventQueue.h>
#include <DoubleBuffer.h>

int main() {

    // COMAND
	Luz miLuz;
	ComandoEncenderLuz encenderLuz(miLuz);
	ComandoApagarLuz apagarLuz(miLuz);

	ControlRemoto control;
	control.presionarBoton(&encenderLuz);
	control.presionarBoton(&apagarLuz);
	control.deshacer();



	// Crear un objeto de la clase que realiza la operación
	Suma suma(5, 3);
	Resta resta(5, 3);
	Multiplicacion multiplicacion(5, 3);
	Division division(5, 3);

	// Crear un objeto de la clase que invoca la calculadora
	Calculadora calculadora;

	// Suma
	calculadora.realizarOperacion(&suma);
	calculadora.deshacerOperacion();

	// Resta
	calculadora.realizarOperacion(&resta);
	calculadora.deshacerOperacion();

	// Multiplicacion
	calculadora.realizarOperacion(&multiplicacion);
	calculadora.deshacerOperacion();

	// Division
	calculadora.realizarOperacion(&division);
	calculadora.deshacerOperacion();
	calculadora.reahacerOperacion();


	// FLYWEIGHT

	FlyWeightFactory factory;

	// Crear instancias compartidas de FlyWeights
	FlyWeight* a = factory.getFlyWeight('A');
	FlyWeight* b = factory.getFlyWeight('B');
	FlyWeight* c = factory.getFlyWeight('C');
	FlyWeight* d = factory.getFlyWeight('D');

	// Utilizar las instancias compartidas
	a->draw(1, 1);
	b->draw(2, 2);
	c->draw(3, 3);
	d->draw(4, 4);

	// Liberar memoria
	delete a;
	delete b;
	delete c;
	delete d;


	// OBSERVER

	TemperatureSensor sensor;
	DisplayDevice display;

	sensor.addObserver(&display);

	// Simular cambios en la temperatura
	sensor.setTemperature(25);
	sensor.setTemperature(30);
	sensor.setTemperature(35);

	// ACTIVIDAD OBSERVER

	MessageService messageService;
	SoundNotification soundNotification;
	VibrationNotification vibrationNotification;
	ScreenNotification screenNotification;

	messageService.addObserver(&soundNotification);
	messageService.addObserver(&vibrationNotification);
	messageService.addObserver(&screenNotification);

	// Simular recepcion de un nuevo mensaje
	messageService.setMessage("Nuevo mensaje");


	// STATE

	Personaje personaje;
	personaje.atacar();
	personaje.moverse();

	personaje.setEstado(new EstadoHerido());
	personaje.atacar();
	personaje.moverse();


	// ACTIVIDAD STATE

	Vehiculo vehiculo;

	vehiculo.acelerar();

	vehiculo.setEstado(new EstadoVelocidadReducido());
	vehiculo.acelerar();
	vehiculo.frenar();


	// BYTECODE

	BytecodeInterpreter interpreter;
	vector<Bytecode> bytecode = { JUMP, ATTACK, BLOCK, SPECIAL };

	for (Bytecode bc : bytecode) {
		interpreter.interpret(bc);
	}


	// BYTECODE OPERATION

	unique_ptr<BytecodeOperation> operation = make_unique<GreetingOperation>();
	unique_ptr<BytecodeOperation> operation2 = make_unique<FarewellOperation>();

	operation->execute();
	operation2->execute();


	// COMPONENT

	Entity player;
	player.addComponent(new RenderComponent());
	player.addComponent(new PhysicsComponent());
	player.addComponent(new IAComponent());

	player.initComponent();
	player.updateComponent();
	player.renderComponent();
	player.destroyComponent();


	// EVENT QUEUE

	EventQueue eventQueue;

	eventQueue.pushEvent(Event(Event::KEY_PRESS, 'H'));
	eventQueue.pushEvent(Event(Event::KEY_PRESS, 'F'));
	eventQueue.pushEvent(Event(Event::KEY_PRESS, 'G'));
	eventQueue.pushEvent(Event(Event::KEY_PRESS, 'I'));

	eventQueue.pushEvent(Event(Event::MOUSE_CLICK, 01));
	eventQueue.pushEvent(Event(Event::MOUSE_CLICK, 02));

	eventQueue.processEvents();


	// DOUBLE BUFFER

	DoubleBuffer db;
	db.updateData();
	db.printActive();
	db.swapBuffers();
	db.updateData();
	db.printActive();
	return 0;


	// ACTIVIDAD DOUBLE BUFFER

	Game game;
	game.initializeBuffer();
	game.updateGameObject();
	cout << "Objetos en el buffer No1 " << endl;
	game.printActiveObjects();
	game.updateGameObject();
	cout << "Objetos en el buffer No1 actualizados " << endl;
	game.printActiveObjects();
	game.swapBuffers();
	game.updateGameObject();
	cout << "Objetos en el buffer No2 actualizados " << endl;
	game.printActiveObjects();
}