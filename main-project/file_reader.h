#pragma once
#ifndef FILE_READER_H
#define FILE_READER_H

#include "internet_work_protocol.h"

void read(const char* file_name, internet_work_protocol* arr[], int& size);

#endif // !FILE_READER_H
