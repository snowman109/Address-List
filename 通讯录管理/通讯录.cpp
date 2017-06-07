#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;
//******************************定义学生结构体******************************************
typedef struct Student
{
	char sNum[10];
	char sName[10];
	char sMajor[10];
	char sGrade[10];
	char sSex[4];
	char sBorn_date[20];
	char iTell[12];
	char iQQ[12];
	char sAdress[30];
	Student*P_next;
}STUNOTE;
//*******************************声明头指针和尾指针************************************
STUNOTE *g_head = NULL;
STUNOTE *g_end = NULL;

//*******************************声明功能函数**********************************************
//尾添加
void addstumsgend(char sNum[10], char sName[10], char sMajor[10], char sGrade[10], char sSex[4], char sBorn_date[10], char iTell[12], char iQQ[12], char sAdress[30]);

void addstumsgend_1(char sNum[10], char sName[10], char sMajor[10], char sGrade[10], char sSex[4], char sBorn_date[10], char iTell[12], char iQQ[12], char sAdress[30]);

//头添加
void addstumsghead(char sNum[10], char sName[10], char sMajor[10], char sGrade[10], char sSex[4], char sBorn_date[10], char iTell[12], char iQQ[12], char sAdress[30]);

//释放数据
void FreeDate(STUNOTE*p);

//学号排序
void sortnum(Student *head);

//排序姓名
void sortname(Student *head);

//打印单个数据

void Show(Student*ptemp);
//打印所有数据
void Showdate();

//按姓名查找特定学生数据
STUNOTE* Finderbyname(char cname[10]);

//按学号查找特定学生数据
STUNOTE* Finderbynum(char cnum[10]);

//更改指定学生信息
void Update(STUNOTE*P);

//删除学生信息
void DeleteSTUNOTE(STUNOTE* pNode);

//保存信息到文件
void Savedate(Student*ptemp);

//保存所有信息到文件
void Savealldate();

