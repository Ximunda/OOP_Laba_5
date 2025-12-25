#include <iostream>
#include<windows.h>

class Base_NotVirtual {
public:
	void mtd1() {
		std::cout << "Base_NotVirtual - mtd1\n";
		mtd2();
	}
	void mtd2() {
		std::cout << "Base_NotVirtual - mtd2\n";
	}
	virtual ~Base_NotVirtual() {
		std::cout << "Base_NotVirtual - Деструктор\n";
	}
};

class Derived_NotVirtual : public Base_NotVirtual {
public:
	void mtd2() {
		std::cout << "Derived_NotVirtual - mtd2\n";
	}
	~Derived_NotVirtual() {
		std::cout << "Derived_NotVirtual - Деструктор\n";
	}
};

class Base_Virtual {
public:
	//virtual Base_Virtual() {};
	// Не будет работать
	void mtd1() {
		std::cout << "Base_Virtual - mtd1\n";
		mtd2();
	}
	virtual void mtd2() {
		std::cout << "Base_Virtual - mtd2\n";
	}
	~Base_Virtual() {
		std::cout << "Base_Virtual - Деструктор\n";
	}
};

class Derived_Virtual : public Base_Virtual {
public:
	void mtd2() {
		std::cout << "Derived_Virtual - mtd2\n";
	}
	~Derived_Virtual() {
		std::cout << "Derived_Virtual - Деструктор\n";
	}
};

class Point {
protected:
	int _x;
	int _y;
	std::string _classname;
public:
	Point() {
		_x = 0;
		_y = 0;
		_classname = "Point";
		std::cout << "Point - конструктор\n";
	}
	virtual void move(int dx, int dy) {
		_x += dx;
		_y += dy;
		std::cout << "Point - moved to x: " << _x << ", y: " << _y << "\n";
	}
	virtual std::string classname() {
		return _classname;
	}
	virtual bool isA(std::string classname) {
		return classname == _classname;
	}
};

class ColorPoint : public Point {
protected:
	std::string _color;
public:
	ColorPoint() : Point() {
		_x = 0;
		_y = 0;
		_classname = "ColorPoint";
		_color = "Black";
		std::cout << "ColorPoint - конструктор\n";
	}
	void move(int dx, int dy) override {
		_x += dx;
		_y += dy;
		std::cout << "ColorPoint - moved to x: " << _x << ", y: " << _y << "\n";
	}
	void print() {
		std::cout << "ColorPoint - color is " << _color << "\n";
	}
	std::string classname() override {
		return _classname;
	}
	bool isA(std::string classname) override {
		return classname == _classname;
	}
};

class BoldPoint : public Point {
public:
	BoldPoint() : Point() {
		_x = 0;
		_y = 0;
		_classname = "BoldPoint";
		std::cout << "BoldPoint - конструктор\n";
	}
	void move(int dx, int dy) override {
		_x += dx;
		_y += dy;
		std::cout << "BoldPoint - moved to x: " << _x << ", y: " << _y << "\n";
	}
	std::string classname() override {
		return _classname;
	}
	bool isA(std::string classname) override {
		return classname == _classname;
	}
};

class Line : public Point {
protected:
	int _x1;
	int _y1;
	
public:
	Line() : Point() {
		_x = 0;
		_y = 0;
		_x1 = 1;
		_y1 = 1;
		_classname = "Line";
		std::cout << "Line - конструктор\n";
	}
	std::string classname() override {
		return _classname;
	}
	bool isA(std::string classname) override {
		return classname == _classname;
	}
};

class Base {
public:
	Base() {
		std::cout << "Base - Конструктор по умолчанию\n";
	}
	Base(Base* Obj) {
		std::cout << "Base - Конструктор с указателем\n";
	}
	Base(Base& Obj) {
		std::cout << "Base - Конструктор с ссылкой\n";
	}
	~Base() {
		std::cout << "Base - Деструктор\n";
	}
};

