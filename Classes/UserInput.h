#ifndef __USER_INPUT_H__
#define __USER_INPUT_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class UserInputScene : public cocos2d::CCLayer,cocos2d::extension::CCEditBoxDelegate
{
public:

	virtual bool init();

	static cocos2d::CCScene* scene();

	CREATE_FUNC(UserInputScene);

	virtual void editBoxEditingDidBegin(CCEditBox* editBox) ;  
	virtual void editBoxEditingDidEnd(CCEditBox* editBox) ;  
	virtual void editBoxTextChanged(CCEditBox* editBox, const std::string& text) ;  
	virtual void editBoxReturn(CCEditBox* editBox) ;  


	void startGame(CCObject* pSender);
	//void startGame(CCObject* pSender,TouchEventType type);
protected:
private:

	cocos2d::extension::CCEditBox* m_pEditName;
	cocos2d::extension::CCEditBox* m_pEditPassword;

};
#endif