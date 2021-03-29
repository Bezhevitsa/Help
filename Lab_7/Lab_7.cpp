#include <iostream>
#include <string>


/*Написание шаблона функций сортировки.

на 3: быстрая сортировка любого встроенного типа данных. 
на 4: Быстрая сортировка любого встроенного типа данных и пар <Фамилия, возраст> по одному из аргументов на ваш выбор. 
Встроенными структурами и сортировкой пользоваться нельзя.
на 5: Быстрая сортировка любого встроенного типа данных и структуры данных <Surname, Name, Age> по каждому из полей.
Встроенными структурами и сортировкой пользоваться нельзя.

Сортировка должна быть реализована в виде функции.
Наличие main с демонстрацией работы функции с различными типами обязательно*/

//в статическом классе нельзя создавать объекты
static class quick_sorter {
	template < typename T >//синтаксис, объявление шаблонной функции
	static void swap(T* a, T* b)
	{
		T t = *a;//меняем значение
		*a = *b;
		*b = t;
	}

	/* Эта функция принимает последний элемент в качестве разделителя,
	   помещает элемент поворота на его правильное положение в отсортированном
	   массиве, и места меньше(меньше, чем поворот) слева от оси поворота,
	   и все больше элементов справа от разделителя */
	template < typename T >
	static int partition(T arr[], int low_index, int high_index, bool (*is_second_bigger)(T a, T b))
	{
		T pivot = arr[high_index];    // разделитель
		int i = (low_index - 1);		// индекс меньшего элемента

		for (int j = low_index; j <= high_index - 1; j++)
		{
			if (is_second_bigger(arr[j], pivot))
			{
				i++;
				swap(&arr[i], &arr[j]);
			}
		}

		swap(&arr[i + 1], &arr[high_index]);

		return (i + 1);
	}

public:
	/* Функция быстрой сортировки
	 arr[] --> массив,
	 low   --> начальный индекс,
	 high  --> конечный индекс */
	template < typename T >
	static void execute(T arr[], int low, int high, bool (*is_second_bigger)(T a, T b))
	{
		if (low < high)
		{
			int pi = partition(arr, low, high, is_second_bigger);

			execute(arr, low, pi - 1, is_second_bigger);
			execute(arr, pi + 1, high, is_second_bigger);
		}
	}
};


// vvv На 3 vvvv

// "базовый" сравниватель, подходит только для базовых типов,
// которые С++ умеет правильно сравнивать с помощью < > =.
// Отработает неправильно в случае, например, передачи ссылок.
// Возвращает 0, если элементы равны, 1 если второй больше первого,
// -1, если первый больше второго.
template < typename T >
bool is_second_bigger(T a, T b) {
	return b > a;
}

void na_3() {
	unsigned length = 10;
	int* a = new int[length];
	// Заполнение массива случайными числами
	for (int i = 0; i < length; i++) {
		a[i] = rand() % 201 - 100;
	}

	// Вывод элементов массива до сортировки
	for (int i = 0; i < length; i++) {
		std::cout << a[i] << '\t';
	}
	std::cout << std::endl;

	quick_sorter::execute<int>(a, 0, length - 1, is_second_bigger);	// вызов функции сортировки

	// Вывод элементов массива после сортировки
	for (int i = 0; i < length; i++) {
		std::cout << a[i] << '\t';
	}
	std::cout << std::endl;
	std::cout << std::endl;

	delete[] a;
}

// ^^^ На 3 ^^^
// vvv На 4 vvv

struct Person1 {
	int Age;
	std::string Surname;
};

bool is_second_bigger_person1(Person1 a, Person1 b) {
	return b.Age > a.Age;
}

void na_4() {
	unsigned length = 4;
	Person1* a = new Person1[length];

	// Заполнение массива данными
	a[0].Surname = "Gryffindor";
	a[0].Age = 26;
	a[1].Surname = "Ravenclaw";
	a[1].Age = 23;
	a[2].Surname = "Hufflepuff";
	a[2].Age = 27;
	a[3].Surname = "Slytherin";
	a[3].Age = 20;

	// Вывод элементов массива до сортировки
	for (int i = 0; i < length; i++) {
		std::cout << a[i].Surname << " (" << a[i].Age << ")" << '\t';
	}
	std::cout << std::endl;

	quick_sorter::execute<Person1>(a, 0, length - 1, is_second_bigger_person1);	// вызов функции сортировки

	// Вывод элементов массива после сортировки
	for (int i = 0; i < length; i++) {
		std::cout << a[i].Surname << " (" << a[i].Age << ")" << '\t';
	}
	std::cout << std::endl;
	std::cout << std::endl;

	delete[] a;
}

// ^^^ На 4 ^^^
// vvv На 5 vvv

class Person2 {
public:
	std::string Surname;
	std::string Name;
	int Age;
};
//по какому критерию сортировать
bool is_second_bigger_person_age(Person2 a, Person2 b) {
	return b.Age > a.Age;
}

bool is_second_bigger_person_surname(Person2 a, Person2 b) {
	return b.Surname > a.Surname;
}

bool is_second_bigger_person_name(Person2 a, Person2 b) {
	return b.Name > a.Name;
}

void na_5() {
	unsigned length = 4;
	Person2* a = new Person2[length];

	// Заполнение массива данными
	a[0].Surname = "Gryffindor";
	a[0].Name = "Godric";
	a[0].Age = 26;
	a[1].Surname = "Ravenclaw";
	a[1].Name = "Rowena";
	a[1].Age = 23;
	a[2].Surname = "Hufflepuff";
	a[2].Name = "Helga";
	a[2].Age = 27;
	a[3].Surname = "Slytherin";
	a[3].Name = "Salazar";
	a[3].Age = 20;

	// Вывод элементов массива до сортировки
	for (int i = 0; i < length; i++) {
		std::cout << a[i].Name[0] << ". " << a[i].Surname << " (" << a[i].Age << ")" << '\t';
	}
	std::cout << std::endl;

	int option = -1;
	while (option < 0 || option > 3) {
		std::cout << "How do you want to sort? By Age (1), by Name (2) or by Surname (3)? Press 0 to exit." << std::endl;
		std::cin >> option;

		switch (option) {
		case 1:
			quick_sorter::execute<Person2>(a, 0, length - 1, is_second_bigger_person_age);
			break;
		case 2:
			quick_sorter::execute<Person2>(a, 0, length - 1, is_second_bigger_person_name);
			break;
		case 3:
			quick_sorter::execute<Person2>(a, 0, length - 1, is_second_bigger_person_surname);
			break;
		case 0:
			delete[] a;
			return;
		}
	}

	// Вывод элементов массива после сортировки
	for (int i = 0; i < length; i++) {
		std::cout << a[i].Name[0] << ". " << a[i].Surname << " (" << a[i].Age << ")" << '\t';
	}
	std::cout << std::endl;
	std::cout << std::endl;

	delete[] a;
}

// ^^^ На 5 ^^^

int main()
{
	na_3();
	na_4();
	na_5();
}