class Desc : public Base {
public:
	Desc() {
		std::cout << "Desc - Конструктор по умолчанию\n";
	}
	Desc(Desc* Obj) {
		std::cout << "Desc - Конструктор с указателем\n";
	}
	Desc(Desc& Obj) {
		std::cout << "Desc - Конструктор с ссылкой\n";
	}
	~Desc() {
		std::cout << "Desc - Деструктор\n";
	}
};

void func1(Base obj) {
	std::cout << "func1\n";
}

void func2(Base* obj) {
	std::cout << "func2\n";
}

void func3(Base& obj) {
	std::cout << "func3\n";
}

Base function1() {
	std::cout << "function1\n";
	Base obj;
	return obj;
}

Base* function2() {
	std::cout << "function2\n";
	Base obj;
	Base* obj_ptr = &obj;
	return obj_ptr;
}

Base& function3() {
	std::cout << "function3\n";
	Base obj;
	return obj;
}

Base function4() {
	std::cout << "function4\n";
	Base* obj_ptr = new Base;
	return *obj_ptr;
}

Base* function5() {
	std::cout << "function5\n";
	Base* obj_ptr = new Base ;
	return obj_ptr;
}

Base& function6() {
	std::cout << "function6\n";
	Base* obj_ptr = new Base;
	return *obj_ptr;
}

void function7(std::unique_ptr<Base> animal_unq_ptr) {}

void function8(std::unique_ptr<Base>& animal_unq_ptr) {}

std::unique_ptr<Base> function9() {
	std::unique_ptr<Base> base_unq_ptr1 = std::make_unique<Base>();
	return base_unq_ptr1;
}

void function10(std::shared_ptr<Base> base_shr_ptr_) {
	std::cout << "Shared count: " << base_shr_ptr_.use_count() << "\n";
}

void function11(std::shared_ptr<Base>& base_shr_ptr_) {
	std::cout << "Shared count: " << base_shr_ptr_.use_count() << "\n";
}

