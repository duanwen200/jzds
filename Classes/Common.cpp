#include "Common.h"
#include "HelloWorldScene.h"
/*

typedef struct GameInfo{
int		key;//键值
string	songName;//歌曲名
string	level;//难度
int		score;//分值
int		maxCombo;
int		perfectNum;
int		greatNum;
int		missNum;
int		scoreLevel;//得分的等级，sss，ss
}G_Info;
*/
SongSingleton* SongSingleton::m_singleton = nullptr;//m_singleton指向空指针
int SongSingleton::WriteXmlFileG()
{
	std::string fileName = "testSong.xml";
	std::string filePath = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName.c_str());

	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();

	//xml 声明（参数可选）
	//XMLDeclaration *pDel = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");

	//pDoc->LinkEndChild(pDel);

	//添加gameversion节点
	XMLElement *gVersionElement = pDoc->NewElement("Game_Version");
	gVersionElement->SetAttribute("version", "1.0");
	pDoc->LinkEndChild(gVersionElement);

	//XMLComment *commentElement = pDoc->NewComment("this is  songs information");
	//gVersionElement->LinkEndChild(commentElement);

	//添加set_up节点
	XMLElement *setupElement = pDoc->NewElement("set_up");
	gVersionElement->LinkEndChild(setupElement);
	char string[12] = {0};


	//添加songname节点
	XMLElement *userNameElement = pDoc->NewElement("userName");
	userNameElement->LinkEndChild(pDoc->NewText(g_info->userName.c_str()));
	setupElement->LinkEndChild(userNameElement);
	//添加key节点
	XMLElement *keyElement = pDoc->NewElement("key");
	sprintf(string,"%d",g_info->key);
	keyElement->LinkEndChild(pDoc->NewText(string));
	setupElement->LinkEndChild(keyElement);
	//添加songname节点
	XMLElement *songNameElement = pDoc->NewElement("songName");
	songNameElement->LinkEndChild(pDoc->NewText(g_info->songName.c_str()));
	setupElement->LinkEndChild(songNameElement);
	//添加level节点
	XMLElement *levelElement = pDoc->NewElement("level");
	levelElement->LinkEndChild(pDoc->NewText(g_info->level.c_str()));
	setupElement->LinkEndChild(levelElement);
	//添加score节点
	XMLElement *scoreElement = pDoc->NewElement("score");
	memset(string,0,sizeof(string));
	sprintf(string,"%d",g_info->score);
	scoreElement->LinkEndChild(pDoc->NewText(string));
	setupElement->LinkEndChild(scoreElement);

	//添加maxCombo节点
	XMLElement *maxComboElement = pDoc->NewElement("maxCombo");
	memset(string,0,sizeof(string));
	sprintf(string,"%d",g_info->maxCombo);
	maxComboElement->LinkEndChild(pDoc->NewText(string));
	setupElement->LinkEndChild(maxComboElement);
	//添加perfectNum节点
	XMLElement *perfectNumElement = pDoc->NewElement("perfectNum");
	memset(string,0,sizeof(string));
	sprintf(string,"%d",g_info->perfectNum);
	perfectNumElement->LinkEndChild(pDoc->NewText(string));
	setupElement->LinkEndChild(perfectNumElement);
	//添加greatNum节点
	XMLElement *greatNumElement = pDoc->NewElement("greatNum");
	memset(string,0,sizeof(string));
	sprintf(string,"%d",g_info->greatNum);
	greatNumElement->LinkEndChild(pDoc->NewText(string));
	setupElement->LinkEndChild(greatNumElement);
	//添加missNum节点
	XMLElement *missNumElement = pDoc->NewElement("missNum");
	memset(string,0,sizeof(string));
	sprintf(string,"%d",g_info->missNum);
	missNumElement->LinkEndChild(pDoc->NewText(string));
	setupElement->LinkEndChild(missNumElement);
	//添加scoreLevel节点
	XMLElement *scoreLevelElement = pDoc->NewElement("scoreLevel");
	memset(string,0,sizeof(string));
	sprintf(string,"%d",g_info->scoreLevel);
	scoreLevelElement->LinkEndChild(pDoc->NewText(string));
	setupElement->LinkEndChild(scoreLevelElement);

	//delete string;

	pDoc->SaveFile(filePath.c_str());
	pDoc->Print();

	delete pDoc;
	return 0;
}
/*

typedef struct GameInfo{
int		key;//键值
string	songName;//歌曲名
string	level;//难度
int		score;//分值
int		maxCombo;
int		perfectNum;
int		greatNum;
int		missNum;
int		scoreLevel;//得分的等级，sss，ss等等
}G_Info;
*/
int SongSingleton::ReadXmlFileG()
{
	std::string fileName = "testSong.xml";
	//std::string filePath  = CCFileUtils::sharedFileUtils()->getWritablePath() + fileName;
	std::string filePath = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName.c_str());
	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
	XMLError errorId = pDoc->LoadFile(filePath.c_str());

	if (errorId != 0) {
		//xml格式错误
		return errorId;
	}

	XMLElement *rootEle = pDoc->RootElement();

	//获取第一个节点属性
	const XMLAttribute *attribute = rootEle->FirstAttribute();
	//打印节点属性名和值
	//log("attribute_name = %s,attribute_value = %s", attribute->Name(), attribute->Value());

	XMLElement *dicEle = rootEle->FirstChildElement("set_up");
	XMLElement *keyEle = dicEle->FirstChildElement("userName");
	g_info->userName = keyEle->GetText();
	keyEle = keyEle->NextSiblingElement("key");
	g_info->key = atoi(keyEle->GetText());
	keyEle = keyEle->NextSiblingElement("songName");
	g_info->songName = keyEle->GetText();
	keyEle = keyEle->NextSiblingElement("level");
	g_info->songName = keyEle->GetText();
	keyEle = keyEle->NextSiblingElement("score");
	g_info->score = atoi(keyEle->GetText());

	keyEle = keyEle->NextSiblingElement("maxCombo");
	g_info->maxCombo = atoi(keyEle->GetText());
	keyEle = keyEle->NextSiblingElement("perfectNum");
	g_info->perfectNum = atoi(keyEle->GetText());
	keyEle = keyEle->NextSiblingElement("greatNum");
	g_info->greatNum = atoi(keyEle->GetText());
	keyEle = keyEle->NextSiblingElement("missNum");
	g_info->missNum = atoi(keyEle->GetText());
	keyEle = keyEle->NextSiblingElement("scoreLevel");
	g_info->scoreLevel = atoi(keyEle->GetText());
	delete pDoc;
	return 0;
}
/*


typedef struct SongInfo{
string	songName;//名字
float	musicTime;//mp3音乐总时长
int		mp3Seconds; //音乐播放时间
string	background;//背景图
string	key4Value;//4键的音符的生产位置
string	key5Value;//5键的音符的生产位置
string	key6Value;//6键的音符的生产位置
string	born4KeyType;//4音符的类型
string	born5KeyType;//5音符的类型
string	born6KeyType;//6音符的类型
}S_Info;
*/


