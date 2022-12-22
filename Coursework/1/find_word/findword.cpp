//lian zirui.,10701319, 2020.
//找到以文本最后一个字母为开头和结尾的单词

//1、打开文件
//2、检查文件，排除数字
//3、构建源文件的副本用于操作
//4、开始查找
#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>

using namespace std;


bool condition(char c)
{
	return c != ' ' && c != ',' && c != '? ' && c != '!' && c != '.';
}
//判断文本字符
bool letter(char c)
{
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}

void Judgment_file(fstream& file) {

	char j;
	int i = 0;
	while (!file.eof())//判断其是否读到文件结尾
	{
		i++;
		file.get(j);
		if (j == ' ' || j == ',' || j == '? ' || j == '!' || j == '.')
		{
			continue;
		}
		if (letter(j) == 0)
		{
			cout << "文件不适用" << endl;
			exit(1);
		}
	}
	cout << "循环次数" << i << endl;

	file.clear();
	file.seekp(0, ios::beg);
}

void build_copy(fstream& file, char text[]) {

	while (!file.eof())
	{
		file.getline(text, 1000);//将文档保存在字符数组中

	}

}
fstream Open_File() {

	string filename;
	fstream file;

	while (1) {
		cout << "输入要打开的文件名：" << endl;
		cin >> filename;

		file.open(filename + ".txt", ios::in | ios::out);

		if (!file.fail())
		{
			break;
		}
		else {
			cout << "打开失败" << endl;
		}
	}

	return file;
}

string Find_Word(char text[]) {

	int len = strlen(text);//获取字符串长度
	cout << "文本长度：" << len << endl;
	//4、开始查找
	char* y = text;
	string w, word, str; //保存找到的单词
	char x = NULL;//文本最后一个字母

	if (condition(text[len - 1])) {
		x = text[len - 1];
	}
	//cout << x << endl;
	//检索算法
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
		cout << "没有合适的词" << endl;
	}
	return str;
}

//string*  charToStr() {
//
//}
int main()
{
	//1、打开文件
	fstream file = Open_File();

	//2、检查文件，排除数字
	Judgment_file(file);

	//3、构建源文件的副本用于操作
	char text[1000] = { 0 }; //存储原始文本
	build_copy(file, text);
	file.close();
	cout << text << endl;

	//4、开始检索
	string res = Find_Word(text);
	cout << res << endl;
	
	system("pause");
	return 0;
}