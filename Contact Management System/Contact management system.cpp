#include <iostream>
using namespace std;
#define MAX 1000

// 设计联系人结构体
struct Person
{
	string m_Name;
	int m_Sex = 0;
	int m_Age = 0;
	string m_Phone;
	string m_Addr;
};

// 设计通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size = 0;
};

// 1、添加联系人
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		int sex = 0;
		cout << "请输入性别：（1-->男，2-->女）" << endl;
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
				cout << "输入有误，请重新输入！" << endl;
			}
		}

		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		
		cout << "添加成功！" << endl;

		system("pause");

		system("cls");
	}

}

// 2、显示联系人
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << " | ";
			cout << "性别:" << (abs->personArray[i].m_Sex == 1 ? "男" : "女" ) << " | ";
			cout << "年龄:" << abs->personArray[i].m_Age << " | ";
			cout << "联系电话:" << abs->personArray[i].m_Phone << " | ";
			cout << "家庭住址:" << abs->personArray[i].m_Addr<< endl;
		}
	}

	system("pause");
	system("cls");
}

// 3.1 检测联系人是否存在，存在返回联系人所在数组的位置，不存在返回-1
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

// 3.2 删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; // 更新通讯录中的人员数
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

// 4、查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << " | ";
		cout << "性别：" << abs->personArray[ret].m_Sex << " | ";
		cout << "年龄：" << abs->personArray[ret].m_Age << " | ";
		cout << "联系电话：" << abs->personArray[ret].m_Phone << " | ";
		cout << "家庭住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人!" << endl;
	}

	system("pause");
	system("cls");
}

// 5、修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		int sex = 0;
		cout << "请输入性别：（1-->男，2-->女）" << endl;
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
				cout << "输入有误，请重新输入！" << endl;
			}
		}

		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功!" << endl;
	}
	else
	{
		cout << "查无此人!" << endl;
	}

	system("pause");
	system("cls");
}

// 6、清空联系人
void cleanPerson(Addressbooks* abs)
{
	cout << "您是否继续清空联系人(y/n):" << endl;
	while (true)
	{
		string ditto;
		cin >> ditto;
		if (ditto == "y")
		{
			abs->m_Size = 0; // 将当前记录联系人数量置为0，做逻辑清空操作
			cout << "通讯录已经清空！" << endl;
			break;
		}
		else if (ditto == "n")
		{
			cout << "您选择不清空联系人！" << endl;
			break;
		}
		     else
			{
				cout << "输入无效！请重新输入：" << endl;
			}
	}
	
	system("pause");
	system("cls");
}

// 显示菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1->添加联系人  *****" << endl;
	cout << "*****  2->显示联系人  *****" << endl;
	cout << "*****  3->删除联系人  *****" << endl;
	cout << "*****  4->查找联系人  *****" << endl;
	cout << "*****  5->修改联系人  *****" << endl;
	cout << "*****  6->清空联系人  *****" << endl;
	cout << "*****  0->退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}


int main()
{

	// 创建通讯录结构体变量
	Addressbooks  abs;
	abs.m_Size = 0;


	int select = 0;
	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1: // 1、添加联系人
			addPerson(&abs); // 利用地址传递实参形参同时改变
			break;
		case 2: // 2、显示联系人
			showPerson(&abs);
			break;
		case 3: // 3、删除联系人
			deletePerson(&abs);
			break;
		case 4: // 4、查找联系人
			findPerson(&abs);
			break;
		case 5: // 5、修改联系人
			modifyPerson(&abs);
			break;
		case 6: // 6、清空联系人
			cleanPerson(&abs);
			break;
		case 0: // 0、退出通讯录
			cout << "欢迎下次使用！" << endl;
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