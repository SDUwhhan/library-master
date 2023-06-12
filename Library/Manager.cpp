#include "Manager.h"


Manager::Manager()
{
}


Manager::~Manager()
{
}
VOID HideConsoleCursor1(VOID)
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
VOID ShowConsoleCursor1(VOID)
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 1 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void Manager::ShowMenu()
{
	HideConsoleCursor1();
	system("cls");
	system("color 74");
	printf("\n");
	printf("\n");
	printf("\t\t                   �q �] % �r                             �q ```�r  \n");
	printf("\t\t                   (@^o^@) ��ӭʹ��ͼ����Ϣ��̨����ϵͳ   (��:��)\n");
	printf("\t\t                   (~):(~)                            (~)v(~) \n");
	printf("\t\t                   *****************************************\n");
	printf("\t\t  *           *    *                                       *  *           *    \n");
	printf("\t\t  * *       * *    *                                       *  * *       * *    \n");
	printf("\t\t  *   *   *   *    *                ��   ��                *  *   *   *   *    \n");
	printf("\t\t  *     *     *    *                                       *  *     *     *    \n");
	printf("\t\t  *     *     *    *           [1]������¼��               *  *     *     *    \n");
	printf("\t\t  *     *     *    *                                       *     *     *    \n");
	printf("\t\t  *     *     *    *           [2]��ͼ���ѯ               *  *     *     *    \n");
	printf("\t\t  *     *     *    *	                                   *  *     *     *    \n");
	printf("\t\t  *     *     *    *	       [3]��ɾ��ͼ��               *  *     *     *    \n");
	printf("\t\t  *     *     *    *	                                   *  *     *     *    \n");
	printf("\t\t  *     *     *    *	       [4]��ͼ���б�               *  *     *     *    \n");
	printf("\t\t  *     *     *    *	                                   *  *     *     *    \n");
	printf("\t\t  *     *     *    *	       [5]�����ļ�¼               *  *     *     *    \n");
	printf("\t\t  *     *     *    *	                                   *  *     *     *    \n");
	printf("\t\t  *     *     *    *	       [6]�������û�               *  *     *     *    \n");
	printf("\t\t  *     *     *    *	                                   *  *     *     *    \n");
	printf("\t\t   *    *    *     *           [7]���û��б�               *  *     *     *     \n");
	printf("\t\t  *     *     *    *	                                   *  *     *     *    \n");
	printf("\t\t  *     *     *    *	       [8]��ɾ���û�               *  *     *     *    \n");
	printf("\t\t  *     *     *    *	                                   *  *     *     *    \n");
	printf("\t\t  *     *     *    *	       [9]����ѯ�û�               *  *     *     *    \n");
	printf("\t\t  *     *     *    *	                                   *  *     *     *    \n");
	printf("\t\t  *     *     *    *	       [0]:�˳���¼                *  *     *     *    \n");
	printf("\t\t    *   *   *      *                                       *    *   *   *      \n");
	printf("\t\t      * * *        *****************************************      * * *        \n");
	printf("\n\t\t                                ���������Ĳ�����");
}

bool Manager::AddBook()
{
	string bookName;
	string author;
	string classify;
	string isbn;
	string pub;
	int total;
	char szTime[32] = { 0 };
	time_t lt;
	lt = time(NULL);
	m_timeUtil.TimeToString(lt, szTime);

	cout << "��ѡ���������ͼ�鹦�ܣ�����������ͼ����Ϣ" << endl;
	cout << "ͼ������ ��� ���� ISBN ������ �ܲ���" << endl;
	cin >> bookName;
	cin >> classify;
	cin >> author;
	cin >> isbn;
	cin >> pub;
	cin >> total;

	Book book;
	book.SetBookName(bookName);
	book.SetClassify(classify);
	book.SetAuthor(author);
	book.SetISBN(isbn);
	book.SetPub(pub);
	book.SetTotalNum(total);
	book.SetLeftNum(0);
	book.SetInDate(szTime);

	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	m_dbUtil.AddBook(book);
	cout << "����ͼ��ɹ�" << endl;
	getchar();
	return true;
}

