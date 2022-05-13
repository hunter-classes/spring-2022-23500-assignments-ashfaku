#include "Dictionary.h"
#include "OList.h"
Dictionary::Dictionary()
{
	for (int i = 0; i < 10; i++)
	{
		arr[i] = new OList();
	}
}

Dictionary::~Dictionary()
{

}
