//lian zirui.,10701319, 2020.
//�ҵ����ı����һ����ĸΪ��ͷ�ͽ�β�ĵ���

//1�����ļ�
//2������ļ����ų�����
//3������Դ�ļ��ĸ������ڲ���
//4����ʼ����
#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>

using namespace std;


bool condition(char c)
{
	return c != ' ' && c != ',' && c != '? ' && c != '!' && c != '.';
}
//�ж��ı��ַ�
bool letter(char c)
{
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}

void Judgment_file(fstream& file) {

	char j;
	int i = 0;
	while (!file.eof())//�ж����Ƿ�����ļ���β
	{
		i++;
		file.get(j);
		if (j == ' ' || j == ',' || j == '? ' || j == '!' || j == '.')
		{
			continue;
		}
		if (letter(j) == 0)
		{
			cout << "�ļ�������" << endl;
			exit(1);
		}
	}
	cout << "ѭ������" << i << endl;

	file.clear();
	file.seekp(0, ios::beg);
}

void build_copy(fstream& file, char text[]) {

	while (!file.eof())
	{
		file.getline(text, 1000);//���ĵ��������ַ�������

	}

}
fstream Open_File() {

	string filename;
	fstream file;

	while (1) {
		cout << "����Ҫ�򿪵��ļ�����" << endl;
		cin >> filename;

		file.open(filename + ".txt", ios::in | ios::out);

		if (!file.fail())
		{
			break;
		}
		else {
			cout << "��ʧ��" << endl;
		}
	}

	return file;
}

string Find_Word(char text[]) {

	int len = strlen(text);//��ȡ�ַ�������
	cout << "�ı����ȣ�" << len << endl;
	//4����ʼ����
	char* y = text;
	string w, word, str; //�����ҵ��ĵ���
	char x = NULL;//�ı����һ����ĸ

	if (condition(text[len - 1])) {
		x = text[len - 1];
	}
	//cout << x << endl;
	//�����㷨
	for (int i = 0; i < len; i++)
	{
		//cout << i << endl;
		if (*(y + i) == x && *(y + i - 1) == ' ') {
			word = *(y + i);
			i++;
			while (condition(*(y + i))) {
				w = *(y + i);
				word = word + w;
				i++;
			}
			if (*(y + i - 1) == x) {
				str = str + word + '\t';
				//cout << word << endl;
				word.clear();
			}
			else {
				word.clear();
			}
		}
		else {
			continue;
		}
	}

	if (str.empty())
	{
		cout << "û�к��ʵĴ�" << endl;
	}
	return str;
}

//string*  charToStr() {
//
//}
int main()
{
	//1�����ļ�
	fstream file = Open_File();

	//2������ļ����ų�����
	Judgment_file(file);

	//3������Դ�ļ��ĸ������ڲ���
	char text[1000] = { 0 }; //�洢ԭʼ�ı�
	build_copy(file, text);
	file.close();
	cout << text << endl;

	//4����ʼ����
	string res = Find_Word(text);
	cout << res << endl;
	
	system("pause");
	return 0;
}