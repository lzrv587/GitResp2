#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//任务：求主对角线上的负数之和


bool number(char c)
{
	return (c >= '0' && c <= '9');
}

int main()
{
	//请求内存
	int** array;
	int m = 4, n = 4;
	array = new int* [m];
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n]();
	}

	//打开文件
	string filename;
	cout << "输入要打开的文件名：" << endl;
	cin >> filename;

	fstream infile;
	infile.open(filename + ".txt", ios::in | ios::out | ios::app);

	if (!infile)
	{
		cout << "无法打开文件" << endl;
		return -1;
	}
	else
	{
		cout << "成功打开文件" << endl;
	}

	//检查文件内容
	char s;
	while (!infile.eof())
	{
		infile.get(s);
		if (s == ' ' || s == '-' || s == '\n')
		{
			continue;
		}
		if (!number(s))
		{
			cout << "非法字符" << endl;
			exit(1);
		}
	}

	//处理文件
	infile.clear();
	infile.seekp(0, ios::beg);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (infile.eof())
			{
				break;
			}
			infile >> *(array[i] + j);
			cout << *(*(array + i) + j) << ' ';
		}
		cout << endl;
	}

	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		if (*(*(array + i) + i) < 0)
		{
			sum = sum + *(*(array + i) + i);
		}
		else
		{
			continue;
		}
	}
	cout << "主对角线上的负数之和为:" << sum << endl;

	//输出到文本
	infile.clear();
	infile << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			infile << *(*(array + i) + j) << ' ';
		}
		infile << endl;
	}

	//关闭文件释放内存
	infile.close();
	for (int i = 0; i < m; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	array = NULL;

	system("pause");
	return 0;
}