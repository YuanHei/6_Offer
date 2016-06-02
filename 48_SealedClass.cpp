//用C++设计不能被继承的类
#include <iostream>
using namespace std;

//方法一：将构造函数设为私有函数
//定义共有的静态函数创建和释放类的实例
class SealedClass1
{
public:
	static SealedClass1 * GetInstance()
	{
		return new SealedClass1();
	}

	static void DeleteInstance(SealedClass1 * pInstance)
	{
		delete pInstance;
	}

private:
	SealedClass1()
	{}
	~SealedClass1()
	{}
};

//方法二：利用虚拟继承

template<typename T>class MakeSealed
{
	friend T;
private:
	MakeSealed();
	~MakeSealed();
};

//GCC 中不支持模板参数类型作为友元类型
class SealedClass2 :virtual public MakeSealed<SealedClass2>
{
public:
	SealedClass2()
	{}
	~SealedClass2()
	{}
};

class Try1 :public SealedClass1
{
public:
	Try1()
	{}
	~Try1()
	{}
};

class Try2 :public SealedClass2
{
public:
	Try2()
	{}
	~Try2()
	{}
};

int main()
{
	return 0;
}
