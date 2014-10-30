#include "ShowScore.h"
#include "SelectSong1.h"
#include "HelloWorldScene.h"
#include "mainFace.h"
#include "Common.h"
bool ShowScore::init()
{
	if (!CCLayer::init()) {
		return false;
	}
	setTouchEnabled(true);
	//����ӿ�(��������)�Ĵ�С
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//���������������꣬���ڴ������λ�õ�ʱ��ǳ����ã�ȷ���ڵ��ڲ�ͬ�ֱ����µ�λ��һ�¡�
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCSprite* slecetSongSprite = CCSprite::createWithSpriteFrameName(
		"bg2.png");	
	slecetSongSprite->setPosition(
		ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	this->addChild(slecetSongSprite, 0);

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create("CloseNormal.png",
		"CloseSelected.png", this,
		menu_selector(ShowScore::menuCloseCallback));

	pCloseItem->setPosition(
		ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));

	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu);

	//////////////////////////////////////////////////////////////////////////
	getScore();
	//////////////////////////////////////////////////////////////////////////
	if (score > 100)
	{
		CCSprite* levelScore = CCSprite::createWithSpriteFrameName("s3.png");
		levelScore->setAnchorPoint(CCPointZero);
		levelScore->setPosition(ccp(origin.x+visibleSize.width*2/3 - levelScore->getContentSize().width, origin.y+visibleSize.height*2/3));
		addChild(levelScore,10);
	}
	//��ǩ�Ĵ���
	CCLabelAtlas *scoreLable = CCLabelAtlas::create("0123456789",
		"fonts/jinscore.png", 18, 20, 48);
	addChild(scoreLable, 10, 10);
	scoreLable->setPosition(
		ccp(origin.x+visibleSize.width*2/3, origin.y+visibleSize.height*2/3));
	char scorestring[12] = { 0 };
	sprintf(scorestring, "%d", score);
	scoreLable->setString(scorestring);

	char string[12] = { 0 };
	CCSprite* comboSprite = CCSprite::createWithSpriteFrameName("zmax.png");
	comboSprite->setPosition(
		ccp(origin.x + visibleSize.width /5,origin.y + visibleSize.height/3));
	comboSprite->setAnchorPoint(CCPointZero);
	addChild(comboSprite,10);
	CCLabelAtlas *comboLable = CCLabelAtlas::create("0123456789",
		"fonts/jinscore.png", 18, comboSprite->getContentSize().height, 48);
	addChild(comboLable, 10, 11);
	comboLable->setPosition(
		ccp(origin.x+visibleSize.width/5 + comboSprite->getContentSize().width + 18, origin.y+visibleSize.height/3));
	sprintf(string, "%d", combo);
	comboLable->setString(string);
	
	CCSprite* perfectSprite = CCSprite::createWithSpriteFrameName("z_1.png");
	perfectSprite->setPosition(
		ccp(comboLable->getPositionX() + 18 * 6,origin.y + visibleSize.height/3));
	perfectSprite->setAnchorPoint(CCPointZero);
	addChild(perfectSprite,10);
	CCLabelAtlas *perfectLable = CCLabelAtlas::create("0123456789",
		"fonts/jinscore.png", 18, 20, 48);
	addChild(perfectLable, 10, 12);
	perfectLable->setPosition(
		ccp(perfectSprite->getPositionX() + perfectSprite->getContentSize().width + 18, origin.y + visibleSize.height/3));
	memset(string,0,sizeof(string));
	sprintf(string, "%d", perfectNum);
	perfectLable->setString(string);

	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/music_select_01.mp3");
