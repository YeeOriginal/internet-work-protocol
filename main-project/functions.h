#pragma once
#include "internet_work_protocol.h"

void protocol_Skype(internet_work_protocol* protocol[], int size);
void protocol_8am(internet_work_protocol* protocol[], int size);

bool time_used(internet_work_protocol* a, internet_work_protocol* b);
bool protocol_name(internet_work_protocol* a, internet_work_protocol* b);

void insertion_sort(internet_work_protocol* protocol[], int size, bool(*criterion)(internet_work_protocol* a, internet_work_protocol* b));

int partition(internet_work_protocol* protocol[], bool(*criterion)(internet_work_protocol* a, internet_work_protocol* b), int low, int high);
void quick_sort(internet_work_protocol* protocol[], bool(*criterion)(internet_work_protocol* a, internet_work_protocol* b), int low, int high);