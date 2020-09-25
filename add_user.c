Action()
{
	lr_start_transaction("Start_page");

	web_url("WebTours", 
		"URL=http://{URL}:{Port}/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t27.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("header.html", 
		"URL=http://{URL}:{Port}/WebTours/header.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/WebTours/", 
		"Snapshot=t28.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("welcome.pl", 
		"URL=http://{URL}:{Port}/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/WebTours/", 
		"Snapshot=t31.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("webtours.png", 
		"URL=http://{URL}:{Port}/WebTours/images/webtours.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=http://{URL}:{Port}/WebTours/header.html", 
		"Snapshot=t29.inf", 
		LAST);

	web_url("hp_logo.png", 
		"URL=http://{URL}:{Port}/WebTours/images/hp_logo.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=http://{URL}:{Port}/WebTours/header.html", 
		"Snapshot=t30.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("home.html", 
		"URL=http://{URL}:{Port}/WebTours/home.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t32.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl", 
		"URL=http://{URL}:{Port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t33.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	web_url("mer_login.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/mer_login.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t34.inf", 
		LAST);
	
	lr_end_transaction("Start_page", LR_AUTO);

	lr_think_time(93);

	lr_start_transaction("Sign_up");

	web_url("sign up now", 
		"URL=http://{URL}:{Port}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/WebTours/home.html", 
		"Snapshot=t35.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("profileValidate.js", 
		"URL=http://{URL}:{Port}/WebTours/profileValidate.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=http://{URL}:{Port}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t36.inf", 
		LAST);

	web_url("button_next.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/button_next.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t37.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("Sign_up",LR_AUTO);

	lr_think_time(78);

	lr_start_transaction("Customer_profile");
	
//	web_reg_find("Text=Your username is taken",
//	             LAST);
//
//	web_submit_data("login.pl", 
//		"Action=http://{URL}:{Port}/cgi-bin/login.pl", 
//		"Method=POST", 
//		"RecContentType=text/html", 
//		"Referer=http://{URL}:{Port}/cgi-bin/login.pl?username=&password=&getInfo=true", 
//		"Snapshot=t38.inf", 
//		"Mode=HTTP", 
//		ITEMDATA, 
//		"Name=username", "Value={Username}", ENDITEM, 
//		"Name=password", "Value={pasword}", ENDITEM, 
//		"Name=passwordConfirm", "Value={pasword}", ENDITEM, 
//		"Name=firstName", "Value={Firstname}", ENDITEM, 
//		"Name=lastName", "Value={Lastname}", ENDITEM, 
//		"Name=address1", "Value={Adress}", ENDITEM, 
//		"Name=address2", "Value={CityState}", ENDITEM, 
//		"Name=register.x", "Value=48", ENDITEM, 
//		"Name=register.y", "Value=12", ENDITEM, 
//		LAST);
//
//	lr_think_time(222);
//	
//	web_reg_find("Text=Your password is invalid",
//	             LAST);
//
//	web_submit_data("login.pl_2", 
//		"Action=http://{URL}:{Port}/cgi-bin/login.pl", 
//		"Method=POST", 
//		"RecContentType=text/html", 
//		"Referer=http://{URL}:{Port}/cgi-bin/login.pl", 
//		"Snapshot=t39.inf", 
//		"Mode=HTTP", 
//		ITEMDATA, 
//		"Name=username", "Value={Username}", ENDITEM, 
//		"Name=password", "Value={pasword}", ENDITEM, 
//		"Name=passwordConfirm", "Value={pasword}{pasword}", ENDITEM, 
//		"Name=firstName", "Value={Firstname}", ENDITEM, 
//		"Name=lastName", "Value={Lastname}", ENDITEM, 
//		"Name=address1", "Value={Adress}", ENDITEM, 
//		"Name=address2", "Value={CityState}", ENDITEM, 
//		"Name=register.x", "Value=43", ENDITEM, 
//		"Name=register.y", "Value=8", ENDITEM, 
//		LAST);

	lr_think_time(21);

	web_submit_data("login.pl_3", 
		"Action=http://{URL}:{Port}/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/login.pl", 
		"Snapshot=t40.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=username", "Value={Username}", ENDITEM, 
		"Name=password", "Value={pasword}", ENDITEM, 
		"Name=passwordConfirm", "Value={pasword}", ENDITEM, 
		"Name=firstName", "Value={Firstname}", ENDITEM, 
		"Name=lastName", "Value={Lastname}", ENDITEM, 
		"Name=address1", "Value={Adress}", ENDITEM, 
		"Name=address2", "Value={CityState}", ENDITEM, 
		"Name=register.x", "Value=47", ENDITEM, 
		"Name=register.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("Customer_profile",LR_AUTO);

	lr_think_time(30);

	lr_start_transaction("go_home");

	web_url("button_next.gif_2", 
		"URL=http://{URL}:{Port}/cgi-bin/welcome.pl?page=menus", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/login.pl", 
		"Snapshot=t41.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("login.pl_4", 
		"URL=http://{URL}:{Port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t42.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_2", 
		"URL=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t43.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("in_home.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/in_home.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t44.inf", 
		LAST);

	web_url("itinerary.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/itinerary.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t45.inf", 
		LAST);

	web_url("signoff.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/signoff.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t46.inf", 
		LAST);

	web_url("flights.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/flights.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t47.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_url("Home Button", 
		"URL=http://{URL}:{Port}/cgi-bin/welcome.pl?page=menus", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t48.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("login.pl_5", 
		"URL=http://{URL}:{Port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t49.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_3", 
		"URL=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t50.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("go_home",LR_AUTO);

	lr_think_time(16);


	return 0;
}