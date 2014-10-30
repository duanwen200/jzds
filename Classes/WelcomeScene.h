#ifndef __WELCOME_SCENE_H__
#define __WELCOME_SCENE_H__
#include "cocos2d.h"
#include "cocos-ext.h"
#include <string>
USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

class WelcomeScene : public cocos2d::CCLayer,cocos2d::extension::CCEditBoxDelegate
{
public:
	WelcomeScene();
	~WelcomeScene();

	static cocos2d::CCScene* scene();

	bool init();

	CREATE_FUNC(WelcomeScene);

	void playWithQQ(CCObject* pSender);
	void playWithWeixin(CCObject* pSender);

	void amation(float dt);

	virtual void editBoxEditingDidBegin(CCEditBox* editBox) ;  
	virtual void editBoxEditingDidEnd(CCEditBox* editBox) ;  
	virtual void editBoxTextChanged(CCEditBox* editBox, const std::string& text) ;  
	virtual void editBoxReturn(CCEditBox* editBox) ;  
private:

	cocos2d::extension::CCEditBox* m_pEditName;
	cocos2d::extension::CCEditBox* m_pEditPassword;
};



#endif