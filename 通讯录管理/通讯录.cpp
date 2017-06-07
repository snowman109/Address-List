#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;
//******************************����ѧ���ṹ��******************************************
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
//*******************************����ͷָ���βָ��************************************
STUNOTE *g_head = NULL;
STUNOTE *g_end = NULL;

//*******************************�������ܺ���**********************************************
//β���
void addstumsgend(char sNum[10], char sName[10], char sMajor[10], char sGrade[10], char sSex[4], char sBorn_date[10], char iTell[12], char iQQ[12], char sAdress[30]);

void addstumsgend_1(char sNum[10], char sName[10], char sMajor[10], char sGrade[10], char sSex[4], char sBorn_date[10], char iTell[12], char iQQ[12], char sAdress[30]);

//ͷ���
void addstumsghead(char sNum[10], char sName[10], char sMajor[10], char sGrade[10], char sSex[4], char sBorn_date[10], char iTell[12], char iQQ[12], char sAdress[30]);

//�ͷ�����
void FreeDate(STUNOTE*p);

//ѧ������
void sortnum(Student *head);

//��������
void sortname(Student *head);

//��ӡ��������

void Show(Student*ptemp);
//��ӡ��������
void Showdate();

//�����������ض�ѧ������
STUNOTE* Finderbyname(char cname[10]);

//��ѧ�Ų����ض�ѧ������
STUNOTE* Finderbynum(char cnum[10]);

//����ָ��ѧ����Ϣ
void Update(STUNOTE*P);

//ɾ��ѧ����Ϣ
void DeleteSTUNOTE(STUNOTE* pNode);

//������Ϣ���ļ�
void Savedate(Student*ptemp);

//����������Ϣ���ļ�
void Savealldate();

//���ļ���ȡ��Ϣ
void ReaddatefromFile();
//**************************************������*******************************************
int main()
{
	Student*ptemp = g_head;
	int iOreder = -1,Flag=1;//�ж��Ƿ��˳�
	int add = -1;//�������ʱ���ѡ��
	int cos = -1;//��������ʱ��ѡ��
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
	cout << "**************ѧ��ͨѶ¼����ϵͳ**************" << endl;
	cout << "**                                          **" << endl;
	cout << "**------------1�����ѧ����Ϣ---------------**" << endl;
	cout << "**------------2����ѯѧ����Ϣ---------------**" << endl;
	cout << "**------------3���޸�ѧ����Ϣ---------------**" << endl;
	cout << "**------------4��ɾ��ѧ����Ϣ---------------**" << endl;
	cout << "**------------5����ʾͨѶ¼�е�������Ϣ-----**" << endl;
	cout << "**------------6���˳�ϵͳ-------------------**" << endl;
	cout << "**                                          **" << endl;
	cout << "**********************************************" << endl;
	while (Flag)
	{
		cout << endl << endl << "������ָ�";
		cin >> iOreder;
		switch (iOreder)
		{
		case 1:
			cout << "������ѧ�ţ�";
			cin >> sNum;
			cout << "������������";
			cin >> sName;
			cout << "������רҵ��";
			cin >> sMajor;
			cout << "�������꼶��";
			cin >> sGrade;
			cout << "�������Ա�";
			cin >> sSex;
			cout << "�������������(��ʽ19970101)��";
			cin >> sBorn_date;
			cout << "�������ֻ��ţ�";
			cin >> iTell;
			cout << "������QQ��";
			cin >> iQQ;
			cout << "�������ַ��";
			cin >> sAdress;
			cout << "��ѡ����1��ͷ���   2��β���   " << endl;
			cin >> add;
			if (add == 1)
				addstumsghead(sNum, sName, sMajor, sGrade, sSex, sBorn_date, iTell, iQQ, sAdress);
			else if (add == 2)
				addstumsgend(sNum, sName, sMajor, sGrade, sSex, sBorn_date, iTell, iQQ, sAdress);
			else
				cout << "�������" << endl;
			break;
		case 2://����ѧ����Ϣ
			cout << "��ѡ��������ݣ�\n";
			cout << "1��������������\n2������ѧ�Ų���\n";
			cin >> cos;
			if (cos == 1)
			{
				cout << "������ѧ��������\n";
				cin >> sName;
				if ((Finderbyname(sName) == NULL))
					break;
				else
				{
					cout << "ѧ��--------����--------רҵ--------�꼶--------�Ա�--------����--------�绰��-------qq--------��ַ--------" << endl;
					Show(Finderbyname(sName));
				}
			}
			else if (cos == 2)
			{
				cout << "������ѧ��ѧ�ţ�\n";
				cin >> sNum;
				if ((Finderbynum(sNum) == NULL))
					break;
				else
				{
					cout << "ѧ��--------����--------רҵ--------�꼶--------�Ա�--------����--------�绰��-------qq--------��ַ--------" << endl;
					Show(Finderbynum(sNum));
				}
			}
			else
				cout << "�������" << endl;
			break;
		case 3://�޸�ѧ����Ϣ
			cout << "���������Ҫ�޸�ѧ�������ݣ�\n";
			cout << "1��������������\n2������ѧ�Ų���\n";
			cin >> cos;
			if (cos == 1)
			{
				cout << "������Ҫ�޸�ѧ����������\n";
				cin >> sName;
				if ((Finderbyname(sName) == NULL))
					break;
				else
					Update(Finderbyname( sName));
			}
			else if (cos == 2)
			{
				cout << "������ѧ��ѧ�ţ�\n";
				cin >> sNum;
				if ((Finderbynum(sNum) == NULL))
					break;
				else
					Update(Finderbynum(sNum));
			}
			else
				cout << "�������" << endl;
			break;
		case 4://ɾ��ѧ����Ϣ
			cout << "���������Ҫɾ��ѧ�������ݣ�\n";
			cout << "1��������������\n2������ѧ�Ų���\n";
			cin >> cos;
			if (cos == 1)
			{
				cout << "������Ҫɾ��ѧ����������\n";
				cin >> sName;
				if ((Finderbyname(sName) == NULL))
					break;
				else
					DeleteSTUNOTE(Finderbyname(sName));
			//	Deletebyname(sName);
			}
			else if (cos == 2)
			{
				cout << "������ɾ��ѧ��ѧ�ţ�\n";
				cin >> sNum;
				if ((Finderbynum(sNum) == NULL))
					break;
				else
					DeleteSTUNOTE(Finderbynum(sNum));
				//Deletebycnum(sNum);
			}
			else
				cout << "�������" << endl;
			break;
		case 5://��ʾѧ����Ϣ
			Showdate();
			break;
		case 6://�˳�
			Flag = 0;
			while (g_head != NULL)//һֱѭ����ȫ��ɾ��
			{
				//��¼�ڵ�
				ptemp = g_head;
				//�ƶ��ڵ�
				g_head = g_head->P_next;
				//ɾ���ڵ�
				FreeDate(ptemp);
			}
			cout << "���˳�\n";
			break;
		default:cout << "ָ���������";
			break;
		}
	}
	
	system("pause");
}

