#pragma once

#include <windows.h>
#include <stdio.h>
#include <conio.h>

#include "base.h"
#include "map.h"
#include "backup.h"

void draws();
void init();
void data(int row);
int action();
void next();
void start();
void end();
void success();

void draws()
{
	printf("�����������������������������������������������������������������������������������Щ�����������������������������������������\n");
	for (int i = 0; i < 20; i++)
	{
		printf("��");
		for (int j = 0; j < 20; j++)
		{
			switch (map[level][i][j])
			{
			case 0:
				printf("  ");       // �հ׵ĵط�
				break;
			case 1:
				printf("��");        // ǽ 
				break;
			case 2:
				printf("��");        // �� 
				break;
			case 3:
				printf("��");        // ���� 
				break;
			case 4:
				printf("��");        // �յ�ط� 
				break;
			case 6:
				printf("��");        // �����յ�λ�� 
				break;
			case 7:
				printf("��");        // �������յ�λ��
				break;
			}
		}
		data(i);
	}
	printf("�����������������������������������������������������������������������������������ة�����������������������������������������\n");
}

void data(int row)
{
	switch (row)
	{
	case 1:
		printf("��      �ؿ�: %3d     ��\n", level + 1);
		break;
	case 4:
		if (flag == 1)
			printf("��      ��ϲͨ��!     ��\n");
		else
			printf("��                    ��\n");
		break;
	case 13:
		printf("��    ��              ��\n");
		break;
	case 14:
		printf("��  ������  ������ƶ���\n");
		break;
	case 16:
		printf("��    Q��   ������һ����\n");
		break;
	case 18:
		printf("��    Z��   ���¿�ʼ  ��\n");
		break;
	default:
		printf("��                    ��\n");
		break;
	}
}

int action()
{
	int count, caw;                                                 // �к��� 
	for (int i = 0; i < 20; i++)                                    // ȷ���˵�λ�� 
	{
		for (int j = 0; j < 20; j++)
		{
			if (map[level][i][j] == 2 || map[level][i][j] == 6)
			{
				count = i;
				caw = j;
			}
		}
	}
	int tui = _getch();

	switch (tui)
	{
		// ��
	case 72:
	case 'w':
	case 'W':
		if (map[level][count - 1][caw] == 0 || map[level][count - 1][caw] == 4)
		{
			map[level][count][caw] -= 2;
			map[level][count - 1][caw] += 2;
			backup();
		}
		else if (map[level][count - 1][caw] == 3 || map[level][count - 1][caw] == 7)
		{
			if (map[level][count - 2][caw] == 0 || map[level][count - 2][caw] == 4)
			{
				map[level][count][caw] -= 2;
				map[level][count - 1][caw] -= 1;
				map[level][count - 2][caw] += 3;
				backup();
			}
		}
		return 1;
		break;

		// �� 
	case 80:
	case 's':
	case 'S':
		if (map[level][count + 1][caw] == 0 || map[level][count + 1][caw] == 4)
		{
			map[level][count][caw] -= 2;
			map[level][count + 1][caw] += 2;
			backup();
		}

		else if (map[level][count + 2][caw] == 0 || map[level][count + 2][caw] == 4)
		{
			if (map[level][count + 1][caw] == 3 || map[level][count + 1][caw] == 7)
			{
				map[level][count][caw] -= 2;
				map[level][count + 1][caw] -= 1;
				map[level][count + 2][caw] += 3;
				backup();
			}
		}
		return 1;
		break;

		// �� 
	case 75:
	case 'a':
	case 'A':
		if (map[level][count][caw - 1] == 0 || map[level][count][caw - 1] == 4)
		{
			map[level][count][caw] -= 2;
			map[level][count][caw - 1] += 2;
			backup();
		}

		else if (map[level][count][caw - 2] == 0 || map[level][count][caw - 2] == 4)
		{
			if (map[level][count][caw - 1] == 3 || map[level][count][caw - 1] == 7)
			{
				map[level][count][caw] -= 2;
				map[level][count][caw - 1] -= 1;
				map[level][count][caw - 2] += 3;
				backup();
			}
		}
		return 1;
		break;

		// �� 
	case 77:
	case 'd':
	case 'D':
		if (map[level][count][caw + 1] == 0 || map[level][count][caw + 1] == 4)
		{
			map[level][count][caw] -= 2;
			map[level][count][caw + 1] += 2;
			backup();
		}

		else if (map[level][count][caw + 2] == 0 || map[level][count][caw + 2] == 4)
		{
			if (map[level][count][caw + 1] == 3 || map[level][count][caw + 1] == 7)
			{
				map[level][count][caw] -= 2;
				map[level][count][caw + 1] -= 1;
				map[level][count][caw + 2] += 3;
				backup();
			}
		}
		return 1;
		break;

	case 'q':
	case 'Q':
		if (flag != 0)
		{
			getback();
		}
		return 1;
		break;

	case 'z':
	case 'Z':
		again();
		return 1;
		break;

	case 'e':
	case 'E':
		return 0;
		break;
	}
}

void next()
{
	int index = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (map[level][i][j] == 3)
				index++;
		}
	}
	if (index == 0)
	{
		level++;
		flag = 0;
		init();
		if (level == max)
		{
			level--;
			flag = 1;
		}
	}
}

void init()
{
	abackup();
	backup();
	backup();
}

void start()
{
	printf("������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                     __        ___.                          ��\n");
	printf("��         __________ |  | ______\\_ |__ _____    ____          ��\n");
	printf("��        /  ___/  _ \\|  |/ /  _ \\| __ \\\\__  \\  /    \\         ��\n");
	printf("��        \\___ (  <_> )    <  <_> ) \\_\\ \\/ __ \\|   |  \\        ��\n");
	printf("��       /____  >____/|__|_ \\____/|___  (____  /___|  /        ��\n");
	printf("��            \\/           \\/         \\/     \\/     \\/         ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                       ������С��Ϸ                          ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                  >   �������ʼ��Ϸ   <                     ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("������������������������������������������������������������������������������������������������������������������������������\n");
	_getch();
	system("cls");
}

void end()
{
	printf("������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                                    .___                     ��\n");
	printf("��                   ____   ____    __| _/                     ��\n");
	printf("��                 _/ __ \\ /    \\  / __ |                      ��\n");
	printf("��                 \\  ___/|   |  \\/ /_/ |                      ��\n");
	printf("��                  \\___  >___|  /\\____ |                      ��\n");
	printf("��                      \\/     \\/      \\/                      ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                       ��ӭ�´�����                          ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                  >   ������˳���Ϸ   <                     ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("������������������������������������������������������������������������������������������������������������������������������\n");
	system("pause");
}

void success()
{
	printf("������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                          _            _                     ��\n");
	printf("��                         (_)          | |                    ��\n");
	printf("��                    _ __  _  ___ ___  | |                    ��\n");
	printf("��                   | '_ \\| |/ __/ _ \\ | |                    ��\n");
	printf("��                   | | | | | (_|  __/ |_|                    ��\n");
	printf("��                   |_| |_|_|\\___\\___| (_)                    ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                         ��Ϸͨ��                            ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                  >   ������˳���Ϸ   <                     ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("��                                                             ��\n");
	printf("������������������������������������������������������������������������������������������������������������������������������\n");
	system("pause");
}