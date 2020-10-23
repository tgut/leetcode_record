#include "iostream"
using namespace std;
int main()
{
	void* pData = (void*)(0x004001);
    uint32_t hi = 0;
    // cout<<"&hi" << &hi<<endl;
    // &hi = (uint32_t*)0xa00bc000;
	cout <<"pData:"<< *(uint32_t*)pData<<endl;
    cout <<"hi:" <<hi<<endl;
	getchar();
    return 0;
}

/*指针学习https://blog.csdn.net/mhjcumt/article/details/7355127*/
//todo 给hi地址赋值。
