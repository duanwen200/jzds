/*
 * Game6Key.cpp
 *
 *  Created on: 2013-9-11
 *      Author: song
 */

#include "Game6Key.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
#include <stdlib.h>
#include "cocos-ext.h"
#include "ShowScore.h"
#include "Common.h"
#include "PauseScene.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace CocosDenshion;
using namespace cocos2d::extension;
CCScene* Game6Key::scene() {
	CCScene *scene = CCScene::create();
	Game6Key *layer = Game6Key::create();
	scene->addChild(layer);
	return scene;
}

void Game6Key::clearZero(float dt)
{
	if (this->curCombo == 0)
	{
		CCLabelBMFont* curCombLable = (CCLabelBMFont*) getChildByTag(10);
		clearCurComb(curCombLable);
	}
}
bool Game6Key::init() {
	if (!CCLayer::init()) {
		return false;
	}
	setTouchEnabled(true);
	//获得视口(可视区域)的大小
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//可视区域的起点坐标，这在处理相对位置的时候非常有用，确保节点在不同分辨率下的位置一致。
	origin = CCDirector::sharedDirector()->getVisibleOrigin();
	this->mp3Seconds = 5;
	this->currentSeconds = 0;
	//音符出生坐标：等边直角三角形的顶点
	bornx = origin.x + visibleSize.width / 2;
	//高度等于二分之一根号三乘边长
	borny = origin.y + sqrtf(3) / 2 * (visibleSize.width);
	perKeyW = visibleSize.width / 6;
	perNoteBottom_X = perKeyW;
	//音符下落的速度
	speed = 1;
	this->HP = 100;
	this->lastHP = 100;
	this->score = 0;
	this->curCombo=0;
	this->maxCombo =0;
	this->keyValue =0;
	//perfect，great，miss值
	perfectNum =0;
	greatNum =0;
	missNum =0;
	//按键的位置,矩形框
	key1Rect =
			CCRectMake(origin.x,origin.y,origin.x+perKeyW,origin.y+visibleSize.height/2);
	key2Rect =
			CCRectMake(origin.x+perKeyW,origin.y,origin.x+perKeyW,origin.y+visibleSize.height/2);
	key3Rect =
			CCRectMake(origin.x+perKeyW*2,origin.y,origin.x+perKeyW,origin.y+visibleSize.height/2);
	key4Rect =
			CCRectMake(origin.x+perKeyW*3,origin.y,origin.x+perKeyW,origin.y+visibleSize.height/2);
	key5Rect =
		CCRectMake(origin.x+perKeyW*4,origin.y,origin.x+perKeyW,origin.y+visibleSize.height/2);
	key6Rect =
		CCRectMake(origin.x+perKeyW*5,origin.y,origin.x+perKeyW,origin.y+visibleSize.height/2);
//场景及返回按钮
	CCSprite* pSprite = CCSprite::create("song/andy/andy.png");
	//节奏大师按键场景
	CCSprite* panlGameSprite = CCSprite::createWithSpriteFrameName(
			"panl_game.png");
	CCSprite* panl6KSprite = CCSprite::createWithSpriteFrameName("panl_6k.png");
	CCSprite* top = CCSprite::createWithSpriteFrameName("top.png");
	//左右的两个边
	CCSprite* lSide = CCSprite::createWithSpriteFrameName("b_side.png");
	CCSprite* rSide = CCSprite::createWithSpriteFrameName("b_side.png");
	//按键中间的间隔
	CCSprite* sider_1 = CCSprite::createWithSpriteFrameName("b_sider.png");
	CCSprite* sider_2 = CCSprite::createWithSpriteFrameName("b_sider.png");
	CCSprite* sider_3 = CCSprite::createWithSpriteFrameName("b_sider.png");
	CCSprite* sider_4 = CCSprite::createWithSpriteFrameName("b_sider.png");
	CCSprite* sider_5 = CCSprite::createWithSpriteFrameName("b_sider.png");

	pSprite->setPosition(
			ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	this->addChild(pSprite, 0);
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create("CloseNormal.png",
			"CloseSelected.png", this, menu_selector(Game6Key::menuCallback));

	pCloseItem->setPosition(
			ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
					visibleSize.height - pCloseItem->getContentSize().height/2));

	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 10);
	top->setAnchorPoint(CCPointZero);

	top->setPosition(
			ccp(origin.x,origin.y+visibleSize.height-top->getContentSize().height));
	panl6KSprite->setAnchorPoint(CCPointMake(0.5,1));
	panlGameSprite->setAnchorPoint(CCPointMake(0.5,1));
	panlGameSprite->setPosition(
			ccp(origin.x+visibleSize.width/2,origin.y+visibleSize.height));
	this->addChild(panlGameSprite, 1);
	panl6KSprite->setPosition(
			ccp(origin.x+visibleSize.width/2,origin.y+visibleSize.height-panlGameSprite->getContentSize().height+1));
	this->addChild(panl6KSprite, 2);
	this->addChild(top, 5);

	//////////////////////////////////////////////////////////////////////////
	//顶点出生音符宽度；
	float bornPerx = panlGameSprite->getContentSize().width / 8 / 6;
	float tleftx = origin.x + visibleSize.width / 2 - 3 * bornPerx;
	float trightx = tleftx + 6 * bornPerx;
	//每个音符的初始位置
	bornNotePos1 = CCPointMake(tleftx,origin.y+visibleSize.height);
	bornNotePos2 = CCPointMake(tleftx+bornPerx,origin.y+visibleSize.height);
	bornNotePos3 = CCPointMake(tleftx+2*bornPerx,origin.y+visibleSize.height);
	bornNotePos4 = CCPointMake(tleftx+3*bornPerx,origin.y+visibleSize.height);
	bornNotePos5 = CCPointMake(tleftx+4*bornPerx,origin.y+visibleSize.height);
	bornNotePos6 = CCPointMake(trightx,origin.y+visibleSize.height);
	//内角度数,左右的边线的偏折角度
	float ndu = atan(
			(panl6KSprite->getContentSize().height / 3
					+ panlGameSprite->getContentSize().height)
					/ (panl6KSprite->getContentSize().width / 2 - 3 * bornPerx))
			* 180 / 3.14;
	lSide->setAnchorPoint(CCPointMake(1,0));
	lSide->setPosition(
			ccp(origin.x-2,origin.y+panl6KSprite->getContentSize().height/3*2));
	lSide->setRotation(90 - ndu +1);
	this->addChild(lSide, 4);
	rSide->setAnchorPoint(CCPointMake(0,0));
	rSide->setPosition(
			ccp(origin.x+visibleSize.width+2,origin.y+panl6KSprite->getContentSize().height/3*2));
	rSide->setRotation(-(90 - ndu+1));
	this->addChild(rSide, 4);
	//中间的间隔线的偏折
	float perns = (panlGameSprite->getContentSize().width
			- panl6KSprite->getContentSize().height / 3 * 2) / 6;//////////////底部///////////////////////////////////////////////////
	float nndu = atan(
			2*(perns - bornPerx) / panlGameSprite->getContentSize().height) * 180
			/ 3.14;
	float nndu1 = atan(
		((perns - bornPerx)) / panlGameSprite->getContentSize().height) * 180
		/ 3.14;
	sider_1->setAnchorPoint(CCPointMake(0.5,0));
	sider_2->setAnchorPoint(CCPointMake(0.5,0));
	sider_3->setAnchorPoint(CCPointMake(0.5,0));
	sider_4->setAnchorPoint(CCPointMake(0.5,0));
	sider_5->setAnchorPoint(CCPointMake(0.5,0));


	sider_3->setPosition(
		ccp(origin.x+visibleSize.width/2,origin.y+panl6KSprite->getContentSize().height));
	sider_1->setPosition(
			ccp(sider_3->getPosition().x-2*perns -3,sider_3->getPosition().y));
	sider_2->setPosition(
			ccp(sider_3->getPosition().x-perns -1,sider_3->getPosition().y));
	sider_4->setPosition(
		ccp(sider_3->getPosition().x+perns +2,sider_3->getPosition().y));
	sider_5->setPosition(
		ccp(sider_3->getPosition().x+2*perns +4.5,sider_3->getPosition().y));
	sider_1->setRotation(nndu);
	sider_2->setRotation(nndu1);
	//sider_3->setRotation(-nndu1);
	sider_4->setRotation(-nndu1);
	sider_5->setRotation(-nndu);
	this->addChild(sider_2, 4);
	this->addChild(sider_1, 4);
	this->addChild(sider_3, 4);
	this->addChild(sider_4, 4);
	this->addChild(sider_5, 4);
	//////////////////////////////////////////////////////////////////////////

	draw1 = CCDrawNode::create();
	draw2 = CCDrawNode::create();
	draw3 = CCDrawNode::create();
	draw4 = CCDrawNode::create();
	draw5 = CCDrawNode::create();
	draw6 = CCDrawNode::create();
	//todo
	addChild(draw1, 4);
	addChild(draw2, 4);
	addChild(draw3, 4);
	addChild(draw4, 4);
	addChild(draw5, 4);
	addChild(draw6, 4);

	star1[0] =
			ccp(origin.x+visibleSize.width/2-3*bornPerx - perKeyW/2,origin.y+visibleSize.height);
	star1[1] =
			ccp(origin.x+visibleSize.width/2-3*perns,origin.y+panl6KSprite->getContentSize().height);
	star1[2] =
			ccp(origin.x+visibleSize.width/2-2*perns-1,origin.y+panl6KSprite->getContentSize().height);
	star1[3] =
			ccp(origin.x+visibleSize.width/2-2*bornPerx-1,origin.y+visibleSize.height);

	star2[0] =
			ccp(origin.x+visibleSize.width/2-2*bornPerx+1,origin.y+visibleSize.height);
	star2[1] =
			ccp(origin.x+visibleSize.width/2-2*perns+2,origin.y+panl6KSprite->getContentSize().height);
	star2[2] =
			ccp(origin.x+visibleSize.width/2-2-perns,origin.y+panl6KSprite->getContentSize().height);
	star2[3] = 
			ccp(origin.x+visibleSize.width/2-1-bornPerx,origin.y+visibleSize.height);

	star3[0] = 
			ccp(origin.x+visibleSize.width/2+1-bornPerx,origin.y+visibleSize.height);
	star3[1] =
			ccp(origin.x+visibleSize.width/2+2-perns,origin.y+panl6KSprite->getContentSize().height);
	star3[2] =
			ccp(origin.x+visibleSize.width/2+0*perns-2,origin.y+panl6KSprite->getContentSize().height);
	star3[3] =
			ccp(origin.x+visibleSize.width/2+0*bornPerx-1,origin.y+visibleSize.height);

	star4[0] =
			ccp(origin.x+visibleSize.width/2+0*bornPerx+1,origin.y+visibleSize.height);
	star4[1] =
			ccp(origin.x+visibleSize.width/2+0*perns+3,origin.y+panl6KSprite->getContentSize().height);
	star4[2] =
			ccp(origin.x+visibleSize.width/2+perns,origin.y+panl6KSprite->getContentSize().height);
	star4[3] =
			ccp(origin.x+visibleSize.width/2+bornPerx,origin.y+visibleSize.height);


	star5[0] =
		ccp(origin.x+visibleSize.width/2+bornPerx+1,origin.y+visibleSize.height);
	star5[1] =
		ccp(origin.x+visibleSize.width/2+perns+3,origin.y+panl6KSprite->getContentSize().height);
	star5[2] =
		ccp(origin.x+visibleSize.width/2+2*perns,origin.y+panl6KSprite->getContentSize().height);
	star5[3] =
		ccp(origin.x+visibleSize.width/2+2*bornPerx,origin.y+visibleSize.height);


	star6[0] =
		ccp(origin.x+visibleSize.width/2+2*bornPerx+1,origin.y+visibleSize.height);
	star6[1] =
		ccp(origin.x+visibleSize.width/2+2*perns+3,origin.y+panl6KSprite->getContentSize().height);
	star6[2] =
		ccp(origin.x+visibleSize.width/2+3*perns,origin.y+panl6KSprite->getContentSize().height);
	star6[3] =
		ccp(origin.x+visibleSize.width/2+3*bornPerx,origin.y+visibleSize.height);


