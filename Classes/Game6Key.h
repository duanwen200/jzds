/*
5����Ϸ����
*/

#ifndef GAME6KEY_H_
#define GAME6KEY_H_
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "VisibleRect.h"
#include "SelectSong1.h"
USING_NS_CC;
class Game6Key: public cocos2d::CCLayer {
private:
	CCSize visibleSize;
	CCPoint origin;
	//�����������
	float perNoteX;
	float perNoteY;
	float perKeyW;
	float perNoteBottom_X;
	int speed;
	int keyValue;
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
	CCDrawNode *draw5;
	CCDrawNode *draw6;

	CCSprite* bottomButton0_1;
	CCSprite* bottomButton0_2;
	CCSprite* bottomButton0_3;
	CCSprite* bottomButton0_4;
	CCSprite* bottomButton0_5;
	CCSprite* bottomButton0_6;
	CCSprite* bottomButton1_1;
	CCSprite* bottomButton1_2;
	CCSprite* bottomButton1_3;
	CCSprite* bottomButton1_4;
	CCSprite* bottomButton1_5;
	CCSprite* bottomButton1_6;

public:
	float musicTime; //mp3������ʱ��

	CCPoint star1[4];
	CCPoint star2[4];
	CCPoint star3[4];
	CCPoint star4[4];
	CCPoint star5[4];
	CCPoint star6[4];
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
	//���ģʽ��������������
	CCPoint bornNotePos1;
	CCPoint bornNotePos2;
	CCPoint bornNotePos3;
	CCPoint bornNotePos4;
	CCPoint bornNotePos5;
	CCPoint bornNotePos6;
	CCProgressTimer *hpProgress;
	//��������ļ�����Χ
	CCRect key1Rect;
	CCRect key2Rect;
	CCRect key3Rect;
	CCRect key4Rect;
	CCRect key5Rect;
	CCRect key6Rect;
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
	void menuCallback(CCObject* pSender);CREATE_FUNC(Game6Key);
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
};

#endif /* GAME5KEY_H_ */