std::shared_ptr<Base> function12() {
	std::shared_ptr<Base> base_shr_ptr_ = std::make_shared<Base>();
	return base_shr_ptr_;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Вызывая mtd1() у потомка у которого он не переопределен вызывается метод предка и 
	// соответсвенно mtd2() вызывается так же у предка 
	std::cout << "---Не виртуальный метод---\n";
	{
		Base_NotVirtual A;
		Derived_NotVirtual B;
		B.mtd1();
	}
	std::cout << "--------------\n\n";
	
	// Здесь же mtd2() виртуальный и mtd1() вызывает уже mtd2() потомка даже если mtd1() у него не переопределен
	std::cout << "---Виртуальный метод---\n";
	{
		Base_Virtual A;
		Derived_Virtual B;
		B.mtd1();
	}
	std::cout << "--------------\n\n";

	// У объекта в указателе на предка взывается метод предка, а в указателе на потомка - метод потомка
	std::cout << "---Указатель на базовый и потомка---\n";
	{
		Base_NotVirtual* A = new Derived_NotVirtual;
		Derived_NotVirtual* B = new Derived_NotVirtual;

		std::cout << "\nУказатель на базовый:\n";
		A->mtd2();
		std::cout << "\nУказатель на потомка:\n";
		B->mtd2();
		std::cout << "\n";

		delete A, B;
	}
	std::cout << "--------------\n\n";

	// В данном случае вызывается метод класса потомка не зависимо от того хранится ли объект в указателе
	// на предка или потомка
	std::cout << "---Указатель на базовый и потомка с виртуальной функцией---\n";
	{
		Base_Virtual* A = new Derived_Virtual;
		Derived_Virtual* B = new Derived_Virtual;

		std::cout << "\nУказатель на базовый:\n";
		A->mtd2();
		std::cout << "\nУказатель на потомка:\n";
		B->mtd2();
		std::cout << "\n";

		delete A;
		delete B;
	}
	std::cout << "--------------\n\n";

	// По скольку метод move виртуальный то вызывая его у указателя на базовый класс 
	// он вызовется у соответсвующего предка. А так же предков можно хранить в массиве типа базового класса
	std::cout << "---Пример хранения объекта в указателе на предка---\n";
	Point* points[3] = { new Point, new ColorPoint, new BoldPoint };

	for (Point* point : points) {
		point->move(10, 5);
	}
	for (Point* point : points) {
		delete point;
	}

	std::cout << "--------------\n\n";

	// проверка позволяет дополнительно обезопасить программиста от ошибки и undefined behavior
	std::cout << "---Пример проверки принадлежности классу---\n";
	Point* arr[4] = { new Point, new ColorPoint, new BoldPoint, new Line };

	for (Point* point : arr) {
		// Без проверки у Line вызовется метод базового класса Point что приведет к неправильному передвижению объекта
		//point->move(10, 5);

		if (not point->isA("Line")) {
			point->move(10, 5);
		}
	}
	for (Point* point : arr) {
		delete point;
	}

	std::cout << "--------------\n\n";

	std::cout << "---Опасное приведение типов---\n";
	Point* base = new Line;
	
	//ColorPoint* colorpoint = (ColorPoint*)line; // Так делать не надо

	// Если же сделать то colorpoint будет считается объектом класса ColorPoint, но хранить в себе указатель на Line
	// суть в том что Line не имеет метода print, а Colorpoint имеет, так что если попытатся применить к colorpoint метод print 
	// то получим неопределённое поведение
	
	//colorpoint->print(); // завершит программу с каким то НЕ нулевым кодом но сам проект скомпилируется, соберется и запустится
	// поэтому следует делать поверку

	std::cout << "\nПроверка через isA\n";
	if (base->isA("ColorPoint")) {
		ColorPoint* colorpoint = (ColorPoint*)base;
		colorpoint->print();
	}
	else {
		std::cout << "Object is not ColorPoint\n";
	}

	std::cout << "\nПроверка через dynamic_cast\n";
	if (ColorPoint* colorpoint = dynamic_cast<ColorPoint*>(base)) {
		colorpoint->print();
	}
	else {
		std::cout << "Object is not ColorPoint\n";
	}

	std::cout << "\nПроверка через dynamic_cast 2\n";
	Point* base2 = new ColorPoint;
	if (ColorPoint* colorpoint2 = dynamic_cast<ColorPoint*>(base2)) {
		colorpoint2->print();
	}
	else {
		std::cout << "Object is not ColorPoint\n";
	}

	delete base, base2;
	std::cout << "--------------\n\n";
	
	// Передача объектов как параметров в функции
	std::cout << "---Использование объекта как парраметра---\n";
	{
		Base obj;
		std::cout << "\nfunc1(Base obj):\n";
		// Создаст копию, удалит ее по завершении работы функции
		func1(obj);
		std::cout << "\nfunc2(Base* obj):\n";
		// Примет либо адрес объекта, либо указатель
		func2(&obj);
		std::cout << "\nfunc3(Base& obj):\n";
		func3(obj);
	}
	std::cout << "\n===========\n\n";
	{
		Desc obj;
		std::cout << "\nfunc1(Base obj):\n";
		// Создаст копию, удалит ее по завершении работы функции.
		// При этом обрежет у копии потомка все, чего нет у предка
		func1(obj);
		std::cout << "\nfunc2(Base* obj):\n";
		// Примет либо адрес объекта, либо указатель
		func2(&obj);
		std::cout << "\nfunc3(Base& obj):\n";
		func3(obj);
	}
	std::cout << "--------------\n\n";

	// Внутри функции привести переданный Base к Desc с помощью
	// приведения типов невозможно.
	// Ни static_cast, ни dynamic_cast не вернут потомка

	// Отправка по значению создает копию, что невсегда нужно.
	// Указатели могут баговать, поэтому рекомендуется тогда уж по ссылке.
	// Но при этом в указатель можно отправить nullptr, тогда как ссылка
	// обязана на что-либо указывать

	// Возвращение объектов как результата из функции
	std::cout << "---Возвращение объектов из функции---\n";
	{
		// Объект возвращается нормально
		Base obj1 = function1();
		std::cout << "Outside function1\n";
	}
	std::cout << "\n===========\n\n";
	{
		// Объект уничтожается еще до выхода из функции. Плохо
		Base* obj2 = function2();
		std::cout << "Outside function2\n";
	}
	std::cout << "\n===========\n\n";
	{
		// Объект уничтожается еще до выхода из функции. Плохо
		Base obj3 = function3();
		std::cout << "Outside function3\n";
	}
	std::cout << "\n===========\n\n";
	{
		// Создается копия внутреннего объекта. Внутренний объект невозможно
		// уничтожить
		Base obj4 = function4();
		std::cout << "Outside function4\n";
	}
	std::cout << "\n===========\n\n";
	{
		// Все нормально
		Base* obj5 = function5();
		std::cout << "Outside function5\n";
		delete obj5;
	}
	std::cout << "\n===========\n\n";
	{
		// Создается копия внутреннего объекта. Внутренний объект невозможно
		// уничтожить
		Base obj6 = function6();
		std::cout << "Outside function6\n";
	}
	std::cout << "--------------\n\n";

	// Тестирование unique_ptr
	// unique_ptr берет на себя всю ответственность за жизнь объекта,
	// никакой другой указатель не может указывать на этот объект,
	// но ответственность может быть передана (без копирования).
	// unique_ptr автоматически удаляет объект, когда выходит за "}"
	std::cout << "---unique_ptr---\n";
	{
		std::cout << "function8\n";
		std::unique_ptr<Base> base_unq_ptr = std::make_unique<Base>();
		// Невозможно передать в функцию по значению (попытка сделать копию)
		//function7(base_unq_ptr);

		// Возможно передать по ссылке
		function8(base_unq_ptr);
	}
	std::cout << "\n===========\n\n";
	{
		std::cout << "function9\n";
		// Возвращаем unique_ptr из функции. Все нормально
		std::unique_ptr<Base> base_unq_ptr1 = function9();
	}
	std::cout << "--------------\n\n";

	// Тестирование shared_ptr
	// shared_ptr отслеживает, сколько указателей указывают на наш объект.
	// При кол-ве указателей == 0 удаляет объект
	std::cout << "---shared_ptr---\n";
	{
		// Создаем копию shared_ptr
		std::shared_ptr<Base> base_shr_ptr1 = std::make_shared<Base>();
		std::shared_ptr<Base> base_shr_ptr2 = base_shr_ptr1;
		// Вывод кол-ва указателей на объект
		std::cout << "Shared count: " << base_shr_ptr2.use_count() << "\n";
	}
	std::cout << "\n===========\n\n";
	// Передача в функцию
	{
		// Создает копию shared_ptr
		std::shared_ptr<Base> base_shr_ptr3 = std::make_shared<Base>();
		function10(base_shr_ptr3);
		std::cout << "Shared count: " << base_shr_ptr3.use_count() << "\n";
	}
	std::cout << "\n===========\n\n";
	{
		// Передача по ссылке. Копии не создается
		std::shared_ptr<Base> base_shr_ptr4 = std::make_shared<Base>();
		function11(base_shr_ptr4);
		std::cout << "Shared count: " << base_shr_ptr4.use_count() << "\n";
	}
	std::cout << "\n===========\n\n";
	// Возврат shared_ptr из функции
	{
		// Функция вернет нормально, без копий
		std::shared_ptr<Base> base_shr_ptr5 = function12();
		std::cout << "Shared count: " << base_shr_ptr5.use_count() << "\n";
	}
	std::cout << "--------------\n\n";
}

