#include "XMLParse.h"

#include "platform/CCSAXParser.h"


HXmlParse * HXmlParse::parserWithFile(const char *tmxFile)

{

	HXmlParse *pRet = new HXmlParse();

	if(pRet->initHXmlParse(tmxFile))

	{

		pRet->autorelease();

		return pRet;

	}

	CC_SAFE_DELETE(pRet);

	return NULL;

}


bool HXmlParse::initHXmlParse(const char* xmlName)


{    

	CCSAXParser _par;

	if (false == _par.init("UTF-8") )

	{

		CCLog("请使用utf-8格式!");

		return false;

	}

	_par.setDelegator(this);

	//获取文件的完整相对路径

	//const char* _path =CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(xmlName);
	std::string _path =CCFileUtils::sharedFileUtils()->getWritablePath() + xmlName;
	return _par.parse(_path.c_str());



}



//开始解析时回调

void HXmlParse::startElement(void *ctx, const char *name, const char **atts)


{

	CC_UNUSED_PARAM(ctx);



	startXmlElement = (char*)name;

	if(!isJumpHeadData){//跳过数据头

		CCLog("------跳过root name");

		isJumpHeadData=true;

		root_name=startXmlElement;

		return;

	}

}

//结束解析回调

void HXmlParse::endElement(void *ctx, const char *name)


{

	CC_UNUSED_PARAM(ctx);



	endXmlElement = (char*)name;

	if(endXmlElement==root_name){//数据尾

		CCLog("读取xml结束");

		isJumpHeadData=false;

		root_name="";

		return;

	}

}

//键值对的结束字段

void HXmlParse::textHandler(void *ctx, const char *ch, int len)

{



	CC_UNUSED_PARAM(ctx);

	currString=string((char*)ch,0,len);

	if(root_name!=""){

		allData.push_back(currString);

	}



}


//析构函数释放内存

HXmlParse::~HXmlParse()

{

	for (int i=0; i<allData.size(); i++) {

		allData[i].clear();

	}

	allData.clear();

}