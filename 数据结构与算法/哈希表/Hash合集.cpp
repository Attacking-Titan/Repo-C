#include<stdio.h>

/// @brief BKDR Hash Function
/// @detail ���㷨������Brian Kernighan��Dennis Ritchie�ġ�The C Programming Language��һ�鱻չʾ����������һ�ּ򵥿�ݵ�hash�㷨��Ҳ��JavaĿǰ���õ��ַ�����Hash�㷨���۳�����Ϊ31����
template<class T>
unsigned int HashBKDR(const T *str)
{
	register unsigned int hash = 0;
	while (unsigned int ch = (unsigned int)*str++)
	{
		hash = hash * 131 + ch;   // Ҳ���Գ���31��131��1313��13131��131313..
		// ����˵���˷��ֽ�Ϊλ���㼰�Ӽ����������Ч�ʣ��罫��ʽ���Ϊ��hash = hash << 7 + hash << 1 + hash + ch;
		// ����ʵ��Intelƽ̨�ϣ�CPU�ڲ��Զ��ߵĴ���Ч�ʶ��ǲ��ģ�
		// �ҷֱ������100�ڴε������������㣬���ֶ���ʱ�������Ϊ0�������Debug�棬�ֽ��λ�����ĺ�ʱ��Ҫ��1/3����
		// ��ARM����RISCϵͳ��û�в��Թ�������ARM�ڲ�ʹ��Booth's Algorithm��ģ��32λ�����˷����㣬����Ч��������йأ�
		// ������8-31λ��Ϊ1��0ʱ����Ҫ1��ʱ������
		// ������16-31λ��Ϊ1��0ʱ����Ҫ2��ʱ������
		// ������24-31λ��Ϊ1��0ʱ����Ҫ3��ʱ������
		// ������Ҫ4��ʱ������
		// ��ˣ���Ȼ��û��ʵ�ʲ��ԣ���������Ȼ��Ϊ����Ч���ϲ�𲻴�
	}
	return hash;
}


