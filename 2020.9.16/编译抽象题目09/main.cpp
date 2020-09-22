#include "Test.h"
#include <iostream>
#include <vector>

using namespace std;

Test* find(vector<Test*> vTests, int id)
{
	for(int i = 0; i < vTests.size(); ++i)
	{
		if(id == vTests[i]->m_iId) return vTests[i];
	}
	return NULL;
}
int main()
{
	vector<Test*> vTests;
	for(int i = 0; i < 10; ++i)
	{
		Test* tmp = new Test();
		tmp->m_iId = i;
		vTests.push_back(tmp);
	}
	Test* ft = find(vTests, 1);
	if(ft != NULL)
		ft->f();
	return 0;	
}