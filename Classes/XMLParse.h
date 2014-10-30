#ifndef __XML_PARSER_H__
#define __XML_PARSER_H__

#include "cocos2d.h"
#include "platform/CCSAXParser.h"

#include "cocoa/CCObject.h"


using namespace cocos2d;

using namespace std;


class CC_DLL HXmlParse :public CCObject, public CCSAXDelegator

{



public:



	static HXmlParse * parserWithFile(const char *tmxFile);

	bool initHXmlParse(const char* xmlName);

	string root_name;

	bool isJumpHeadData;

	~HXmlParse();

	vector< string> allData;//���ڼ�¼��������



	//  ʹ�� CCSAXDelegator ��д3���ص�����

	//��ʼ����ʱ�ص�

	void startElement(void *ctx, const char *name, const char **atts);

	//���������ص�

	void endElement(void *ctx, const char *name);

	//��ֵ�ԵĽ����ֶ�

	void textHandler(void *ctx, const char *ch, int len);



private:



	string startXmlElement;//������¼ÿ��keyǰ�ֶ�



	string endXmlElement;//������¼ÿ��key���ֶ�



	string currString;//��¼ÿ��value��ֵ

};
#endif //__XML_PARSER_H__