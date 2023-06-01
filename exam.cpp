#include <iostream>
#include <cstring> 
using namespace std;
const int SIZE = 20;
struct Time // ñòðóêòóðà, êîòîðàÿ áóäåò îáîçíà÷àòü âðåìÿ èñïîëíåíèÿ äåëà
{
	int minutes;
	int hours;
};
struct Date //ñòðóêòóðà, îáîçíà÷àþùàÿ äàòó äåëà(è âðåìåíåì èñïîëíåíèÿ)
{
	Time time;
	int year;
	int month;
	int day;
};
struct Case // ãëàâíàÿ ñòðóêòóðà, îïèñûâàþùåå âñå äåëî(èìÿ,ïðèîðèòåò,îïèñàíèå  è äàòó)
{
	Date date;
	char name[SIZE];
	char description[SIZE];
	int priority;
};
Case createCase(); // ïðîòîòèïû ôóíêöèé
void addCase(Case*& list, const int SIZE, int& list_size); // ôóíêöèÿ äîáàâëåíèÿ äåëà â ñïèñîê
Case* deleteCase(Case* list, const int SIZE, int& list_size); // ôóíêöèÿ óäàëåíèÿ äåëà èç 
void editCase(Case& _case, int list_size); // ôóíêöèÿ ðåäàêòèðîâàíèÿ ëþáîãî äåëà èç ñïèñêà ïî êðèòåðèþ
void findCase(Case* list, int list_size); // ôóíêöèÿ ïîèñêà âñåõ äåë ïî çàäàííîìó êðèòåðèþ
void showCase(Case _case, int list_size); // ôóíêöèÿ îòîáðàæåíèÿ ñïèñêà
void sortList(Case*& list, int list_size); // ôóíêöèÿ äëÿ ñîðòèðîâêè ñïèñêà
int main()
{
	setlocale(LC_ALL, "");
	int list_size;
	int choice, choicecase;
	bool flag = 0;
	cout << "Ââåäèòå ðàçìåð ñïèñêà:" << endl;
	cin >> list_size;
	Case* list = new Case[SIZE]; //âûäåëèì ìåñòî ïîä 100 äåë, íî çàïîëíèì òîëüêî list_size çíà÷åíèé ìàññèâà list
	for (int i = 0; i < list_size; i++)
		list[i] = createCase();
	do
	{
		cout << "×òî âû õîòèòå ñäåëàòü äàëüøå?" << endl;
		cout << "1 - äîáàâèòü äåëî" << endl;
		cout << "2 - óäàëèòü äåëî" << endl;
		cout << "3 - îòðåäàêòèðîâàíèå äåëà" << endl;
		cout << "4 - ïîèñê äåëà ïî êðèòåðèþ" << endl;
		cout << "5 - îòîáðàæåíèå ñïèñêà äåë" << endl;
		cout << "6 - îòñîðòèðîâàòü äåëî ïî êðèòåðèþ" << endl;
		cout << "7 - âûõîä èç ïðîãðàììû" << endl << endl;
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
			cout << "Êàêîå äåëî âû õîòèòå ïîìåíÿòü ?" << endl;
			do
			{
				cin >> choicecase;
				if (!(choicecase >= 1 && choicecase <= list_size))
					cout << "Âûáåðèòå íîìåð äåëà, êîòîðîå åñòü â ñïèñêå" << endl;
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
}
Case createCase()
{
	Case _case;//íèæíåå ïîä÷åðêèâàíèå, ïîòîìó ÷òî case - ýòî óæå êëþ÷åâîå ñëîâî, èñïîëüçóåìîå â êîíñòðóêöèè switch
	cout << "Ââåäèòå èìÿ äåëà:" << endl;
	cin.ignore();//èñïîëüçóåì cin.ignore() ïåðåä êàæäûì cin.getline() äëÿ èçáåæàíèÿ îøèáîê
	cin.getline(_case.name, SIZE);
	cout << "Êàêîé ïðèîðèòåò äåëà?" << endl;
	cout << "1 - íå âàæíî" << endl;
	cout << "2 - ìàëîâàæíî" << endl;
	cout << "3 - âàæíî" << endl;
	cout << "4 - î÷åíü âàæíî" << endl;
	do // äåëàåì äî òåõ ïîð ïîêà ïîëüçîâàòåëü íå ââåäåò ÷èñëî îò 1 äî 4. Áóäåì èñïîëüçîâàòü ýòè ïðîâåðêè ïî÷òè ó êàæäîé õàðàêòåðèñòèêè
	{
		cin >> _case.priority;
		if (!(_case.priority >= 1 && _case.priority <= 4))
			cout << "Ïðèîðèòåò äåëà äîëæåí áûòü â äèàïàçîíå îò 1 äî 4" << endl;
	} while (!(_case.priority >= 1 && _case.priority <= 4));
	cout << "Ââåäèòå îïèñàíèå äåëà(äî 100 ñèìâîëîâ):" << endl;
	cin.ignore();
	cin.getline(_case.description, SIZE);
	cout << "Ââåäèòå ãîä èñïîëíåíèÿ äåëà:" << endl;
	do
	{
		cin >> _case.date.year;
		if (!(_case.date.year >= 2013 && _case.date.year <= 2123))
			cout << "Ãîä èñïîëíåíèÿ äåëà ìîæåò áûòü â äèàïàçîíå îò 2013 ãîäà äî 2123 ãîäà." << endl;
	} while (!(_case.date.year >= 2013 && _case.date.year <= 2123));
	cout << endl;
	cout << "Ââåäèòå ìåñÿö èñïîëíåíèÿ äåëà:" << endl;
	do
	{
		cin >> _case.date.month;
		if (!(_case.date.month >= 1 && _case.date.month <= 12))
			cout << "Ìåñÿö èñïîëíåíèÿ äåëà äîëæåí áûòü â äèàïàçîíå îò 1 äî 12" << endl;
	} while (!(_case.date.month >= 1 && _case.date.month <= 12));
	cout << "Ââåäèòå äåíü èñïîëíåíèÿ äåëà:" << endl;
	do
	{
		cin >> _case.date.day;
		if (_case.date.month == 1 || _case.date.month == 3 || _case.date.month == 5 || _case.date.month == 7 || _case.date.month == 8 || _case.date.month == 10 || _case.date.month == 12)
		{
			if (!(_case.date.day >= 1 && _case.date.day <= 31))
				cout << "Â ýòîì ìåñÿöå íåò òàêîãî äíÿ" << endl;
			else
				break;
		}
		else if (_case.date.month == 2)
		{
			if (!(_case.date.day >= 1 && _case.date.day <= 28))
				cout << "Â ýòîì ìåñÿöå íåò òàêîãî äíÿ" << endl;
			else
				break;
		}
		else if (_case.date.month == 4 || _case.date.month == 6 || _case.date.month == 9 || _case.date.month == 11)
		{
			if (!(_case.date.day >= 1 && _case.date.day <= 30))
				cout << "Â ýòîì ìåñÿöå íåò òàêîãî äíÿ" << endl;
			else
				break;
		}
	} while (true);
	cout << "Ââåäèòå â êîòîðûé ÷àñ áûëî èñïîëíåíî äåëî:" << endl;
	do
	{
		cin >> _case.date.time.hours;
		if (!(_case.date.time.hours >= 0 && _case.date.time.hours <= 23))
			cout << "×àñ èñïîëíåíèÿ äåëà ìîæåò áûòü â äèàïàçîíå îò 0 äî 23 ÷àñîâ" << endl;
	} while (!(_case.date.time.hours >= 0 && _case.date.time.hours <= 23));
	cout << "Ââåäèòå â êàêóþ ìèíóòó áûëî èñïîëíåíî äåëî:" << endl;
	do
	{
		cin >> _case.date.time.minutes;
		if (!(_case.date.time.minutes >= 0 && _case.date.time.minutes <= 59))
			cout << "Ìèíóòà èñïîëíåíèÿ äåëà ìîæåò áûòü â äèàïàçîíå îò 0 äî 59 ìèíóò" << endl;
	} while (!(_case.date.time.minutes >= 0 && _case.date.time.minutes <= 59));
	cout << endl << endl;
	return _case;
}
void addCase(Case*& list, const int SIZE, int& list_size)
{
	list_size++;
	if (list_size >= SIZE)
	{
		cout << "Ñïèñîê ïåðåïîëíåí. Âû íå ìîæåòå äîáàâèòü äåëî";
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
		cout << "Â ñïèñêå óæå íåò äåë. Âû íå ìîæåòå íè÷åãî óäàëèòü" << endl;
		return list;
	}
	else
	{
		cout << "Êàêîå äåëî âû õîòèòå óäàëèòü?" << endl;
		while (true)
		{
			cin >> index;
			if (index > list_size || index <= 0)
			{
				cout << "Ââåäèòå ÷èñëî îò 1 äî ðàçìåðà ñïèñêà." << endl;
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
		cout << "Ó âàñ íåò äåë,÷òîá èõ âûâåñòè" << endl;
		return;
	}
	cout << "Èìÿ äåëà: " << _case.name << endl;
	cout << "Ïðèîðèòåò äåëà: ";
	switch (_case.priority)
	{
	case 1:
		cout << "Íå âàæíî" << endl;
		break;
	case 2:
		cout << "Ìàëîâàæíî" << endl;
		break;
	case 3:
		cout << "Âàæíî" << endl;
		break;
	case 4:
		cout << "Î÷åíü âàæíî" << endl;
		break;
	}
	cout << "Îïèñàíèå äåëà: " << _case.description << endl;
	cout << "Äàòà èñïîëíåíèÿ äåëà: " << _case.date.year << " ãîä " << _case.date.month << " ìåñÿö " << _case.date.day << " äåíü " << endl;
	cout << "Âðåìÿ èñïîëíåíèÿ äåëà: " << _case.date.time.hours << " ÷àñà(-îâ) " << _case.date.time.minutes << " ìèíóò(-û)" << endl;
}
void editCase(Case& _case, int list_size)
{
	int choicecriterion;
	char str[SIZE];
	if (list_size == 0)
	{
		cout << "Ñïèñîê ïóñò. Äëÿ ðåäàêòèðîâàíèÿ íóæíî ÷òî-òî äîáàâèòü" << endl;
		return;
	}
	cout << "Êàêîé êðèòåðèé äåëà âû õîòèòå èçìåíèòü?" << endl;
	cout << "1 - Èìÿ äåëà" << endl;
	cout << "2 - Ïðèîðèòåò äåëà" << endl;
	cout << "3 - Îïèñàíèå äåëà" << endl;
	cout << "4 - Äàòà èñïîëíåíèÿ äåëà" << endl;
	cout << "5 - Âðåìÿ èñïîëíåíèÿ äåëà" << endl;
	do
	{
		cin >> choicecriterion;
		if (!(choicecriterion >= 1 && choicecriterion <= 5))
			cout << "Âûáåðèòå êðèòåðèé îò 1 äî 5" << endl;
	} while (!(choicecriterion >= 1 && choicecriterion <= 5));
	switch (choicecriterion)
	{
	case 1:
		cout << "Ââåäèòå íîâîå íàçâàíèå äåëà:" << endl;
		cin.ignore();
		cin.getline(str, SIZE);
		strcpy_s(_case.name, str);
		return;
	case 2:
		cout << "Ââåäèòå íîâûé ïðèîðèòåò äåëà:" << endl;
		cout << "1 - íå âàæíî" << endl;
		cout << "2 - ìàëîâàæíî" << endl;
		cout << "3 - âàæíî" << endl;
		cout << "4 - î÷åíü âàæíî" << endl;
		do
		{
			cin >> _case.priority;
			if (!(_case.priority >= 1 && _case.priority <= 4))
				cout << "Ïðèîðèòåò äåëà äîëæåí áûòü â äèàïàçîíå îò 1 äî 4" << endl;
		} while (!(_case.priority >= 1 && _case.priority <= 4));
		return;
	case 3:
		cout << "Ââåäèòå íîâîå îïèñàíèå äåëà:" << endl;
		cin.ignore();
		cin.getline(str, SIZE);
		strcpy_s(_case.description, str);
		return;
	case 4:
		cout << "Ââåäèòå ãîä èñïîëíåíèÿ äåëà:" << endl;
		do
		{
			cin >> _case.date.year;
			if (!(_case.date.year >= 2013 && _case.date.year <= 2123))
				cout << "Ãîä èñïîëíåíèÿ äåëà ìîæåò áûòü â äèàïàçîíå îò 2013 ãîäà äî 2123 ãîäà." << endl;
		} while (!(_case.date.year >= 2013 && _case.date.year <= 2123));
		cout << endl;
		cout << "Ââåäèòå ìåñÿö èñïîëíåíèÿ äåëà:" << endl;
		do
		{
			cin >> _case.date.month;
			if (!(_case.date.month >= 1 && _case.date.month <= 12))
				cout << "Ìåñÿö èñïîëíåíèÿ äåëà äîëæåí áûòü â äèàïàçîíå îò 1 äî 12" << endl;
		} while (!(_case.date.month >= 1 && _case.date.month <= 12));
		cout << "Ââåäèòå äåíü èñïîëíåíèÿ äåëà:" << endl;
		do
		{
			cin >> _case.date.day;
			if (_case.date.month == 1 || _case.date.month == 3 || _case.date.month == 5 || _case.date.month == 7 || _case.date.month == 8 || _case.date.month == 10 || _case.date.month == 12)
			{
				if (!(_case.date.day >= 1 && _case.date.day <= 31))
					cout << "Â ýòîì ìåñÿöå íåò òàêîãî äíÿ" << endl;
				else
					break;
			}
			else if (_case.date.month == 2)
			{
				if (!(_case.date.day >= 1 && _case.date.day <= 28))
					cout << "Â ýòîì ìåñÿöå íåò òàêîãî äíÿ" << endl;
				else
					break;
			}
			else if (_case.date.month == 4 || _case.date.month == 6 || _case.date.month == 9 || _case.date.month == 11)
			{
				if (!(_case.date.day >= 1 && _case.date.day <= 30))
					cout << "Â ýòîì ìåñÿöå íåò òàêîãî äíÿ" << endl;
				else
					break;
			}
		} while (true);
		return;
	case 5:
		cout << "Ââåäèòå â êîòîðûé ÷àñ áûëî èñïîëíåíî äåëî:";
		do
		{
			cin >> _case.date.time.hours;
			if (!(_case.date.time.hours >= 1 && _case.date.time.hours <= 23))
				cout << "×àñ èñïîëíåíèÿ äåëà ìîæåò áûòü â äèàïàçîíå îò 1 äî 23 ÷àñîâ" << endl;
		} while (!(_case.date.time.hours >= 1 && _case.date.time.hours <= 23));
		cout << "Ââåäèòå â êàêóþ ìèíóòó áûëî èñïîëíåíî äåëî:";
		do
		{
			cin >> _case.date.time.minutes;
			if (!(_case.date.time.minutes >= 0 && _case.date.time.minutes <= 59))
				cout << "Ìèíóòà èñïîëíåíèÿ äåëà ìîæåò áûòü â äèàïàçîíå îò 0 äî 59 ìèíóò" << endl;
		} while (!(_case.date.time.minutes >= 0 && _case.date.time.minutes <= 59));
		return;
	}
}
void findCase(Case* list, int list_size)
{
	int choice, priority, num;
	bool flag = 0;
	char str[SIZE];
	cout << "Ïî êàêîìó êðèòåðèþ âû õîòèòå íàéòè äåëà?" << endl;
	cout << "1 - Èìÿ äåëà" << endl;
	cout << "2 - Ïðèîðèòåò äåëà" << endl;
	cout << "3 - Îïèñàíèå äåëà" << endl;
	cout << "4 - Äàòà èñïîëíåíèÿ äåëà" << endl;
	do
	{
		cin >> choice;
		if (!(choice >= 1 && choice <= 4))
			cout << "Âûáîð äîëæåí áûòü â äèàïàçîíå îò 1 äî 4" << endl;
	} while (!(choice >= 1 && choice <= 4));
	switch (choice)
	{
	case 1:
		cout << "Ââåäèòå ïîëíîñòüþ èìÿ äåëà, êîòîðîå õîòèòå íàéòè:" << endl;
		cin.ignore();
		cin.getline(str, SIZE);
		for (int i = 0; i < list_size; i++)
		{
			if (strcmp(str, list[i].name) == 0)
			{
				showCase(list[i], list_size);
				flag = 1; // äîáàâèì ïîíÿòèå ôëàãà, êîòîðûé áóäåò èçìåíÿòüñÿ, åñëè áóäåò íàéäåí õîòü îäèí ðåçóëüòàò
			}
		}
		if (flag == 0)
			cout << "Â äàííîì ñïèñêå íåò äåë ñ òàêèì íàçâàíèåì" << endl;
		return;
	case 2:
		flag = 0;
		cout << "Ââåäèòå ïðèîðèòåò äåëà, êîòîðîå âû èùåòå:" << endl;
		cout << "1 - íå âàæíî" << endl;
		cout << "2 - ìàëîâàæíî" << endl;
		cout << "3 - âàæíî" << endl;
		cout << "4 - î÷åíü âàæíî" << endl;
		do
		{
			cin >> priority;
			if (!(priority >= 1 && priority <= 4))
				cout << "Ïðèîðèòåò äåëà äîëæåí áûòü â äèàïàçîíå îò 1 äî 4" << endl;
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
			cout << "Â äàííîì ñïèñêå íåò äåë ñ òàêèì ïðèîðèòåòîì" << endl;
		return;
	case 3:
		flag = 0;
		cout << "Ââåäèòå îïèñàíèå äåëà, êîòîðîå âû èùåòå" << endl;
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
			cout << "Â äàííîì ñïèñêå íåò äåë ñ òàêèì îïèñàíèåì" << endl;
		return;
	case 4:
		flag = 0;
		int datechoice;
		cout << "Âû õîòèòå íàéòè äåëî ïî ãîäó,ìåñÿöó èëè äíþ?" << endl;
		cout << "1 - ãîä" << endl;
		cout << "2 - ìåñÿö" << endl;
		cout << "3 - äåíü " << endl;
		do
		{
			cin >> datechoice;
			if (!(datechoice >= 1 && datechoice <= 3))
				cout << "Ñäåëàéòå, ïîæàëóéñòà, âûáîð îò 1 äî 3" << endl;
		} while (!(datechoice >= 1 && datechoice <= 3));
		switch (datechoice)
		{
		case 1:
			cout << "Ââåäèòå ãîä äåëà, êîòîðîå âû èùåòå" << endl;
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
				cout << "Â äàííîì ñïèñêå íåò äåë ñ òàêèì ãîäîì èñïîëíåíèÿ" << endl;
			return;
		case 2:
			cout << "Ââåäèòå ìåñÿö äåëà, êîòîðîå âû èùåòå" << endl;
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
				cout << "Â äàííîì ñïèñêå íåò äåë ñ òàêèì ìåñÿöåì èñïîëíåíèÿ" << endl;
			return;
		case 3:
			cout << "Ââåäèòå äåíü äåëà, êîòîðîå âû èùåòå" << endl;
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
				cout << "Â ýòîì ñïèñêå íåò äåë ñ òàêèì äíåì èñïîëíåíèÿ" << endl;
			return;
		}

	}
}
void sortList(Case*& list, int list_size)
{
	int choice, sortdirection;
	cout << "Ïî êàêîìó êðèòåðèþ âû õîòèòå îòñîðòèðîâàòü ñïèñîê?" << endl;
	cout << "1 - ïî èìåíè" << endl;
	cout << "2 - ïî ïðèîðèòåòó" << endl;
	cout << "3 - ïî äàòå èñïîëíåíèÿ" << endl;
	do
	{
		cin >> choice;
		if (!(choice >= 1 && choice <= 3))
			cout << "Íåò òàêîãî âàðèàíòà" << endl;
	} while (!(choice >= 1 && choice <= 3));
	switch (choice)
	{
	case 1:
		cout << "Âû õîòèòå îòñîðòèðîâàòü ñïèñîê ïî óáûâàíèþ èìåíè èëè ïî âîçðàñòàíèþ?" << endl;
		cout << "1 - ïî âîçðàñòàíèþ" << endl;
		cout << "2 - ïî óáûâàíèþ" << endl;
		do
		{
			cin >> sortdirection;
			if (!(sortdirection >= 1 && sortdirection <= 2))
				cout << "Íåò òàêîãî âàðèàíòà" << endl;
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
		cout << "Âû õîòèòå îòñîðòèðîâàòü ñïèñîê ïî óáûâàíèþ ïðèîðèòåòà èëè ïî âîçðàñòàíèþ?" << endl;
		cout << "1 - ïî âîçðàñòàíèþ" << endl;
		cout << "2 - ïî óáûâàíèþ" << endl;
		do
		{
			cin >> sortdirection;
			if (!(sortdirection >= 1 && sortdirection <= 2))
				cout << "Íåò òàêîãî âàðèàíòà" << endl;

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
		cout << "Âû õîòèòå îòñîðòèðîâàòü ñïèñîê ïî óáûâàíèþ äàòû è âðåìåíè èñïîëíåíèÿ?" << endl;
		cout << "1 - ïî âîçðàñòàíèþ" << endl;
		cout << "2 - ïî óáûâàíèþ" << endl;
		do
		{
			cin >> sortdirection;
			if (!(sortdirection >= 1 && sortdirection <= 2))
				cout << "Íåò òàêîãî âàðèàíòà" << endl;

		} while (!(sortdirection >= 1 && sortdirection <= 2));
		switch (sortdirection)
		{
		case 1: // ïî âîçðàñòàíèþ 
			for (int i = 0; i < list_size; i++)
			{
				for (int j = list_size - 1; j > i; j--)
				{ //äîâîëüíî áîëüøîé ñïèñîê óñëîâèé äëÿ ïðàâèëüíîé ñîðòèðîâêè ñïèñêà
					if (list[j].date.year < list[j - 1].date.year || (list[j].date.year == list[j - 1].date.year && list[j].date.month < list[j - 1].date.month) || (list[j].date.year == list[j - 1].date.year && list[j].date.month == list[j - 1].date.month && list[j].date.day < list[j - 1].date.day) ||
						(list[j].date.year == list[j - 1].date.year && list[j].date.month == list[j - 1].date.month && list[j].date.day == list[j - 1].date.day && list[j].date.time.hours < list[j - 1].date.time.hours) ||
						(list[j].date.year == list[j - 1].date.year && list[j].date.month == list[j - 1].date.month && list[j].date.day == list[j - 1].date.day && list[j].date.time.hours == list[j - 1].date.time.hours && list[j].date.time.minutes < list[j - 1].date.time.minutes))
						swap(list[j], list[j - 1]);
				}
			}
			return;
		case 2: // ïî óáûâàíèþ
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