//从文件读取信息
void ReaddatefromFile();
//**************************************主函数*******************************************
int main()
{
	Student*ptemp = g_head;
	int iOreder = -1,Flag=1;//判断是否退出
	int add = -1;//添加数据时候的选择
	int cos = -1;//查找数据时的选择
	char sNum[10];
	char sName[10];
	char sMajor[10];
	char sGrade[10];
	char sSex[4];
	char sBorn_date[10];
	char iTell[12];
	char iQQ[12];
	char sAdress[30];
	ReaddatefromFile();
	cout << "**************学生通讯录管理系统**************" << endl;
	cout << "**                                          **" << endl;
	cout << "**------------1、添加学生信息---------------**" << endl;
	cout << "**------------2、查询学生信息---------------**" << endl;
	cout << "**------------3、修改学生信息---------------**" << endl;
	cout << "**------------4、删除学生信息---------------**" << endl;
	cout << "**------------5、显示通讯录中的所有信息-----**" << endl;
	cout << "**------------6、退出系统-------------------**" << endl;
	cout << "**                                          **" << endl;
	cout << "**********************************************" << endl;
	while (Flag)
	{
		cout << endl << endl << "请输入指令：";
		cin >> iOreder;
		switch (iOreder)
		{
		case 1:
			cout << "请输入学号：";
			cin >> sNum;
			cout << "请输入姓名：";
			cin >> sName;
			cout << "请输入专业：";
			cin >> sMajor;
			cout << "请输入年级：";
			cin >> sGrade;
			cout << "请输入性别：";
			cin >> sSex;
			cout << "请输入出生日期(格式19970101)：";
			cin >> sBorn_date;
			cout << "请输入手机号：";
			cin >> iTell;
			cout << "请输入QQ：";
			cin >> iQQ;
			cout << "请输入地址：";
			cin >> sAdress;
			cout << "请选择是1、头添加   2、尾添加   " << endl;
			cin >> add;
			if (add == 1)
				addstumsghead(sNum, sName, sMajor, sGrade, sSex, sBorn_date, iTell, iQQ, sAdress);
			else if (add == 2)
				addstumsgend(sNum, sName, sMajor, sGrade, sSex, sBorn_date, iTell, iQQ, sAdress);
			else
				cout << "输入错误！" << endl;
			break;
		case 2://查找学生信息
			cout << "请选择查找依据：\n";
			cout << "1、按照姓名查找\n2、按照学号查找\n";
			cin >> cos;
			if (cos == 1)
			{
				cout << "请输入学生姓名：\n";
				cin >> sName;
				if ((Finderbyname(sName) == NULL))
					break;
				else
				{
					cout << "学号--------姓名--------专业--------年级--------性别--------生日--------电话号-------qq--------地址--------" << endl;
					Show(Finderbyname(sName));
				}
			}
			else if (cos == 2)
			{
				cout << "请输入学生学号：\n";
				cin >> sNum;
				if ((Finderbynum(sNum) == NULL))
					break;
				else
				{
					cout << "学号--------姓名--------专业--------年级--------性别--------生日--------电话号-------qq--------地址--------" << endl;
					Show(Finderbynum(sNum));
				}
			}
			else
				cout << "输入错误！" << endl;
			break;
		case 3://修改学生信息
			cout << "请输入查找要修改学生的依据：\n";
			cout << "1、按照姓名查找\n2、按照学号查找\n";
			cin >> cos;
			if (cos == 1)
			{
				cout << "请输入要修改学生的姓名：\n";
				cin >> sName;
				if ((Finderbyname(sName) == NULL))
					break;
				else
					Update(Finderbyname( sName));
			}
			else if (cos == 2)
			{
				cout << "请输入学生学号：\n";
				cin >> sNum;
				if ((Finderbynum(sNum) == NULL))
					break;
				else
					Update(Finderbynum(sNum));
			}
			else
				cout << "输入错误！" << endl;
			break;
		case 4://删除学生信息
			cout << "请输入查找要删除学生的依据：\n";
			cout << "1、按照姓名查找\n2、按照学号查找\n";
			cin >> cos;
			if (cos == 1)
			{
				cout << "请输入要删除学生的姓名：\n";
				cin >> sName;
				if ((Finderbyname(sName) == NULL))
					break;
				else
					DeleteSTUNOTE(Finderbyname(sName));
			//	Deletebyname(sName);
			}
			else if (cos == 2)
			{
				cout << "请输入删除学生学号：\n";
				cin >> sNum;
				if ((Finderbynum(sNum) == NULL))
					break;
				else
					DeleteSTUNOTE(Finderbynum(sNum));
				//Deletebycnum(sNum);
			}
			else
				cout << "输入错误！" << endl;
			break;
		case 5://显示学生信息
			Showdate();
			break;
		case 6://退出
			Flag = 0;
			while (g_head != NULL)//一直循环到全部删除
			{
				//记录节点
				ptemp = g_head;
				//移动节点
				g_head = g_head->P_next;
				//删除节点
				FreeDate(ptemp);
			}
			cout << "已退出\n";
			break;
		default:cout << "指令输入错误！";
			break;
		}
	}
	
	system("pause");
}

//****************************************定义功能函数****************************************
//尾添加
void addstumsgend(char sNum[10], char sName[10], char sMajor[10], char sGrade[10], char sSex[4], char sBorn_date[10], char iTell[12], char iQQ[12], char sAdress[30])
{
	//判断输入是否合法
	char tell_min[12]={"10000000000"};
	char tell_max[12]={"19999999999"}; 
	if (sNum == NULL || sName == NULL || sMajor == NULL || sGrade == NULL || sSex == NULL || sBorn_date == NULL || strlen(iTell) != 11 || strlen(iQQ) > 11 || strlen(iQQ) < 5)
	{
		cout << "输入的信息错误" << endl;
		return;
	}
	if(strcmp(tell_min,iTell)>0||strcmp(iTell,tell_max)>0)
	{
		cout<<"输入的信息错误"<<endl;
		return; 
	}
	//创建节点
	STUNOTE *ptemp = new Student;
	//赋值
	strcpy_s(ptemp->sNum, sNum);
	strcpy_s(ptemp->sName, sName);
	strcpy_s(ptemp->sMajor, sMajor);
	strcpy_s(ptemp->sGrade, sGrade);
	strcpy_s(ptemp->sSex, sSex);
	strcpy_s(ptemp->sBorn_date, sBorn_date);
	strcpy_s(ptemp->iTell, iTell);
	strcpy_s(ptemp->iQQ, iQQ);
	strcpy_s(ptemp->sAdress, sAdress);
	ptemp->P_next = NULL;
	//链接链表
	if (g_head == NULL)
		g_head = ptemp;
	else g_end->P_next = ptemp;
	g_end = ptemp;//向后移动
	cout<<"添加完成！"<<endl; 
	Savedate(ptemp);
}

