#include <iostream>
#include <cstring>
#include "functions.h"
#include "internet_work_protocol.h"

using namespace std;

void protocol_Skype(internet_work_protocol* protocol[], int size)
{
	bool(*check_function) = nullptr;
	int sorting_choice = 0;
	cout << "1) Сортировка вставками.\n";
	cout << "2) Быстрая сортировка.\n";
	cout << "Ваш выбор: ";
	while (sorting_choice != 1 && sorting_choice != 2)
	{
		cin >> sorting_choice;
		cout << "\n";
		switch (sorting_choice)
		{
		case 1:
			sorting_choice = 1;
			break;
		case 2:
			sorting_choice = 2;
			break;
		default:
			cout << "Такого выбора нет.\n";
		}
	}

	int criterion_choice = 0;
	cout << "1) По убыванию времени использования сети Интернет.\n";
	cout << "2) Во возрастанию названия программы.\n";
	cout << "Ваш выбор: ";
	while (criterion_choice != 1 && criterion_choice != 2)
	{
		cin >> criterion_choice;
		cout << "\n";
		switch (criterion_choice)
		{
		case 1:
			criterion_choice = 1;
			break;
		case 2:
			criterion_choice = 2;
			break;
		default:
			cout << "Такого выбора нет.\n";
		}

	}

	internet_work_protocol** skype_protocol = new internet_work_protocol*[size];
	int new_size = 0;
	for (int i = 0; i < size; i++)
	{
		string Skype = "Skype";
		bool titles_equal = true;
		if (protocol[i]->title == Skype)
		{
			skype_protocol[new_size] = protocol[i];
			new_size++;
		}
	}

	if (sorting_choice == 1) 
	{
		if (criterion_choice == 1)
			insertion_sort(skype_protocol, new_size, time_used);
		else if (criterion_choice == 2)
			insertion_sort(skype_protocol, new_size, protocol_name);
	}
	else if (sorting_choice == 2)
	{
		if (criterion_choice == 1)
			quick_sort(skype_protocol, time_used, 0, new_size-1);
		else if (criterion_choice == 2)
			quick_sort(skype_protocol, protocol_name, 0, new_size-1);
	}

	for (int i = 0; i < new_size; i++)
	{
		cout << "Время начала работы: " << skype_protocol[i]->start.hour << ":"
			<< skype_protocol[i]->start.minute << ":"
			<< skype_protocol[i]->start.seconds << endl;
		cout << "Время конца работы: " << skype_protocol[i]->finish.hour << ":"
			<< skype_protocol[i]->finish.minute << ":"
			<< skype_protocol[i]->finish.seconds << endl;
		cout << "Получено байт: " << skype_protocol[i]->recieved.byte << endl;
		cout << "Отправлено байт: " << skype_protocol[i]->sent.byte << endl;
		cout << "Название процесса: " << skype_protocol[i]->title << endl;
		cout << "\n";
	}
}

void protocol_8am(internet_work_protocol* protocol[], int size)
{
	bool(*check_function) = nullptr;
	int sorting_choice = 0;
	cout << "1) Сортировка вставками.\n";
	cout << "2) Быстрая сортировка.\n";
	cout << "Ваш выбор: ";
	while (sorting_choice != 1 && sorting_choice != 2)
	{
		cin >> sorting_choice;
		cout << "\n";
		switch (sorting_choice)
		{
		case 1:
			sorting_choice = 1;
			break;
		case 2:
			sorting_choice = 2;
			break;
		default:
			cout << "Такого выбора нет.\n";
		}
	}

	int criterion_choice = 0;
	cout << "1) По убыванию времени использования сети Интернет.\n";
	cout << "2) Во возрастанию названия программы.\n";
	cout << "Ваш выбор: ";
	while (criterion_choice != 1 && criterion_choice != 2)
	{
		cin >> criterion_choice;
		cout << "\n";
		switch (criterion_choice)
		{
		case 1:
			criterion_choice = 1;
			break;
		case 2:
			criterion_choice = 2;
			break;
		default:
			cout << "Такого выбора нет.\n";
		}

	}

	internet_work_protocol** after8hours = new internet_work_protocol*[size];
	int new_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (protocol[i]->start.hour >= 8)
		{
			after8hours[new_size] = protocol[i];
			new_size++;
		}
	}

	if (sorting_choice == 1)
	{
		if (criterion_choice == 1)
			insertion_sort(after8hours, new_size, time_used);
		else if (criterion_choice == 2)
			insertion_sort(after8hours, new_size, protocol_name);
	}
	else if (sorting_choice == 2)
	{
		if (criterion_choice == 1)
			quick_sort(after8hours, time_used, 0, new_size - 1);
		else if (criterion_choice == 2)
			quick_sort(after8hours, protocol_name, 0, new_size - 1);
	}

	for (int i = 0; i < new_size; i++)
	{
		cout << "Время начала работы: " << after8hours[i]->start.hour << ":"
			<< after8hours[i]->start.minute << ":"
			<< after8hours[i]->start.seconds << endl;
		cout << "Время конца работы: " << after8hours[i]->finish.hour << ":"
			<< after8hours[i]->finish.minute << ":"
			<< after8hours[i]->finish.seconds << endl;
		cout << "Получено байт: " << after8hours[i]->recieved.byte << endl;
		cout << "Отправлено байт: " << after8hours[i]->sent.byte << endl;
		cout << "Название процесса: " << after8hours[i]->title << endl;
		cout << "\n";
	}
}

bool time_used(internet_work_protocol* a, internet_work_protocol* b)
{
	int a_runtime_start = a->start.hour * 3600 + a->start.minute * 60 + a->start.seconds;
	int a_runtime_finish = a->finish.hour * 3600 + a->finish.minute * 60 + a->finish.seconds;
	int b_runtime_start = b->start.hour * 3600 + b->start.minute * 60 + b->start.seconds;
	int b_runtime_finish = b->finish.hour * 3600 + b->finish.minute * 60 + b->finish.seconds;
	return abs(a_runtime_finish - a_runtime_start) > abs(b_runtime_finish - b_runtime_start);
}
bool protocol_name(internet_work_protocol* a, internet_work_protocol* b)
{
	if (strcmp(a->title, b->title) == 0)
	{
		return (a->sent.byte + a->recieved.byte) > (b->sent.byte + b->recieved.byte);
	}
	else if (strcmp(a->title, b->title) > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void insertion_sort(internet_work_protocol* protocol[], int size, bool(*criterion)(internet_work_protocol* a, internet_work_protocol* b))
{
	for (int i = 1; i < size; i++)
	{
		internet_work_protocol* key = protocol[i];
		int j;
		for (j =i - 1; j >= 0 && criterion(key, protocol[j]); j--)
		{
			protocol[j + 1] = protocol[j];
		}
		protocol[j + 1] = key;
	}
}

int partition(internet_work_protocol* protocol[], bool(*criterion)(internet_work_protocol* a, internet_work_protocol* b), int low, int high)
{
	internet_work_protocol* pivot = protocol[high];

	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (criterion((protocol[j]), pivot))
		{
			i++;
			swap(protocol[i], protocol[j]);
		}
	}

	swap(protocol[i + 1], protocol[high]);
	return  i + 1;
}

void quick_sort(internet_work_protocol* protocol[], bool(*criterion)(internet_work_protocol* a, internet_work_protocol* b), int low, int high)
{
	if (low < high)
	{
		int pi = partition(protocol,criterion, low, high);

		quick_sort(protocol,criterion, low, pi - 1);
		quick_sort(protocol,criterion, pi + 1, high);
	}
}