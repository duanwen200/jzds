#ifndef _GBKTOUTF8_H_
#define _GBKTOUTF8_H_
#include "cocos2d.h"
//�����ͷ�ļ���iconv����һ���ַ�ת���Ŀ�Դ�Ŀ⣬cocos2dx֧�ֵı�����UTF-8��
//��win32��ʹ�õı�����GB2312������Ҫת��һ�£�������ʾ����
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "platform\third_party\win32\iconv\iconv.h"
#else
#include "../../libiconv/include/iconv.h"
#endif
//#include "../../../../libiconv/include/iconv.h"

//��ס����������libiconv.lib����ʹ�����µĴ���
//#pragma comment(lib, "libiconv.lib")

//����һ������û�з�װ����
int GBKToUTF8(std::string & gbkStr, const char* toCode, const char* fromCode);

#endif