//头添加
void addstumsghead(char sNum[10], char sName[10], char sMajor[10], char sGrade[10], char sSex[4], char sBorn_date[10], char iTell[12], char iQQ[12], char sAdress[30])
{
	//判断输入是否合法
	char tell_min[12]={"10000000000"};
	char tell_max[12]={"19999999999"}; 
	if (sNum == NULL || sName == NULL || sMajor == NULL || sGrade == NULL || sSex == NULL || sBorn_date == NULL || strlen(iTell) != 11 || strlen(iQQ) > 11 || strlen(iQQ) < 5)
	{
		cout << "输入的信息错误" << endl;
		return;
	}
	if(strcmp(tell_min,iTell)>0||strcmp(iTell,tell_max)>0)
	{
		cout<<"输入的信息错误"<<endl;
		return; 
	}
	//创建节点
	STUNOTE *ptemp = new Student;
	//赋值
	strcpy_s(ptemp->sNum, sNum);
	strcpy_s(ptemp->sName, sName);
	strcpy_s(ptemp->sMajor, sMajor);
	strcpy_s(ptemp->sGrade, sGrade);
	strcpy_s(ptemp->sSex, sSex);
	strcpy_s(ptemp->sBorn_date, sBorn_date);
	strcpy_s(ptemp->iTell, iTell);
	strcpy_s(ptemp->iQQ, iQQ);
	strcpy_s(ptemp->sAdress, sAdress);
	ptemp->P_next = NULL;
	//链接链表
	if (g_head == NULL)
		g_end = ptemp;
	else ptemp->P_next = g_head;
	g_head = ptemp;//向前移动
	cout<<"添加完成！"<<endl; 
	Savedate(ptemp);

}

//释放数据
void FreeDate(STUNOTE*p)
{
		delete p;
	
}

//学号排序
void sortnum(Student *head)
{
	Student *p, *q;
	char sNum[10];
	char sName[10];
	char sMajor[10];
	char sGrade[10];
	char sSex[4];
	char sBorn_date[10];
	char iTell[12];
	char iQQ[12];
	char sAdress[30];
	if (head == NULL || head->P_next == NULL)
		cout << "链表为空或只有一个元素,所以没做排序！" << endl;
	while (head != NULL)
	{
		p = head;
		q = head->P_next;
		while (q != NULL)
		{
			if (strcmp(q->sNum, p->sNum)>0)
			{
				p = q;
				q = q->P_next;
			}
			else q = q->P_next;
		}
		//拷贝学号
		strcpy_s(sNum, head->sNum);
		strcpy_s(head->sNum, p->sNum);
		strcpy_s(p->sNum, sNum);
		//拷贝姓名
		strcpy_s(sName, head->sName);
		strcpy_s(head->sName, p->sName);
		strcpy_s(p->sName, sName);
		//拷贝专业
		strcpy_s(sMajor, head->sMajor);
		strcpy_s(head->sMajor, p->sMajor);
		strcpy_s(p->sMajor, sMajor);
		//拷贝年级
		strcpy_s(sGrade, head->sGrade);
		strcpy_s(head->sGrade, p->sGrade);
		strcpy_s(p->sGrade, sGrade);
		//拷贝性别
		strcpy_s(sSex, head->sSex);
		strcpy_s(head->sSex, p->sSex);
		strcpy_s(p->sSex, sSex);
		//拷贝生日
		strcpy_s(sBorn_date, head->sBorn_date);
		strcpy_s(head->sBorn_date, p->sBorn_date);
		strcpy_s(p->sBorn_date, sBorn_date);
		//拷贝电话
		strcpy_s(iTell, head->iTell);
		strcpy_s(head->iTell, p->iTell);
		strcpy_s(p->iTell, iTell);
		//拷贝QQ
		strcpy_s(iQQ, head->iQQ);
		strcpy_s(head->iQQ, p->iQQ);
		strcpy_s(p->iQQ, iQQ);
		//拷贝地址
		strcpy_s(sAdress, head->sAdress);
		strcpy_s(head->sAdress, p->sAdress);
		strcpy_s(p->sAdress, sAdress);
		head = head->P_next;
	}
	Savealldate();
}