//****************************************���幦�ܺ���****************************************
//β���
void addstumsgend(char sNum[10], char sName[10], char sMajor[10], char sGrade[10], char sSex[4], char sBorn_date[10], char iTell[12], char iQQ[12], char sAdress[30])
{
	//�ж������Ƿ�Ϸ�
	char tell_min[12]={"10000000000"};
	char tell_max[12]={"19999999999"}; 
	if (sNum == NULL || sName == NULL || sMajor == NULL || sGrade == NULL || sSex == NULL || sBorn_date == NULL || strlen(iTell) != 11 || strlen(iQQ) > 11 || strlen(iQQ) < 5)
	{
		cout << "�������Ϣ����" << endl;
		return;
	}
	if(strcmp(tell_min,iTell)>0||strcmp(iTell,tell_max)>0)
	{
		cout<<"�������Ϣ����"<<endl;
		return; 
	}
	//�����ڵ�
	STUNOTE *ptemp = new Student;
	//��ֵ
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
	//��������
	if (g_head == NULL)
		g_head = ptemp;
	else g_end->P_next = ptemp;
	g_end = ptemp;//����ƶ�
	cout<<"�����ɣ�"<<endl; 
	Savedate(ptemp);
}

//ͷ���
void addstumsghead(char sNum[10], char sName[10], char sMajor[10], char sGrade[10], char sSex[4], char sBorn_date[10], char iTell[12], char iQQ[12], char sAdress[30])
{
	//�ж������Ƿ�Ϸ�
	char tell_min[12]={"10000000000"};
	char tell_max[12]={"19999999999"}; 
	if (sNum == NULL || sName == NULL || sMajor == NULL || sGrade == NULL || sSex == NULL || sBorn_date == NULL || strlen(iTell) != 11 || strlen(iQQ) > 11 || strlen(iQQ) < 5)
	{
		cout << "�������Ϣ����" << endl;
		return;
	}
	if(strcmp(tell_min,iTell)>0||strcmp(iTell,tell_max)>0)
	{
		cout<<"�������Ϣ����"<<endl;
		return; 
	}
	//�����ڵ�
	STUNOTE *ptemp = new Student;
	//��ֵ
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
	//��������
	if (g_head == NULL)
		g_end = ptemp;
	else ptemp->P_next = g_head;
	g_head = ptemp;//��ǰ�ƶ�
	cout<<"�����ɣ�"<<endl; 
	Savedate(ptemp);

}

//�ͷ�����
void FreeDate(STUNOTE*p)
{
		delete p;
	
}