//չʾ�����鼮
bool Manager::DisplayAllBook()
{
	vector<Book> books;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}

	m_dbUtil.SelectAllBook(books);
	vector<Book>::iterator vecIter;
	cout << "ID     ����            ���            ����           ������       �������     �ݲ�����   ����" << endl;
	for (vecIter = books.begin(); vecIter != books.end(); vecIter++)
	{

		cout << setiosflags(ios::left) << setw(4) << vecIter->GetBookID() << "  " << setw(14) << vecIter->GetBookName() << "  " << setw(10) << vecIter->GetClassify() << "  " << setw(10) << vecIter->GetAuthor() << "  " << setw(14) << vecIter->GetPub() << "  " << setw(14) << vecIter->GetInDate() << "  " << setw(8) << vecIter->GetTotalNum() << "  " << setw(3) << vecIter->GetLeftNum() << endl;
	}
	cin.get();
	cin.get();
	return true;
}

//����������ѯ�鼮
bool Manager::QueryBook(string strBookName)
{
	vector<Book> books;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}

	m_dbUtil.SelectBookByName(strBookName, books);
	vector<Book>::iterator vecIter;
	cout << "ID     ����            ���            ����           ������       �������     �ݲ�����   ����" << endl;
	for (vecIter = books.begin(); vecIter != books.end(); vecIter++)
	{

		cout << setiosflags(ios::left) << setw(4) << vecIter->GetBookID() << "  " << setw(14) << vecIter->GetBookName() << "  " << setw(10) << vecIter->GetClassify() << "  " << setw(10) << vecIter->GetAuthor() << "  " << setw(14) << vecIter->GetPub() << "  " << setw(14) << vecIter->GetInDate() << "  " << setw(8) << vecIter->GetTotalNum() << "  " << setw(3) << vecIter->GetLeftNum() << endl;
	}
	cin.get();
	cin.get();
	return true;
}

//����ͼ��IDɾ��ͼ��
bool Manager::DeleteBook(int nBookId)
{
	Book book;
	book.SetBookID(-1);
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	m_dbUtil.SelectBookById(nBookId, book);
	if (book.GetBookID() != -1)
	{
		cout << "ID     ����            ���            ����           ������       �������     �ݲ�����   ����" << endl;
		cout << setiosflags(ios::left) << setw(4) << book.GetBookID() << "  " << setw(14) << book.GetBookName() << "  " << setw(10) << book.GetClassify() << "  " << setw(10) << book.GetAuthor() << "  " << setw(14) << book.GetPub() << "  " << setw(14) << book.GetInDate() << "  " << setw(8) << book.GetTotalNum() << "  " << setw(3) << book.GetLeftNum() << endl;

		//ѯ���Ƿ�ɾ��
		char chIsDelete = 'a';
		cout << "ɾ���Ȿ����?n/y" << endl;
		cin.get();
		cin >> chIsDelete;
		while (true)
		{
			if (chIsDelete == 'y' || chIsDelete == 'Y')
			{
				m_dbUtil.DeleteBookById(nBookId);
				break;
			}
			else if (chIsDelete == 'n' || chIsDelete == 'N')
			{
				cout << "��ȡ��ɾ����";
				break;
			}
			else
			{
				cout << "��������,����������:";
				cin.get();
				cin >> chIsDelete;
			}
		}
	}
	else
	{
		cout << "û���ҵ�IDΪ" << nBookId << "���鼮" << endl;
	}
	cin.get();
	cin.get();
	return true;
}