//排序姓名
void sortname(Student *head)
{
	Student *p, *q;
	char sNum[10];
	char sName[10];
	char sMajor[10];
	char sGrade[10];
	char sSex[4];
	char sBorn_date[10];
	char iTell[12];
	char iQQ[12];
	char sAdress[30];;
	if (head == NULL || head->P_next == NULL)
		cout << "链表为空或只有一个元素,所以没做排序！" << endl;
	while (head != NULL)
	{
		p = head;
		q = head->P_next;
		while (q != NULL)
		{
			if (strcmp(q->sName, p->sName)>0)
			{
				p = q;
				q = q->P_next;
			}
			else q = q->P_next;
		}
		//拷贝学号
		strcpy_s(sNum, head->sNum);
		strcpy_s(head->sNum, p->sNum);
		strcpy_s(p->sNum, sNum);
		//拷贝姓名
		strcpy_s(sName, head->sName);
		strcpy_s(head->sName, p->sName);
		strcpy_s(p->sName, sName);
		//拷贝专业
		strcpy_s(sMajor, head->sMajor);
		strcpy_s(head->sMajor, p->sMajor);
		strcpy_s(p->sMajor, sMajor);
		//拷贝年级
		strcpy_s(sGrade, head->sGrade);
		strcpy_s(head->sGrade, p->sGrade);
		strcpy_s(p->sGrade, sGrade);
		//拷贝性别
		strcpy_s(sSex, head->sSex);
		strcpy_s(head->sSex, p->sSex);
		strcpy_s(p->sSex, sSex);
		//拷贝生日
		strcpy_s(sBorn_date, head->sBorn_date);
		strcpy_s(head->sBorn_date, p->sBorn_date);
		strcpy_s(p->sBorn_date, sBorn_date);
		//拷贝电话
		strcpy_s(iTell, head->iTell);
		strcpy_s(head->iTell, p->iTell);
		strcpy_s(p->iTell, iTell);
		//拷贝QQ
		strcpy_s(iQQ, head->iQQ);
		strcpy_s(head->iQQ, p->iQQ);
		strcpy_s(p->iQQ, iQQ);
		//拷贝地址
		strcpy_s(sAdress, head->sAdress);
		strcpy_s(head->sAdress, p->sAdress);
		strcpy_s(p->sAdress, sAdress);
		head = head->P_next;
	}
	Savealldate();
}

//打印单个数据
void Show(Student*ptemp)
{
	cout << setw(12) << setiosflags(ios::left) << ptemp->sNum;
	cout << setw(12) << setiosflags(ios::left) << ptemp->sName;
	cout << setw(12) << setiosflags(ios::left) << ptemp->sMajor;
	cout << setw(12) << setiosflags(ios::left) << ptemp->sGrade;
	cout << setw(12) << setiosflags(ios::left) << ptemp->sSex;
	cout << setw(12) << setiosflags(ios::left) << ptemp->sBorn_date;
	cout << setw(13) << setiosflags(ios::left) << ptemp->iTell;
	cout << setw(12) << setiosflags(ios::left) << ptemp->iQQ;
	cout << setw(12) << setiosflags(ios::left) << ptemp->sAdress << endl;
}

//打印所有数据
void Showdate()
{
	int a = -1, b = -1;
	STUNOTE*ptemp = g_head;
	cout << "是否需要排序？ 1、需要   2、不需要\n";
	cin >> a;
	if (a == 1)
	{
		cout << "请选择排序类型 1、按照学号   2、按照姓名\n";
		cin >> b;
		if (b == 1)
		{
			sortnum(ptemp);
			cout << "学号--------姓名--------专业--------年级--------性别--------生日--------电话号-------qq--------地址--------" << endl;
			while (ptemp != NULL)
			{
				Show(ptemp);
				ptemp = ptemp->P_next;
			}
		}
		else if (b == 2)
		{
			sortname(ptemp);
			cout << "学号--------姓名--------专业--------年级--------性别--------生日--------电话号-------qq--------地址--------" << endl;
			while (ptemp != NULL)
			{
				Show(ptemp);
				ptemp = ptemp->P_next;
			}
		}
		else cout << "输入错误！" << endl;

	}
	else if (a == 2)
	{
		cout << "学号--------姓名--------专业--------年级--------性别--------生日--------电话号-------qq--------地址--------" << endl;
		while (ptemp != NULL)
		{
			Show(ptemp);
			ptemp = ptemp->P_next;
		}
	}
	else cout << "输入错误!" << endl;

}

