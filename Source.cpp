#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Train.h"
#include"Railway.h"
using namespace std;

int main()
{

	Train tr1(5, {12,17,33},"London");
	Train tr2(8, { 15,23,11},"London");
	Train tr3(9, { 3,47,7 }, "Berlin");

	Railway rw;
	rw.AddToSystem(tr1);
	rw.AddToSystem(tr2);
	rw.AddToSystem(tr3);
	//rw.ShowInfoRailway();
	
	rw.EditTime(9, 4,48,9);
	//rw.ShowInfoRailway();
	//rw.Save();
	//rw.Load();

	rw.SortingVectorTrains();
	rw.ShowInfoRailway();
	

	system("pause");
	return 0;
}