//	draw1->clear();

	CCBlink* lsideActin = CCBlink::create(10, 10);
	CCBlink* rsideActin = CCBlink::create(10, 10);
	lSide->runAction(
			CCRepeatForever::create(CCSequence::create(lsideActin, NULL)));
	rSide->runAction(
			CCRepeatForever::create(CCSequence::create(rsideActin, NULL)));
	//按键精灵
	bottomButton0_1 = CCSprite::createWithSpriteFrameName(
			"button_4key_0_1.png");
	bottomButton0_1->setScaleX(0.67f);//缺少图片，暂代。原图是4键的，此处为5键，故缩放为0.8
	bottomButton0_2 = CCSprite::createWithSpriteFrameName(
		"button_4key_0_2.png");
	bottomButton0_2->setScaleX(0.67f);//缺少图片，暂代
	bottomButton0_3 = CCSprite::createWithSpriteFrameName(
		"button_4key_0_3.png");
	bottomButton0_3->setScaleX(0.67f);//缺少图片，暂代
	bottomButton0_4 = CCSprite::createWithSpriteFrameName(
		"button_4key_0_4.png");
	bottomButton0_4->setScaleX(0.67f);//缺少图片，暂代
	bottomButton0_5 = CCSprite::createWithSpriteFrameName(
		"button_4key_0_4.png");
	bottomButton0_5->setScaleX(0.67f);//缺少图片，暂代
	bottomButton0_6 = CCSprite::createWithSpriteFrameName(
		"button_4key_0_4.png");
	bottomButton0_6->setScaleX(0.67f);//缺少图片，暂代

	bottomButton1_1 = CCSprite::createWithSpriteFrameName(
		"button_4key_1_1.png");
	bottomButton1_1->setScaleX(0.67f);//缺少图片，暂代
	bottomButton1_2 = CCSprite::createWithSpriteFrameName(
		"button_4key_1_2.png");
	bottomButton1_2->setScaleX(0.67f);//缺少图片，暂代
	bottomButton1_3 = CCSprite::createWithSpriteFrameName(
		"button_4key_1_3.png");
	bottomButton1_3->setScaleX(0.67f);//缺少图片，暂代
	bottomButton1_4 = CCSprite::createWithSpriteFrameName(
		"button_4key_1_4.png");
	bottomButton1_4->setScaleX(0.67f);//缺少图片，暂代
	bottomButton1_5 = CCSprite::createWithSpriteFrameName(
		"button_4key_1_4.png");
	bottomButton1_5->setScaleX(0.67f);//缺少图片，暂代
	bottomButton1_6 = CCSprite::createWithSpriteFrameName(
		"button_4key_1_4.png");
	bottomButton1_6->setScaleX(0.67f);//缺少图片，暂代

	//todo按键位置修改perKeyW/2+2后面的值
	bottomButton0_1->setPosition(
			ccp(origin.x+perKeyW/2+4,origin.y +bottomButton0_1->getContentSize().height/2+18));
	this->addChild(bottomButton0_1, 3);
	bottomButton0_2->setPosition(
			ccp(origin.x+perKeyW+perKeyW/2+2,origin.y +bottomButton0_2->getContentSize().height/2+18));
	this->addChild(bottomButton0_2, 3);
	bottomButton0_3->setPosition(
			ccp(origin.x+perKeyW*2+perKeyW/2,origin.y +bottomButton0_3->getContentSize().height/2+18));
	this->addChild(bottomButton0_3, 3);
	bottomButton0_4->setPosition(
			ccp(origin.x+perKeyW*3+perKeyW/2-2,origin.y +bottomButton0_4->getContentSize().height/2+18));
	this->addChild(bottomButton0_4, 3);
	bottomButton0_5->setPosition(
		ccp(origin.x+perKeyW*4+perKeyW/2-4,origin.y +bottomButton0_5->getContentSize().height/2+18));
	this->addChild(bottomButton0_5, 3);
	bottomButton0_6->setPosition(
		ccp(origin.x+perKeyW*5+perKeyW/2-4,origin.y +bottomButton0_6->getContentSize().height/2+18));
	this->addChild(bottomButton0_6, 3);

	bottomButton1_1->setPosition(
			ccp(origin.x+perKeyW/2+4,origin.y +bottomButton1_1->getContentSize().height/2+18));
	this->addChild(bottomButton1_1, -10);
	bottomButton1_2->setPosition(
			ccp(origin.x+perKeyW+perKeyW/2+2,origin.y +bottomButton1_2->getContentSize().height/2+18));
	this->addChild(bottomButton1_2, -10);
	bottomButton1_3->setPosition(
			ccp(origin.x+perKeyW*2+perKeyW/2,origin.y +bottomButton1_3->getContentSize().height/2+18));
	this->addChild(bottomButton1_3, -10);
	bottomButton1_4->setPosition(
			ccp(origin.x+perKeyW*3+perKeyW/2-2,origin.y +bottomButton1_4->getContentSize().height/2+18));
	this->addChild(bottomButton1_4, -10);
	bottomButton1_5->setPosition(
		ccp(origin.x+perKeyW*4+perKeyW/2-4,origin.y +bottomButton1_5->getContentSize().height/2+18));
	this->addChild(bottomButton1_5, -10);
	bottomButton1_6->setPosition(
		ccp(origin.x+perKeyW*5+perKeyW/2-4,origin.y +bottomButton1_6->getContentSize().height/2+18));
	this->addChild(bottomButton1_6, -10);


	CCLabelBMFont *comble = CCLabelBMFont::create("", "fonts/futura-48.fnt");
	addChild(comble, 10, 10);
	comble->setPosition(
			ccp(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2));

	CCLabelAtlas *scoreLable = CCLabelAtlas::create("0123456789",
			"fonts/jinscore.png", 18, 20, 48);

	addChild(scoreLable, 10, 11);
	scoreLable->setPosition(
			ccp(origin.x+visibleSize.width*2/3, origin.y+visibleSize.height-top->getContentSize().height/2));
