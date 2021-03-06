/*
5键游戏场景
*/

#ifndef GAME5KEY_H_
#define GAME5KEY_H_
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "VisibleRect.h"
#include "SelectSong1.h"
USING_NS_CC;
class Game5Key: public cocos2d::CCLayer {
private:
	CCSize visibleSize;
	CCPoint origin;
	//音符出生宽度
	float perNoteX;
	float perNoteY;
	float perKeyW;
	float perNoteBottom_X;
	int speed;
	int keyValue;
protected:
	int mp3Seconds; //音乐播放时间
	int currentSeconds; //当前音乐播放时间
	float bornx;
	float borny;
	CCParticleSystem* m_emitter;
	CCDrawNode *draw1;
	CCDrawNode *draw2;
	CCDrawNode *draw3;
	CCDrawNode *draw4;
	CCDrawNode *draw5;

	CCSprite* bottomButton0_1;
	CCSprite* bottomButton0_2;
	CCSprite* bottomButton0_3;
	CCSprite* bottomButton0_4;
	CCSprite* bottomButton0_5;
	CCSprite* bottomButton1_1;
	CCSprite* bottomButton1_2;
	CCSprite* bottomButton1_3;
	CCSprite* bottomButton1_4;
	CCSprite* bottomButton1_5;

public:
	float musicTime; //mp3音乐总时长

	CCPoint star1[4];
	CCPoint star2[4];
	CCPoint star3[4];
	CCPoint star4[4];
	CCPoint star5[4];
	int bornKey;
	//最大连击
	int maxCombo;
	//当前连击
	int curCombo;
	//生命血条
	int HP;
	int lastHP;
	//得分
	int score;
	//五键模式下音符出生坐标
	CCPoint bornNotePos1;
	CCPoint bornNotePos2;
	CCPoint bornNotePos3;
	CCPoint bornNotePos4;
	CCPoint bornNotePos5;
	CCProgressTimer *hpProgress;
	//五个按键的监听范围
	CCRect key1Rect;
	CCRect key2Rect;
	CCRect key3Rect;
	CCRect key4Rect;
	CCRect key5Rect;
	//大小perfect,great的监听范围
	CCRect perfectRect;
	CCRect bPerfectRect;
	CCRect greatRect;
	int perfectNum; //perfect击中数量
	int greatNum; //great击中数量
	int missNum; //miss数量
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	//显示连击数
	void showCombo(int id);
	void clearCurComb(CCNode *pLable);
	int checkScore(CCNode *pNode);
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCallback(CCObject* pSender);CREATE_FUNC(Game5Key);
	//出生产生
	void born(float dt);
	void remove(CCNode *pSender);
	void zOrderSprite(CCSprite* sprite1, CCSprite* sprite2);
	int containsTouchLocation(CCTouch* touch);
	//触摸的实现
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

	void clearZero(float dt);
	void finishGame(float dt);

	void resumeGame(cocos2d::CCNode *pNode);
};

#endif /* GAME5KEY_H_ */