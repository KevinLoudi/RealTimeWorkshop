/*
  Author: Kevin
  Purpose: Demo the C++ feature---member function overload
  Date: 7th April, 2017
  Environment: gcc 4.2
*/

#ifndef OVER_LOAD_H_INCLUDED
#define OVER_LOAD_H_INCLUDED

#include "stdio.h"
#include "string.h"

//Function overload
class CMessage
{
public:
    CMessage(){};

	void ShowMessage(const char* Text ,const char* Caption)
	{
	printf("Message: Text=%s. Caption=%s\n",Text,Caption+1);
	}
    void ShowMessage(const char* Text ,unsigned int Type)
	{
	printf("Message: Text=%s. Type=%d\n",Text,Type);
	}
    void ShowMessage(const char* Text)
	{
	printf("Message: Text=%s\n",Text);
	}

};

class COKMessage :public CMessage
{
public:
    COKMessage(){};
    //overloaded three types of messages
    //identical input parameter-list
	void ShowMessage(const char* Text ,const char* Caption)
	{
	    char TextForOK[40];
		strcpy(TextForOK,"OK,");
		strcat(TextForOK,Text);
	    CMessage::ShowMessage( TextForOK , Caption);
	}
    void ShowMessage(const char* Text ,unsigned int Type)
	{
		char TextForOK[40];
		strcpy(TextForOK,"OK,");
		strcat(TextForOK,Text);
	   CMessage::ShowMessage(TextForOK , Type);

	}
    void ShowMessage(const char* Text )
	{
		char TextForOK[40];
		strcpy(TextForOK,"OK,");
		strcat(TextForOK,Text);
	   CMessage::ShowMessage(TextForOK);
	}

};

//Operator overload



#endif // OVER_LOAD_H_INCLUDED
