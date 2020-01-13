#include <string.h>
#include<iostream>
#include<stdio.h>
#include <fstream>
using namespace std;
const int Maxx=135709677;
int arr[Maxx + 5];
int ansArr[Maxx + 1];
int f, s;												//左区间，右区间

int main() 
{

	ifstream myfile("3");
	ofstream outfile("out.txt", ios::trunc);
	int num = 0;
	int k = 0;
	memset(arr, 0, Maxx+5);
	while (myfile >>f>>s&&f!=0)
	{
		if (f > s)	swap(f, s);
		for (int i = f; i <= s; i++)
			arr[i] = 1;
	}
	for (int i = 1; i <= Maxx; i++)
	{
		if ((arr[i - 1] == 1 && arr[i] == 0)||(arr[i] == 0 && arr[i+1] == 1))
			ansArr[num++] = i;
	}
	if (arr[1] == 0)
	{
		outfile << 1 << " ";
		k++;
	}
		
	for (int i = 0; i < num; i++)
	{
		outfile <<ansArr[i]<<" ";
		if ((k + 1) % 2 == 0)
			outfile << endl;
		k++;
	}
	if (arr[Maxx] == 0)
		outfile << Maxx;

	myfile.close();
	outfile.close();
	return 0;
}
