#include "List.h"

typedef unsigned int ui;

static const ui SizeOfAr = 10;
static const ui SizeOfInf = 2;

void StringListInit(char*** list)
{
	void* tmp_ptr = malloc(SizeOfAr * sizeof(char*) + SizeOfInf * sizeof(ui));
	memset(tmp_ptr, 0, SizeOfAr * sizeof(char*) + SizeOfInf * sizeof(ui));

	unsigned* capacity = (unsigned*)tmp_ptr;
	unsigned* size = (unsigned*)tmp_ptr + 1;
	*capacity = 10;
	*list = (char**)(capacity + 2);

}

void StringListDestroy(char*** list)
{
	if (list != nullptr)
	{
	ui size = StringListSize(*list);
	for (int i = 0; i < size; i++)
		{
		free((*list)[i]);
		(*list)[i] = nullptr;
		}
	*list = nullptr;
    }
}

ui StringListSize(char** list)
{
	if (list != nullptr)
		return (ui)list[-1];
	else
		return -1;
}

ui StringListCapacity(char** list)
{
	if (list != nullptr)
		return (ui)list[-2];
	else
		return -1;
}

void ShowList(char** list)
{
	std::cout << "Capacity: " << StringListCapacity(list) << std::endl;
	std::cout << "Size" << StringListSize(list) << std::endl;
	ui size = StringListSize(list);
	for(int i = 0; i < size; i++)
	std::cout << "Number: " << i << ':' << list[i] << std::endl;
}

void StringListAdd(char*** list, char* str)
{
	if (list != nullptr)
	{
		ui size = StringListSize(*list);
		if(size == StringListCapacity(*list))
		{
			ui newcapacity = size * 2;
			void* newmem = (*list) - 2;
			newmem = realloc(newmem, newcapacity * sizeof(char**) + SizeOfInf * sizeof(ui));

			if(newmem != nullptr)
			{
				*list = (char**)(((ui*)(newmem)) + 2);
				memset((*list) + size + 1, 0, newcapacity - size);
			}
			
		}
			size = (ui) (*list)[-1]++;
			*list[size] = (char*)malloc(strlen(str) + 1);
			strcpy(*list[size], str);

	}
}

void StringListRemove(char** list, char* str)
{
	if (list != nullptr)
	{
		ui size = StringListSize(list);
		ui index = StringListIndexOf(list, str);
		while(index != -1)
		{
			for(int i = index; i <= size - 2; i++)
			{
				Swap(&list[i], &list[i + 1]);
			}
			list[-1]--;
			free(list[size - 1]);
			list[size - 1] = nullptr;
		}
	}
}

ui StringListIndexOf(char** list, char* str)
{
	if (list != nullptr)
	{
	ui size = StringListSize(list);
		if (list != nullptr)
			for (int i = 0; i < size; i++)
				if (strcmp(list[i], str) == 0)
					return i;
	}
	return -1;
}

void Swap(char** a, char** b)
{
	char* temporary_pointer = *a;
	*a = *b;
	*b = temporary_pointer;
}

void StringListRemoveDuplicates(char** list)
{
	if (list != nullptr)
	{
		for (int i = 0; i < StringListSize(list) - 1; i++)
			for (int j = i + 1; j < StringListSize(list); j++)
				if (!strcmp(list[i], list[j]))
					{
						StringListRemove(list, list[j]);
						j--;
					}
	}
}


void StringListReplaceInStrings(char** list, char* before, char* after)
{
	if (list != nullptr)
	{
		int index = StringListIndexOf(list, before);
		while (index != -1)
		{
			list[index] = (char*)realloc(list[index], strlen(after) + 1);
			strcpy(list[index], after);
		}
	}
}

void StringListSort(char** list)
{
	if (list != nullptr)
	{
		for(int i = 0; i < StringListSize(list) - 1; i++)
		{
			for(int j = i + 1; j < StringListSize(list); j++)
				if(strcmp(list[i], list[j]) > 0)
					Swap(&list[i], &list[j]);
		}
	}
}
