#include "process.h"
#include "internet_work_protocol.h"
#include <math.h>

int timeOnInternet(internet_work_protocol* protocols[], char* title, int size, int titleSize)
{
	int sumTime = 0;
	for (int i = 0; i < size; i++)
	{
		bool titleEqual = true;
		for (int j = 0; j < titleSize; j++)
		{
			if (title[j] != protocols[i]->title[j])
			{
				titleEqual = false;
				break;
			}
		}
		if (titleEqual)
		{	
			int hour = abs(protocols[i]->finish.hour - protocols[i]->start.hour) * 3600;
			int minute = (protocols[i]->finish.minute - protocols[i]->start.minute) * 60;
			int second = (protocols[i]->finish.seconds - protocols[i]->start.seconds);
			sumTime = sumTime + hour + minute + second;
		}
	}

	return sumTime;
}