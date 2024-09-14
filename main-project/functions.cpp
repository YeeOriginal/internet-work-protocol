#include <iostream>
#include "functions.h"
#include "internet_work_protocol.h"

using namespace std;

void protocol_Skype(internet_work_protocol* protocol[], int size)
{
	for (int i = 0; i < size; i++)
	{
		char Skype[MAX_STRING_SIZE] = "Skype";
		bool titles_equal = true;
		for (int j = 0; j < 6; j++)
			if (protocol[i]->title[j] != Skype[j])
			{
				titles_equal = false;
				break;
			}
		if (titles_equal)
		{
			cout << "Время начала работы: " << protocol[i]->start.hour << ":"
				<< protocol[i]->start.minute << ":"
				<< protocol[i]->start.seconds << endl;
			cout << "Время конца работы: " << protocol[i]->finish.hour << ":"
				<< protocol[i]->finish.minute << ":"
				<< protocol[i]->finish.seconds << endl;
			cout << "Получено байт: " << protocol[i]->recieved.byte << endl;
			cout << "Отправлено байт: " << protocol[i]->sent.byte << endl;
			cout << "Название процесса: " << protocol[i]->title << endl;
			cout << "\n";
		}
	}
}

void protocol_8am(internet_work_protocol* protocol[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (protocol[i]->start.hour >= 8)
		{
			cout << "Время начала работы: " << protocol[i]->start.hour << ":"
				<< protocol[i]->start.minute << ":"
				<< protocol[i]->start.seconds << endl;
			cout << "Время конца работы: " << protocol[i]->finish.hour << ":"
				<< protocol[i]->finish.minute << ":"
				<< protocol[i]->finish.seconds << endl;
			cout << "Получено байт: " << protocol[i]->recieved.byte << endl;
			cout << "Отправлено байт: " << protocol[i]->sent.byte << endl;
			cout << "Название процесса: " << protocol[i]->title << endl;
			cout << "\n";
		}
	}
}