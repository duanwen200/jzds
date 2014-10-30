#ifndef  _APP_rhythmInterface_H_
#define  _APP_rhythmInterface_H_

/*
������Ҫ��Ӽ���������ʱ�����
*/
#include <curl/curl.h>
#include "GBKToUTF8.h"

#define HTTP_URL_OF_activityinfo   "http://www.changesfly.com/game/rhythm/activityinfo.php"
#define HTTP_URL_OF_userinfo   "http://www.changesfly.com/game/rhythm/userinfo.php"
#define HTTP_URL_OF_ranking   "http://www.changesfly.com/game/rhythm/ranking.php"
#define HTTP_URL_OF_mall   "http://www.changesfly.com/game/rhythm/mall.php"
#define HTTP_URL_OF_purchase   "http://www.changesfly.com/game/rhythm/purchase.php"
#define HTTP_URL_OF_reward   "http://www.changesfly.com/game/rhythm/reward.php"
#define HTTP_URL_OF_checkpoints   "http://www.changesfly.com/game/rhythm/checkpoints.php"
#define HTTP_URL_OF_clearance   "http://www.changesfly.com/game/rhythm/clearance.php"
#define HTTP_URL_OF_tasklist   "http://www.changesfly.com/game/rhythm/tasklist.php"
#define HTTP_URL_OF_musiclist   "http://www.changesfly.com/game/rhythm/musiclist.php"
#define HTTP_URL_OF_itemlist   "http://www.changesfly.com/game/rhythm/itemlist.php"
#define HTTP_URL_OF_useritemlist   "http://www.changesfly.com/game/rhythm/useritemlist.php"

using namespace std;

class rhythmInterface
{
public:
	rhythmInterface(void);
	~rhythmInterface(void);

	std::string activityinfo(std::string page);
    std::string userinfo(std::string Username,std::string Userpass,std::string Userfrom);
    std::string ranking(std::string Userid,std::string Type);
	std::string mall(std::string Userid,std::string Type,std::string Number);
    std::string purchase(std::string Userid,std::string Paytype,std::string Paynumber,std::string Buytype,std::string Itemid,std::string Buynumber);
    std::string reward(std::string Userid,std::string Type,std::string Itemid,std::string ItemCount);
	std::string checkpoints(std::string Userid);
    std::string clearance(	std::string Userid,std::string Type,std::string Checkpoint,std::string Score,
										std::string Figureid,std::string Itemid,std::string Perfectnumber,std::string Goodnumber,
										std::string Missnumber,std::string Hitsuquence);
    std::string tasklist(std::string Userid);
	std::string musiclist(std::string Userid,std::string Type);
	std::string itemlist(std::string Listtype,std::string Page);
	std::string useritemlist(std::string Userid,std::string Type);

	std::string getdata(std::string url,unsigned int _connectionTimeout);
};

#endif // _APP_rhythmInterface_H_
