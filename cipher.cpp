//����������������ӽ����ļ�
#include<stdio.h>
#include<iostream>
#include<string>
#include <fstream>
#include <cassert>
using namespace std;
int main(int argc, char* argv[])
{
	char mingwen;
	char miwen;
	//char* b = argv[2];//�ڶ�����������Կ
	char key2[50];
	string key(argv[2]);
	///////////////////////�����ƶ������Կֵ///////////////////////////////////
	for (int i = 0; i < key.length(); i++)
	{
		if (key[i] < 97)    //��Сд��ĸ
			key2[i] = key[i] - 'A';
		if (key[i] >= 97)
			key2[i] = key[i] - 'a';
	}
	///////////////////////////////////��ȡ�ļ�����//////////////////////////////
	char* c = argv[3];  //���������������ļ���
	string infilename(argv[3]);
	char* d = argv[4];
	string outfilename(argv[4]);

	ifstream infile;       //�����ļ�
	ofstream outFile;    //����ļ�
	infile.open(infilename);   //���ļ����������ļ��������� 
	outFile.open(outfilename);
	assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 

	infile >> noskipws;
	string m(argv[1]);
	for (int i = 0; !infile.eof(); i++)
	{
		infile >> mingwen;
		if (m == "-e")  //����
		{
			int j = 0;
			if (mingwen != ' ' && mingwen >= 97)   //�ո�ֱ������
			{
				char m = mingwen - 97;
				int k = key2[j];      //ȡ��key2���汣���ƫ����  
				miwen = (m + k) % 26 + 65;
				if (j != key.length() - 1)
					j++;
				else
					j = 0;
				outFile << miwen;
			}
			if (mingwen != ' ' && mingwen < 97)   //�ո�ֱ������
			{
				char m = mingwen - 65;
				int k = key2[j];      //ȡ��key2���汣���ƫ����  
				miwen = (m + k) % 26 + 97;
				if (j != key.length() - 1)
					j++;
				else
					j = 0;
				outFile << miwen;
			}
			if (mingwen == ' ')
			{
				miwen = ' ';
				outFile << miwen;
			}
		}
		if (m == "-d")  //����,����������˼·����һ���ģ�ֻ���ƶ����ʺϲ�ͬ�����л�������������ʾ�û����������
		{
			int j = 0;
			if (mingwen != ' ' && mingwen >= 97)   //�ո�ֱ������
			{
				char m = mingwen - 97;
				int k = key2[j];      //ȡ��key2���汣���ƫ����  
				miwen = (m + 26 - k) % 26 + 65;
				if (j != key.length() - 1)
					j++;
				else
					j = 0;
				outFile << miwen;
			}
			if (mingwen != ' ' && mingwen < 97)   //�ո�ֱ������
			{
				char m = mingwen - 65;
				int k = key2[j];      //ȡ��key2���汣���ƫ����  
				miwen = (m + (26 - k)) % 26 + 97;
				if (j != key.length() - 1)
					j++;
				else
					j = 0;
				outFile << miwen;
			}
			if (mingwen == ' ')
			{
				miwen = ' ';
				outFile << miwen;
			}
		}

	}
	infile.close();             //�ر��ļ�����
	outFile.close();




	return 0;
}