//	scoreLable->setString("0");
	perfectRect =
			CCRectMake(bottomButton0_1->getPosition().x,bottomButton0_1->getPosition().y,bottomButton0_1->getContentSize().width,bottomButton0_1->getContentSize().height);
	bPerfectRect =
			CCRectMake(bottomButton0_1->getPosition().x,bottomButton0_1->getPosition().y,bottomButton0_1->getContentSize().width,bottomButton0_1->getContentSize().height/2);
	greatRect =
			CCRectMake(panl6KSprite->getPosition().x,panl6KSprite->getPosition().y,panl6KSprite->getContentSize().width,panl6KSprite->getContentSize().height*2);

//背景音乐
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(
			"song/andy/andy.mp3");
	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()) {
		CCLOG("background music is playing");
	} else {
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
				"song/andy/andy.mp3", true);
		CCLOG("background music is not playing");
	}
	CCProgressTo *program = CCProgressTo::create(mp3Seconds, 100);
	CCProgressTimer *left = CCProgressTimer::create(
			CCSprite::createWithSpriteFrameName("jindu.png"));
	left->setType(kCCProgressTimerTypeBar);
	left->setMidpoint(ccp(0,0));
	left->setBarChangeRate(ccp(1, 0));
	addChild(left, 6);
	left->setPosition(
			ccp(origin.x+visibleSize.width/2,origin.y+visibleSize.height-left->getContentSize().height/2));
	left->runAction(CCRepeatForever::create(program));

	hpProgress = CCProgressTimer::create(
			CCSprite::createWithSpriteFrameName("hp.png"));
	hpProgress->setType(kCCProgressTimerTypeBar);
	hpProgress->setMidpoint(ccp(0,0));
	hpProgress->setBarChangeRate(ccp(1, 0));
	addChild(hpProgress, 6);

	hpProgress->setPosition(
			ccp(origin.x+visibleSize.width/4-40,origin.y+visibleSize.height-top->getContentSize().height/4-left->getContentSize().height));

	schedule(schedule_selector(Game6Key::born), 0.5);
	schedule(schedule_selector(Game6Key::clearZero),0.5);
	schedule(schedule_selector(Game6Key::finishGame),1);
	return true;
}


