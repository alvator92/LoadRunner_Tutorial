Action()
{
		char foo[50];

	lr_think_time(5);

	lr_start_transaction("Find_flight");

	web_url("Search Flights Button", 
		"URL=http://{URL}:{Port}/cgi-bin/welcome.pl?page=search", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t16.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("nav.pl_3", 
		"URL=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t17.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("reservations.pl", 
		"URL=http://{URL}:{Port}/cgi-bin/reservations.pl?page=welcome", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t18.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	web_concurrent_start(NULL);

	web_url("in_flights.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/in_flights.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t19.inf", 
		LAST);

	web_url("home.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/home.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t20.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_url("button_next.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/button_next.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t21.inf", 
		LAST);

	//web_set_sockets_option("SSL_VERSION", "2&3");

	//lr_think_time(20);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=type=\"radio\" name=\"outboundFlight\" value=\"",
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Flight departing from",
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=type=\"radio\" name=\"returnFlight\" value=\"",
		LAST);
	
	web_reg_save_param_ex(
    "ParamName=outboundFlight", 
    "LB/IC=type=\"radio\" name=\"outboundFlight\" value=\"",
    "RB/IC=\"",
    "Ordinal=all",
    SEARCH_FILTERS,
        "Scope=body",
	LAST);
	
	web_reg_save_param_ex(
    "ParamName=returnFlight", 
    "LB/IC=type=\"radio\" name=\"returnFlight\" value=\"",
    "RB/IC=\"",
    "Ordinal=all",
    SEARCH_FILTERS,
        "Scope=body",
	LAST);


	web_submit_data("reservations.pl_2", 
		"Action=http://{URL}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t22.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={dateDepart}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		"Name=returnDate", "Value={dateReturn}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=54", ENDITEM, 
		"Name=findFlights.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("Find_flight",LR_AUTO);

	lr_think_time(15);

	lr_start_transaction("booking_Flight");
	
	
	lr_save_string(lr_paramarr_random("outboundFlight"),"RandomParam");
	
	lr_message(lr_eval_string("My param value = {RandomParam}"));
	
	lr_save_string(lr_paramarr_random("returnFlight"),"RandomParamReturn");
	
	lr_message(lr_eval_string("My param value = {RandomParamReturn}"));
	
	web_submit_data("reservations.pl_3", 
		"Action=http://{URL}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/reservations.pl", 
		"Snapshot=t23.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={RandomParam}", ENDITEM, 
		"Name=returnFlight", "Value={RandomParamReturn}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=reserveFlights.x", "Value=46", ENDITEM, 
		"Name=reserveFlights.y", "Value=4", ENDITEM, 
		LAST);

	lr_end_transaction("booking_Flight",LR_AUTO);

	lr_think_time(20);

	lr_start_transaction("Payment");

	web_submit_data("reservations.pl_4", 
		"Action=http://{URL}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/reservations.pl", 
		"Snapshot=t24.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={Lastname}", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value={FirstName} {Lastname}", ENDITEM, 
		"Name=creditCard", "Value={card}", ENDITEM, 
		"Name=expDate", "Value={exp_date}", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=outboundFlight", "Value={RandomParam}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value={RandomParamReturn}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=33", ENDITEM, 
		"Name=buyFlights.y", "Value=6", ENDITEM, 
		LAST);

	web_url("bookanother.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/bookanother.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/reservations.pl", 
		"Snapshot=t25.inf", 
		LAST);

	lr_end_transaction("Payment",LR_AUTO);

	lr_think_time(15);

	lr_start_transaction("itenary");

	web_url("Itinerary Button", 
		"URL=http://{URL}:{Port}/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t26.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("nav.pl_4", 
		"URL=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t27.inf", 
		"Mode=HTTP", 
		LAST);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=name=\"flightID\" value=\"",
		LAST);
	
	web_reg_save_param_ex(
    "ParamName=flightID", 
    "LB/IC=name=\"flightID\" value=\"",
    "RB/IC=\"",
    "Ordinal=1",
    SEARCH_FILTERS,
        "Scope=body",
	LAST);
	
//	Есть вопрос в этом месте.
//	web_reg_save_param_ex(
//    "ParamName=cgifields", 
//    "LB/IC=cgifields\" value=\"",
//    "RB/IC=\"",
//    "Ordinal=1",
//    SEARCH_FILTERS,
//        "Scope=body",
//	LAST);


	web_url("itinerary.pl", 
		"URL=http://{URL}:{Port}/cgi-bin/itinerary.pl", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t28.inf", 
		"Mode=HTTP", 
		LAST);
		

	web_concurrent_end(NULL);

	web_url("in_itinerary.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/in_itinerary.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t29.inf", 
		LAST);

	web_concurrent_start(NULL);

	web_url("cancelallreservations.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/cancelallreservations.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/itinerary.pl", 
		"Snapshot=t30.inf", 
		LAST);

	web_url("cancelreservation.gif", 
		"URL=http://{URL}:{Port}/WebTours/images/cancelreservation.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=http://{URL}:{Port}/cgi-bin/itinerary.pl", 
		"Snapshot=t31.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("itenary",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("cancel");
	
	web_reg_find("Text=No flights",
	             LAST);


	web_submit_data("itinerary.pl_2", 
		"Action=http://{URL}:{Port}/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/itinerary.pl", 
		"Snapshot=t32.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=flightID", "Value={flightID}", ENDITEM, 
		//"Name=flightID", "Value=", ENDITEM,
		"Name=.cgifields", "Value=1", ENDITEM,
		//"Name=.cgifields", "Value=2", ENDITEM,		
		"Name=removeAllFlights.x", "Value=44", ENDITEM, 
		"Name=removeAllFlights.y", "Value=9", ENDITEM, 
		LAST);
	
	

	lr_end_transaction("cancel",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("home");

	web_url("Home Button", 
		"URL=http://{URL}:{Port}/cgi-bin/welcome.pl?page=menus", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t33.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("nav.pl_5", 
		"URL=http://{URL}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t34.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("login.pl_3", 
		"URL=http://{URL}:{Port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{Port}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t35.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("home",LR_AUTO);

	lr_think_time(5);


	return 0;
}