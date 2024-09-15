#include <iostream>

using namespace std;

#include "internet_work_protocol.h"
#include "file_reader.h"
#include "constants.h"
#include "functions.h"
#include "process.h"

int main()
{
	//Лабораторная работа 4
	//Вариант 5: Протокол работы в интернете
	//Иванов Иван
	
	internet_work_protocol* protocols[MAX_FILE_ROWS_COUNT];
	int size = NULL;
	try
	{
		read("data.txt", protocols, size);
		for(int i = 0; i < size; i++)
		{
			cout << "Время начала работы: " << protocols[i]->start.hour << ":"
				<< protocols[i]->start.minute << ":"
				<< protocols[i]->start.seconds << endl;
			cout << "Время конца работы: " << protocols[i]->finish.hour << ":" 
				<< protocols[i]->finish.minute << ":" 
				<< protocols[i]->finish.seconds << endl;
			cout << "Получено байт: " << protocols[i]->recieved.byte << endl;
			cout << "Отправлено байт: " << protocols[i]->sent.byte << endl;
			cout << "Название процесса: " << protocols[i]->title << endl;
			cout << "\n";
		}

		int choice = 0;
		while (choice != 3)
		{
			cout << "МЕНЮ:\n";
			cout << "1) Просмотреть протокол работы Skype.\n";
			cout << "2) Просмотреть протокол работы после 8:00:00.\n";
			cout << "3) Выход из программы.\n";
			cout << "Ваш выбор: ";
			cin >> choice;

			cout << "\n";
			switch (choice)
			{
			case 1:
				protocol_Skype(protocols, size);
				break;
			case 2:
				protocol_8am(protocols, size);
				break;
			case 3:
				cout << "Выход из программы...\n";
				for (int i = 0; i < size; i++)
				{
					delete protocols[i];
				}
				return 0;
			default:
				cout << "Такого выбора нет.\n";
			}
		}
	}
	catch (const char* error)
	{
		cout << error << endl;
	}

	return 0;
}