void Game6Key::remove(CCNode *pSender) { //动作执行完后移除
	if (pSender == NULL) {
		return;
	}
	CCSprite *sprite = (CCSprite *) pSender;
	
	//////////////////////滑落将连击清零//////////////////////////////////////
	if (sprite->getPositionY() < key1Rect.getMaxY()+10)
	{
		if (curCombo != 0)
		{
			CCLabelBMFont* curCombLable = (CCLabelBMFont*) getChildByTag(10);
			this->curCombo = 0;
			char string[12] = { 0 };
			sprintf(string, "%d", curCombo);
			curCombLable->setString(string);
		}
	}
	//////////////////////////////////////////////////////////////////////////
	sprite->removeFromParent();
}
int Game6Key::checkScore(CCNode *pNode) {
	int checkid = 0;
	if (pNode == NULL) {
		return checkid;
	}
	CCSprite *sprite = (CCSprite *) pNode;

	float s_y = sprite->getPosition().y;
	float s_bperfect_maxy = bPerfectRect.getMaxY();
	float s_bperfect_miny = bPerfectRect.getMinY();
	float s_perfect_maxy = perfectRect.getMaxY();
	float s_perfect_miny = perfectRect.getMinY();
	float s_great_maxy = greatRect.getMaxY();
	float s_great_miny = greatRect.getMinY();
	if (s_y >= s_bperfect_miny && s_y <= s_bperfect_maxy) { //大perfect
		checkid = 1;
		perfectNum+=2;
	} else if (s_y >= s_perfect_miny && s_y <= s_perfect_maxy) { //小perfect
		checkid = 2;
		perfectNum++;
	} else if (s_y >= s_great_miny && s_y <= s_great_maxy) { //great
		checkid = 3;
		greatNum++;
	} else { //miss
		checkid = 4;
		missNum++;
	}
	sprite->removeFromParent();
	return checkid;
}
void Game6Key::clearCurComb(CCNode *pLable) {
	if (pLable == NULL) {
		return;
	}
	CCLabelBMFont *lable = (CCLabelBMFont*) pLable;
	lable->setString("");
}
/*
参数bperfect，perfect，great，miss
*/
void Game6Key::showCombo(int id) {
	//todo......
	if (id == 0) {
		return;
	}
	CCSprite* s_p;
	if (id == 1) {

		s_p = CCSprite::createWithSpriteFrameName("s_bperfect.png");
		if (this->HP < 100) {
			this->lastHP = HP;
			this->HP += 20;
			score += 200;
		}
	}
	if (id == 2) {

		s_p = CCSprite::createWithSpriteFrameName("s_perfect.png");
		score += 183;
	}
	if (id == 3) {

		s_p = CCSprite::createWithSpriteFrameName("s_great.png");
		score += 80;
	}
	curCombo++;
	if (maxCombo <= curCombo) {
		maxCombo++;
	}
	if ((id == 4) || (id == 5)) {//////////////////////////////////////////////////////////////////////////
		s_p = CCSprite::createWithSpriteFrameName("s_miss.png");
		if (HP > 0) {
			this->lastHP = HP;
			this->HP -= 20;
		}
		this->curCombo = 0;
	}
	s_p->setScale(0.2);
	this->addChild(s_p, 10);
	s_p->setPosition(
			ccp(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2+80));
	CCCallFuncN* s_pCallBack = CCCallFuncN::create(this,
			callfuncN_selector(Game6Key::remove));
	CCAction* s_pAction = CCSequence::create(CCScaleTo::create(0.2, 1),
			s_pCallBack, NULL);
	s_p->runAction(s_pAction);
	CCLabelBMFont* curCombLable = (CCLabelBMFont*) getChildByTag(10);
	CCLabelAtlas* scoreLable = (CCLabelAtlas*) getChildByTag(11);
	char string[12] = { 0 };
	char strscore[12] = { 0 };
	sprintf(string, "%d", curCombo);
	//CCLOG(string);
	curCombLable->setString(string);
	sprintf(strscore, "%d", score);
	scoreLable->setString(strscore);
}
//位置修改,musicNote_6_1->setScale(0.2f);缩放比率修改。
//修改ccp(origin.x+perNoteBottom_X*4+perNoteBottom_X/2+25,origin.y)), NULL),pCallback,NULL);

