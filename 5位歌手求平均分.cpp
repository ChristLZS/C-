#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<deque>
#include<ctime>
using namespace std;

/*
	��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
	//1. ��������ѡ�֣��ŵ�vector��
	//2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
	//3. sort�㷨��deque�����з�������pop_back pop_frontȥ����ߺ���ͷ�
	//4. deque��������һ�飬�ۼӷ������ۼӷ���/d.size()
	//5. person.score = ƽ����
*/


class Singer
{
public:
	Singer(string name)
	{
		this->m_Name = name;
	}
	string m_Name;
	int m_Sorce;
};


void CreatSinger(vector<Singer> &v)
{
	char s[5] = { 'A','B','C','D','E' };
	for (int i = 0; i < 5; i++)
	{
		string str = "����";
		str += s[i];
		Singer s(str);
		v.push_back(s);
	}
}

void printSinger(vector<Singer> &v)
{
	for (vector<Singer>::iterator it=v.begin(); it != v.end(); it++)
	{
		cout << "������" << (*it).m_Name << endl;
	}
}

void CreatSorce(vector<Singer> &v)
{
	for (vector<Singer>::iterator it = v.begin() ; it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int s = rand() % 41 + 60;
			d.push_back(s);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		int sum = 0;
		for (deque<int>::iterator itit = d.begin(); itit != d.end(); itit++)
		{
			sum += (*itit);
		}
		(*it).m_Sorce = sum / d.size();
	}
}

void printSingerSorce(vector<Singer> &v)
{
	for (vector<Singer>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << (*it).m_Name << " ƽ���֣�" << (*it).m_Sorce << endl;
	}
}

int main()
{
	//���������
	srand((unsigned int)time(NULL));

	//��vector�����������
	vector<Singer> v;
	CreatSinger(v);
	
	//���Դ�ӡ����
	//printSinger(v);

	//��deque����10λ��ί���
	CreatSorce(v);

	//�������ƽ����
	printSingerSorce(v);
	

	system("pause");
	return EXIT_SUCCESS;
}

