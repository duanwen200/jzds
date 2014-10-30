#include "GBKToUTF8.h"

//���º����Ǵ�����copy�ģ�����һ�¿��Խ������
int GBKToUTF8(std::string & gbkStr, const char* fromCode, const char* toCode)
{
	iconv_t iconvH;
	//����������õ������ǽ�formCode�ı���ת����toCode�ı��룬����һ����õ�ʱ����GB2312 UTF-8
	//��Ϊϵͳ�ֵı���֧���еĲ�֧�����Ծ��п��ܷ���0
	iconvH = iconv_open(toCode,fromCode);

	//�������ֵΪ0��������ת��
	if (iconvH == 0)
	{
		return -1;
	}

	//��string����ת��Ϊchar *����
	const char* strChar = gbkStr.c_str();
	//�����ǻ�����˵��
	const char** pin = &strChar;
	size_t strLength = gbkStr.length();
	char* outbuf = (char*) malloc(strLength*4);
	char* pBuff = outbuf;

	//����GB2312��UTF-8��λ����1:4�����ף�֪������˵һ��
	memset(outbuf, 0, strLength*4);
	size_t outLength = strLength*4;

	//�ڶ���������ʾת��ǰ�ַ��ĵ�ַ���Ժ�Ĳ����ֱ���ת��ǰ�ַ��ĳ��ȣ�ת����Ĵ洢��ַ��ת����ĳ���
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
