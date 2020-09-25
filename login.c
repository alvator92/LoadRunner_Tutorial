login()
{
	
	lr_start_transaction("Open_webTour");

	web_url("WebTours", 
		"URL=http://{URL}:{Port}/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("header.html", 
		"URL=http://{URL}:{Port}/WebTours/header.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/WebTours/", 
		"Snapshot=t2.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("welcome.pl", 
		"URL=http://{URL}:{Port}/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/WebTours/", 
		"Snapshot=t3.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("hp_logo.png", 
		"URL=http://{URL}:{Port}/WebTours/images/hp_logo.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=http://{URL}:{Port}/WebTours/header.html", 
		"Snapshot=t4.inf", 
		LAST);

	web_url("webtours.png", 
		"URL=http://{URL}:{Port}/WebTours/images/webtours.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=http://{URL}:{Port}/WebTours/header.html", 
		"Snapshot=t5.inf", 
		LAST);

	web_concurrent_end(NULL);
	
	

	web_concurrent_start(NULL);

	web_url("home.html", 
		"URL=http://{URL}:{Port}/WebTours/home.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t6.inf", 
		"Mode=HTTP", 
		LAST);

	web_reg_save_param("USER_SESSION",
	    "LB=name=\"userSession\" value=\"", 
	    "RB=\"", 
	    LAST);
	
	web_url("nav.pl", 
		"URL=http://{URL}:{Port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t7.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	web_url("mer_login.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/mer_login.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t8.inf", 
		LAST);
	
	lr_end_transaction("Open_webTour", LR_AUTO);

//	lr_think_time(10);

	lr_start_transaction("login");

	web_submit_data("login.pl", 
		"Action=http://{URL}:{Port}/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t9.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=userSession", "Value={USER_SESSION}", ENDITEM, //129664.458647226zzzQzVfpfQVzzzzHtAAVHpzQDff
		"Name=username", "Value={login_pass}", ENDITEM, 
		"Name=password", "Value={pass}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=39", ENDITEM, 
		"Name=login.y", "Value=8", ENDITEM, 
		LAST);

	web_concurrent_start(NULL);
		
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Welcome, <b>{login_pass}</b>",
		LAST);

	web_url("login.pl_2", 
		"URL=http://{URL}:{Port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/login.pl", 
		"Snapshot=t10.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_2", 
		"URL=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/login.pl", 
		"Snapshot=t11.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("in_home.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/in_home.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t12.inf", 
		LAST);

	web_url("signoff.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/signoff.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t13.inf", 
		LAST);

	web_url("itinerary.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/itinerary.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t14.inf", 
		LAST);

	web_url("flights.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/flights.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t15.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("login",LR_AUTO);
	
	
	return 0;
}
