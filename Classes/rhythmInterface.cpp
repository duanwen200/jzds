#include "rhythmInterface.h"


rhythmInterface::rhythmInterface(void)
{
}


rhythmInterface::~rhythmInterface(void)
{
}

std::string rhythmInterface::activityinfo(std::string page){
	std::string urlstr=HTTP_URL_OF_activityinfo ;
	urlstr+=std::string("?")+"pages="+page;
	return getdata(urlstr,3000);
}
std::string rhythmInterface::userinfo(std::string Username,std::string Userpass,std::string Userfrom){
	std::string urlstr=HTTP_URL_OF_userinfo ;
	urlstr+=std::string("?")+"Username="+Username;
	urlstr+=std::string("&")+"Userpass="+Userpass;
	urlstr+=std::string("&")+"Userfrom="+Userfrom;
	return getdata(urlstr,3000);
}
std::string rhythmInterface::ranking(std::string Userid,std::string Type){
	std::string urlstr=HTTP_URL_OF_ranking ;
	urlstr+=std::string("?")+"Userid="+Userid;
	urlstr+=std::string("&")+"Type="+Type;
	return getdata(urlstr,3000);
}
std::string rhythmInterface::mall(std::string Userid,std::string Type,std::string Number){
	std::string urlstr=HTTP_URL_OF_mall ;
	urlstr+=std::string("?")+"Userid="+Userid;
	urlstr+=std::string("&")+"Type="+Type;
	urlstr+=std::string("&")+"Number="+Number;
	return getdata(urlstr,3000);
}
std::string rhythmInterface::purchase(std::string Userid,std::string Paytype,std::string Paynumber,std::string Buytype,std::string Itemid,std::string Buynumber){
	std::string urlstr=HTTP_URL_OF_purchase ;
	urlstr+=std::string("?")+"Userid="+Userid;
	urlstr+=std::string("&")+"Paytype="+Paytype;
	urlstr+=std::string("&")+"Paynumber="+Paynumber;
	urlstr+=std::string("&")+"Buytype="+Buytype;
	urlstr+=std::string("&")+"Itemid="+Itemid;
	urlstr+=std::string("&")+"Buynumber="+Buynumber;
	return getdata(urlstr,3000);
}
std::string rhythmInterface::reward(std::string Userid,std::string Type,std::string Itemid,std::string ItemCount){
	std::string urlstr=HTTP_URL_OF_reward ;
	urlstr+=std::string("?")+"Userid="+Userid;
	urlstr+=std::string("&")+"Type="+Type;
	urlstr+=std::string("&")+"Itemid="+Itemid;
	urlstr+=std::string("&")+"ItemCount="+ItemCount;
	return getdata(urlstr,3000);
}
std::string rhythmInterface::checkpoints(std::string Userid){
	std::string urlstr=HTTP_URL_OF_checkpoints ;
	urlstr+=std::string("?")+"Userid="+Userid;
	return getdata(urlstr,3000);
}
std::string rhythmInterface::clearance(	std::string Userid,std::string Type,std::string Checkpoint,std::string Score,
										std::string Figureid,std::string Itemid,std::string Perfectnumber,std::string Goodnumber,
										std::string Missnumber,std::string Hitsuquence){
	std::string urlstr=HTTP_URL_OF_clearance ;
	urlstr+=std::string("?")+"Userid="+Userid;
	urlstr+=std::string("&")+"Type="+Type;
	urlstr+=std::string("&")+"Checkpoint="+Checkpoint;
	urlstr+=std::string("&")+"Score="+Score;
	urlstr+=std::string("&")+"Figureid="+Figureid;
	urlstr+=std::string("&")+"Itemid="+Itemid;
	urlstr+=std::string("&")+"Perfectnumber="+Perfectnumber;
	urlstr+=std::string("&")+"Goodnumber="+Goodnumber;
	urlstr+=std::string("&")+"Missnumber="+Missnumber;
	urlstr+=std::string("&")+"Hitsuquence="+Hitsuquence;
	return getdata(urlstr,3000);
}
std::string rhythmInterface::tasklist(std::string Userid){
	std::string urlstr=HTTP_URL_OF_tasklist ;
	urlstr+=std::string("?")+"Userid="+Userid;
	return getdata(urlstr,3000);
}
std::string rhythmInterface::musiclist(std::string Userid,std::string Type){
	std::string urlstr=HTTP_URL_OF_musiclist ;
	urlstr+=std::string("?")+"Userid="+Userid;
	urlstr+=std::string("&")+"Type="+Type;
	return getdata(urlstr,3000);
}
std::string rhythmInterface::itemlist(std::string Listtype,std::string Page){
	std::string urlstr=HTTP_URL_OF_itemlist ;
	urlstr+=std::string("?")+"Listtype="+Listtype;
	urlstr+=std::string("&")+"Page="+Page;
	return getdata(urlstr,3000);
}
std::string rhythmInterface::useritemlist(std::string Userid,std::string Type){
	std::string urlstr=HTTP_URL_OF_useritemlist ;
	urlstr+=std::string("?")+"Userid="+Userid;
	urlstr+=std::string("&")+"Type="+Type;
	return getdata(urlstr,3000);
}

static size_t GetRhythmHttpRet(void *ptr, size_t size, size_t nmemb, void *userdata)
{
    string *version = (string*)userdata;
    version->append((char*)ptr, size * nmemb);
    
    return (size * nmemb);
}

std::string rhythmInterface::getdata(std::string url,unsigned int _connectionTimeout){
	
	std::string returnstr;
	CURLcode res;
	CURL *_curl=curl_easy_init();
	
	if (! _curl)
    {
        
        return "can not init curl";
    }
    
	curl_easy_setopt(_curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, GetRhythmHttpRet);
    curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &returnstr);
    
	if (_connectionTimeout) curl_easy_setopt(_curl, CURLOPT_CONNECTTIMEOUT, _connectionTimeout);
    res = curl_easy_perform(_curl);
    
    if (res != 0)
    {
        curl_easy_cleanup(_curl);
    }
	if(res == CURLE_OK){

	}
	else{
		return "";
	}

    GBKToUTF8(returnstr,"GB2312","UTF-8");
	return returnstr;
}