/*
	CCLabelAtlas *greatLable = CCLabelAtlas::create("0123456789",
		"fonts/jinscore.png", 18, 20, 48);
	addChild(greatLable, 10, 13);
	greatLable->setPosition(
		ccp(origin.x+visibleSize.width*2/3, origin.y+visibleSize.height-top->getContentSize().height/2));

	CCLabelAtlas *missLable = CCLabelAtlas::create("0123456789",
		"fonts/jinscore.png", 18, 20, 48);
	addChild(missLable, 10, 14);
	missLable->setPosition(
		ccp(origin.x+visibleSize.width*2/3, origin.y+visibleSize.height-top->getContentSize().height/2));
		*/
	//////////////////////////////////////////////////////////////////////////
	//this->setScale(0.5f);
	return true;
}

cocos2d::CCScene* ShowScore::scene()
{
	CCScene *scene = CCScene::create();

	ShowScore *layer = ShowScore::create();

	scene->addChild(layer);

	return scene;
}

void ShowScore::menuCloseCallback( CCObject* pSender )
{

	CCDirector* pDirector = CCDirector::sharedDirector();
	CCScene *pScene = MainGaneScene::scene();
	pDirector->replaceScene(pScene);
}

void ShowScore::getScore()
{
	score = CCUserDefault::sharedUserDefault()->getIntegerForKey("score");
	combo = CCUserDefault::sharedUserDefault()->getIntegerForKey("maxCombo");
	perfectNum = CCUserDefault::sharedUserDefault()->getIntegerForKey("perfect");
	greatNum = CCUserDefault::sharedUserDefault()->getIntegerForKey("great");
	missNum = CCUserDefault::sharedUserDefault()->getIntegerForKey("miss");
	CCUserDefault::sharedUserDefault()->flush();
	score = SongSingleton::getInstance()->g_info->score;
	combo = SongSingleton::getInstance()->g_info->maxCombo;
	perfectNum = SongSingleton::getInstance()->g_info->perfectNum;
	greatNum = SongSingleton::getInstance()->g_info->greatNum;
	missNum = SongSingleton::getInstance()->g_info->missNum;
}


/*�Ի��򳡾���ľ���ʵ��*/

CCScene * ScoreLayer::scene()
{
	CCScene * scene = NULL;
	do
	{
		scene = CCScene::create();
		ScoreLayer * layer = ScoreLayer::create();
		scene->addChild(layer);
	}
	while(0);

	return scene;
}

bool ScoreLayer::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!CCLayer::init());

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		//����ӿ�(��������)�Ĵ�С
		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
		//���������������꣬���ڴ������λ�õ�ʱ��ǳ����ã�ȷ���ڵ��ڲ�ͬ�ֱ����µ�λ��һ�¡�
		CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
		//���������ı���ͼƬ������������λ��Ϊ������Ļ���е�
		CCSprite * background = CCSprite::createWithSpriteFrameName("bg2.png");
		m_bgSprite = background;
		background->setPosition(ccp(winSize.width/2,winSize.height/2));
		background->setScale(0.5f);
		this->addChild(background);

		//��ñ���ͼƬ�Ĵ�С
		CCSize contentSize = background->getContentSize();
		m_size = contentSize;

		//��������˵����������
		SEL_MenuHandler repeatselect= (SEL_MenuHandler)menu_selector(ScoreLayer::menuCloseCallback);
		SEL_MenuHandler shareselect= (SEL_MenuHandler)menu_selector(ScoreLayer::menuCloseCallback);
		SEL_MenuHandler overselect= (SEL_MenuHandler)menu_selector(ScoreLayer::menuCloseCallback);
		CCSprite* repeatSpriteButton = CCSprite::createWithSpriteFrameName(
			"button_4key_3_1.png");	
		CCMenuItemSprite* repeatMenu = CCMenuItemSprite::create(repeatSpriteButton,
			repeatSpriteButton, repeatSpriteButton, this,
			repeatselect );
		CCSprite* shareSpriteButton = CCSprite::createWithSpriteFrameName(
			"button_4key_3_2.png");	
		CCMenuItemSprite* shareMenu = CCMenuItemSprite::create(shareSpriteButton,
			shareSpriteButton, shareSpriteButton, this,
			shareselect );
		CCSprite* overSpriteButton = CCSprite::createWithSpriteFrameName(
			"button_4key_3_3.png");	
		CCMenuItemSprite* overMenu = CCMenuItemSprite::create(overSpriteButton,
			overSpriteButton, overSpriteButton, this,
			repeatselect );

		CCMenu * menu = CCMenu::create(repeatMenu,shareMenu,overMenu,NULL);
		menu->alignItemsHorizontallyWithPadding(5);
		menu->setPosition(ccp(contentSize.width/2,contentSize.height/3));
		menu->setTouchPriority(kCCMenuHandlerPriority*2-1);
		this->addChild(menu);


		CCMenuItemImage *pCloseItem = CCMenuItemImage::create("CloseNormal.png",
			"CloseSelected.png", this, menu_selector(ScoreLayer::menuCloseCallback));

		pCloseItem->setPosition(
			ccp((origin.x + visibleSize.width - pCloseItem->getContentSize().width/2) ,
			(visibleSize.height - pCloseItem->getContentSize().height/2)));

		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		this->addChild(pMenu);

		//������Ŀ���ı�����
		//this->setTitle();
		this->setContent();

		this->setTouchEnabled(true);
		bRet = true;
	}
	while(0);

	return bRet;
}