/// @brief SDBM Hash Function
/// @detail ���㷨�������ڿ�Դ��ĿSDBM��һ�ּ򵥵����ݿ����棩�б�Ӧ�ö�����������BKDRHash˼��һ�£�ֻ�����Ӳ�ͬ���ѡ�
template<class T>
unsigned int HashSDBM(const T *str)
{
	register unsigned int hash = 0;
	while (unsigned int ch = (unsigned int)*str++)
	{
		hash = 65599 * hash + ch;
		//hash = (unsigned int)ch + (hash << 6) + (hash << 16) - hash;
	}
	return hash;
}
/// @brief RS Hash Function
/// @detail ��Robert Sedgwicks���䡶Algorithms in C��һ����չʾ��������
template<class T>
unsigned int HashRS(const T *str)
{
	register unsigned int hash = 0;
	unsigned int magic = 63689;
	while (unsigned int ch = (unsigned int)*str++)
	{
		hash = hash * magic + ch;
		magic *= 378551;
	}
	return hash;
}
/// @brief AP Hash Function
/// @detail ��Arash Partow������һ��hash�㷨��
template<class T>
unsigned int HashAP(const T *str)
{
	register unsigned int hash = 0;
	unsigned int ch;
	for (long i = 0; ch = (unsigned int)*str++; i++)
	{
		if ((i & 1) == 0)
		{
			hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
		}
		else
		{
			hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
		}
	}
	return hash;
}
/// @brief JS Hash Function
/// ��Justin Sobel������һ��hash�㷨��
template<class T>
unsigned int HashJS(const T *str)
{
	if(!*str)		 // �����ɱ�����ӣ��Ա�֤���ַ������ع�ϣֵ0
		return 0;
	register unsigned int hash = 1315423911;
	while (unsigned int ch = (unsigned int)*str++)
	{
		hash ^= ((hash << 5) + ch + (hash >> 2));
	}
	return hash;
}
/// @brief DEK Function
/// @detail ���㷨������Donald E. Knuth�ڡ�Art Of Computer Programming Volume 3����չʾ��������
template<class T>
unsigned int HashDEK(const T* str)
{
	if(!*str)		 // �����ɱ�����ӣ��Ա�֤���ַ������ع�ϣֵ0
		return 0;
	register unsigned int hash = 1315423911;
	while (unsigned int ch = (unsigned int)*str++)
	{
		hash = ((hash << 5) ^ (hash >> 27)) ^ ch;
	}
	return hash;
}
/// @brief FNV Hash Function
/// @detail Unix systemϵͳ��ʹ�õ�һ������hash�㷨������΢��Ҳ����hash_map��ʵ�֡�
template<class T>
unsigned int HashFNV(const T* str)
{
	if(!*str)	// �����ɱ�����ӣ��Ա�֤���ַ������ع�ϣֵ0
		return 0;
	register unsigned int hash = 2166136261;
	while (unsigned int ch = (unsigned int)*str++)
	{
		hash *= 16777619;
		hash ^= ch;
	}
	return hash;
}
/// @brief DJB Hash Function
/// @detail ��Daniel J. Bernstein���ڷ�����һ��hash�㷨��
template<class T>
unsigned int HashDJB(const T *str)
{
	if(!*str)	// �����ɱ�����ӣ��Ա�֤���ַ������ع�ϣֵ0
		return 0;
	register unsigned int hash = 5381;
	while (unsigned int ch = (unsigned int)*str++)
	{
		hash += (hash << 5) + ch;
	}
	return hash;
}
/// @brief DJB Hash Function 2
/// @detail ��Daniel J. Bernstein ��������һ��hash�㷨��
template<class T>
unsigned int HashDJB2(const T *str)
{
	if(!*str)	// �����ɱ�����ӣ��Ա�֤���ַ������ع�ϣֵ0
		return 0;
	register unsigned int hash = 5381;
	while (unsigned int ch = (unsigned int)*str++)
	{
		hash = hash * 33 ^ ch;
	}
	return hash;
}
/// @brief PJW Hash Function
/// @detail ���㷨�ǻ���AT&T����ʵ���ҵ�Peter J. Weinberger�����Ķ�������һ��hash�㷨��
template<class T>
unsigned int HashPJW(const T *str)
{
	static const unsigned int TotalBits		= sizeof(unsigned int) * 8;
	static const unsigned int ThreeQuarters	= (TotalBits  * 3) / 4;
	static const unsigned int OneEighth		= TotalBits / 8;
	static const unsigned int HighBits		= ((unsigned int)-1) << (TotalBits - OneEighth);

	register unsigned int hash = 0;
	unsigned int magic = 0;
	while (unsigned int ch = (unsigned int)*str++)
	{
		hash = (hash << OneEighth) + ch;
		if ((magic = hash & HighBits) != 0)
		{
			hash = ((hash ^ (magic >> ThreeQuarters)) & (~HighBits));
		}
	}
	return hash;
}
/// @brief ELF Hash Function
/// @detail ������Unix��Extended Library Function��������������һ��hash�㷨������ʵ����PJW Hash�ı��Ρ�
template<class T>
unsigned int HashELF(const T *str)
{
	static const unsigned int TotalBits		= sizeof(unsigned int) * 8;
	static const unsigned int ThreeQuarters	= (TotalBits  * 3) / 4;
	static const unsigned int OneEighth		= TotalBits / 8;
	static const unsigned int HighBits		= ((unsigned int)-1) << (TotalBits - OneEighth);
	register unsigned int hash = 0;
	unsigned int magic = 0;
	while (unsigned int ch = (unsigned int)*str++)
	{
		hash = (hash << OneEighth) + ch;
		if ((magic = hash & HighBits) != 0)
		{
			hash ^= (magic >> ThreeQuarters);
			hash &= ~magic;
		}
	}
	return hash;
}

int main(){
	return 0;
}
