/*
�����ļ�����ȡ��д��Ĳ���
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
��������
1����
2���ơ�
3���ơ�
4�̳���
5������
6�󳤰�
|
|
����
	|
	|
7�ҳ���
8
9
0
*/
typedef struct SongInfo{
	string	songName;//����
	int	musicTime;//mp3������ʱ��
	int		mp3Seconds; //���ֲ���ʱ��
	string	background;//����ͼ
	string	key4Value;//4��������������λ��
	string	key5Value;//5��������������λ��
	string	key6Value;//6��������������λ��
	string	born4KeyType;//4����������
	string	born5KeyType;//5����������
	string	born6KeyType;//6����������
}S_Info;


typedef struct GameInfo{
	string	userName;
	int		key;//��ֵ
	string	songName;//������
	string	level;//�Ѷ�
	int		score;//��ֵ
	int		maxCombo;
	int		perfectNum;
	int		greatNum;
	int		missNum;
	int		scoreLevel;//�÷ֵĵȼ���sss��ss�ȵ�
}G_Info;
typedef map<string,S_Info> ssMap;
typedef vector<string>		sVec;
int WriteXmlFile(G_Info g_info);
int ReadXmlFile(G_Info* g_info);
int WriteXmlFile(S_Info s_info);

class SongSingleton 
{
public:
	static SongSingleton* getInstance();//����һ��ȫ�ַ��ʵ㣬�������ǳ��õ�Director::getInstance()��������һ������
	int ReadXmlFile();//���Ե���ʱ�õ���
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