void ScoreLayer::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,
		kCCMenuHandlerPriority*2,true);
}

bool ScoreLayer::ccTouchBegan(CCTouch * touch,CCEvent * pevent)
{
	return true;
}

//����˵���ť��ʱ����õ��¼�������
void ScoreLayer::yesButton(CCObject * object)
{
	this->removeFromParentAndCleanup(true);
}

void ScoreLayer::noButton(CCObject * object)
{
	this->removeFromParentAndCleanup(true);
}

//������������Ŀ
void ScoreLayer::setTitle()
{
	//CCLabelTTF * title = CCLabelTTF::create("Tips","",24);
	CCLabelBMFont * title = CCLabelBMFont::create("Tips","bitmapFontChinese.fnt");
	title->setPosition(ccp(m_size.width/2,m_size.height-title->getContentSize().height/2));
	m_bgSprite->addChild(title);
}

//���ò������
void ScoreLayer::setContent()
{


	setTouchEnabled(true);
	//����ӿ�(��������)�Ĵ�С
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//���������������꣬���ڴ������λ�õ�ʱ��ǳ����ã�ȷ���ڵ��ڲ�ͬ�ֱ����µ�λ��һ�¡�
	
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	/*
	CCLabelTTF * content = CCLabelTTF::create("hello! everyone,welcome to www.zaojiahua.com",
		"",24);
	content->setPosition(ccp(m_size.width/2,m_size.height/2));
	//����ttf���ı���
	content->setDimensions(CCSize(this->m_size.width-60,this->m_size.height-100));
	//����ttf��ˮƽ���뷽ʽ
	content->setHorizontalAlignment(kCCTextAlignmentLeft);

	m_bgSprite->addChild(content);
	*/


	CCSprite* levelScore = CCSprite::createWithSpriteFrameName("s3.png");
	levelScore->setAnchorPoint(CCPointZero);
	levelScore->setPosition(ccp(m_size.width/4,m_size.height/2));
	addChild(levelScore,10);

	CCLabelAtlas *scoreLable = CCLabelAtlas::create("0123456789",
		"fonts/jinscore.png", 18, 20, 48);
	addChild(scoreLable, 10, 12);
	scoreLable->setPosition(
		ccp(m_size.width/4 + levelScore->getContentSize().width,m_size.height/2));
	char string[12] = {0};
	memset(string,0,sizeof(string));
	sprintf(string, "%d", SongSingleton::getInstance()->g_info->score);
	scoreLable->setString(string);
}

void ScoreLayer::menuCloseCallback( CCObject* pSender )
{

	CCDirector* pDirector = CCDirector::sharedDirector();
	CCScene *pScene = SelectSongScene::scene();
	pDirector->replaceScene(pScene);
}
