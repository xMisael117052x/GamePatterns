#pragma once
#include "Prerrequisites.h"

class Component
{
public:
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void destroy() = 0;
	virtual ~Component() {};
};

class RenderComponent : public Component
{
public:
	void init() override {
		cout << "Se inicializa el render" << endl;
	}

	void update() override {

	}

	void render() override {
		cout << "Se actualiza la posicion de la maya" << endl;
	}

	void destroy() override {

	}
};

class PhysicsComponent : public Component
{
public:
	void init() override {
		cout << "Se inicializa el componente de fisica" << endl;
	}

	void update() override {
		cout << "Se actualiza el proceso matematico" << endl;
	}

	void render() override {
		cout << "Se actualiza la fisica del objeto" << endl;
	}

	void destroy() override {

	}
};

class IAComponent : public Component
{
public:
	void init() override {
		cout << "Se inicializa el componente de IA" << endl;
	}

	void update() override {
		cout << "Se actualiza el proceso de IA" << endl;
	}

	void render() override {
		cout << "Se actualiza la IA del objeto" << endl;
	}

	void destroy() override {

	}
};

class Entity
{
public:
	void addComponent(Component* component)
	{
		components.push_back(component);
	}

	void initComponent()
	{
		for (auto component : components)
		{
			component->init();
		}
	}

	void updateComponent()
	{
		for (auto component : components)
		{
			component->update();
		}
	}

	void renderComponent()
	{
		for (auto component : components)
		{
			component->render();
		}
	}

	void destroyComponent()
	{
		for (auto component : components)
		{
			component->destroy();
		}
	}

private:
	vector<Component*> components;
};