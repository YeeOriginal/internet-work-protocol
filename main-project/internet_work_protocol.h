#pragma once
#ifndef INTERNET_WORK_PROTOCOL
#define INTERNET WORK_PROTOCOL

#include "constants.h"

class date
{
public:
	unsigned int hour;
	unsigned int minute;
	unsigned int seconds;
};

class bytes
{
public:
	unsigned int byte;
};

class internet_work_protocol
{
public:
	date start;
	date finish;
	bytes recieved;
	bytes sent;
	char title[MAX_STRING_SIZE];
};

#endif
