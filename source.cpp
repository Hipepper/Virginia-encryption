#include <fstream>
#include<string>
#include<iostream>
#include <cassert>

using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class shiyan1  //���ܺ���ά����������
{
private:
	string mingwen;  //�������������
	string key;       //�����������Կ
	int key2[26];    //�����Ǳ�����Կ���Ƶ���ֵ
	char miwen[100];     //������������� 
	char jiemi[100] = { 0 };

public:

	void setdate()     //�������ݲ���
	{
		cout << "��������Ҫ�������ַ�����(ֻ�������Сд��ĸ)";
		getline(cin, mingwen);
		cout << "������key:";
		getline(cin, key);
	}

	int panduan()    //����һ���жϺ������涨�������Ч��
	{
		for (int i = 0; i < mingwen.length(); i++)
		{
			if ((mingwen[i] >= 65 && mingwen[i] <= 90) || (mingwen[i] >= 97 && mingwen[i] <= 122) || mingwen[i] == ' ') {}
			else
			{
				cout << "�����ַ���: " << endl;
				cout << mingwen << endl;
				return 1;
			}
		}
		return 0;
	}

	void yi_key()    //������Կ���ƶ�λ�ã�Ȼ�󱣴������
	{
		for (int i = 0; i < key.length(); i++)
		{
			if (key[i] < 97)    //��Сд��ĸ
				key2[i] = key[i] - 'A';
			if (key[i] >= 97)
				key2[i] = key[i] - 'a';
		}
	}
	void encryption()
	{
		int j = 0;
		for (int i = 0; i < mingwen.length(); i++)
		{
			if (mingwen[i] != ' '&&mingwen[i]>=97)   //�ո�ֱ������
			{
				char m=mingwen[i]-97;
				int k = key2[j];      //ȡ��key2���汣���ƫ����  
				miwen[i] = (m + k) % 26+65;
				if (j != key.length()-1)
					j++;
				else
					j = 0;
			}
			if (mingwen[i] != ' ' && mingwen[i] < 97)   //�ո�ֱ������
			{
				char m = mingwen[i] -65;
				int k = key2[j];      //ȡ��key2���汣���ƫ����  
				miwen[i] = (m + k) % 26 + 97;
				if (j != key.length()-1)
					j++;
				else
					j = 0;
			}
			if (mingwen[i] == ' ')
			{
				miwen[i] = ' ';
			}
		}
	}
	void decryption()
	{
		int j = 0;
		for (int i = 0; i < 100; i++)
		{
			if (miwen[i] == ' ')
			{
				jiemi[i] = ' ';
			}
			if (miwen[i] != ' ' && miwen[i] >= 97)
			{
				char m = miwen[i] - 97;
				int k = key2[j];
				jiemi[i] = (m + 26-k) % 26 + 65;
				if (j != key.length() - 1)
					j++;
				else
					j = 0;
			}
			if (miwen[i] != ' ' && miwen[i] < 97)
			{
				char m = miwen[i] - 65;
				int k = key2[j];
				jiemi[i] = (m +(26-k)) % 26 + 97;
				if (j != key.length() - 1)
					j++;
				else
					j = 0;
			}
		}
	}

	void show()
	{
		cout << "����֮��������ǣ�";
		cout << miwen << endl;
		cout << "ͨ������֮���ԭ�ģ�" << endl;
		for (int i = 0; i < mingwen.length(); i++)
		{
			cout << jiemi[i];
}
	}
};

//********************************************************************************************************************************************
class Single_table   //�����ӽ����㷨
{
private:
	string mingwen;  //�������������
	char miwen[100];      //�����������Կ
	int s;     //��ĸ��
public:
	void setdate()     //�������ݲ���
	{
		cout << "��������Ҫ���ܵ�ԭ�ģ�";
		getline(cin, mingwen);
		cout << "��������Կ��";
		cin >> s;
	}

	void encrypt()
	{
		for (int i = 0; i < mingwen.length(); i++)    
		{
			if (mingwen[i] == ' ')
				miwen[i] = '*';
			if (mingwen[i] > 96)
			{
				miwen[i] = (mingwen[i] - 97 + s) % 26 + 65;
			}
			if (mingwen[i] < 96)
			{
				miwen[i] = (mingwen[i] - 65 + s) % 26 + 97;
			}
		}
	}

	void show()
	{
		string a = "abcdefghijklmnopqrstuvwxyz";
		char a1[26];
		for (int i = 0; i < 26; i++)
		{
			a1[i] = (a[i]-97 + s) % 26+97;
		}
		
		cout << "�滻���ǣ�";
		for (int j = 0; j < 26; j++)
		{
			cout << a1[j];
		}
		cout << "�����ǣ�" << miwen << endl;
	}
};

   shiyan1 shiyan1test;
   Single_table singletest;
  
	int main()
	{
		char c;
		shiyan1test.setdate();
		int i=shiyan1test.panduan();
		if (i == 1)
		{
			goto _1;
		}
		shiyan1test.yi_key();
		 shiyan1test.encryption();
		shiyan1test.decryption();
		shiyan1test.show();
		_1:;
		
		
		singletest.setdate();
		singletest.encrypt();
		singletest.show();

		return 0;

	}
