#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Train.h"
#include<fstream>
using namespace std;

class Railway 
{
	vector<Train> trains;
	friend ofstream& operator<<(ofstream& of, const Railway& rw);
	//friend ifstream& operator>>(ifstream& ifs, Railway& rw);

	public:
	Railway()
	{ }

	void AddToSystem(Train other)
	{
		trains.push_back(other);
	}

	void ShowInfoRailway()
	{
		for (int i=0;i< trains.size();i++)
		{
			trains[i].ShowTrainInfo();
		}
	}

	void ShowTrainInfoByNumber(int numberTrain)
	{
		for (int i = 0; i < trains.size(); i++)
		{
			if (trains[i].GetNumberTrain() == numberTrain)
			{
				trains[i].ShowTrainInfo();
			}
		}
	}

	void EditTime(int numberTrain, short myHours,short myMinutes, short mySecnds)
	{
		for (int i = 0; i < trains.size(); i++)
		{
			if (trains[i].GetNumberTrain() == numberTrain)
			{
				trains[i].SetTime(myHours, myMinutes, mySecnds);
			}
		}
	}

	void SortingVectorTrains()
	{
		for (int i = 0; i < trains.size()-1; i++)
		{
			for (int j = 0; j < trains.size() - 1; j++)
			{
				if (trains[j].GetDepartureTimeHours() > trains[j + 1].GetDepartureTimeHours())
				{
					Train tmp = trains[j];
					trains[j] = trains[j + 1];
					trains[j + 1] = tmp;
				}
			}
		}
	}

	void SearchTrainByDestination(string destination)
	{

		for (int i = 0; i < trains.size(); i++)
		{
			
			if (trains[i].GetDestination() == destination)
			{
				trains[i].ShowTrainInfo();
			}
		}
	}

	/*void Save()const
	{
		ofstream fout("Railway.bin", ios_base::out | ios_base::binary);
		fout.write((char*)&this->trains, sizeof(trains));
		fout.close();
	}*/



	/*void Load()
	{
		ifstream fin("Railway.bin", ios_base::in | ios_base::binary);
		fin.read((char*)&this->trains, sizeof(trains));
		fin.close();
	}*/


};

ofstream& operator<<(ofstream& fout, const Railway& rw)
{
	for (int i = 0; i < rw.trains.size(); i++)
	{
		fout << rw.trains[i].GetNumberTrain();
		fout << rw.trains[i].GetDepartureTimeHours();
		fout << rw.trains[i].GetDepartureTimeMinutes();
		fout << rw.trains[i].GetDepartureTimeSeconds();
		fout << rw.trains[i].GetDestination();
	}
	
}

//ifstream& operator>>(ifstream& ifs, Railway& rw)
//{
//
//}