//按姓名查找指定学生信息
STUNOTE* Finderbyname(char cname[10])
{
	STUNOTE*p=g_head;
	if (p == NULL)
		cout << "链表为空\n";
	else
	{
		while (strcmp(p->sName,cname)!=0)
		{
			
			if (p == g_end && strcmp(p->sName, cname) != 0)
			{
				cout << "未找到此人！" << endl;
				return NULL;
				break;
			}
			
			p = p->P_next;
		}
		return p;
	}
}

//按学号查找特定学生数据
STUNOTE* Finderbynum(char cnum[10])
{
	STUNOTE*p = g_head;
	if (p == NULL)
		cout << "链表为空\n";
	else
	{
		while (strcmp(p->sNum, cnum) != 0)
		{
			
			if (p == g_end && strcmp(p->sNum, cnum) != 0)
			{
				cout << "未找到此人！" << endl;
				return NULL;
				break;
			}
			p = p->P_next;
		}
		return p;
		
	}
}

void Update(STUNOTE*p)
{

	int j;//提示是否确认修改。
	
		cout << "是否确认修改？\n1、确认\n2、取消" << endl;
		cin >> j;
		if (j == 1)
		{
			
				cout << "请输入学号：";
				cin >> p->sNum;
				cout << "请输入姓名：";
				cin >> p->sName;
				cout << "请输入专业：";
				cin >> p->sMajor;
				cout << "请输入年级：";
				cin >> p->sGrade;
				cout << "请输入性别：";
				cin >> p->sSex;
				cout << "请输入出生日期(格式19970101)：";
				cin >> p->sBorn_date;
				cout << "请输入手机号：";
				cin >> p->iTell;
				cout << "请输入QQ：";
				cin >> p->iQQ;
				cout << "请输入地址：";
				cin >> p->sAdress;
			cout<<"修改成功！"<<endl;
			Savealldate();
		}
		else if (j == 2)
			cout << "已取消\n";
		else cout << "输入错误！" << endl;
	
}


//删除学生信息
void DeleteSTUNOTE(STUNOTE* pNode)
{
	//只有一个节点 
	if (g_head == g_end)
	{
		FreeDate(g_head);
		g_head = NULL;
		g_end = NULL;

	}
	//只有两个节点 
	else if (g_head->P_next == g_end)
	{
		if (g_head == pNode)
		{
			FreeDate(g_head);
			g_head = g_end;
		}
		else
		{
			FreeDate(g_end);
			g_end = g_head;
		}
	}
	//大于等于三个节点
	else
	{
		STUNOTE*pTemp = g_head;
		//判断头
		if (g_head == pNode)
		{
			//记住头
			pTemp = g_head;
			g_head = g_head->P_next;
			FreeDate(pTemp);
			pTemp = NULL;
			return;
		}
		while (pTemp)
		{
			if (pTemp->P_next == pNode)
			{
				//删除
				if (pNode == g_end)
				{
					FreeDate(pNode);
					pNode = NULL;
					g_end = pTemp;
					return;

				}
				else
				{
					//记住要删除的节点
					STUNOTE*p = pTemp->P_next;
					//链接
					pTemp->P_next = pTemp->P_next->P_next;
					//释放节点
					FreeDate(p);
					p = NULL;
					cout<<"删除成功"<<endl; 
				    Savealldate();
					return;
				}
			}
			pTemp = pTemp->P_next;
		}
	}
	cout<<"删除成功"<<endl; 
	Savealldate();
}

