#include <iostream>
#include <memory>

class AbstractClass {
public:
	virtual void templateMethod() final
	{
		std::cout << "Super: template method." << std::endl;

		this->abstractOperation1();
		this->abstractOperation2();
		this->hookOperation();
	}

protected:
	virtual void abstractOperation1() = 0;
	virtual void abstractOperation2() = 0;

	virtual void hookOperation()
	{
		std::cout << "Super: hook operation." << std::endl;
	}
};

class SubClass1 : public AbstractClass {
protected:
	virtual void abstractOperation1() override
	{
		std::cout << "Sub: abstract operation 1." << std::endl;
	}

	virtual void abstractOperation2() override
	{
		std::cout << "Sub: abstract operation 2." << std::endl;
	}
};

class SubClass2 : public AbstractClass {
protected:
	virtual void abstractOperation1() override
	{
		std::cout << "Sub2: abstract operation 1." << std::endl;
	}

	virtual void abstractOperation2() override
	{
		std::cout << "Sub2: abstract operation 2." << std::endl;
	}

	virtual void hookOperation()
	{
		std::cout << "Sub2: hook operation." << std::endl;
	}
};

int main()
{
	std::shared_ptr<AbstractClass> obj1 = std::make_shared<SubClass1>();
	obj1->templateMethod();

	std::shared_ptr<AbstractClass> obj2 = std::make_shared<SubClass2>();
	obj2->templateMethod();

	return 0;
}