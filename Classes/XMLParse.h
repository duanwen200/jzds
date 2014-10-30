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

	vector< string> allData;//用于记录所有数据



	//  使用 CCSAXDelegator 重写3个回调函数

	//开始解析时回调

	void startElement(void *ctx, const char *name, const char **atts);

	//结束解析回调

	void endElement(void *ctx, const char *name);

	//键值对的结束字段

	void textHandler(void *ctx, const char *ch, int len);



private:



	string startXmlElement;//用来记录每个key前字段



	string endXmlElement;//用来记录每个key后字段



	string currString;//记录每个value的值

};
#endif //__XML_PARSER_H__