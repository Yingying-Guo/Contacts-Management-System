#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别 1 男 2 女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数
	int m_Size;
};

//菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出联系人  *****" << endl;
	cout << "***************************" << endl;
}

//1、添加联系人
void addPerson(Addressbooks * abs)
{
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		
		//性别
		int sex = 0;
		cout << "请输入性别： " << endl;
		cout << "1 --- 男 " << endl;
		cout << "2 --- 女 " << endl;
		while (true)
		{
			//如果输入的是1 或 2 可以退出循环
			//如果输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}		
		
		//年龄
		int age;
		cout << "请输入年龄： " << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		string phone;
		cout << "请输入联系电话： " << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		string address;
		cout << "请输入家庭住址： " << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录中人数
		abs->m_Size++;

		cout << "添加成功" << endl;

		system("pause"); //请按任意键继续
		system("cls"); //清屏操作
	}
}

//2、显示联系人
void showPerson(Addressbooks * abs)
{
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话： " << abs->personArray[i].m_Phone << "\t";
			cout << "住址： " << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

//检测联系人是否存在，如果存在，返回来呢西人所在数组中的具体位置，不存在返回-1
int isExist(Addressbooks * abs, string name)
{
	if (abs->m_Size == 0) //通讯录为空
	{
		return -1;
	}
	for (int i = 0; i < abs->m_Size; i++)
	{
		//找到用户输入的姓名了
		if (abs->personArray[i].m_Name == name)
		{
			return i; //找到了，返回这个人在数组中的下标编号
		}
	}
	return -1; //如果遍历结束都没有找到，返回-1
}

//3、删除联系人
void deletePerson(Addressbooks * abs)
{
	cout << "请输入您要删除的联系人" << endl;

	string name;
	cin >> name;

	//ret == -1 未查到
	//ret != -1 查到了
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//查找到人，要进行删除操作
		for (int i = 0; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; //更新通讯录中的人员数
		cout << "删除成功" << endl;

	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

//4、查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) //找到联系人
	{
		cout << "姓名： " << abs->personArray[ret].m_Name << "\t";
		cout << "性别： " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[ret].m_Age << "\t";
		cout << "电话： " << abs->personArray[ret].m_Phone << "\t";
		cout << "住址： " << abs->personArray[ret].m_Addr << endl;
	}
	else //未找到联系人
	{
		cout << "查无此人" << endl;
	}

	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

//5、修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) //找到联系人
	{
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别： " << endl;
		cout << "1 --- 男 " << endl;
		cout << "2 --- 女 " << endl;
		while (true)
		{
			//如果输入的是1 或 2 可以退出循环
			//如果输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		int age;
		cout << "请输入年龄： " << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		string phone;
		cout << "请输入联系电话： " << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		string address;
		cout << "请输入家庭住址： " << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功！" << endl;
	}
	else //未找到联系人
	{
		cout << "查无此人" << endl;
	}

	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

//6、清空联系人
void cleanPerson(Addressbooks* abs)
{
	//只要将通讯录记录的联系人数量置为0，做逻辑清空即可
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;

	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0; //创建用户选择输入的变量

	while (true)
	{
		//菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1: // 1、添加联系人
			addPerson(&abs);
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
		case 0: // 0、退出联系人
			cout << "欢迎下次使用" << endl;
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