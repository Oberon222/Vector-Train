#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Time
{
	short hours;
	short minutes;
	short seconds;

	Time() { }
	Time(short hours, short minutes, short seconds) : 
		hours(hours), minutes(minutes), seconds(seconds) { }
};

class Train
{
	int numberTrain;
	Time departureTime; // час відправлення
	string destination; // пункт призначення


public:
	Train(Time departureTime)
	{
		 numberTrain = 0;
		 this->departureTime = departureTime;
		 destination = " ";

	}

	Train(int number, Time departureTime, string destination) 
	{
		 this->numberTrain = number;
		 this->departureTime = departureTime;
		 this->destination = destination;


	}

	void SetTime(short hours, short minutes, short seconds)
	{
		this->departureTime.hours = hours;
		this->departureTime.minutes = minutes;
		this->departureTime.seconds = seconds;
	}

	int GetDepartureTimeHours()
	{
		return this->departureTime.hours;
	}

	int GetDepartureTimeMinutes()
	{
		return this->departureTime.minutes;
	}

	int GetDepartureTimeSeconds()
	{
		return this->departureTime.seconds;
	}

	Time GetDepartureTime()
	{
		return departureTime;
	}

	int GetNumberTrain()
	{
		return this->numberTrain;
	}

	string GetDestination()
	{
		return this->destination;
	}

	void ShowTrainInfo()const
	{
		cout << "Train number: " << numberTrain << endl;
		cout << "Departure time: " << departureTime.hours<<"_"<< departureTime.minutes<<"_"<< departureTime.seconds << endl;
		cout << "Destination: " << destination << endl;
	}

	void ShowDepartureTime()const
	{
		cout << departureTime.hours << ": " << departureTime.minutes << ": " << departureTime.seconds << endl;
	}

	
	 
};


