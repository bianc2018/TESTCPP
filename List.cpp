#include <iostream>
#include <cstring>
using namespace std;
class node
{
public:
	int data;
	node* next;
};
class List
{
	node*head;
	int len;
public:
	List()
	{
		head = NULL;
		len = 0;
	}
	//�±��������
	int at(int id)
	{
		if (id < 0 || id >= len)
		{
			cout << "����Խ�磺"<<"(0,"<<len<<")" << endl;
			return -1;
		}
		node*p = head;
		while (id)
		{
			id -= 1;
			p = p->next;
		}
		return p->data;
	}
	//β���������
	int append(int value)
	{
		node*p = head;
		//����ͷ���
		if (p == NULL)
		{
			head = new node;
			head->data = value;
			head->next = NULL;
			len += 1;
			return len;
		}
		//�ҵ�β���
		while (p->next)p=p->next;
		//�����½��
		node* new_node = new node;
		new_node->data = value;
		new_node->next = NULL;
		p->next = new_node;
		len += 1;
		return len;
	}
	//����ֵɾ����һ�����
	bool remove(int value)
	{
		node*p = head,*pre = head;
		while (p)
		{
			if (p->data == value)
			{
				node*NODE = NULL;
				if (p == head)
				{
					NODE = head;
					head = head->next;
				}
				else
				{
					NODE = p;
					pre->next = p->next;
				}
				delete NODE;
				len--;
				return true;
			}
			pre = p;
			p = p->next;
		}
		return false;
	}
	//�����±�ɾ�����
	bool del(int id)
	{
		if (id >= len)return false;
		node*p = head,*pre = head;
		while (id)
		{
			id -= 1;
			pre = p;
			p=p->next;

		}
		if (p == head)
		{
			node*NODE = head;
			head = head->next;
			delete NODE;
			len--;
			return true;
		}
		node*NODE = p;
		pre->next = p->next;
		delete NODE;
		len--;
		return true;
	}
	//���س���
	int length()
	{
		return this->len;
	}
	~List()
	{
		node*p = head;
		while (p)
		{
			node*NODE = p;
			p = p->next;
			delete NODE;
		}
		head = NULL;
	}
};
int main(int argc, char *argv[])
{
	List L;
	for (int i = 0; i < 100; i++)
	{
		L.append(i);
		cout <<"���ȣ�"<< L.length() << endl<<endl;
	}
	cout << "���ȣ�" << L.length() << endl;
	//L.remove(0);
	//L.remove(99);
	L.remove(56);
	cout << L.at(56) << endl;
	L.del(56);
	cout << "���ȣ�" << L.length() << endl;
	for (int i = 0; i < L.length(); i++)
	{
		cout << L.at(i)<<'\t';
		if (i+1 % 5 == 0)cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}