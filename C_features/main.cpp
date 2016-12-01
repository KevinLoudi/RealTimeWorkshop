#include <iostream>
#include "src/Over_load.h"
using namespace std;

int t_main()
{
    //realize function overloading
    printf("realize function overloading\n");
	COKMessage OKMessage;
	OKMessage.ShowMessage("Welcom");
	OKMessage.CMessage::ShowMessage("Welcom");

	//overloading rules
	printf("\ndemo overloading rules\n");
	CMessage Mess;
     char i=0;
    //Mess.ShowMessage("ok",0); //err reason: cannot decide whether "0" is char* or int
    Mess.ShowMessage("ok",i);
    unsigned int j=0;
    Mess.ShowMessage("ok",j);
    return 0;
}
