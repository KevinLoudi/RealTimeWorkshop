#include "stdio.h"
    void ShowMessage(const char* Text ,const char* Type)
	{
	printf("Message: Text=%s,Caption=%s\n",Text,Type+1);
	}
    void ShowMessage(const char* Text ,unsigned int Type)
	{
	printf("Message: Text=%s,Type=%d\n",Text,Type);
	}

int main()
{
   unsigned char i=0;
   ShowMessage("ok",i);
   return 0;
}