//添加信息到文件
void Savedate(Student*ptemp)
{
	ofstream outfile("通讯录.txt",ios::app);
	if (!outfile)
	{
		cout << "open error!" << endl;
		abort();
	}
	outfile << setw(12) << setiosflags(ios::left) << ptemp->sNum;
	outfile << setw(12) << setiosflags(ios::left) << ptemp->sName;
	outfile << setw(12) << setiosflags(ios::left) << ptemp->sMajor;
	outfile << setw(12) << setiosflags(ios::left) << ptemp->sGrade;
	outfile << setw(12) << setiosflags(ios::left) << ptemp->sSex;
	outfile << setw(12) << setiosflags(ios::left) << ptemp->sBorn_date;
	outfile << setw(13) << setiosflags(ios::left) << ptemp->iTell;
	outfile << setw(12) << setiosflags(ios::left) << ptemp->iQQ;
	outfile << setw(12) << setiosflags(ios::left) << ptemp->sAdress << endl;
	
	outfile.close();
}

//保存所有信息到文件
void Savealldate()
{
	ofstream outfile("通讯录.txt", ios::out);
	if (!outfile)
	{
		cout << "open error!" << endl;
		abort();
	}
	Student*ptemp = g_head;
	while (ptemp != NULL)
	{
		outfile << setw(12) << setiosflags(ios::left) << ptemp->sNum;
		outfile << setw(12) << setiosflags(ios::left) << ptemp->sName;
		outfile << setw(12) << setiosflags(ios::left) << ptemp->sMajor;
		outfile << setw(12) << setiosflags(ios::left) << ptemp->sGrade;
		outfile << setw(12) << setiosflags(ios::left) << ptemp->sSex;
		outfile << setw(12) << setiosflags(ios::left) << ptemp->sBorn_date;
		outfile << setw(13) << setiosflags(ios::left) << ptemp->iTell;
		outfile << setw(12) << setiosflags(ios::left) << ptemp->iQQ;
		outfile << setw(12) << setiosflags(ios::left) << ptemp->sAdress << endl;
		ptemp = ptemp->P_next;
	}
	outfile.close();
}


//从文件读取信息
void ReaddatefromFile()
{
	char sNum[10] = { 0 };
	char sName[10] = { 0 };
	char sMajor[10] = { 0 };
	char sGrade[10] = { 0 };
	char sSex[4] = { 0 };
	char sBorn_date[10] = { 0 };
	char iTell[12] = { 0 };
	char iQQ[12] = { 0 };
	char sAdress[30] = { 0 };
	ifstream infile("通讯录.txt", ios::in);
	if (!infile)
	{
		cout << "打开错误！" << endl;
		return;
	}
	while (infile >> sNum )
	{
		infile >> sName;
		infile >> sMajor;
		infile >> sGrade;
		infile >> sSex;
		infile >> sBorn_date;
		infile >> iTell;
		infile >> iQQ;
		infile >> sAdress;
		addstumsgend_1(sNum, sName, sMajor, sGrade, sSex, sBorn_date, iTell, iQQ, sAdress);
	}
}

void addstumsgend_1(char sNum[10], char sName[10], char sMajor[10], char sGrade[10], char sSex[4], char sBorn_date[10], char iTell[12], char iQQ[12], char sAdress[30])
{
	//判断输入是否合法
	char tell_min[12] = { "10000000000" };
	char tell_max[12] = { "19999999999" };
	if (sNum == NULL || sName == NULL || sMajor == NULL || sGrade == NULL || sSex == NULL || sBorn_date == NULL || strlen(iTell) != 11 || strlen(iQQ) > 11 || strlen(iQQ) < 5)
	{
		cout << "输入的信息错误" << endl;
		return;
	}
	if (strcmp(tell_min, iTell)>0 || strcmp(iTell, tell_max)>0)
	{
		cout << "输入的信息错误" << endl;
		return;
	}
	//创建节点
	STUNOTE *ptemp = new Student;
	//赋值
	strcpy_s(ptemp->sNum, sNum);
	strcpy_s(ptemp->sName, sName);
	strcpy_s(ptemp->sMajor, sMajor);
	strcpy_s(ptemp->sGrade, sGrade);
	strcpy_s(ptemp->sSex, sSex);
	strcpy_s(ptemp->sBorn_date, sBorn_date);
	strcpy_s(ptemp->iTell, iTell);
	strcpy_s(ptemp->iQQ, iQQ);
	strcpy_s(ptemp->sAdress, sAdress);
	ptemp->P_next = NULL;
	//链接链表
	if (g_head == NULL)
		g_head = ptemp;
	else g_end->P_next = ptemp;
	g_end = ptemp;//向后移动
	cout << "添加完成！" << endl;
}