void Game6Key::born(float dt) {
	//bornKey = rand() % 7;
	CCCallFuncN* pCallback = CCCallFuncN::create(this,
			callfuncN_selector(Game6Key::remove));
	map<string,S_Info>::iterator it;
	ssMap* ssmap = SongSingleton::getInstance()->ssmap;
	it = ssmap->find("aaaa");
	if (keyValue != (it->second).key6Value.length())
	{
		string key(it->second.key6Value,keyValue,1); 
		bornKey = atoi(key.c_str());
		keyValue++;
	}else
	{
		keyValue=0;
	}
	if (bornKey == 1) {
		CCSprite* musicNote_6_1 = CCSprite::createWithSpriteFrameName(
				"button_4key_3_1.png");
		musicNote_6_1->setPosition(bornNotePos1);
		musicNote_6_1->setScale(1/6);
		this->addChild(musicNote_6_1, 4, 1);
		CCFiniteTimeAction* noteAction1 =
				(CCFiniteTimeAction*) CCSequence::create(
						CCSpawn::create(CCScaleTo::create(speed, 1),
								CCMoveTo::create(speed,
										ccp(origin.x+perNoteBottom_X/2-30,origin.y)),NULL),pCallback,NULL);
		musicNote_6_1->runAction(noteAction1);
	}
	if (bornKey == 2) {
		CCSprite* musicNote_6_2 = CCSprite::createWithSpriteFrameName(
				"button_4key_3_2.png");
		musicNote_6_2->setPosition(bornNotePos2);
		musicNote_6_2->setScale(1/6);
		this->addChild(musicNote_6_2, 4, 2);
		CCFiniteTimeAction* noteAction2 =
				(CCFiniteTimeAction*) CCSequence::create(
						CCSpawn::create(CCScaleTo::create(speed, 1),
								CCMoveTo::create(speed,
										ccp(origin.x+perNoteBottom_X+perNoteBottom_X/2-20,origin.y)),NULL),pCallback,NULL);
		musicNote_6_2->runAction(noteAction2);
	}
	if (bornKey == 3) {
		CCSprite* musicNote_6_3 = CCSprite::createWithSpriteFrameName(
				"button_4key_3_3.png");
		musicNote_6_3->setPosition(bornNotePos3);
		musicNote_6_3->setScale(1/6);
		this->addChild(musicNote_6_3, 4, 3);
		CCFiniteTimeAction* noteAction3 =
				(CCFiniteTimeAction*) CCSequence::create(
						CCSpawn::create(CCScaleTo::create(speed, 1),
								CCMoveTo::create(speed,
										ccp(origin.x+perNoteBottom_X*2+perNoteBottom_X/2 -10,origin.y)),NULL),pCallback,NULL);

		musicNote_6_3->runAction(noteAction3);
	}
	if (bornKey == 4) {
		CCSprite* musicNote_6_4 = CCSprite::createWithSpriteFrameName(
				"button_4key_3_4.png");

		musicNote_6_4->setPosition(bornNotePos4);

		musicNote_6_4->setScale(1/6);

		this->addChild(musicNote_6_4, 4, 4);

		CCFiniteTimeAction* noteAction4 =
				(CCFiniteTimeAction*) CCSequence::create(
						CCSpawn::create(CCScaleTo::create(speed, 1),
								CCMoveTo::create(speed,
										ccp(origin.x+perNoteBottom_X*3+perNoteBottom_X/2+10,origin.y)), NULL),pCallback,NULL);

		musicNote_6_4->runAction(noteAction4);
	}
	if (bornKey == 5) {
		CCLOG("5");
		CCSprite* musicNote_6_5 = CCSprite::createWithSpriteFrameName(
			"button_4key_3_4.png");

		musicNote_6_5->setPosition(bornNotePos5);

		musicNote_6_5->setScale(1/6);

		this->addChild(musicNote_6_5, 4, 5);

		CCFiniteTimeAction* noteAction5 =
			(CCFiniteTimeAction*) CCSequence::create(
			CCSpawn::create(CCScaleTo::create(speed, 1),
			CCMoveTo::create(speed,
			ccp(origin.x+perNoteBottom_X*4+perNoteBottom_X/2+20,origin.y)), NULL),pCallback,NULL);

		musicNote_6_5->runAction(noteAction5);
	}
	if (bornKey == 6) {
		CCSprite* musicNote_6_6 = CCSprite::createWithSpriteFrameName(
			"button_4key_3_4.png");

		musicNote_6_6->setPosition(bornNotePos6);

		musicNote_6_6->setScale(1/6);

		this->addChild(musicNote_6_6, 4, 6);

		CCFiniteTimeAction* noteAction6 =
			(CCFiniteTimeAction*) CCSequence::create(
			CCSpawn::create(CCScaleTo::create(speed, 1),
			CCMoveTo::create(speed,
			ccp(origin.x+perNoteBottom_X*5+perNoteBottom_X/2+30,origin.y)), NULL),pCallback,NULL);

		musicNote_6_6->runAction(noteAction6);
	}
	hpProgress->runAction(
			CCRepeatForever::create(
					CCProgressFromTo::create(0.02, lastHP, HP)));

}
int Game6Key::containsTouchLocation(CCTouch* touch) {
	if (key1Rect.containsPoint(convertTouchToNodeSpace(touch))) {
		return 1;
	}
	if (key2Rect.containsPoint(convertTouchToNodeSpace(touch))) {
		return 2;
	}
	if (key3Rect.containsPoint(convertTouchToNodeSpace(touch))) {
		return 3;
	}
	if (key4Rect.containsPoint(convertTouchToNodeSpace(touch))) {
		return 4;
	}
	if (key5Rect.containsPoint(convertTouchToNodeSpace(touch))) {
		return 5;
	}
	if (key6Rect.containsPoint(convertTouchToNodeSpace(touch))) {
		return 6;
	}
	return 0;

}
void Game6Key::ccTouchesBegan(CCSet *touches, CCEvent *pEvent) {
	CCSetIterator iter;
	CCTouch *touch;

	for (iter = touches->begin(); iter != touches->end(); ++iter) {
		touch = (CCTouch *) (*iter);
		int touchKey = Game6Key::containsTouchLocation(touch);
		if (touchKey == 0) {
			return;
		}
		switch (touchKey) {
		case 1:
			draw1->drawPolygon(star1, sizeof(star1) / sizeof(star1[0]),
					ccc4f(0.2, 0.8, 1, 0.5), 1, ccc4f(0, 0, 1, 255));

			zOrderSprite(bottomButton0_1, bottomButton1_1);
			showCombo(checkScore(getChildByTag(1)));
			break;
		case 2:
			draw2->drawPolygon(star2, sizeof(star2) / sizeof(star2[0]),
					ccc4f(0.2, 0.8, 1, 0.5), 1, ccc4f(0, 0, 1, 255));

			zOrderSprite(bottomButton0_2, bottomButton1_2);
			showCombo(checkScore(getChildByTag(2)));
			break;
		case 3:
			draw3->drawPolygon(star3, sizeof(star3) / sizeof(star3[0]),
					ccc4f(0.2, 0.8, 1, 0.5), 1, ccc4f(0, 0, 1, 255));

			zOrderSprite(bottomButton0_3, bottomButton1_3);
			showCombo(checkScore(getChildByTag(3)));
			break;
		case 4:
			draw4->drawPolygon(star4, sizeof(star4) / sizeof(star4[0]),
					ccc4f(0.2, 0.8, 1, 0.5), 1, ccc4f(0, 0, 1, 255));
			zOrderSprite(bottomButton0_4, bottomButton1_4);
			showCombo(checkScore(getChildByTag(4)));
			break;
		case 5:
			draw5->drawPolygon(star5, sizeof(star5) / sizeof(star5[0]),
				ccc4f(0.2, 0.8, 1, 0.5), 1, ccc4f(0, 0, 1, 255));
			zOrderSprite(bottomButton0_5, bottomButton1_5);
			showCombo(checkScore(getChildByTag(5)));
			break;
		case 6:
			draw6->drawPolygon(star6, sizeof(star6) / sizeof(star6[0]),
				ccc4f(0.2, 0.8, 1, 0.5), 1, ccc4f(0, 0, 1, 255));
			zOrderSprite(bottomButton0_6, bottomButton1_6);
			showCombo(checkScore(getChildByTag(6)));
			break;
		default:
			return;
		}

	}
}
void Game6Key::zOrderSprite(CCSprite* sprite1, CCSprite* sprite2) {

	/*CCArmature* armature = CCArmature::create("key_press");
	 armature->getAnimation()->playByIndex(0);
	 armature->getAnimation()->setAnimationScale(0.4f);
	 armature->setPosition(sprite1->getPosition());
	 //		armature->setScale(0.6f);
	 this->addChild(armature,4);*/

	reorderChild(sprite1, -10);
	reorderChild(sprite2, 3);
}
void Game6Key::ccTouchesEnded(CCSet *touches, CCEvent *pEvent) {
	CCSetIterator iter;
	CCTouch *touch;
	for (iter = touches->begin(); iter != touches->end(); ++iter) {
		touch = (CCTouch *) (*iter);
		int touchKey = Game6Key::containsTouchLocation(touch);
		if (touchKey == 0) {
			return;
		}
		switch (touchKey) {
		case 1:
			draw1->clear();
			zOrderSprite(bottomButton1_1, bottomButton0_1);
			return;
		case 2:
			draw2->clear();
			zOrderSprite(bottomButton1_2, bottomButton0_2);
			return;
		case 3:
			draw3->clear();
			zOrderSprite(bottomButton1_3, bottomButton0_3);
			return;
		case 4:
			draw4->clear();
			zOrderSprite(bottomButton1_4, bottomButton0_4);
			return;
		case 5:
			draw5->clear();
			zOrderSprite(bottomButton1_5, bottomButton0_5);
			return;
		case 6:
			draw6->clear();
			zOrderSprite(bottomButton1_6, bottomButton0_6);
			return;
		default:
			return;
		}
	}
}
void Game6Key::ccTouchesMoved(CCSet *touches, CCEvent *pEvent) {
	CCSetIterator iter;
	CCTouch *touch;
	for (iter = touches->begin(); iter != touches->end(); ++iter) {
		touch = (CCTouch *) (*iter);
		int touchKey = Game6Key::containsTouchLocation(touch);
		if (touchKey == 0) {
			return;
		}
		switch (touchKey) {
		case 1:
			zOrderSprite(bottomButton0_1, bottomButton1_1);
			reorderChild(bottomButton0_2, 3);
			reorderChild(bottomButton0_3, 3);
			reorderChild(bottomButton0_4, 3);
			reorderChild(bottomButton0_5, 3);
			reorderChild(bottomButton0_6, 3);

			break;
		case 2:
			zOrderSprite(bottomButton0_2, bottomButton1_2);
			reorderChild(bottomButton0_1, 3);
			reorderChild(bottomButton0_3, 3);
			reorderChild(bottomButton0_4, 3);
			reorderChild(bottomButton0_5, 3);
			reorderChild(bottomButton0_6, 3);
			break;
		case 3:
			zOrderSprite(bottomButton0_3, bottomButton1_3);
			reorderChild(bottomButton0_1, 3);
			reorderChild(bottomButton0_2, 3);
			reorderChild(bottomButton0_4, 3);
			reorderChild(bottomButton0_5, 3);
			reorderChild(bottomButton0_6, 3);
			break;
		case 4:
			zOrderSprite(bottomButton0_4, bottomButton1_4);
			reorderChild(bottomButton0_1, 3);
			reorderChild(bottomButton0_2, 3);
			reorderChild(bottomButton0_3, 3);
			reorderChild(bottomButton0_5, 3);
			reorderChild(bottomButton0_6, 3);
			break;
		case 5:
			zOrderSprite(bottomButton0_5, bottomButton1_5);
			reorderChild(bottomButton0_1, 3);
			reorderChild(bottomButton0_2, 3);
			reorderChild(bottomButton0_3, 3);
			reorderChild(bottomButton0_4, 3);
			reorderChild(bottomButton0_6, 3);
			break;
		case 6:
			zOrderSprite(bottomButton0_6, bottomButton1_6);
			reorderChild(bottomButton0_1, 3);
			reorderChild(bottomButton0_2, 3);
			reorderChild(bottomButton0_3, 3);
			reorderChild(bottomButton0_4, 3);
			reorderChild(bottomButton0_5, 3);
			break;
		default:
			reorderChild(bottomButton0_1, 3);
			reorderChild(bottomButton0_2, 3);
			reorderChild(bottomButton0_3, 3);
			reorderChild(bottomButton0_4, 3);
			reorderChild(bottomButton0_5, 3);
			return;
		}
	}
}
void Game6Key::menuCallback(CCObject* pSender) {
	//CCDirector* pDirector = CCDirector::sharedDirector();
	//CCUserDefault::sharedUserDefault()->setIntegerForKey("key",6);
	//CCUserDefault::sharedUserDefault()->flush();
	//SongSingleton::getInstance()->g_info->key = 6;
	//CCScene *pScene = SelectSongScene::scene();
	////CCScene *pScene = HelloWorld::scene();
	//pDirector->replaceScene(pScene);

	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	//this->pauseSchedulerAndActions();

	CCDirector::sharedDirector()->pause();
	PauseScene* p1 = PauseScene::create("buygold.png");
	p1->setContentSize(CCSizeMake(200,200));
	p1->setCallbackFunc(this,callfuncN_selector(Game6Key::resumeGame));
	this->addChild(p1,15);;
}

