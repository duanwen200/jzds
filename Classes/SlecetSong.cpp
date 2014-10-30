#include "SlecetSong.h"
#include "Common.h"
#include "HelloWorldScene.h"
#include "Game4Key.h"
#include "Game5Key.h"
#include "Game6Key.h"

SlecetSong::SlecetSong()
{
}

SlecetSong::~SlecetSong()
{
}

void SlecetSong::parseXml( const char* fileName )
{
	std::string filePath  = CCFileUtils::sharedFileUtils()->getWritablePath() + fileName;
	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
	XMLError errorId = pDoc->LoadFile(filePath.c_str());

	if (errorId != 0) {
		//xml格式错误
		return;
	}

	XMLElement *rootEle = pDoc->RootElement();

	//获取第一个节点属性
	const XMLAttribute *attribute = rootEle->FirstAttribute();
	//打印节点属性名和值
	//log("attribute_name = %s,attribute_value = %s", attribute->Name(), attribute->Value());

	XMLElement *dicEle = rootEle->FirstChildElement("dic");
	XMLElement *keyEle = dicEle->FirstChildElement("key");
	do
	{

		if (keyEle) {
			CCLOG("keyEle Text= %s", keyEle->GetText());
		}

		XMLElement *arrayEle = keyEle->NextSiblingElement();
		XMLElement *childEle = arrayEle->FirstChildElement();
		while ( childEle ) {
			CCLOG("childEle Text= %s", childEle->GetText());
			songsName.push_back(childEle->GetText());
			childEle = childEle->NextSiblingElement();
		}
	}while (keyEle = keyEle->NextSiblingElement("key"));
	delete pDoc;
}

bool SlecetSong::init()
{
	if (!CCLayer::init()) {
	return false;
	}
	setTouchEnabled(true);
	//获得视口(可视区域)的大小
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//可视区域的起点坐标，这在处理相对位置的时候非常有用，确保节点在不同分辨率下的位置一致。
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCSprite* slecetSongSprite = CCSprite::createWithSpriteFrameName(
		"bg.png");	
	slecetSongSprite->setPosition(
	ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	this->addChild(slecetSongSprite, 0);

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create("CloseNormal.png",
		"CloseSelected.png", this,
		menu_selector(SlecetSong::menuCloseCallback));

	pCloseItem->setPosition(
		ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));

	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu);


	//todo

		SEL_MenuHandler hSelect= (SEL_MenuHandler)menu_selector(SlecetSong::tempLayer);
	menu = CCMenu::create();
	parseXml("test.xml");
	for (int i=0; i< songsName.size(); i++) {

		CCLabelTTF *pLabel=CCLabelTTF::create(songsName[i].c_str(), "Thonburi", 20);
		CCMenuItemLabel* selectLabel = CCMenuItemLabel::create(pLabel,this,hSelect);
		//selectLabel->setZOrder(i);
		menu->addChild(selectLabel,i,i);
	}

	menu->alignItemsVertically();
	//menu->alignItemsHorizontally();
	this->addChild(menu, 1);
	menu->setPosition(ccp(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height/2));
	return true;
}

cocos2d::CCScene* SlecetSong::scene()
{
	CCScene *scene = CCScene::create();

	SlecetSong *layer = SlecetSong::create();

	scene->addChild(layer);

	return scene;
}

void SlecetSong::menuCloseCallback( CCObject* pSender )
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	CCScene *pScene = HelloWorld::scene();
	pDirector->replaceScene(pScene);
}

void SlecetSong::tempLayer(CCObject* pSender) {
	//SimpleAudioEngine::sharedEngine()->playEffect("music/mode_select_02.wav");
	CCMenuItem* pMenuItem = (CCMenuItem *)(pSender);
	int zIdx = pMenuItem->getZOrder();
	int tIdx = pMenuItem->getTag();
	CCUserDefault::sharedUserDefault()->setStringForKey("songName",songsName[zIdx]);
	CCUserDefault::sharedUserDefault()->flush();
	SongSingleton::getInstance()->g_info->songName = songsName[zIdx];
	//int selectNum = CCUserDefault::sharedUserDefault()->getIntegerForKey("key")
	int selectNum = SongSingleton::getInstance()->g_info->key;
	CCDirector* pDirector = CCDirector::sharedDirector();
	if (selectNum == 4)
	{
		CCScene *pScene = Game4Key::scene();
		pDirector->replaceScene(pScene);
	}
	if (selectNum == 5)
	{
		CCScene *pScene = Game5Key::scene();
		pDirector->replaceScene(pScene);
	}	
	if (selectNum == 6)
	{
		CCScene *pScene = Game6Key::scene();
		pDirector->replaceScene(pScene);
	}
	// run
}

