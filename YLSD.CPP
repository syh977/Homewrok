#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main()
{
	int lineCount = 0;   //����
	int charCount = 0;   //�ַ���
	int sentenceCount=0; //������
	int wordCount=0;     //������
	int Count=0;         //,������

	string str;

	ifstream infile;          //���ļ�
	infile.open("YLSD.txt");
 
	ofstream outfile;          //д�ļ�
	outfile.open("out.txt");
	
	while(getline(infile,str))  //ͳ����
	{

		lineCount++;
		outfile<<str<<"\n";     //д�뵽out.txt
	}


	ifstream infile1;            //�����ļ�
	infile1.open("YLSD.txt");


	char c;
	while(infile1>>c)        //��ȡ�ַ�
	{
		charCount++;
		if(c == '.'|| c=='!'||c=='?')
		{
           sentenceCount++;
		}
		else if(c ==',')
		{
         Count++;
		}
	}

    wordCount=charCount-sentenceCount-Count; //��ȥ, . ? ! ���ַ�

    outfile<<"\n";                    //out�Ľ�β
    outfile<<"There are "<<lineCount<<" lines, and "<<charCount<<" chars,and "<<sentenceCount<<" sentence,and "<<wordCount<<" words\n";    
	outfile<<"END"<<"\n";

	infile.close();
	outfile.close();
	infile1.close();

	cout<<"There are "<<lineCount<<" lines\n"<<"          "<<charCount<<" chars\n"<<"          "<<sentenceCount<<" sentences\n"<<"          "<<wordCount<<" words\n";
}