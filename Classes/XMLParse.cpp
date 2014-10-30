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

		CCLog("��ʹ��utf-8��ʽ!");

		return false;

	}

	_par.setDelegator(this);

	//��ȡ�ļ����������·��

	//const char* _path =CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(xmlName);
	std::string _path =CCFileUtils::sharedFileUtils()->getWritablePath() + xmlName;
	return _par.parse(_path.c_str());



}



//��ʼ����ʱ�ص�

void HXmlParse::startElement(void *ctx, const char *name, const char **atts)


{

	CC_UNUSED_PARAM(ctx);



	startXmlElement = (char*)name;

	if(!isJumpHeadData){//��������ͷ

		CCLog("------����root name");

		isJumpHeadData=true;

		root_name=startXmlElement;

		return;

	}

}

//���������ص�

void HXmlParse::endElement(void *ctx, const char *name)


{

	CC_UNUSED_PARAM(ctx);



	endXmlElement = (char*)name;

	if(endXmlElement==root_name){//����β

		CCLog("��ȡxml����");

		isJumpHeadData=false;

		root_name="";

		return;

	}

}

//��ֵ�ԵĽ����ֶ�

void HXmlParse::textHandler(void *ctx, const char *ch, int len)

{



	CC_UNUSED_PARAM(ctx);

	currString=string((char*)ch,0,len);

	if(root_name!=""){

		allData.push_back(currString);

	}



}


//���������ͷ��ڴ�

HXmlParse::~HXmlParse()

{

	for (int i=0; i<allData.size(); i++) {

		allData[i].clear();

	}

	allData.clear();

}