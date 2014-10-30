#ifndef __MAIN_GAME_H__
#define __MAIN_GAME_H__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class MainGaneScene : public cocos2d::CCLayer,public cocos2d::extension::CCTableViewDataSource, public cocos2d::extension::CCTableViewDelegate
{
public:


	virtual bool init();  
	static cocos2d::CCScene* scene();
	CREATE_FUNC(MainGaneScene);


	virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view) {};
	virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view) {};
	virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
	virtual cocos2d::CCSize tableCellSizeForIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
	virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
	virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);
	//按下去的时候，就是高亮显示，这里可以设置高亮状态  
	//virtual void tableCellHighlight(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);  
	//松开的时候，取消高亮状态  
	//virtual void tableCellUnhighlight(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);  

	void moretype(CCObject* pSender);
	void rank(CCObject* pSender);
	void addPhysical(CCObject* pSender);
	void tableSelectCall0(CCObject* pSender);
	void tableSelectCall1(CCObject* pSender);
	void setting(CCObject* pSender);
	void invite(CCObject* pSender);
	void bill(CCObject* pSender);
	void quest(CCObject* pSender);
	void race(CCObject* pSender);
	void buttonCallback(cocos2d::CCNode *pNode);

protected:
private:
		
	CCLabelTTF* username;
	CCLabelTTF* Physical;
	CCLabelTTF* gold;
	CCLabelTTF* Diamond;
	CCLabelTTF* level;


	int cellNum;
	int tableSelect;

};
#endif