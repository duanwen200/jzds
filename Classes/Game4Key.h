/*
 * Game4Key.h
 *
 *  Created on: 2013-9-11
 *      Author: song
 */

#ifndef GAME4KEY_H_
#define GAME4KEY_H_
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "VisibleRect.h"
#include "SelectSong1.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
class Game4Key: public cocos2d::CCLayer {
private:
	CCSize visibleSize;
	CCPoint origin;
	//�����������
	float perNoteX;
	float perNoteY;
	float perKeyW;
	float perNoteBottom_X;
	int speed;
protected:
	int mp3Seconds; //���ֲ���ʱ��
	int currentSeconds; //��ǰ���ֲ���ʱ��
	float bornx;
	float borny;
	CCParticleSystem* m_emitter;
	CCDrawNode *draw1;
	CCDrawNode *draw2;
	CCDrawNode *draw3;
	CCDrawNode *draw4;

	CCSprite* bottomButton0_1;
	CCSprite* bottomButton0_2;
	CCSprite* bottomButton0_3;
	CCSprite* bottomButton0_4;
	CCSprite* bottomButton1_1;
	CCSprite* bottomButton1_2;
	CCSprite* bottomButton1_3;
	CCSprite* bottomButton1_4;

	int keyValue;
public:
	float musicTime; //mp3������ʱ��

	CCPoint star1[4];
	CCPoint star2[4];
	CCPoint star3[4];
	CCPoint star4[4];
	int bornKey;
	//�������
	int maxCombo;
	//��ǰ����
	int curCombo;
	//����Ѫ��
	int HP;
	int lastHP;
	//�÷�
	int score;
	//�ļ�ģʽ��������������
	CCPoint bornNotePos1;
	CCPoint bornNotePos2;
	CCPoint bornNotePos3;
	CCPoint bornNotePos4;
	CCProgressTimer *hpProgress;
	//�ĸ������ļ�����Χ
	CCRect key1Rect;
	CCRect key2Rect;
	CCRect key3Rect;
	CCRect key4Rect;
	//��Сperfect,great�ļ�����Χ
	CCRect perfectRect;
	CCRect bPerfectRect;
	CCRect greatRect;
	int perfectNum; //perfect��������
	int greatNum; //great��������
	int missNum; //miss����
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	//��ʾ������
	void showCombo(int id);
	void clearCurComb(CCNode *pLable);
	int checkScore(CCNode *pNode);
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCallback(CCObject* pSender);CREATE_FUNC(Game4Key);
	//��������
	void born(float dt);
	void remove(CCNode *pSender);
	void zOrderSprite(CCSprite* sprite1, CCSprite* sprite2);
	int containsTouchLocation(CCTouch* touch);
	//������ʵ��
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

	void clearZero(float dt);
	void finishGame(float dt);
	void resumeGame(cocos2d::CCNode *pNode);
	void showArmature(const char* armatureName);
	

	void delCallBack(CCArmature *pArmature, MovementEventType eventType, const char *animationID);
};

#endif /* GAME4KEY_H_ */
