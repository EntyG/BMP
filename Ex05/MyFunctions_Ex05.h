#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string findFileName(const string path);
void findSource(const string& path, string*& source, int& n);
void mergeFile(const int& n, string*& source, const string& destination);