//�����û���ɾ���û�
bool Manager::DeleteUser(int id)
{
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	User user = m_dbUtil.SelectUserById(id);
	if (user.m_nID != id)
	{
		cout << "�ܱ�Ǹ,�����ڸ��û���" << endl;
	}
	else {
		cout << "ID     �û���      ���" << endl;
		cout << setiosflags(ios::left) << setw(6) << user.m_nID << "  " << setw(8) << user.m_strName << "  " << (user.m_nRole == 1 ? "����Ա" : "ѧ��") << endl;
		//ѯ���Ƿ�ɾ��
		char chIsDelete = 'a';
		cout << "ɾ������û���?n/y" << endl;
		cin.get();
		cin >> chIsDelete;
		while (true)
		{
			if (chIsDelete == 'y' || chIsDelete == 'Y')
			{
				m_dbUtil.DeleteByUserId(id);
				break;
			}
			else if (chIsDelete == 'n' || chIsDelete == 'N')
			{
				cout << "��ȡ��ɾ����";
				break;
			}
			else
			{
				cout << "��������,����������:";
				cin.get();
				cin >> chIsDelete;
			}
		}
	}
	cout << "��������ֵ����....";
	getchar();
	return true;
}

//չʾ���н��ļ�¼
bool Manager::DiaplayAllBorrowRecord()
{
	vector<BorrowRecord> borrowRecords;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}

	m_dbUtil.SelectAllBorrowRecord(borrowRecords);
	User user;
	Book book;
	vector<BorrowRecord>::iterator vecIter;
	cout << "ID       ����        ������    ��������       Ӧ������     ��������   �������" << endl;
	for (vecIter = borrowRecords.begin(); vecIter != borrowRecords.end(); vecIter++)
	{
		user = m_dbUtil.SelectUserById(vecIter->m_nUserId);
		m_dbUtil.SelectBookById(vecIter->m_nBookId, book);
		cout << setiosflags(ios::left) << setw(4) << vecIter->m_nBorrowId << "  " << setw(14) << book.GetBookName() << "  " << setw(6) << user.m_strName << "  " << setw(13) << vecIter->m_tBorrowDate << "  " << setw(13) << vecIter->m_tShouldReturnDate << "  " << setw(13) << vecIter->m_tReturnDate << "  " << setw(3) << vecIter->m_nContinue << endl;
	}
	cin.get();
	cin.get();
	return true;
}

//�����û�
bool Manager::AddUser()
{
	cout << "������һ���û���Ϣ:" << endl;
	cout << "�û���   ����   �û�����" << endl;
	User user;

	cin >> user.m_strName;
	cin >> user.m_strPassword;
	cin >> user.m_nRole;

	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}

	m_dbUtil.AddUser(user);
	cout << "�����û��ɹ�" << endl;
	cin.get();
	cin.get();
	return true;
}

//չʾ�����û�
bool Manager::DisplayAllUser()
{
	vector<User> users;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}

	m_dbUtil.SelectAllUser(users);
	User user;
	Book book;
	vector<User>::iterator vecIter;
	cout << "ID     �û���      ���" << endl;
	for (vecIter = users.begin(); vecIter != users.end(); vecIter++)
	{
		cout << setiosflags(ios::left) << setw(6) << vecIter->m_nID << "  " << setw(8) << vecIter->m_strName << "  " << (vecIter->m_nRole == 1 ? "����Ա" : "ѧ��") << endl;
	}
	cin.get();
	cin.get();
	return true;
}
bool Manager::SelectUser()
{
	vector<User> users;
	string name;
	if (!m_dbUtil.isOpen)
	{
		m_dbUtil.OpenDB();
	}
	cout << "\n�������û�����\t";
	cin >> name;
	m_dbUtil.SelectByName(name, users);
	vector<User>::iterator vecIter;
	cout << "ID     �û���      ���" << endl;
	for (vecIter = users.begin(); vecIter != users.end(); vecIter++)
	{
		cout << setiosflags(ios::left) << setw(6) << vecIter->m_nID << "  " << setw(8) << vecIter->m_strName << "  " << (vecIter->m_nRole == 1 ? "����Ա" : "ѧ��") << endl;
	}
	cout << "���������ַ�����........" << endl;
	cin.get();
	cin.get();
	return true;
}
