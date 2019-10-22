#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main()
{
	int lineCount = 0;   //行数
	int charCount = 0;   //字符数
	int sentenceCount=0; //句子数
	int wordCount=0;     //单词数
	int Count=0;         //,的数量

	string str;

	ifstream infile;          //读文件
	infile.open("YLSD.txt");
 
	ofstream outfile;          //写文件
	outfile.open("out.txt");
	
	while(getline(infile,str))  //统计行
	{

		lineCount++;
		outfile<<str<<"\n";     //写入到out.txt
	}


	ifstream infile1;            //重置文件
	infile1.open("YLSD.txt");


	char c;
	while(infile1>>c)        //读取字符
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

    wordCount=charCount-sentenceCount-Count; //减去, . ? ! 的字符

    outfile<<"\n";                    //out的结尾
    outfile<<"There are "<<lineCount<<" lines, and "<<charCount<<" chars,and "<<sentenceCount<<" sentence,and "<<wordCount<<" words\n";    
	outfile<<"END"<<"\n";

	infile.close();
	outfile.close();
	infile1.close();

	cout<<"There are "<<lineCount<<" lines\n"<<"          "<<charCount<<" chars\n"<<"          "<<sentenceCount<<" sentences\n"<<"          "<<wordCount<<" words\n";
}
