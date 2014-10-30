#ifndef __SELECT_SONG_1_H__
#define __SELECT_SONG_1_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;


class SelectSongScene : public cocos2d::CCLayer,public cocos2d::extension::CCTableViewDataSource, public cocos2d::extension::CCTableViewDelegate
{
public:
	virtual bool init();  
	static cocos2d::CCScene* scene();
	CREATE_FUNC(SelectSongScene);


	virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view) {};
	virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view) {};
	virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);
	virtual cocos2d::CCSize tableCellSizeForIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
	virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
	virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);
	//����ȥ��ʱ�򣬾��Ǹ�����ʾ������������ø���״̬  
	//virtual void tableCellHighlight(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);  
	//�ɿ���ʱ��ȡ������״̬  
	//virtual void tableCellUnhighlight(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell);  

	void startGame(CCObject* pSender);


	void menuCloseCallback(CCObject* pSender);
protected:
private:
	int cellNum;
};
#endif