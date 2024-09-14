#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

date convert(char* str)
{
    date time;
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.hour = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.minute = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.seconds = atoi(str_number);
    return result;
}

void read(const char* file_name, internet_work_protocol* arr[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (true)
        {
            internet_work_protocol* item = new internet_work_protocol; 
            file >> tmp_buffer;
            if (file.eof())
                break;
            item->start = convert(tmp_buffer);
            file >> tmp_buffer;
            item->finish = convert(tmp_buffer);
            file >> item->recieved.byte;
            file >> item->sent.byte;
            file >> item->title;
            arr[size++] = item;  
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}
