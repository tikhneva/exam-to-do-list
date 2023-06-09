#include <iostream>
#include <cstring>
using namespace std;
const int SIZE = 20; 
struct Time // структура, которая будет обозначать время исполнения дела
{
	int minutes;
	int hours;
};
struct Date //структура, обозначающая дату дела(и временем исполнения)
{
	Time time;
	int year;
	int month;
	int day;
};
struct Case // главная структура, описывающее все дело(имя,приоритет,описание  и дату)
{
	Date date;
	char name[SIZE];
	char description[SIZE];
	int priority;
};

Case createCase(); // прототипы функций
void addCase(Case*& list, const int SIZE, int& list_size); // функция добавления дела в список
Case* deleteCase(Case* list, const int SIZE, int& list_size); // функция удаления дела из 
void editCase(Case& _case, int list_size); // функция редактирования любого дела из списка по критерию
void findCase(Case* list, int list_size); // функция поиска всех дел по заданному критерию
void showCase(Case _case, int list_size); // функция отображения списка
void sortList(Case*& list, int list_size); // функция для сортировки списка

int main()
{
	setlocale(LC_ALL, "");
	int list_size;
	int choice, choicecase;
	bool flag = 0;
	cout << "Введите размер списка:" << endl;
	do
	{
		cin >> list_size;
		if (!(list_size >= 1 && list_size <= 20))
		{
			cout << "Ваш список должен содержать от 1 до " << SIZE << " дел" << endl;
		}
	} while (!(list_size >= 1 && list_size <= 20));
	Case* list = new Case[SIZE]; //выделим место под 20 дел, но заполним только list_size значений массива list
	for (int i = 0; i < list_size; i++)
		list[i] = createCase();
	do
	{
		cout << "Что вы хотите сделать дальше?" << endl;
		cout << "1 - добавить дело" << endl;
		cout << "2 - удалить дело" << endl;
		cout << "3 - отредактирование дела" << endl;
		cout << "4 - поиск дела по критерию" << endl;
		cout << "5 - отображение списка дел" << endl;
		cout << "6 - отсортировать дело по критерию" << endl;
		cout << "7 - выход из программы" << endl << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			addCase(list, SIZE, list_size);
			break;
		case 2:
			list = deleteCase(list, SIZE, list_size);
			break;
		case 3:
			cout << "Какое дело вы хотите поменять ?" << endl;
			do
			{
				cin >> choicecase;
				if (!(choicecase >= 1 && choicecase <= list_size))
					cout << "Выберите номер дела, которое есть в списке" << endl;
			} while (!(choicecase >= 1 && choicecase <= list_size));
			editCase(list[choicecase - 1], list_size);
			break;
		case 4:
			findCase(list, list_size);
			break;
		case 5:
			if (list_size <= 0)
			{
				cout << "У вас нет дел, чтобы их вывести" << endl;
				break;
			}
			for (int i = 0; i < list_size; i++)
			{
				cout << "ID: " << i + 1 << endl;
                showCase(list[i], list_size);
			}
				
			break;
		case 6:
			sortList(list, list_size);
			break;
		case 7:
			flag = 1;
			break;
		}
		if (flag == 1)
			break;
	} while (true);
	delete[]list;
	return 0;
}
Case createCase()
{
	Case _case;//нижнее подчеркивание, потому что case - это уже ключевое слово, используемое в конструкции switch
	cout << "Введите имя дела:" << endl;
	cin.ignore();
	cin.getline(_case.name, SIZE);
	cout << "Какой приоритет дела?" << endl;
	cout << "1 - не важно" << endl;
	cout << "2 - маловажно" << endl;
	cout << "3 - важно" << endl;
	cout << "4 - очень важно" << endl;
	do // делаем до тех пор пока пользователь не введет число от 1 до 4. Будем использовать эти проверки почти у каждой характеристики
	{
		cin >> _case.priority;
		
		if (!(_case.priority >= 1 && _case.priority <= 4))
			cout << "Приоритет дела должен быть в диапазоне от 1 до 4" << endl;
	} while (!(_case.priority >= 1 && _case.priority <= 4));
	cout << "Введите описание дела(до 100 символов):" << endl;
	cin.ignore();
	cin.getline(_case.description, SIZE);
	cout << "Введите год исполнения дела:" << endl;
	do
	{
		cin >> _case.date.year;
		if (!(_case.date.year >= 2013 && _case.date.year <= 2123))
			cout << "Год исполнения дела может быть в диапазоне от 2013 года до 2123 года." << endl;
	} while (!(_case.date.year >= 2013 && _case.date.year <= 2123));
	cout << endl;
	cout << "Введите месяц исполнения дела:" << endl;
	do
	{
		cin >> _case.date.month;
		if (!(_case.date.month >= 1 && _case.date.month <= 12))
			cout << "Месяц исполнения дела должен быть в диапазоне от 1 до 12" << endl;
	} while (!(_case.date.month >= 1 && _case.date.month <= 12));
	cout << "Введите день исполнения дела:" << endl;
	do
	{
		cin >> _case.date.day;
		if (_case.date.month == 1 || _case.date.month == 3 || _case.date.month == 5 || _case.date.month == 7 || _case.date.month == 8 || _case.date.month == 10 || _case.date.month == 12)
		{
			if (!(_case.date.day >= 1 && _case.date.day <= 31))
				cout << "В этом месяце нет такого дня" << endl;
			else
				break;
		}
		else if (_case.date.month == 2)
		{
			if (!(_case.date.day >= 1 && _case.date.day <= 28))
				cout << "В этом месяце нет такого дня" << endl;
			else
				break;
		}
		else if (_case.date.month == 4 || _case.date.month == 6 || _case.date.month == 9 || _case.date.month == 11)
		{
			if (!(_case.date.day >= 1 && _case.date.day <= 30))
				cout << "В этом месяце нет такого дня" << endl;
			else
				break;
		}
	} while (true);
	cout << "Введите в который час было исполнено дело:" << endl;
	do
	{
		cin >> _case.date.time.hours;
		if (!(_case.date.time.hours >= 0 && _case.date.time.hours <= 23))
			cout << "Час исполнения дела может быть в диапазоне от 0 до 23 часов" << endl;
	} while (!(_case.date.time.hours >= 0 && _case.date.time.hours <= 23));
	cout << "Введите в какую минуту было исполнено дело:" << endl;
	do
	{
		cin >> _case.date.time.minutes;
		if (!(_case.date.time.minutes >= 0 && _case.date.time.minutes <= 59))
			cout << "Минута исполнения дела может быть в диапазоне от 0 до 59 минут" << endl;
	} while (!(_case.date.time.minutes >= 0 && _case.date.time.minutes <= 59));
	cout << endl << endl;
	return _case;
}
void addCase(Case*& list, const int SIZE, int& list_size)
{
	list_size++;
	if (list_size >= SIZE)
	{
		cout << "Список переполнен. Вы не можете добавить дело";
		return;
	}
	else
		list[list_size - 1] = createCase();
	return;
}
Case* deleteCase(Case* list, const int SIZE, int& list_size)
{
	int index;
	if (list_size == 0)
	{
		cout << "В списке уже нет дел. Вы не можете ничего удалить" << endl;
		return list;
	}
	else
	{
		cout << "Какое дело вы хотите удалить?" << endl;
		while (true)
		{
			cin >> index;
			if (index > list_size || index <= 0)
			{
				cout << "Введите число от 1 до размера списка." << endl;
				continue;
			}
			else
			{
				list_size--;
				Case* newList = new Case[list_size];
				for (int i = 0; i < list_size + 1; i++)
				{
					if (i == index - 1)
					{
						continue;
					}
					else if (i < index - 1)
						newList[i] = list[i];
					else
						newList[i - 1] = list[i];
				}
				delete[]list;
				return newList;
			}
		}
	}
}
void showCase(Case _case, int list_size)
{

	cout << "Имя дела: " << _case.name << endl;
	cout << "Приоритет дела: ";
	switch (_case.priority)
	{
	case 1:
		cout << "Не важно" << endl;
		break;
	case 2:
		cout << "Маловажно" << endl;
		break;
	case 3:
		cout << "Важно" << endl;
		break;
	case 4:
		cout << "Очень важно" << endl;
		break;
	}
	cout << "Описание дела: " << _case.description << endl;
	cout << "Дата исполнения дела: " << _case.date.year << " год " << _case.date.month << " месяц " << _case.date.day << " день " << endl;
	cout << "Время исполнения дела: " << _case.date.time.hours << " часа(-ов) " << _case.date.time.minutes << " минут(-ы)" << endl;
}
void editCase(Case& _case, int list_size)
{
	int choicecriterion;
	char str[SIZE];
	if (list_size == 0)
	{
		cout << "Список пуст. Для редактирования нужно что-то добавить" << endl;
		return;
	}
	cout << "Какой критерий дела вы хотите изменить?" << endl;
	cout << "1 - Имя дела" << endl;
	cout << "2 - Приоритет дела" << endl;
	cout << "3 - Описание дела" << endl;
	cout << "4 - Дата исполнения дела" << endl;
	cout << "5 - Время исполнения дела" << endl;
	do
	{
		cin >> choicecriterion;
		if (!(choicecriterion >= 1 && choicecriterion <= 5))
			cout << "Выберите критерий от 1 до 5" << endl;
	} while (!(choicecriterion >= 1 && choicecriterion <= 5));
	switch (choicecriterion)
	{
	case 1:
		cout << "Введите новое название дела:" << endl;
		cin.ignore();
		cin.getline(str, SIZE);
		strcpy_s(_case.name, str);
		return;
	case 2:
		cout << "Введите новый приоритет дела:" << endl;
		cout << "1 - не важно" << endl;
		cout << "2 - маловажно" << endl;
		cout << "3 - важно" << endl;
		cout << "4 - очень важно" << endl;
		do
		{
			cin >> _case.priority;
			if (!(_case.priority >= 1 && _case.priority <= 4))
				cout << "Приоритет дела должен быть в диапазоне от 1 до 4" << endl;
		} while (!(_case.priority >= 1 && _case.priority <= 4));
		return;
	case 3:
		cout << "Введите новое описание дела:" << endl;
		cin.ignore();
		cin.getline(str, SIZE);
		strcpy_s(_case.description, str);
		return;
	case 4:
		cout << "Введите год исполнения дела:" << endl;
		do
		{
			cin >> _case.date.year;
			if (!(_case.date.year >= 2013 && _case.date.year <= 2123))
				cout << "Год исполнения дела может быть в диапазоне от 2013 года до 2123 года." << endl;
		} while (!(_case.date.year >= 2013 && _case.date.year <= 2123));
		cout << endl;
		cout << "Введите месяц исполнения дела:" << endl;
		do
		{
			cin >> _case.date.month;
			if (!(_case.date.month >= 1 && _case.date.month <= 12))
				cout << "Месяц исполнения дела должен быть в диапазоне от 1 до 12" << endl;
		} while (!(_case.date.month >= 1 && _case.date.month <= 12));
		cout << "Введите день исполнения дела:" << endl;
		do
		{
			cin >> _case.date.day;
			if (_case.date.month == 1 || _case.date.month == 3 || _case.date.month == 5 || _case.date.month == 7 || _case.date.month == 8 || _case.date.month == 10 || _case.date.month == 12)
			{
				if (!(_case.date.day >= 1 && _case.date.day <= 31))
					cout << "В этом месяце нет такого дня" << endl;
				else
					break;
			}
			else if (_case.date.month == 2)
			{
				if (!(_case.date.day >= 1 && _case.date.day <= 28))
					cout << "В этом месяце нет такого дня" << endl;
				else
					break;
			}
			else if (_case.date.month == 4 || _case.date.month == 6 || _case.date.month == 9 || _case.date.month == 11)
			{
				if (!(_case.date.day >= 1 && _case.date.day <= 30))
					cout << "В этом месяце нет такого дня" << endl;
				else
					break;
			}
		} while (true);
		return;
	case 5:
		cout << "Введите в который час было исполнено дело:";
		do
		{
			cin >> _case.date.time.hours;
			if (!(_case.date.time.hours >= 1 && _case.date.time.hours <= 23))
				cout << "Час исполнения дела может быть в диапазоне от 1 до 23 часов" << endl;
		} while (!(_case.date.time.hours >= 1 && _case.date.time.hours <= 23));
		cout << "Введите в какую минуту было исполнено дело:";
		do
		{
			cin >> _case.date.time.minutes;
			if (!(_case.date.time.minutes >= 0 && _case.date.time.minutes <= 59))
				cout << "Минута исполнения дела может быть в диапазоне от 0 до 59 минут" << endl;
		} while (!(_case.date.time.minutes >= 0 && _case.date.time.minutes <= 59));
		return;
	}
}
void findCase(Case* list, int list_size)
{
	int choice, priority, num;
	bool flag = 0;
	char str[SIZE];
	cout << "По какому критерию вы хотите найти дела?" << endl;
	cout << "1 - Имя дела" << endl;
	cout << "2 - Приоритет дела" << endl;
	cout << "3 - Описание дела" << endl;
	cout << "4 - Дата исполнения дела" << endl;
	do
	{
		cin >> choice;
		if (!(choice >= 1 && choice <= 4))
			cout << "Выбор должен быть в диапазоне от 1 до 4" << endl;
	} while (!(choice >= 1 && choice <= 4));
	switch (choice)
	{
	case 1:
		cout << "Введите полностью имя дела, которое хотите найти:" << endl;
		cin.ignore();
		cin.getline(str, SIZE);
		for (int i = 0; i < list_size; i++)
		{
			if (strcmp(str, list[i].name) == 0)
			{
				showCase(list[i], list_size);
				flag = 1; // добавим понятие флага, который будет изменяться, если будет найден хоть один результат
			}
		}
		if (flag == 0)
			cout << "В данном списке нет дел с таким названием" << endl;
		return;
	case 2:
		flag = 0;
		cout << "Введите приоритет дела, которое вы ищете:" << endl;
		cout << "1 - не важно" << endl;
		cout << "2 - маловажно" << endl;
		cout << "3 - важно" << endl;
		cout << "4 - очень важно" << endl;
		do
		{
			cin >> priority;
			if (!(priority >= 1 && priority <= 4))
				cout << "Приоритет дела должен быть в диапазоне от 1 до 4" << endl;
		} while (!(priority >= 1 && priority <= 4));
		for (int i = 0; i < list_size; i++)
		{
			if (list[i].priority == priority)
			{
				showCase(list[i], list_size);
				flag = 1;
			}
		}
		if (flag == 0)
			cout << "В данном списке нет дел с таким приоритетом" << endl;
		return;
	case 3:
		flag = 0;
		cout << "Введите описание дела, которое вы ищете" << endl;
		cin.ignore();
		cin.getline(str, SIZE);
		for (int i = 0; i < list_size; i++)
		{
			if (strcmp(str, list[i].description) == 0)
			{
				showCase(list[i], list_size);
				flag = 1;
			}
		}
		if (flag == 0)
			cout << "В данном списке нет дел с таким описанием" << endl;
		return;
	case 4:
		flag = 0;
		int datechoice;
		cout << "Вы хотите найти дело по году,месяцу или дню?" << endl;
		cout << "1 - год" << endl;
		cout << "2 - месяц" << endl;
		cout << "3 - день " << endl;
		do
		{
			cin >> datechoice;
			if (!(datechoice >= 1 && datechoice <= 3))
				cout << "Сделайте, пожалуйста, выбор от 1 до 3" << endl;
		} while (!(datechoice >= 1 && datechoice <= 3));
		switch (datechoice)
		{
		case 1:
			cout << "Введите год дела, которое вы ищете" << endl;
			cin >> num;
			for (int i = 0; i < list_size; i++)
			{
				if (num == list[i].date.year)
				{
					showCase(list[i], list_size);
					flag = 1;
				}
			}
			if (flag == 0)
				cout << "В данном списке нет дел с таким годом исполнения" << endl;
			return;
		case 2:
			cout << "Введите месяц дела, которое вы ищете" << endl;
			cin >> num;
			for (int i = 0; i < list_size; i++)
			{
				if (num == list[i].date.month)
				{
					showCase(list[i], list_size);
					flag = 1;
				}
			}
			if (flag == 0)
				cout << "В данном списке нет дел с таким месяцем исполнения" << endl;
			return;
		case 3:
			cout << "Введите день дела, которое вы ищете" << endl;
			cin >> num;
			for (int i = 0; i < list_size; i++)
			{
				if (num == list[i].date.day)
				{
					showCase(list[i], list_size);
					flag = 1;
				}
			}
			if (flag == 0)
				cout << "В этом списке нет дел с таким днем исполнения" << endl;
			return;
		}

	}
}
void sortList(Case*& list, int list_size)
{
	int choice, sortdirection;
	cout << "По какому критерию вы хотите отсортировать список?" << endl;
	cout << "1 - по имени" << endl;
	cout << "2 - по приоритету" << endl;
	cout << "3 - по дате исполнения" << endl;
	do
	{
		cin >> choice;
		if (!(choice >= 1 && choice <= 3))
			cout << "Нет такого варианта" << endl;
	} while (!(choice >= 1 && choice <= 3));
	switch (choice)
	{
	case 1:
		cout << "Вы хотите отсортировать список по убыванию имени или по возрастанию?" << endl;
		cout << "1 - по возрастанию" << endl;
		cout << "2 - по убыванию" << endl;
		do
		{
			cin >> sortdirection;
			if (!(sortdirection >= 1 && sortdirection <= 2))
				cout << "Нет такого варианта" << endl;
		} while (!(sortdirection >= 1 && sortdirection <= 2));
		switch (sortdirection)
		{
		case 1:
			for (int i = 0; i < list_size; i++)
			{
				for (int j = list_size - 1; j > i; j--)
				{
					if (strcmp(list[j].name, list[j - 1].name) == -1)
						swap(list[j], list[j - 1]);
				}
			}
			return;
		case 2:
			for (int i = 0; i < list_size; i++)
			{
				for (int j = list_size - 1; j > i; j--)
				{
					if (strcmp(list[j].name, list[j - 1].name) == 1)
						swap(list[j], list[j - 1]);
				}
			}
			return;
		}
	case 2:
		cout << "Вы хотите отсортировать список по убыванию приоритета или по возрастанию?" << endl;
		cout << "1 - по возрастанию" << endl;
		cout << "2 - по убыванию" << endl;
		do
		{
			cin >> sortdirection;
			if (!(sortdirection >= 1 && sortdirection <= 2))
				cout << "Нет такого варианта" << endl;

		} while (!(sortdirection >= 1 && sortdirection <= 2));
		switch (sortdirection)
		{
		case 1:
			for (int i = 0; i < list_size; i++)
			{
				for (int j = list_size - 1; j > i; j--)
				{
					if (list[j].priority < list[j - 1].priority)
						swap(list[j], list[j - 1]);
				}
			}
			return;
		case 2:
			for (int i = 0; i < list_size; i++)
			{
				for (int j = list_size - 1; j > i; j--)
				{
					if (list[j].priority > list[j - 1].priority)
						swap(list[j], list[j - 1]);
				}
			}
			return;
		}
	case 3:
		cout << "Вы хотите отсортировать список по убыванию даты и времени исполнения?" << endl;
		cout << "1 - по возрастанию" << endl;
		cout << "2 - по убыванию" << endl;
		do
		{
			cin >> sortdirection;
			if (!(sortdirection >= 1 && sortdirection <= 2))
				cout << "Нет такого варианта" << endl;

		} while (!(sortdirection >= 1 && sortdirection <= 2));
		switch (sortdirection)
		{
		case 1: // по возрастанию 
			for (int i = 0; i < list_size; i++)
			{
				for (int j = list_size - 1; j > i; j--)
				{ //довольно большой список условий для правильной сортировки списка
					if (list[j].date.year < list[j - 1].date.year || (list[j].date.year == list[j - 1].date.year && list[j].date.month < list[j - 1].date.month) || (list[j].date.year == list[j - 1].date.year && list[j].date.month == list[j - 1].date.month && list[j].date.day < list[j - 1].date.day) ||
						(list[j].date.year == list[j - 1].date.year && list[j].date.month == list[j - 1].date.month && list[j].date.day == list[j - 1].date.day && list[j].date.time.hours < list[j - 1].date.time.hours) ||
						(list[j].date.year == list[j - 1].date.year && list[j].date.month == list[j - 1].date.month && list[j].date.day == list[j - 1].date.day && list[j].date.time.hours == list[j - 1].date.time.hours && list[j].date.time.minutes < list[j - 1].date.time.minutes))
						swap(list[j], list[j - 1]);
				}
			}
			return;
		case 2: // по убыванию
			for (int i = 0; i < list_size; i++)
			{
				for (int j = list_size - 1; j > i; j--)
				{
					if (list[j].date.year > list[j - 1].date.year || (list[j].date.year == list[j - 1].date.year && list[j].date.month > list[j - 1].date.month) || (list[j].date.year == list[j - 1].date.year && list[j].date.month == list[j - 1].date.month && list[j].date.day > list[j - 1].date.day) ||
						(list[j].date.year == list[j - 1].date.year && list[j].date.month == list[j - 1].date.month && list[j].date.day == list[j - 1].date.day && list[j].date.time.hours > list[j - 1].date.time.hours) ||
						(list[j].date.year == list[j - 1].date.year && list[j].date.month == list[j - 1].date.month && list[j].date.day == list[j - 1].date.day && list[j].date.time.hours == list[j - 1].date.time.hours && list[j].date.time.minutes > list[j - 1].date.time.minutes))
						swap(list[j], list[j - 1]);
				}
			}
			return;
		}
	}

}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