bool SlectSongTable::init()
{
	if ( !CCLayer::init() )  
	{  
		return false;  
	}  


	CCSize visibSize=CCDirector::sharedDirector()->getVisibleSize();  

	CCTableView *tableView=CCTableView::create(this, CCSizeMake(visibSize.width/2, visibSize.height/2));  

	tableView->setDirection(kCCScrollViewDirectionVertical);  

	tableView->setPosition(CCPointZero);  

	// tableView->setAnchorPoint(ccp(0, 0));  
	tableView->setDelegate(this);  

	tableView->setVerticalFillOrder(kCCTableViewFillTopDown);  

	this->addChild(tableView,1);  

	tableView->reloadData();  
	return true;
}

unsigned int SlectSongTable::numberOfCellsInTableView(CCTableView *table)
{

	return SongSingleton::getInstance()->ssmap->size();


}

CCTableViewCell* SlectSongTable::tableCellAtIndex(CCTableView *table, unsigned int idx)
{

	CCLOG("%d",idx);
	//CCString *nameString=CCString::createWithFormat("icon_%d.png",idx+1); 
	string nameString = SongSingleton::getInstance()->songNameVec[idx];
	CCTableViewCell *cell = table->dequeueCell();

	if (!cell) {

		cell = new CCTableViewCell();

		cell->autorelease();
		CCSprite *bgSprite = CCSprite::createWithSpriteFrameName("nandu.png");
		bgSprite->setAnchorPoint(CCPointZero);
		bgSprite->setPosition(CCPointZero);
		bgSprite->setTag(789);
		cell->addChild(bgSprite);


		CCSprite *iconSprite = CCSprite::createWithSpriteFrameName("d1.png");
		//iconSprite->setScale(0.6);
		iconSprite->setAnchorPoint(CCPointZero);
		iconSprite->setPosition(ccp(25, 10));
		iconSprite->setTag(123);
		cell->addChild(iconSprite);


		CCLabelTTF *pLabel = CCLabelTTF::create(nameString.c_str(), "Arial", 20.0);
		pLabel->setPosition(ccp(200, 10));
		pLabel->setTag(456);
		pLabel->setAnchorPoint(CCPointZero);
		cell->addChild(pLabel);
	}
	else
	{

		//创建了就不需要再重新创建了，不然你会发现图片跟文字都不对
		CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("nandu.png");

		CCSprite *pSprite=(CCSprite *)cell->getChildByTag(123);

		pSprite->setTexture(aTexture);


		CCLabelTTF *pLabel = (CCLabelTTF*)cell->getChildByTag(456);
		pLabel->setString(nameString.c_str());



		// this->scrollBar(table);

	}


	return cell;


}


CCSize SlectSongTable::cellSizeForTable(CCTableView *table)
{


	CCSize visibSize=CCDirector::sharedDirector()->getVisibleSize();

	return CCSizeMake(visibSize.width/2, 84);


}

void SlectSongTable::tableCellHighlight(CCTableView *table, CCTableViewCell *cell)
{

	CCLOG("wwww");
	//CCTextureCache::sharedTextureCache()-
	//CCTexture2D *aTexture1= CCTextureCache::sharedTextureCache()->textureForKey("nandu1.png");
	//CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("nandu1.png");

	//CCSprite *pSprite=(CCSprite *)cell->getChildByTag(789);

	//pSprite->setTexture(aTexture);


}

void SlectSongTable::tableCellUnhighlight(CCTableView *table, CCTableViewCell *cell)
{


	CCLOG("dddd");


	//CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("nandu.png");

	//CCSprite *pSprite=(CCSprite *)cell->getChildByTag(789);

	//pSprite->setTexture(aTexture);



}


void SlectSongTable::tableCellTouched(CCTableView *table, CCTableViewCell *cell)
{


	CCLog("cell touched at index: %i", cell->getIdx());
	SongSingleton::getInstance()->g_info->songName = SongSingleton::getInstance()->songNameVec[cell->getIdx()];
	if (SongSingleton::getInstance()->g_info->key ==4)
	{
		CCDirector::sharedDirector()->replaceScene(Game4Key::scene());
	}
	if (SongSingleton::getInstance()->g_info->key ==5)
	{
		CCDirector::sharedDirector()->replaceScene(Game5Key::scene());
	}

	if (SongSingleton::getInstance()->g_info->key ==6)
	{
		CCDirector::sharedDirector()->replaceScene(Game6Key::scene());
	}

	

}

cocos2d::CCScene* SlectSongTable::scene()
{
	CCScene *scene = CCScene::create();
	SlectSongTable *layer = SlectSongTable::create();
	scene->addChild(layer);
	return scene;
}