void Game6Key::finishGame( float dt )
{
	currentSeconds++;
	if (this->lastHP > 0)
	{
		if (currentSeconds == mp3Seconds)
		{

			SongSingleton::getInstance()->g_info->score = score;
			SongSingleton::getInstance()->g_info->maxCombo = maxCombo;
			SongSingleton::getInstance()->g_info->perfectNum = perfectNum;
			SongSingleton::getInstance()->g_info->greatNum = greatNum;
			SongSingleton::getInstance()->g_info->missNum = missNum;
			CCDirector::sharedDirector()->replaceScene(ShowScore::scene());
			//ScoreLayer* popLayer = ScoreLayer::create();
			//this->addChild(popLayer,17);

			////CCDirector::sharedDirector()->pause();
			//CCClippingNode* clip = CCClippingNode::create();
			//clip->setInverted(TRUE);  //设置ALPHA镂空的阈值， ture:裁剪区域镂空，其他区域显示底板颜色 false：裁剪区域显示底板颜色，其他区域镂空
			//clip->setAlphaThreshold(0.5f); //设置ALPHA的测试参考值   //奇怪的东东  /设置alpha值（0~1），这个很重要，裁剪是按像素抠图的，所以只有大于这个alpha值的模版像素才会被画出来 
			////默认是1，也就是完全裁剪。 
			//CCLayerColor* back=CCLayerColor::create(ccc4(125,125,125,200));
			//clip->addChild(back);//给clip加一个颜色层，clip不受影响，其他区域有层级遮挡

			//CCNode* nodef=CCNode::create();
			//CCSprite* bg=CCSprite::createWithSpriteFrameName("bg2.png");
			//bg->setScale(0.5f);
			//nodef->addChild(bg);
			//nodef->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
			//clip->setStencil(nodef); //印刷，使图片被印刷出来，带图形的遮罩
			//this->addChild(clip,16); //创建一个剪辑区域

			/*
			CCUserDefault::sharedUserDefault()->setDoubleForKey("score",score);
			CCUserDefault::sharedUserDefault()->setIntegerForKey("maxCombo",maxCombo);
			CCUserDefault::sharedUserDefault()->setIntegerForKey("perfect",perfectNum);
			CCUserDefault::sharedUserDefault()->setIntegerForKey("great",greatNum);
			CCUserDefault::sharedUserDefault()->setIntegerForKey("miss",missNum);
			CCUserDefault::sharedUserDefault()->flush();
			CCDirector::sharedDirector()->replaceScene(ShowScore::scene());
			*/

		}
	}else
	{
		/*
		CCUserDefault::sharedUserDefault()->setIntegerForKey("score",score);
		CCUserDefault::sharedUserDefault()->setIntegerForKey("maxCombo",maxCombo);
		CCUserDefault::sharedUserDefault()->setIntegerForKey("perfect",perfectNum);
		CCUserDefault::sharedUserDefault()->setIntegerForKey("great",greatNum);
		CCUserDefault::sharedUserDefault()->setIntegerForKey("miss",missNum);
		CCUserDefault::sharedUserDefault()->flush();

		CCDirector::sharedDirector()->replaceScene(ShowScore::scene());
		*/
		SongSingleton::getInstance()->g_info->score = score;
		SongSingleton::getInstance()->g_info->maxCombo = maxCombo;
		SongSingleton::getInstance()->g_info->perfectNum = perfectNum;
		SongSingleton::getInstance()->g_info->greatNum = greatNum;
		SongSingleton::getInstance()->g_info->missNum = missNum;
		CCDirector::sharedDirector()->replaceScene(ShowScore::scene());
		//ScoreLayer* popLayer = ScoreLayer::create();
		//this->addChild(popLayer,17);

		//CCDirector::sharedDirector()->pause();
		//CCClippingNode* clip = CCClippingNode::create();
		//clip->setInverted(TRUE);  //设置ALPHA镂空的阈值， ture:裁剪区域镂空，其他区域显示底板颜色 false：裁剪区域显示底板颜色，其他区域镂空
		//clip->setAlphaThreshold(0.5f); //设置ALPHA的测试参考值   //奇怪的东东  /设置alpha值（0~1），这个很重要，裁剪是按像素抠图的，所以只有大于这个alpha值的模版像素才会被画出来 
		////默认是1，也就是完全裁剪。 
		//CCLayerColor* back=CCLayerColor::create(ccc4(125,125,125,200));
		//clip->addChild(back);//给clip加一个颜色层，clip不受影响，其他区域有层级遮挡

		//CCNode* nodef=CCNode::create();
		//CCSprite* bg=CCSprite::createWithSpriteFrameName("bg2.png");
		//bg->setScale(0.5f);
		//nodef->addChild(bg);
		//nodef->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
		//clip->setStencil(nodef); //印刷，使图片被印刷出来，带图形的遮罩
		//this->addChild(clip,16); //创建一个剪辑区域
	}

}

void Game6Key::resumeGame( cocos2d::CCNode *pNode )
{
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
		//this->resumeSchedulerAndActions();
	CCDirector::sharedDirector()->resume();
}
