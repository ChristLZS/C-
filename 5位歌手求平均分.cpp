#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<deque>
#include<ctime>
using namespace std;

/*
	有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
	//1. 创建五名选手，放到vector中
	//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
	//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
	//4. deque容器遍历一遍，累加分数，累加分数/d.size()
	//5. person.score = 平均分
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
		string str = "歌手";
		str += s[i];
		Singer s(str);
		v.push_back(s);
	}
}

void printSinger(vector<Singer> &v)
{
	for (vector<Singer>::iterator it=v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << endl;
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
		cout << "姓名：" << (*it).m_Name << " 平均分：" << (*it).m_Sorce << endl;
	}
}

int main()
{
	//随机数播种
	srand((unsigned int)time(NULL));

	//用vector创建五个歌手
	vector<Singer> v;
	CreatSinger(v);
	
	//测试打印歌手
	//printSinger(v);

	//用deque创建10位评委打分
	CreatSorce(v);

	//输出歌手平均分
	printSingerSorce(v);
	

	system("pause");
	return EXIT_SUCCESS;
}

