#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>

#include "base.h"
#include "backup.h"
#include "map.h"
#include "opration.h"

int main()//Ö÷º¯Êý 
{
	start();
	init();
	while (actions)
	{
		next();
		draws();
		if (flag != 1)
			actions = action();
		if (flag == 0)
		{
			flag = 2;
		}
		if (flag == 1)
		{
			system("cls");
			break;
		}
		system("cls");	
	}
	if (flag == 1)
		success();
	else
		end();
	return 0;
}
