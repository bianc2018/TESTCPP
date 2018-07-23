#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;
class Print
{
	int line;
	char tag;
public:
	Print(int l=0, char t=' '):line(l),tag(t)
	{

	}
	void reset()
	{
		cout << "\r";
		for (int i = 0; i<line; i++)
			cout << tag;
		line = 0;
	}
	void print(string str,char end='\0')
	{
		cout << "\r";
		cout << str;
		int size = str.length();
		if (size<line)
		{
			for(int i=size;i<line;i++)
				cout << tag;
		}
		line = size;
		if(end!=0)
			cout << end;
	}

};
int main()
{
	int size = 100;
	Print out;
	for (int i = 0; i < size; i++)
	{
		char buff[1024];
		sprintf(buff, "½ø¶È£º%0.2f %%,%d,¹²:%d", (double(i)/ size)*100,i,size);
		out.print(buff);
		if (i + 1 % 10 == 0)
			out.reset();
		Sleep(10);
	}
	out.reset();
	system("pause");
	return 0;
}