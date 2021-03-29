#include <iostream>
#include <fstream>

/*
   ВСЕ ЗАДАНИЯ ДЛЯ ЛАТИННИЦЫ!!!
Необходимо сделать меню, к которому можно обращаться несколько раз. Каждое задание делать в виде отдельной функции. К каждой функции написать комментарий: что она делает, что подается на вход, что на выход, какие входные данные изменяются в результате работы функции.
написать набор функций для работы с файловой системой
1. string file_format(const string file_path_full) по введенному полному расположению файла получить расширение,
2. string file_name(const string file_path_full) по введенному полному расположению файла получить название,
3. string file_path (const string file_path_full) по введенному полному расположению файла получить расположение,
4. char file_disk (const string file_path_full) по введенному полному расположению файла получить название диска,
5. bool file_rename(string * file_path_full) по введенному полному расположению файла и новому имени переименовать файл,
6. bool file_copy(const string file_path_full) по введенному полному расположению файла создать копию файла (имя копии получается приписыванием «_copy» к имени файла).
При реализации функций 1-5 должна реализовываться работа со строками (работа с файловой системой не происходит): разбор строк, получение нужной информации из строки, заданной определенным форматом.
В функции 6 нужно
а) открыть файл, полное расположение которого задано аргументом file_path_full, если такого файла нет или он не открывается вернуть false;
б) создать (открыть) файл, полное расположение которого получается из file_path_full приписыванием «_copy» к имени файла, если неуспешно, вернуть false;
в) реализовать построчное или посимвольное считывание из file_path_full и соответствующую запись в созданный файл. Буфер не должен быть меньше длины файла.
г) Закрыть оба файла и вернуть true.

   */

using namespace std;

void readStr(char input[255], const char* text) {
	cout << text << "\n";
	cin.getline(input, 255);
}

bool isSubstrAtN(const char* str_for_search_in, const char* substring, int n) {
	int len1 = strlen(str_for_search_in);
	int len2 = strlen(substring);

	if (len1 - n < len2) {
		return false;
	}

	for (int i = 0; i < len2; i++) {
		if (str_for_search_in[n + i] != substring[i]) {
			return false;
		}
	}

	return true;
}

int find_substring1(const char* str_for_search_in, const char* substring, int start_position) {
	int len1 = strlen(str_for_search_in);
	int len2 = strlen(substring);
	for (int i1 = start_position; i1 < len1; i1++) {
		if (isSubstrAtN(str_for_search_in, substring, i1)) {
			return i1;
		}
	}

	return -1;
}

void find_substring2(const char* str_for_search_in, const char* substring) {
	int len1 = strlen(str_for_search_in);
	int len2 = strlen(substring);

	cout << "[ ";
	for (int i1 = 0; i1 < len1; i1++) {
		if (isSubstrAtN(str_for_search_in, substring, i1)) {
			cout << i1 << " ";
		}
	}

	cout << "] \n";
}
//разбивает на сегменты 
void parsePath(const char* fullPath, char* drive, char** path, char** name, char** ext) {
	int len = strlen(fullPath);

	int lastDotIndex = -1, lastSlashIndex = -1;
	for (int i = len; i > 0; --i) {//с конца строки и находит номер точки и слеша и сохраняет их
		if (fullPath[i] == '.' && lastDotIndex == -1) {
			lastDotIndex = i;
		}

		if ((fullPath[i] == '/' || fullPath[i] == '\\') && lastSlashIndex == -1) {
			lastSlashIndex = i;
		}
	}
	//определяются длины элементов строки
	int pathLength = lastSlashIndex - 3;
	int nameLength = lastDotIndex - lastSlashIndex - 1;
	int extLength = len - lastDotIndex;

	(*drive) = fullPath[0];//инициализация первой буковй
	(*path) = new char[pathLength + 1]{ 0 };
	(*name) = new char[nameLength + 1]{ 0 };
	(*ext) = new char[extLength + 1]{ 0 };

	for (int i = 0; i < pathLength; i++) {
		(*path)[i] = fullPath[i + 3];
	}
	(*path)[pathLength] = '\0';

	for (int i = 0; i < nameLength; i++) {
		(*name)[i] = fullPath[i + lastSlashIndex + 1];
	}
	(*name)[nameLength] = '\0';

	for (int i = 0; i < extLength; i++) {
		(*ext)[i] = fullPath[i + lastDotIndex + 1];
	}
	(*ext)[extLength] = '\0';
}


