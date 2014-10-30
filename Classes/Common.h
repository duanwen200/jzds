/*
帮助文件，读取，写入的操作
*/
#ifndef __COMMON_H__
#define __COMMON_H__
#include "cocos2d.h"
#include "support/tinyxml2/tinyxml2.h"
#include <string>
#include <map>


USING_NS_CC;
using namespace tinyxml2;
using namespace std;

/*
音符类型
1正常
2左移←
3右移→
4短长按
5长长按
6左长按
|
|
——
	|
	|
7右长按
8
9
0
*/
typedef struct SongInfo{
	string	songName;//名字
	int	musicTime;//mp3音乐总时长
	int		mp3Seconds; //音乐播放时间
	string	background;//背景图
	string	key4Value;//4键的音符的生产位置
	string	key5Value;//5键的音符的生产位置
	string	key6Value;//6键的音符的生产位置
	string	born4KeyType;//4音符的类型
	string	born5KeyType;//5音符的类型
	string	born6KeyType;//6音符的类型
}S_Info;


typedef struct GameInfo{
	string	userName;
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
typedef map<string,S_Info> ssMap;
typedef vector<string>		sVec;
int WriteXmlFile(G_Info g_info);
int ReadXmlFile(G_Info* g_info);
int WriteXmlFile(S_Info s_info);

class SongSingleton 
{
public:
	static SongSingleton* getInstance();//创建一个全局访问点，例如我们常用的Director::getInstance()就是这样一个单例
	int ReadXmlFile();//测试单例时用到。
	int WriteXmlFileG();
	int ReadXmlFileG();
	ssMap* ssmap;
	G_Info* g_info;
	sVec   songNameVec;
	int		billShow;
private:
	static SongSingleton* m_singleton;

};

#endif
