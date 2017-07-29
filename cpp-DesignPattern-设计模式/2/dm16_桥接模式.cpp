
#include <iostream>
using namespace std;

class Engine
{
public:
	virtual void InstallEngine() = 0;
};
class Engine4400cc : public Engine
{
public:
	virtual void InstallEngine()
	{
		cout << "我是 4400cc 发动机 安装完毕 " << endl;
	}
};


class Engine4500cc : public Engine
{
public:
	virtual void InstallEngine()
	{
		cout << "我是 4500cc 发动机 安装完毕 " << endl;
	}
};


class Car
{
public:
	Car(Engine *engine)
	{
		this->m_engine = engine;
	}
	virtual void installEngine() = 0;

protected:
	Engine *m_engine;
};

class WBM5 : public Car
{
public:
	WBM5(Engine *engine) : Car(engine)
	{
		;
	}

	virtual void installEngine()
	{
		m_engine->InstallEngine();
	}
};

class WBM6 : public Car
{
public:
	WBM6(Engine *engine) : Car(engine)
	{
		;
	}

	virtual void installEngine()
	{
		cout << "我是 王保明 WBM6 " << endl;
		m_engine->InstallEngine();
	}
};

void main()
{
	//
	Engine	*engine = NULL;
	WBM6	*wbm6 = NULL;

	engine = new Engine4400cc;
	wbm6 = new WBM6(engine);
	wbm6->installEngine();

	delete wbm6;
	delete engine;
}