string file_format(const string file_path_full) {
	char drive = '\0', * path = nullptr, * name = nullptr, * ext = nullptr;

	parsePath(file_path_full.c_str(), &drive, &path, &name, &ext);

	string s(ext);
	return s;
}

string file_name(const string file_path_full) {
	char drive = '\0', * path = nullptr, * name = nullptr, * ext = nullptr;

	parsePath(file_path_full.c_str(), &drive, &path, &name, &ext);

	string s(name);
	return s;
}

string file_path(const string file_path_full) {
	char drive = '\0', * path = nullptr, * name = nullptr, * ext = nullptr;

	parsePath(file_path_full.c_str(), &drive, &path, &name, &ext);

	string s(path);
	return s;
}

string file_disk(const string file_path_full) {
	char drive = '\0', * path = nullptr, * name = nullptr, * ext = nullptr;

	parsePath(file_path_full.c_str(), &drive, &path, &name, &ext);

	string s(1, drive);
	return s;
}

bool file_rename(string* file_path_full) {
	char newName[255];
	readStr(newName, "Новое имя (без расширения):");

	string disk = file_disk(*file_path_full);
	string path = file_path(*file_path_full);
	string format = file_format(*file_path_full);

	file_path_full->clear();
	file_path_full->append(disk + ":\\" + path + "\\" + newName + "." + format);

	return true;
}

bool file_rename2(string* file_path_full) {
	string disk = file_disk(*file_path_full);
	string path = file_path(*file_path_full);
	string name = file_name(*file_path_full);
	string format = file_format(*file_path_full);

	file_path_full->clear();
	file_path_full->append(disk + ":\\" + path + "\\" + name + "_copy" + "." + format);

	return true;
}

bool file_copy(const string file_path_full) {
	string newPath(file_path_full);
	file_rename2(&newPath);

	char* buffer;
	int length;
	std::ifstream is(file_path_full, std::ifstream::binary);//открываем файл для чтения
	if (is) {
		// get length of file:
		is.seekg(0, is.end);//смещение указателя в конец
		length = is.tellg();//возвращает текущее положение указателя
		is.seekg(0, is.beg);//в начало 

		buffer = new char[length];

		std::cout << "Считывание " << length << " символов... ";
		// read data as a block:
		is.read(buffer, length);

		if (is)
			std::cout << "считывание успешно.";
		else
			return false;
		is.close();//закрываем файл
	}
	else
	{
		return false;//если файл не открыт, то все конец
	}

	std::ofstream out(newPath, std::ios::binary | std::ios::out); //открытие файла для записи
	if (out.is_open())
	{
		out.write(buffer, length);
		out.close();
	}
	else
	{
		return false;
	}

	delete[] buffer;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int grade;
	char mainStr[255], argStr[255];

	do
	{
		cout << "\n Введите то, что вы хотите сделать: \n";
		cout << " 1 - по введенному полному расположению файла получить расширение \n";
		cout << " 2 - по введенному полному расположению файла получить название \n";
		cout << " 3 - по введенному полному расположению файла получить расположение \n";
		cout << " 4 - по введенному полному расположению файла получить название диска \n";
		cout << " 5 - по введенному полному расположению файла и новому имени переименовать файл \n";
		cout << " 6 - по введенному полному расположению файла создать копию файла \n";
		cout << " 7 - Выйти \n";
		cin >> grade;
		cin.ignore();
		string newPath = "";
		switch (grade)
		{
		case 1:
			readStr(mainStr, "Расположение файла:");
			cout << "Расширение: " << file_format(mainStr) << '\n';

			break;

		case 2:
			readStr(mainStr, "Расположение файла:");
			cout << "Имя: " << file_name(mainStr) << '\n';

			break;
		case 3:
			readStr(mainStr, "Расположение файла:");
			cout << "Расположение: " << file_path(mainStr) << '\n';

			break;
		case 4:
			readStr(mainStr, "Расположение файла:");
			cout << "Название диска: " << file_disk(mainStr) << '\n';

			break;
		case 5:
		{
			readStr(mainStr, "Расположение файла:");
			string newPath(mainStr);
			file_rename(&newPath);

			cout << "Новое расположение: " << newPath << '\n';

		}
		break;
		case 6:
		{
			readStr(mainStr, "Расположение файла:");
			string newPath(mainStr);
			file_copy(newPath);

			cout << "Новое расположение: " << newPath << '\n';

		}
		break;
		case 7:
			cout << "Выходим!\n"; //выход
			break;
		default:
			cout << "Упс! Следует выбирать только из численного диапазона 1-7.\n"; //ошибка
			break;
		}
	} while (grade != 7);
}

