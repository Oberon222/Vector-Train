#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct Time
{
	short hours;
	short minutes;
	short seconds;

	Time() : hours(0), minutes(0), seconds(0) { }

	Time(short hours, short minutes, short seconds) : 
		hours(hours), minutes(minutes), seconds(seconds) { }
};

class Train
{
	int numberTrain;
	Time departureTime; // час відправлення
	string destination; // пункт призначення

	friend ofstream& operator<<(ofstream& of, const Train& rw);
	friend ifstream& operator>>(ifstream& ifs, Train& rw);


public:
	Train() { }

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

	int GetDepartureTimeHours() const
	{
		return this->departureTime.hours;
	}

	void SetDepartureTimeHours(short hours)
	{
		this->departureTime.hours = hours;
	}

	void SetDepartureTimeMinutes(short minutes)
	{
		this->departureTime.minutes = minutes;
	}

	int GetDepartureTimeMinutes()const
	{
		return this->departureTime.minutes;
	}

	int GetDepartureTimeSeconds()const
	{
		return this->departureTime.seconds;
	}

	void SetDepartureTimeSeconds(short seconds)
	{
		this->departureTime.seconds = seconds;
	}

	Time GetDepartureTime()const
	{
		return departureTime;
	}

	int GetNumberTrain()const
	{
		return this->numberTrain;
	}

	string GetDestination()const
	{
		return this->destination;
	}

	void ShowTrainInfo()const
	{
		cout << "Train number: " << numberTrain << endl;
		cout << "Departure time: " << departureTime.hours<<"_"<< departureTime.minutes<<"_"<< departureTime.seconds << endl;
		cout << "Destination: " << destination << endl;
	}

	

	 
};

ofstream& operator<<(ofstream& fout, const Train& tr)
{
	fout << tr.numberTrain;
	fout << tr.departureTime.hours;
	fout << tr.departureTime.minutes;
	fout << tr.departureTime.seconds;
	fout << tr.destination;

	return fout;
}

ifstream& operator>>(ifstream& fin, Train& rw)
{
	Train buff1;
	fin >> buff1.numberTrain;
	fin >> buff1.departureTime.hours;
	fin >> buff1.departureTime.minutes;
	fin >> buff1.departureTime.seconds;
	fin >> buff1.destination;

	return fin;
}






