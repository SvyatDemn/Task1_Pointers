#include "List.h"
#include "List.cpp"

int main()
{

	char** list = nullptr;

	StringListInit(&list);
	StringListAdd(&list, "abc");
	StringListAdd(&list, "abcd");
	StringListAdd(&list, "abcde");
	StringListAdd(&list, "abcde");
	StringListAdd(&list, "abcgf");
	StringListAdd(&list, "abcgr");
	StringListAdd(&list, "abc");
	StringListAdd(&list, "abcgy");
	StringListAdd(&list, "abcgu");
	StringListAdd(&list, "abcgi");
	ShowList(list);



}
