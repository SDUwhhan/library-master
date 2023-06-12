#include <iostream>
#include "User.h"
#include "Manager.h"
#include "DBUtil.h"
#include "Student.h"
#include "Book.h"
using namespace std;
VOID HideConsoleCursor(VOID)
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
VOID ShowConsoleCursor(VOID)
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 1 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void heart()
{
	HideConsoleCursor();
	system("color 74");
	for (float y = 1.5f; y > -1.5f; y -= 0.1f)
	{
		printf("\t\t\t");
		for (float x = -1.5f; x < 1.5f; x += 0.05f)
		{
			float a = x * x + y * y - 1;
			putchar(a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ');
		}
		putchar('\n');
	}
	printf("\t\t\t       ");
	printf("��");
	Sleep(200);
	printf(" ӭ");
	Sleep(200);
	printf(" ʹ");
	Sleep(200);
	printf(" ��");
	Sleep(200);
	printf(" ͼ");
	Sleep(200);
	printf(" ��");
	Sleep(200);
	printf(" ��");
	Sleep(200);
	printf(" ��");
	Sleep(200);
	printf(" ϵ");
	Sleep(200);
	printf(" ͳ��");
	Sleep(200);
	printf(" (�밴���������...)");
	ShowConsoleCursor();
	getchar();
	system("cls");
}
void loginMenu()
{
	HideConsoleCursor();
	system("cls");
	system("color 74");
	printf("\t     -------------------******************ͼ�����ϵͳ*********************--------------------\n");
	printf("\t     -------------------******************ͼ�����ϵͳ*********************--------------------\n\n");
	printf(" --------------------******************�˺�ֻ������1-18λӢ�����������*********************------------------------\n");
	printf("\n --------------------******************����ֻ������6-18λӢ�����������*********************------------------------\n");
	printf("\n\t\t\t\t\t��ӭʹ��ѧ������ϵͳ�����ȵ�¼��\n");
	printf("\n");
	printf("\n");
	printf("\t\t                   �q �] % �r                             �q ```�r  \n");
	printf("\t\t                   (@^o^@) ��ӭʹ��ͼ�����ϵͳ   (��:��)\n");
	printf("\t\t                   (~):(~)                            (~)v(~) \n");
	printf("\t\t                   *****************************************\n");
	printf("\t\t  *           *    *                                       *  *           *    \n");
	printf("\t\t  * *       * *    *                                       *  * *       * *    \n");
	printf("\t\t  *   *   *   *    *                ��   ��                *  *   *   *   *    \n");
	printf("\t\t  *     *     *    *                                       *  *     *     *    \n");
	printf("\t\t  *     *     *    *                1����¼                *  *     *     *    \n");
	printf("\t\t  *     *     *    *                                       *     *     *    \n");
	printf("\t\t  *     *     *    *                                       *  *     *     *    \n");
	printf("\t\t  *     *     *    *	                                      *  *     *     *    \n");
	printf("\t\t   *    *    *     *                0���˳�                *   *    *    *     \n");
	printf("\t\t    *   *   *      *                                       *    *   *   *      \n");
	printf("\t\t      * * *        *****************************************      * * *        \n");
	printf("\n\t\t                                ���������Ĳ�����");
}
int main()
{
	heart();
	loginMenu();
	int handler;
	cin >> handler;
	if (handler == 1)
	{
		string strUserName = "";
		string strUserPWD = "";
		bool bIsLogin = false;
		User user;
		cout << "                          �������û�����";
		cin >> strUserName;
		cout << endl;
		cout << "                          ���������룺";
		cin >> strUserPWD;
		cout << endl;
		DBUtil dbUtil;
		dbUtil.OpenDB();
		user = dbUtil.ReadUser(strUserName, strUserPWD);
		while (user.m_nID == -1)
		{
			cout << "�û������������������������,�����������..." << endl;
			cin.get();
			cin.get();
			system("cls");
			cout << "                          �������û�����";
			cin >> strUserName;
			cout << endl;
			cout << "                          ���������룺";
			cin >> strUserPWD;
			cout << endl;
			user = dbUtil.ReadUser(strUserName, strUserPWD);
		}
		if (user.m_nRole == 1)
		{
			Manager manager;
			manager.m_nID = user.m_nRole;
			manager.m_strName = user.m_strName;
			manager.m_nRole = user.m_nRole;
			int command = -1;		//ѡ������
			bIsLogin = true;
			string strBookName = "";
			int nBookId = 0;
			while (bIsLogin)
			{
				system("cls");
				manager.ShowMenu();
				cin >> command;
				switch (command)
				{
				case 1:
					//ѡ������ͼ��
					manager.AddBook();
					break;
				case 2:
					cout << "������������";
					cin >> strBookName;
					manager.QueryBook(strBookName);
					break;
				case 3:
					cout << "������Ҫɾ��ͼ���ID" << endl;
					cin >> nBookId;
					manager.DeleteBook(nBookId);
					break;
				case 4:
					manager.DisplayAllBook();
					break;
				case 5:
					manager.DiaplayAllBorrowRecord();
					break;
				case 6:
					manager.AddUser();
					break;
				case 7:
					manager.DisplayAllUser();
					break;
				case 8:
					int id;
					cout << "������Ҫɾ���û���ID" << endl;
					cin >> id;
					manager.DeleteUser(id);
					break;
				case 9:
					manager.SelectUser();
					break;
				case 0:
					//ѡ���˳���¼
					bIsLogin = false;
					break;
				default:
					break;
				}
			}
			cout << "�����˳���¼����������˳�..." << endl;
		}
		else
		{
			Student student;
			student.m_nID = user.m_nRole;
			student.m_strName = user.m_strName;
			student.m_nRole = user.m_nRole;
			int command = -1;		//ѡ������
			bIsLogin = true;
			string strBookName = "";
			int nBookId;
			while (bIsLogin)
			{
				system("cls");
				student.ShowMenu();
				cin >> command;
				switch (command)
				{
				case 1:
					//ѡ���ѯͼ��
					cout << "������������";
					cin >> strBookName;
					student.QueryBook(strBookName);
					break;
				case 2:
					//ѡ�����
					cout << "������ͼ��ID��";
					cin >> nBookId;
					student.BorrowBook(nBookId);
					break;
				case 3:
					//�黹ͼ��
					student.ReturnBook();
					break;
				case 4:
					student.ShowMyBorrowRecord();
					break;
				case 5:
					student.RenewBook();
					break;
				case 6:
					student.BorrowTop();
					break;
				case 0:
					//ѡ���˳���¼
					bIsLogin = false;
					break;
				default:
					break;
				}
			}
			cout << "�����˳���¼����������˳�..." << endl;
		}
		cin.get();
		cin.get();
	}
	else if (handler == 0)
	{
		system("exit");
	}
	else {
		
	}
	
	
	return 0;
}