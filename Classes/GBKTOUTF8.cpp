#include "GBKToUTF8.h"

//以下函数是从网上copy的，试了一下可以解决问题
int GBKToUTF8(std::string & gbkStr, const char* fromCode, const char* toCode)
{
	iconv_t iconvH;
	//这个函数调用的作用是将formCode的编码转换成toCode的编码，我们一般调用的时候是GB2312 UTF-8
	//因为系统又的编码支持有的不支持所以就有可能返回0
	iconvH = iconv_open(toCode,fromCode);

	//如果返回值为0代表不可以转化
	if (iconvH == 0)
	{
		return -1;
	}

	//将string类型转化为char *类型
	const char* strChar = gbkStr.c_str();
	//以下是基础不说了
	const char** pin = &strChar;
	size_t strLength = gbkStr.length();
	char* outbuf = (char*) malloc(strLength*4);
	char* pBuff = outbuf;

	//这里GB2312和UTF-8的位数是1:4不明白，知道的人说一下
	memset(outbuf, 0, strLength*4);
	size_t outLength = strLength*4;

	//第二个参数表示转化前字符的地址，以后的参数分别是转化前字符的长度，转化后的存储地址，转化后的长度
	if (-1 == iconv(iconvH, pin, &strLength, &outbuf, &outLength))
	{
		free(pBuff);
		iconv_close(iconvH);
		return -1;
	}

	gbkStr = pBuff;
	iconv_close(iconvH);

	return 0;
}
