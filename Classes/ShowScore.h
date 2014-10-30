/*
单一场景结束后的分值显示界面
*/

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

using namespace CocosDenshion;


USING_NS_CC;

class ShowScore : public CCLayer
{

public:
	virtual bool init();

	static cocos2d::CCScene* scene();

	void menuCloseCallback(CCObject* pSender);

	CREATE_FUNC(ShowScore);
protected:
private:
	void getScore();
private:
	int score;
	int combo;
	int perfectNum;
	int greatNum;
	int missNum;
};

class ScoreLayer :
	public CCLayer
{
public:
public:
	 static CCScene * scene();
	bool init();
	CREATE_FUNC(ScoreLayer);

private:
	void menuCloseCallback(CCObject* pSender);
	//注册触摸事件，实现ccTouchBegan()方法
	 void registerWithTouchDispatcher();
	bool ccTouchBegan(CCTouch * touch,CCEvent * pevent);
	//在弹出的对话框上加俩个按钮，以下的函数是对应的按钮的处理事件
	void yesButton(CCObject * object);
	void noButton(CCObject * object);
	//设置对话框的title
	void setTitle();
	//设置对话框的文本内容
	void setContent();
	//m_size代表的是对话框背景的大小
	 CCSize m_size;
	 //对话框的背景精灵
	CCSprite * m_bgSprite;
};