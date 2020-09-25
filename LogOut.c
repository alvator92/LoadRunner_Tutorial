LogOut()
{
	
	
	lr_start_transaction("Sign_out");

	web_url("SignOff Button", 
		"URL=http://{URL}:{Port}/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t36.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("home.html_2", 
		"URL=http://{URL}:{Port}/WebTours/home.html", 
		"Resource=0", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t37.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_6", 
		"URL=http://{URL}:{Port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t38.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("Sign_out",LR_AUTO);
	
	return 0;
}