SongSingleton* SongSingleton::getInstance()
{
	//判断m_singleton是否已被实例化， 如果没有，将之实例
	if(nullptr == m_singleton)
	{
		m_singleton = new SongSingleton();//
	}
	return m_singleton;
}

//void TestSingleton::test()
//{
//	CCLOG("test testSingleton success~~");
//}
int SongSingleton::ReadXmlFile()
{
	ssmap = new ssMap;
	g_info = new G_Info;
	std::string fileName = "testSongInfo.xml";
	//std::string filePath  = CCFileUtils::sharedFileUtils()->getWritablePath() + fileName;
	std::string filePath = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName.c_str());
	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
	XMLError errorId = pDoc->LoadFile(filePath.c_str());

	if (errorId != 0) {
		//xml格式错误
		return errorId;
	}

	XMLElement *rootEle = pDoc->RootElement();

	//获取第一个节点属性
	const XMLAttribute *attribute = rootEle->FirstAttribute();
	//打印节点属性名和值
	//log("attribute_name = %s,attribute_value = %s", attribute->Name(), attribute->Value());

	S_Info s_info;
	XMLElement *dicEle = rootEle->FirstChildElement("song");
	do 
	{
		XMLElement *keyEle = dicEle->FirstChildElement("songName");
		s_info.songName = keyEle->GetText();
		songNameVec.push_back(keyEle->GetText());
		keyEle = keyEle->NextSiblingElement("musicTime");
		s_info.musicTime = atoi(keyEle->GetText());
		keyEle = keyEle->NextSiblingElement("mp3Seconds");
		s_info.mp3Seconds = atoi(keyEle->GetText());
		keyEle= keyEle->NextSiblingElement("background");
		s_info.background = keyEle->GetText();
		keyEle= keyEle->NextSiblingElement("key4Value");
		s_info.key4Value = keyEle->GetText();
		keyEle= keyEle->NextSiblingElement("key5Value");
		s_info.key5Value = keyEle->GetText();
		keyEle= keyEle->NextSiblingElement("key6Value");
		s_info.key6Value = keyEle->GetText();
		keyEle= keyEle->NextSiblingElement("born4KeyType");
		s_info.born4KeyType = keyEle->GetText();
		keyEle= keyEle->NextSiblingElement("born5KeyType");
		s_info.born5KeyType = keyEle->GetText();
		keyEle= keyEle->NextSiblingElement("born6KeyType");
		s_info.born6KeyType = keyEle->GetText();

		//ssmap[s_info.songName] = s_info;
		ssmap->insert(map<string, S_Info>::value_type(s_info.songName,s_info));
	} while (dicEle = dicEle->NextSiblingElement("song"));

	/*
	keyEle = keyEle->NextSiblingElement("songName");
	g_info->songName = keyEle->GetText();
	keyEle = keyEle->NextSiblingElement("level");
	g_info->songName = keyEle->GetText();
	keyEle = keyEle->NextSiblingElement("score");
	g_info->score = atoi(keyEle->GetText());

	keyEle = keyEle->NextSiblingElement("maxCombo");
	g_info->maxCombo = atoi(keyEle->GetText());
	keyEle = keyEle->NextSiblingElement("perfectNum");
	g_info->perfectNum = atoi(keyEle->GetText());
	keyEle = keyEle->NextSiblingElement("greatNum");
	g_info->greatNum = atoi(keyEle->GetText());
	keyEle = keyEle->NextSiblingElement("missNum");
	g_info->missNum = atoi(keyEle->GetText());
	keyEle = keyEle->NextSiblingElement("scoreLevel");
	g_info->scoreLevel = atoi(keyEle->GetText());
	*/
	delete pDoc;
	return 0;
}