//ѧ������
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
		cout << "����Ϊ�ջ�ֻ��һ��Ԫ��,����û������" << endl;
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
		//����ѧ��
		strcpy_s(sNum, head->sNum);
		strcpy_s(head->sNum, p->sNum);
		strcpy_s(p->sNum, sNum);
		//��������
		strcpy_s(sName, head->sName);
		strcpy_s(head->sName, p->sName);
		strcpy_s(p->sName, sName);
		//����רҵ
		strcpy_s(sMajor, head->sMajor);
		strcpy_s(head->sMajor, p->sMajor);
		strcpy_s(p->sMajor, sMajor);
		//�����꼶
		strcpy_s(sGrade, head->sGrade);
		strcpy_s(head->sGrade, p->sGrade);
		strcpy_s(p->sGrade, sGrade);
		//�����Ա�
		strcpy_s(sSex, head->sSex);
		strcpy_s(head->sSex, p->sSex);
		strcpy_s(p->sSex, sSex);
		//��������
		strcpy_s(sBorn_date, head->sBorn_date);
		strcpy_s(head->sBorn_date, p->sBorn_date);
		strcpy_s(p->sBorn_date, sBorn_date);
		//�����绰
		strcpy_s(iTell, head->iTell);
		strcpy_s(head->iTell, p->iTell);
		strcpy_s(p->iTell, iTell);
		//����QQ
		strcpy_s(iQQ, head->iQQ);
		strcpy_s(head->iQQ, p->iQQ);
		strcpy_s(p->iQQ, iQQ);
		//������ַ
		strcpy_s(sAdress, head->sAdress);
		strcpy_s(head->sAdress, p->sAdress);
		strcpy_s(p->sAdress, sAdress);
		head = head->P_next;
	}
	Savealldate();
}

//��������
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
		cout << "����Ϊ�ջ�ֻ��һ��Ԫ��,����û������" << endl;
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
		//����ѧ��
		strcpy_s(sNum, head->sNum);
		strcpy_s(head->sNum, p->sNum);
		strcpy_s(p->sNum, sNum);
		//��������
		strcpy_s(sName, head->sName);
		strcpy_s(head->sName, p->sName);
		strcpy_s(p->sName, sName);
		//����רҵ
		strcpy_s(sMajor, head->sMajor);
		strcpy_s(head->sMajor, p->sMajor);
		strcpy_s(p->sMajor, sMajor);
		//�����꼶
		strcpy_s(sGrade, head->sGrade);
		strcpy_s(head->sGrade, p->sGrade);
		strcpy_s(p->sGrade, sGrade);
		//�����Ա�
		strcpy_s(sSex, head->sSex);
		strcpy_s(head->sSex, p->sSex);
		strcpy_s(p->sSex, sSex);
		//��������
		strcpy_s(sBorn_date, head->sBorn_date);
		strcpy_s(head->sBorn_date, p->sBorn_date);
		strcpy_s(p->sBorn_date, sBorn_date);
		//�����绰
		strcpy_s(iTell, head->iTell);
		strcpy_s(head->iTell, p->iTell);
		strcpy_s(p->iTell, iTell);
		//����QQ
		strcpy_s(iQQ, head->iQQ);
		strcpy_s(head->iQQ, p->iQQ);
		strcpy_s(p->iQQ, iQQ);
		//������ַ
		strcpy_s(sAdress, head->sAdress);
		strcpy_s(head->sAdress, p->sAdress);
		strcpy_s(p->sAdress, sAdress);
		head = head->P_next;
	}
	Savealldate();
}

//��ӡ��������
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

//��ӡ��������
void Showdate()
{
	int a = -1, b = -1;
	STUNOTE*ptemp = g_head;
	cout << "�Ƿ���Ҫ���� 1����Ҫ   2������Ҫ\n";
	cin >> a;
	if (a == 1)
	{
		cout << "��ѡ���������� 1������ѧ��   2����������\n";
		cin >> b;
		if (b == 1)
		{
			sortnum(ptemp);
			cout << "ѧ��--------����--------רҵ--------�꼶--------�Ա�--------����--------�绰��-------qq--------��ַ--------" << endl;
			while (ptemp != NULL)
			{
				Show(ptemp);
				ptemp = ptemp->P_next;
			}
		}
		else if (b == 2)
		{
			sortname(ptemp);
			cout << "ѧ��--------����--------רҵ--------�꼶--------�Ա�--------����--------�绰��-------qq--------��ַ--------" << endl;
			while (ptemp != NULL)
			{
				Show(ptemp);
				ptemp = ptemp->P_next;
			}
		}
		else cout << "�������" << endl;

	}
	else if (a == 2)
	{
		cout << "ѧ��--------����--------רҵ--------�꼶--------�Ա�--------����--------�绰��-------qq--------��ַ--------" << endl;
		while (ptemp != NULL)
		{
			Show(ptemp);
			ptemp = ptemp->P_next;
		}
	}
	else cout << "�������!" << endl;

}

