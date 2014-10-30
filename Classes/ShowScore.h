/*
��һ����������ķ�ֵ��ʾ����
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
	//ע�ᴥ���¼���ʵ��ccTouchBegan()����
	 void registerWithTouchDispatcher();
	bool ccTouchBegan(CCTouch * touch,CCEvent * pevent);
	//�ڵ����ĶԻ����ϼ�������ť�����µĺ����Ƕ�Ӧ�İ�ť�Ĵ����¼�
	void yesButton(CCObject * object);
	void noButton(CCObject * object);
	//���öԻ����title
	void setTitle();
	//���öԻ�����ı�����
	void setContent();
	//m_size������ǶԻ��򱳾��Ĵ�С
	 CCSize m_size;
	 //�Ի���ı�������
	CCSprite * m_bgSprite;
};