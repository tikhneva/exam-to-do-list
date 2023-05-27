#include <iostream>
#include <cstring> //��� ������� strcpy
using namespace std;
const int SIZE = 100; //�������� ��������� ���������� SIZE, ���� ��������� � ��� ���������� � ���������� � ��������
struct Time // ���������, ������� ����� ���������� ����� ���������� ����
{
	int minutes;
	int hours;
};
struct Date //���������, ������������ ���� ����(� �������� ����������)
{
	Time time;
	int year;
	int month;
	int day;
};
struct Case // ������� ���������, ����������� ��� ����(���,���������,��������  � ����)
{
	Date date;
	char name[SIZE];
	char description[SIZE];
	int priority;
};
Case createCase(); // ��������� �������
void addCase(Case*& list, const int SIZE, int& list_size); // ������� ���������� ���� � ������
Case* deleteCase(Case* list, const int SIZE, int& list_size); // ������� �������� ���� �� 
void editCase(Case& _case, int list_size); // ������� �������������� ������ ���� �� ������ �� ��������
void findCase(Case* list, int list_size); // ������� ������ ���� ��� �� ��������� ��������
void showCase(Case _case, int list_size); // ������� ����������� ������
void sortList(Case*& list, int list_size); // ������� ��� ���������� ������
int main()
{
	setlocale(LC_ALL, "");
	int list_size;
	int choice, choicecase;
	bool flag = 0;
	cout << "������� ������ ������:" << endl;
	cin >> list_size;
	Case* list = new Case[SIZE]; //������� ����� ��� 100 ���, �� �������� ������ list_size �������� ������� list
	for (int i = 0; i < list_size; i++)
		list[i] = createCase();
	do
	{
		cout << "��� �� ������ ������� ������?" << endl;
		cout << "1 - �������� ����" << endl;
		cout << "2 - ������� ����" << endl;
		cout << "3 - ���������������� ����" << endl;
		cout << "4 - ����� ���� �� ��������" << endl;
		cout << "5 - ����������� ������ ���" << endl;
		cout << "6 - ������������� ���� �� ��������" << endl;
		cout << "7 - ����� �� ���������" << endl << endl;
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
			cout << "����� ���� �� ������ �������� ?" << endl;
			do
			{
				cin >> choicecase;
				if (!(choicecase >= 1 && choicecase <= list_size))
					cout << "�������� ����� ����, ������� ���� � ������" << endl;
			} while (!(choicecase >= 1 && choicecase <= list_size));
			editCase(list[choicecase - 1], list_size);
			break;
		case 4:
			findCase(list, list_size);
			break;
		case 5:
			for (int i = 0; i < list_size; i++)
				showCase(list[i], list_size);
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
}
Case createCase()
{
	Case _case;//������ �������������, ������ ��� case - ��� ��� �������� �����, ������������ � ����������� switch
	cout << "������� ��� ����:" << endl;
	cin.ignore();//���������� cin.ignore() ����� ������ cin.getline() ��� ��������� ������
	cin.getline(_case.name, SIZE);
	cout << "����� ��������� ����?" << endl;
	cout << "1 - �� �����" << endl;
	cout << "2 - ���������" << endl;
	cout << "3 - �����" << endl;
	cout << "4 - ����� �����" << endl;
	do // ������ �� ��� ��� ���� ������������ �� ������ ����� �� 1 �� 4. ����� ������������ ��� �������� ����� � ������ ��������������
	{
		cin >> _case.priority;
		if (!(_case.priority >= 1 && _case.priority <= 4))
			cout << "��������� ���� ������ ���� � ��������� �� 1 �� 4" << endl;
	} while (!(_case.priority >= 1 && _case.priority <= 4));
	cout << "������� �������� ����(�� 100 ��������):" << endl;
	cin.ignore();
	cin.getline(_case.description, SIZE);
	cout << "������� ��� ���������� ����:" << endl;
	do
	{
		cin >> _case.date.year;
		if (!(_case.date.year >= 2013 && _case.date.year <= 2123))
			cout << "��� ���������� ���� ����� ���� � ��������� �� 2013 ���� �� 2123 ����." << endl;
	} while (!(_case.date.year >= 2013 && _case.date.year <= 2123));
	cout << endl;
	cout << "������� ����� ���������� ����:" << endl;
	do
	{
		cin >> _case.date.month;
		if (!(_case.date.month >= 1 && _case.date.month <= 12))
			cout << "����� ���������� ���� ������ ���� � ��������� �� 1 �� 12" << endl;
	} while (!(_case.date.month >= 1 && _case.date.month <= 12));
	cout << "������� ���� ���������� ����:" << endl;
	do
	{
		cin >> _case.date.day;
		if (_case.date.month == 1 || _case.date.month == 3 || _case.date.month == 5 || _case.date.month == 7 || _case.date.month == 8 || _case.date.month == 10 || _case.date.month == 12)
		{
			if (!(_case.date.day >= 1 && _case.date.day <= 31))
				cout << "� ���� ������ ��� ������ ���" << endl;
			else
				break;
		}
		else if (_case.date.month == 2)
		{
			if (!(_case.date.day >= 1 && _case.date.day <= 28))
				cout << "� ���� ������ ��� ������ ���" << endl;
			else
				break;
		}
		else if (_case.date.month == 4 || _case.date.month == 6 || _case.date.month == 9 || _case.date.month == 11)
		{
			if (!(_case.date.day >= 1 && _case.date.day <= 30))
				cout << "� ���� ������ ��� ������ ���" << endl;
			else
				break;
		}
	} while (true);
	cout << "������� � ������� ��� ���� ��������� ����:" << endl;
	do
	{
		cin >> _case.date.time.hours;
		if (!(_case.date.time.hours >= 0 && _case.date.time.hours <= 23))
			cout << "��� ���������� ���� ����� ���� � ��������� �� 0 �� 23 �����" << endl;
	} while (!(_case.date.time.hours >= 0 && _case.date.time.hours <= 23));
	cout << "������� � ����� ������ ���� ��������� ����:" << endl;
	do
	{
		cin >> _case.date.time.minutes;
		if (!(_case.date.time.minutes >= 0 && _case.date.time.minutes <= 59))
			cout << "������ ���������� ���� ����� ���� � ��������� �� 0 �� 59 �����" << endl;
	} while (!(_case.date.time.minutes >= 0 && _case.date.time.minutes <= 59));
	cout << endl << endl;
	return _case;
}
void addCase(Case*& list, const int SIZE, int& list_size)
{
	list_size++;
	if (list_size > SIZE - 1)
	{
		cout << "������ ����������. �� �� ������ �������� ����";
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
		cout << "� ������ ��� ��� ���. �� �� ������ ������ �������" << endl;
		return list;
	}
	else
	{
		cout << "����� ���� �� ������ �������?" << endl;
		while (true)
		{
			cin >> index;
			if (index > list_size || index <= 0)
			{
				cout << "������� ����� �� 1 �� ������� ������." << endl;
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
	if (list_size == 0)
	{
		cout << "� ��� ��� ���,���� �� �������" << endl;
		return;
	}
	cout << "��� ����: " << _case.name << endl;
	cout << "��������� ����: ";
	switch (_case.priority)
	{
	case 1:
		cout << "�� �����" << endl;
		break;
	case 2:
		cout << "���������" << endl;
		break;
	case 3:
		cout << "�����" << endl;
		break;
	case 4:
		cout << "����� �����" << endl;
		break;
	}
	cout << "�������� ����: " << _case.description << endl;
	cout << "���� ���������� ����: " << _case.date.year << " ��� " << _case.date.month << " ����� " << _case.date.day << " ���� " << endl;
	cout << "����� ���������� ����: " << _case.date.time.hours << " ����(-��) " << _case.date.time.minutes << " �����(-�)" << endl;
}
void editCase(Case& _case, int list_size)
{
	int choicecriterion;
	char str[SIZE];
	if (list_size == 0)
	{
		cout << "������ ����. ��� �������������� ����� ���-�� ��������" << endl;
		return;
	}
	cout << "����� �������� ���� �� ������ ��������?" << endl;
	cout << "1 - ��� ����" << endl;
	cout << "2 - ��������� ����" << endl;
	cout << "3 - �������� ����" << endl;
	cout << "4 - ���� ���������� ����" << endl;
	cout << "5 - ����� ���������� ����" << endl;
	do
	{
		cin >> choicecriterion;
		if (!(choicecriterion >= 1 && choicecriterion <= 5))
			cout << "�������� �������� �� 1 �� 5" << endl;
	} while (!(choicecriterion >= 1 && choicecriterion <= 5));
	switch (choicecriterion)
	{
	case 1:
		cout << "������� ����� �������� ����:" << endl;
		cin.ignore();
		cin.getline(str, SIZE);
		strcpy_s(_case.name, str);
		return;
	case 2:
		cout << "������� ����� ��������� ����:" << endl;
		cout << "1 - �� �����" << endl;
		cout << "2 - ���������" << endl;
		cout << "3 - �����" << endl;
		cout << "4 - ����� �����" << endl;
		do
		{
			cin >> _case.priority;
			if (!(_case.priority >= 1 && _case.priority <= 4))
				cout << "��������� ���� ������ ���� � ��������� �� 1 �� 4" << endl;
		} while (!(_case.priority >= 1 && _case.priority <= 4));
		return;
	case 3:
		cout << "������� ����� �������� ����:" << endl;
		cin.ignore();
		cin.getline(str, SIZE);
		strcpy_s(_case.description, str);
		return;
	case 4:
		cout << "������� ��� ���������� ����:" << endl;
		do
		{
			cin >> _case.date.year;
			if (!(_case.date.year >= 2013 && _case.date.year <= 2123))
				cout << "��� ���������� ���� ����� ���� � ��������� �� 2013 ���� �� 2123 ����." << endl;
		} while (!(_case.date.year >= 2013 && _case.date.year <= 2123));
		cout << endl;
		cout << "������� ����� ���������� ����:" << endl;
		do
		{
			cin >> _case.date.month;
			if (!(_case.date.month >= 1 && _case.date.month <= 12))
				cout << "����� ���������� ���� ������ ���� � ��������� �� 1 �� 12" << endl;
		} while (!(_case.date.month >= 1 && _case.date.month <= 12));
		cout << "������� ���� ���������� ����:" << endl;
		do
		{
			cin >> _case.date.day;
			if (_case.date.month == 1 || _case.date.month == 3 || _case.date.month == 5 || _case.date.month == 7 || _case.date.month == 8 || _case.date.month == 10 || _case.date.month == 12)
			{
				if (!(_case.date.day >= 1 && _case.date.day <= 31))
					cout << "� ���� ������ ��� ������ ���" << endl;
				else
					break;
			}
			else if (_case.date.month == 2)
			{
				if (!(_case.date.day >= 1 && _case.date.day <= 28))
					cout << "� ���� ������ ��� ������ ���" << endl;
				else
					break;
			}
			else if (_case.date.month == 4 || _case.date.month == 6 || _case.date.month == 9 || _case.date.month == 11)
			{
				if (!(_case.date.day >= 1 && _case.date.day <= 30))
					cout << "� ���� ������ ��� ������ ���" << endl;
				else
					break;
			}
		} while (true);
		return;
	case 5:
		cout << "������� � ������� ��� ���� ��������� ����:";
		do
		{
			cin >> _case.date.time.hours;
			if (!(_case.date.time.hours >= 1 && _case.date.time.hours <= 23))
				cout << "��� ���������� ���� ����� ���� � ��������� �� 1 �� 23 �����" << endl;
		} while (!(_case.date.time.hours >= 1 && _case.date.time.hours <= 23));
		cout << "������� � ����� ������ ���� ��������� ����:";
		do
		{
			cin >> _case.date.time.minutes;
			if (!(_case.date.time.minutes >= 0 && _case.date.time.minutes <= 59))
				cout << "������ ���������� ���� ����� ���� � ��������� �� 0 �� 59 �����" << endl;
		} while (!(_case.date.time.minutes >= 0 && _case.date.time.minutes <= 59));
		return;
	}
}
void findCase(Case* list, int list_size)
{
	int choice, priority, num;
	bool flag = 0;
	char str[SIZE];
	cout << "�� ������ �������� �� ������ ����� ����?" << endl;
	cout << "1 - ��� ����" << endl;
	cout << "2 - ��������� ����" << endl;
	cout << "3 - �������� ����" << endl;
	cout << "4 - ���� ���������� ����" << endl;
	do
	{
		cin >> choice;
		if (!(choice >= 1 && choice <= 4))
			cout << "����� ������ ���� � ��������� �� 1 �� 4" << endl;
	} while (!(choice >= 1 && choice <= 4));
	switch (choice)
	{
	case 1:
		cout << "������� ��������� ��� ����, ������� ������ �����:" << endl;
		cin.ignore();
		cin.getline(str, SIZE);
		for (int i = 0; i < list_size; i++)
		{
			if (strcmp(str, list[i].name) == 0)
			{
				showCase(list[i], list_size);
				flag = 1; // ������� ������� �����, ������� ����� ����������, ���� ����� ������ ���� ���� ���������
			}
		}
		if (flag == 0)
			cout << "� ������ ������ ��� ��� � ����� ���������" << endl;
		return;
	case 2:
		flag = 0;
		cout << "������� ��������� ����, ������� �� �����:" << endl;
		cout << "1 - �� �����" << endl;
		cout << "2 - ���������" << endl;
		cout << "3 - �����" << endl;
		cout << "4 - ����� �����" << endl;
		do
		{
			cin >> priority;
			if (!(priority >= 1 && priority <= 4))
				cout << "��������� ���� ������ ���� � ��������� �� 1 �� 4" << endl;
		} while (!(priority >= 1 && priority <= 4));
		for (int i = 0; i < list_size; i++)
		{
			if (list[i].priority = priority)
			{
				showCase(list[i], list_size);
				flag = 1;
			}
		}
		if (flag == 0)
			cout << "� ������ ������ ��� ��� � ����� �����������" << endl;
		return;
	case 3:
		flag = 0;
		cout << "������� �������� ����, ������� �� �����" << endl;
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
			cout << "� ������ ������ ��� ��� � ����� ���������" << endl;
		return;
	case 4:
		flag = 0;
		int datechoice;
		cout << "�� ������ ����� ���� �� ����,������ ��� ���?" << endl;
		cout << "1 - ���" << endl;
		cout << "2 - �����" << endl;
		cout << "3 - ���� " << endl;
		do
		{
			cin >> datechoice;
			if (!(datechoice >= 1 && datechoice <= 3))
				cout << "��������, ����������, ����� �� 1 �� 3" << endl;
		} while (!(datechoice >= 1 && datechoice <= 3));
		switch (datechoice)
		{
		case 1:
			cout << "������� ��� ����, ������� �� �����" << endl;
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
				cout << "� ������ ������ ��� ��� � ����� ����� ����������" << endl;
			return;
		case 2:
			cout << "������� ����� ����, ������� �� �����" << endl;
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
				cout << "� ������ ������ ��� ��� � ����� ������� ����������" << endl;
			return;
		case 3:
			cout << "������� ���� ����, ������� �� �����" << endl;
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
				cout << "� ���� ������ ��� ��� � ����� ���� ����������" << endl;
			return;
		}

	}
}
void sortList(Case*& list, int list_size)
{
	int choice, sortdirection;
	cout << "�� ������ �������� �� ������ ������������� ������?" << endl;
	cout << "1 - �� �����" << endl;
	cout << "2 - �� ����������" << endl;
	cout << "3 - �� ���� ����������" << endl;
	do
	{
		cin >> choice;
		if (!(choice >= 1 && choice <= 3))
			cout << "��� ������ ��������" << endl;
	} while (!(choice >= 1 && choice <= 3));
	switch (choice)
	{
	case 1:
		cout << "�� ������ ������������� ������ �� �������� ����� ��� �� �����������?" << endl;
		cout << "1 - �� �����������" << endl;
		cout << "2 - �� ��������" << endl;
		do
		{
			cin >> sortdirection;
			if (!(sortdirection >= 1 && sortdirection <= 2))
				cout << "��� ������ ��������" << endl;
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
		cout << "�� ������ ������������� ������ �� �������� ���������� ��� �� �����������?" << endl;
		cout << "1 - �� �����������" << endl;
		cout << "2 - �� ��������" << endl;
		do
		{
			cin >> sortdirection;
			if (!(sortdirection >= 1 && sortdirection <= 2))
				cout << "��� ������ ��������" << endl;

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
		cout << "�� ������ ������������� ������ �� �������� ���� � ������� ����������?" << endl;
		cout << "1 - �� �����������" << endl;
		cout << "2 - �� ��������" << endl;
		do
		{
			cin >> sortdirection;
			if (!(sortdirection >= 1 && sortdirection <= 2))
				cout << "��� ������ ��������" << endl;

		} while (!(sortdirection >= 1 && sortdirection <= 2));
		switch (sortdirection)
		{
		case 1: // �� ����������� 
			for (int i = 0; i < list_size; i++)
			{
				for (int j = list_size - 1; j > i; j--)
				{ //�������� ������� ������ ������� ��� ���������� ���������� ������
					if (list[j].date.year < list[j - 1].date.year || (list[j].date.year == list[j - 1].date.year && list[j].date.month < list[j - 1].date.month) || (list[j].date.year == list[j - 1].date.year && list[j].date.month == list[j - 1].date.month && list[j].date.day < list[j - 1].date.day) ||
						(list[j].date.year == list[j - 1].date.year && list[j].date.month == list[j - 1].date.month && list[j].date.day == list[j - 1].date.day && list[j].date.time.hours < list[j - 1].date.time.hours) ||
						(list[j].date.year == list[j - 1].date.year && list[j].date.month == list[j - 1].date.month && list[j].date.day == list[j - 1].date.day && list[j].date.time.hours == list[j - 1].date.time.hours && list[j].date.time.minutes < list[j - 1].date.time.minutes))
						swap(list[j], list[j - 1]);
				}
			}
			return;
		case 2: // �� ��������
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
