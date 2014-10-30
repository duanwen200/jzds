#ifndef __SLECET_SONG_H__
#define __SLECET_SONG_H__
/*
ѡ�����

*/

#include "cocos2d.h"
#include "support/tinyxml2/tinyxml2.h"
#include <vector>
#include <string>
#include "Game4Key.h"
#include "Game5Key.h"
#include "Game6Key.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace tinyxml2;
using namespace std;
class SlectSongTable:public cocos2d::CCLayer,cocos2d::extension::CCTableViewDelegate,cocos2d::extension::CCTableViewDataSource
{
public:
	virtual bool init();  

	// there's no 'id' in cpp, so we recommend to return the class instance pointer  
	static cocos2d::CCScene* scene();  

	// a selector callback  
	void menuCloseCallback(CCObject* pSender);  

	// preprocessor macro for "static create()" constructor ( node() deprecated )  
	CREATE_FUNC(SlectSongTable);  



public:  

	//CCTableViewDelegate�̳���CCScrollViewDelegate  
	virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view){};  

	virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view){};  

	//����ĸ�cell  
	virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);  
	//ÿ��cell��size  
	virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::CCTableView *table);  
	//����cell  
	virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);  
	//cell������  
	virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);  

	//����ȥ��ʱ�򣬾��Ǹ�����ʾ������������ø���״̬  
	virtual void tableCellHighlight(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);  

	//�ɿ���ʱ��ȡ������״̬  
	virtual void tableCellUnhighlight(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);  



	void scrollBar(cocos2d::extension::CCTableView* table);  


	void toStartGameLayer(CCObject* pSender);

protected:
private:
};


class SlecetSong :public cocos2d::CCLayer
{
public:
	SlecetSong();
	~SlecetSong();

	virtual bool init();

	static cocos2d::CCScene* scene();

	void menuCloseCallback(CCObject* pSender);

	void toStartGameLayer(CCObject* pSender);

	CREATE_FUNC(SlecetSong);
	void tempLayer(CCObject* pSender) ;

public:
	void parseXml(const char* xmlFile);
	vector<std::string> songsName;
	CCMenu* menu;

};
#endif // !__SLECET_SONG_H__