//����������ָ��ѧ����Ϣ
STUNOTE* Finderbyname(char cname[10])
{
	STUNOTE*p=g_head;
	if (p == NULL)
		cout << "����Ϊ��\n";
	else
	{
		while (strcmp(p->sName,cname)!=0)
		{
			
			if (p == g_end && strcmp(p->sName, cname) != 0)
			{
				cout << "δ�ҵ����ˣ�" << endl;
				return NULL;
				break;
			}
			
			p = p->P_next;
		}
		return p;
	}
}

//��ѧ�Ų����ض�ѧ������
STUNOTE* Finderbynum(char cnum[10])
{
	STUNOTE*p = g_head;
	if (p == NULL)
		cout << "����Ϊ��\n";
	else
	{
		while (strcmp(p->sNum, cnum) != 0)
		{
			
			if (p == g_end && strcmp(p->sNum, cnum) != 0)
			{
				cout << "δ�ҵ����ˣ�" << endl;
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

	int j;//��ʾ�Ƿ�ȷ���޸ġ�
	
		cout << "�Ƿ�ȷ���޸ģ�\n1��ȷ��\n2��ȡ��" << endl;
		cin >> j;
		if (j == 1)
		{
			
				cout << "������ѧ�ţ�";
				cin >> p->sNum;
				cout << "������������";
				cin >> p->sName;
				cout << "������רҵ��";
				cin >> p->sMajor;
				cout << "�������꼶��";
				cin >> p->sGrade;
				cout << "�������Ա�";
				cin >> p->sSex;
				cout << "�������������(��ʽ19970101)��";
				cin >> p->sBorn_date;
				cout << "�������ֻ��ţ�";
				cin >> p->iTell;
				cout << "������QQ��";
				cin >> p->iQQ;
				cout << "�������ַ��";
				cin >> p->sAdress;
			cout<<"�޸ĳɹ���"<<endl;
			Savealldate();
		}
		else if (j == 2)
			cout << "��ȡ��\n";
		else cout << "�������" << endl;
	
}


//ɾ��ѧ����Ϣ
void DeleteSTUNOTE(STUNOTE* pNode)
{
	//ֻ��һ���ڵ� 
	if (g_head == g_end)
	{
		FreeDate(g_head);
		g_head = NULL;
		g_end = NULL;

	}
	//ֻ�������ڵ� 
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
	//���ڵ��������ڵ�
	else
	{
		STUNOTE*pTemp = g_head;
		//�ж�ͷ
		if (g_head == pNode)
		{
			//��סͷ
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
				//ɾ��
				if (pNode == g_end)
				{
					FreeDate(pNode);
					pNode = NULL;
					g_end = pTemp;
					return;

				}
				else
				{
					//��סҪɾ���Ľڵ�
					STUNOTE*p = pTemp->P_next;
					//����
					pTemp->P_next = pTemp->P_next->P_next;
					//�ͷŽڵ�
					FreeDate(p);
					p = NULL;
					cout<<"ɾ���ɹ�"<<endl; 
				    Savealldate();
					return;
				}
			}
			pTemp = pTemp->P_next;
		}
	}
	cout<<"ɾ���ɹ�"<<endl; 
	Savealldate();
}

//�����Ϣ���ļ�
void Savedate(Student*ptemp)
{
	ofstream outfile("ͨѶ¼.txt",ios::app);
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

//����������Ϣ���ļ�
void Savealldate()
{
	ofstream outfile("ͨѶ¼.txt", ios::out);
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


//���ļ���ȡ��Ϣ
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
	ifstream infile("ͨѶ¼.txt", ios::in);
	if (!infile)
	{
		cout << "�򿪴���" << endl;
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
	//�ж������Ƿ�Ϸ�
	char tell_min[12] = { "10000000000" };
	char tell_max[12] = { "19999999999" };
	if (sNum == NULL || sName == NULL || sMajor == NULL || sGrade == NULL || sSex == NULL || sBorn_date == NULL || strlen(iTell) != 11 || strlen(iQQ) > 11 || strlen(iQQ) < 5)
	{
		cout << "�������Ϣ����" << endl;
		return;
	}
	if (strcmp(tell_min, iTell)>0 || strcmp(iTell, tell_max)>0)
	{
		cout << "�������Ϣ����" << endl;
		return;
	}
	//�����ڵ�
	STUNOTE *ptemp = new Student;
	//��ֵ
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
	//��������
	if (g_head == NULL)
		g_head = ptemp;
	else g_end->P_next = ptemp;
	g_end = ptemp;//����ƶ�
	cout << "�����ɣ�" << endl;
}