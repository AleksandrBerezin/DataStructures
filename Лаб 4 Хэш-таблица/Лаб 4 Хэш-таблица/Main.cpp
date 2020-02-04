#include <iostream>
#include <string>
#include "Node.h"
#include "HashTable.h"
#include "Map.h"

using namespace std;
using std::string;

int InputInt();
string InputString();
string SubKey(string str);

int main()
{
	setlocale(LC_ALL, "Russian");
    
	Map* map = new Map();
	HashTable* table = new HashTable();

	//TODO: Naming
	bool exit = false;

	//TODO: ?
	int number = 0;

	while (!exit)
	{
		//TODO: Ответственности. Есть смысл разнести меню для ХТ и для словаря
		cout << "\nВыберите структуру данных для работы:\n";
		cout << "1. Словарь.\n"
			<< "2. Хэш-таблица.\n"
			<< "0. Выход.\n\n";

		int number = InputInt();
		//TODO: Naming
		bool back = false;
		switch (number)
		{
			case 1:
			{
				while (!back)
				{
					cout << "\nВыберите вариант:\n";
					cout << "1. Добавление элемента в словарь.\n"
						<< "2. Удаление элемента из словаря.\n"
						<< "3. Поиск значения по ключу.\n"
						<< "4. Удаление словаря.\n"
						<< "5. Вывод словаря на экран.\n"
						<< "0. Назад.\n\n";

					int variant = InputInt();
					switch (variant)
					{
						case 1:
						{
							if (map == nullptr)
							{
								map = new Map();
							}
							//TODO: RSDN
							string key;
							string value;

							cout << "Введите ключ: ";
							key = SubKey(InputString());
							cout << "Введите значение: ";
							value = InputString();

							map->Add(key, value);
							Print(map);
							break;
						}
						case 2:
						{
								//TODO: Дубль
							if (map == nullptr || map->IsEmpty())
							{
								cout << "Словарь пуст.\n";
								break;
							}
							//TODO: RSDN
							string key;

							cout << "Введите ключ: ";
							key = SubKey(InputString());

							map->Remove(key);
							Print(map);
							break;
						}
						case 3:
						{
								//TODO: Дубль
							if (map == nullptr || map->IsEmpty())
							{
								cout << "Словарь пуст.\n";
								break;
							}
							//TODO: RSDN
							string key;
							string value;

							cout << "Введите ключ: ";
							key = SubKey(InputString());

							value = map->Find(key);
							if (value == "")
							{
								cout << "Элемента с таким ключом нет.\n";
							}
							else
							{
								cout << "Элементу с ключом " << key
									<< " соответствует значение " << value << "\n";
							}

							break;
						}
						case 4:
						{
							if (map == nullptr)
							{
								break;
							}

							map->Delete();
							delete map;
							map = nullptr;
							break;
						}
						case 5:
						{
								//TODO: Дубль
							if (map == nullptr)
							{
								cout << "Словарь пуст.\n";
								break;
							}

							Print(map);
							break;
						}
						case 0:
						{
							back = true;
							break;
						}
						default:
							cout << "Выбран неверный вариант, попробуйте еще раз.\n";
							break;
					}
				}
				break;
			}
			case 2:
			{
				while (!back)
				{
					cout << "\nВыберите вариант:\n";
					cout << "1. Добавление элемента в хэш-таблицу.\n"
						<< "2. Удаление элемента из хэш-таблицы.\n"
						<< "3. Поиск значения по ключу.\n"
						<< "4. Удаление хэш-таблицы.\n"
						<< "5. Вывод хэш-таблицы на экран.\n"
						<< "0. Назад.\n\n";

					int variant = InputInt();
					switch (variant)
					{
						case 1:
						{
							if (table == nullptr)
							{
								table = new HashTable();
							}
							//TODO: RSDN
							string key;
							string value;

							cout << "Введите ключ: ";
							key = SubKey(InputString());
							cout << "Введите значение: ";
							value = InputString();

							table->Add(key, value);
							Print(table);
							break;
						}
						case 2:
						{
								//TODO: Дубль
							if (table == nullptr || table->IsEmpty())
							{
								cout << "Словарь пуст.\n";
								break;
							}
							//TODO: RSDN
							string key;

							cout << "Введите ключ: ";
							key = SubKey(InputString());

							table->Remove(key);
							Print(table);
							break;
						}
						case 3:
						{
								//TODO: Дубль
							if (table == nullptr || table->IsEmpty())
							{
								cout << "Словарь пуст.\n";
								break;
							}
							//TODO: RSDN
							string key;
							string value;

							cout << "Введите ключ: ";
							key = SubKey(InputString());

							value = table->Find(key);
							if (value == "")
							{
								cout << "Элемента с таким ключом нет.\n";
							}
							else
							{
								cout << "Элементу с ключом " << key
									<< " соответствует значение " << value << "\n";
							}

							break;
						}
						case 4:
						{
							if (table == nullptr)
							{
								break;
							}

							table->Delete();
							delete table;
							table = nullptr;
							break;
						}
						case 5:
						{
								//TODO: Дубль
							if (table == nullptr)
							{
								cout << "Словарь пуст.\n";
								break;
							}

							Print(table);
							break;
						}
						case 0:
						{
							back = true;
							break;
						}
						default:
							cout << "Выбран неверный вариант, попробуйте еще раз.\n";
							break;
					}
				}
				break;
			}
			case 0:
				if (map != nullptr)
				{
					map->Delete();
					delete map;
					map = nullptr;
				}
				if (table != nullptr)
				{
					table->Delete();
					delete table;
					table = nullptr;
				}

				exit = true;
				break;
			default:
				cout << "Выбран неверный вариант, попробуйте еще раз.\n";
				break;
		}
	}
}

//Проверка, что вводимое число int
int InputInt()
{
	int number = 0;

	while (true)
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR\n";
		}
		else
		{
			break;
		}
	}

	return number;
}

// Проверка, что введенная строка не пустая
string InputString()
{
	string str;
	getline(cin, str);

	while (str.empty())
	{
		getline(cin, str);
	}
	
	return str;
}

// Обрезание ключа до 6 символов
string SubKey(string str)
{
	return str.substr(0, 6);
}