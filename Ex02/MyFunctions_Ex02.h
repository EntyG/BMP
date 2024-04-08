#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct  Date
{
	int day;
	int month;
	int year;
};

void saveDateArr();
void loadDateArr();