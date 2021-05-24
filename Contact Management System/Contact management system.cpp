#include <iostream>
using namespace std;
#define MAX 1000

// �����ϵ�˽ṹ��
struct Person
{
	string m_Name;
	int m_Sex = 0;
	int m_Age = 0;
	string m_Phone;
	string m_Addr;
};

// ���ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size = 0;
};

// 1�������ϵ��
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		int sex = 0;
		cout << "�������Ա𣺣�1-->�У�2-->Ů��" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "�����������������룡" << endl;
			}
		}

		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		
		cout << "��ӳɹ���" << endl;

		system("pause");

		system("cls");
	}

}

// 2����ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << " | ";
			cout << "�Ա�:" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů" ) << " | ";
			cout << "����:" << abs->personArray[i].m_Age << " | ";
			cout << "��ϵ�绰:" << abs->personArray[i].m_Phone << " | ";
			cout << "��ͥסַ:" << abs->personArray[i].m_Addr<< endl;
		}
	}

	system("pause");
	system("cls");
}

// 3.1 �����ϵ���Ƿ���ڣ����ڷ�����ϵ�����������λ�ã������ڷ���-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
		
	}
	return -1;
}

// 3.2 ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; // ����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

// 4��������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << " | ";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << " | ";
		cout << "���䣺" << abs->personArray[ret].m_Age << " | ";
		cout << "��ϵ�绰��" << abs->personArray[ret].m_Phone << " | ";
		cout << "��ͥסַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���!" << endl;
	}

	system("pause");
	system("cls");
}

// 5���޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		int sex = 0;
		cout << "�������Ա𣺣�1-->�У�2-->Ů��" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "�����������������룡" << endl;
			}
		}

		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "���޴���!" << endl;
	}

	system("pause");
	system("cls");
}

// 6�������ϵ��
void cleanPerson(Addressbooks* abs)
{
	cout << "���Ƿ���������ϵ��(y/n):" << endl;
	while (true)
	{
		string ditto;
		cin >> ditto;
		if (ditto == "y")
		{
			abs->m_Size = 0; // ����ǰ��¼��ϵ��������Ϊ0�����߼���ղ���
			cout << "ͨѶ¼�Ѿ���գ�" << endl;
			break;
		}
		else if (ditto == "n")
		{
			cout << "��ѡ�������ϵ�ˣ�" << endl;
			break;
		}
		     else
			{
				cout << "������Ч�����������룺" << endl;
			}
	}
	
	system("pause");
	system("cls");
}

// ��ʾ�˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1->�����ϵ��  *****" << endl;
	cout << "*****  2->��ʾ��ϵ��  *****" << endl;
	cout << "*****  3->ɾ����ϵ��  *****" << endl;
	cout << "*****  4->������ϵ��  *****" << endl;
	cout << "*****  5->�޸���ϵ��  *****" << endl;
	cout << "*****  6->�����ϵ��  *****" << endl;
	cout << "*****  0->�˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}


int main()
{

	// ����ͨѶ¼�ṹ�����
	Addressbooks  abs;
	abs.m_Size = 0;


	int select = 0;
	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1: // 1�������ϵ��
			addPerson(&abs); // ���õ�ַ����ʵ���β�ͬʱ�ı�
			break;
		case 2: // 2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: // 3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4: // 4��������ϵ��
			findPerson(&abs);
			break;
		case 5: // 5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: // 6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0: // 0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	

	system("pause");

	return 0;

}