int WriteXmlFile(S_Info g_info)
{
	std::string fileName = "testSongInfo.xml";
	std::string filePath = CCFileUtils::sharedFileUtils()->getWritablePath() + fileName;

	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();

	//xml 声明（参数可选）
	//XMLDeclaration *pDel = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");

	//pDoc->LinkEndChild(pDel);

	//添加gameversion节点
	XMLElement *gVersionElement = pDoc->NewElement("Game_Version");
	gVersionElement->SetAttribute("version", "1.0");
	pDoc->LinkEndChild(gVersionElement);

	//XMLComment *commentElement = pDoc->NewComment("this is  songs information");
	//gVersionElement->LinkEndChild(commentElement);

	//添加set_up节点
	XMLElement *setupElement = pDoc->NewElement("song");
	gVersionElement->LinkEndChild(setupElement);
	char string[12] = {0};
	//添加songName节点
	XMLElement *songName = pDoc->NewElement("songName");
	//sprintf(string,"%d",g_info.songName);
	songName->LinkEndChild(pDoc->NewText(g_info.songName.c_str()));
	setupElement->LinkEndChild(songName);

	//添加musicTime节点
	XMLElement *musicTime = pDoc->NewElement("musicTime");
	sprintf(string,"%d",g_info.musicTime);
	musicTime->LinkEndChild(pDoc->NewText(string));
	setupElement->LinkEndChild(musicTime);
	//添加mp3Seconds节点
	XMLElement *mp3Seconds = pDoc->NewElement("mp3Seconds");
	memset(string,0,sizeof(string));
	sprintf(string,"%d",g_info.mp3Seconds);
	mp3Seconds->LinkEndChild(pDoc->NewText(string));
	setupElement->LinkEndChild(mp3Seconds);

	//添加background节点
	XMLElement *background = pDoc->NewElement("background");
	background->LinkEndChild(pDoc->NewText(g_info.background.c_str()));
	setupElement->LinkEndChild(background);

	XMLElement *key4Value = pDoc->NewElement("key4Value");
	key4Value->LinkEndChild(pDoc->NewText(g_info.key4Value.c_str()));
	setupElement->LinkEndChild(key4Value);

	XMLElement *key5Value = pDoc->NewElement("key5Value");
	key5Value->LinkEndChild(pDoc->NewText(g_info.key5Value.c_str()));
	setupElement->LinkEndChild(key5Value);

	XMLElement *key6Value = pDoc->NewElement("key6Value");
	key6Value->LinkEndChild(pDoc->NewText(g_info.key6Value.c_str()));
	setupElement->LinkEndChild(key6Value);

	XMLElement *born4KeyType = pDoc->NewElement("born4KeyType");
	born4KeyType->LinkEndChild(pDoc->NewText(g_info.born4KeyType.c_str()));
	setupElement->LinkEndChild(born4KeyType);

	XMLElement *born5KeyType = pDoc->NewElement("born5KeyType");
	born5KeyType->LinkEndChild(pDoc->NewText(g_info.born5KeyType.c_str()));
	setupElement->LinkEndChild(born5KeyType);

	XMLElement *born6KeyType = pDoc->NewElement("born6KeyType");
	born6KeyType->LinkEndChild(pDoc->NewText(g_info.born6KeyType.c_str()));
	setupElement->LinkEndChild(born6KeyType);

	//delete string;

	pDoc->SaveFile(filePath.c_str());
	pDoc->Print();

	delete pDoc;
	return 0;
}