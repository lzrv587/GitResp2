#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//���������Խ����ϵĸ���֮��


bool number(char c)
{
	return (c >= '0' && c <= '9');
}

int main()
{
	//�����ڴ�
	int** array;
	int m = 4, n = 4;
	array = new int* [m];
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n]();
	}

	//���ļ�
	string filename;
	cout << "����Ҫ�򿪵��ļ�����" << endl;
	cin >> filename;

	fstream infile;
	infile.open(filename + ".txt", ios::in | ios::out | ios::app);

	if (!infile)
	{
		cout << "�޷����ļ�" << endl;
		return -1;
	}
	else
	{
		cout << "�ɹ����ļ�" << endl;
	}

	//����ļ�����
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
			cout << "�Ƿ��ַ�" << endl;
			exit(1);
		}
	}

	//�����ļ�
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
	cout << "���Խ����ϵĸ���֮��Ϊ:" << sum << endl;

	//������ı�
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

	//�ر��ļ��ͷ��ڴ�
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