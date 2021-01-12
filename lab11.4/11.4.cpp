#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Price
	{
		string product;
		string shop;
		int cost;
	};

void inputData(string filename)
{
	Price* first = new Price();
	ofstream fout(filename);
	char ch;
	string s, p;
	int c;
	do
	{
		cout << "enter product: "; getline(cin, p);
		first->product = p;
		cout << "enter shop: "; getline(cin, s);
		first->shop = s;
		cout << "enter cost: "; cin >> c;
		first->cost = c;
		char delimiter = ';';
		fout << first->product << delimiter << first->shop << delimiter << first->cost << endl;
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void sortFile (string fname, string gname) 
{
	ofstream g(gname);
	string s, mins, z = "";
	int k;
	do
	{
		k = 0;
		ifstream f(fname);
		while (getline(f, s))
		{
			if (s <= z)
				continue;
			mins = s;
			k++;
			break;
		}
		while (getline(f, s))
		{
			if (s <= z)
				continue;
			if (s < mins)
			{
				mins = s;
				k++;
			}
		}
		z = mins;
		if (k > 0)
			g << z << endl;
		f.close();
	} while (k > 0);
}

void getProductsByShop(string shopName, string filename)
{
	ifstream fin(filename);
	string line;
	bool shopExists = false;
	while (getline(fin, line))
	{
		if (line.find(shopName) != string::npos) {
			cout << line << endl;
			shopExists = true;
		}
	}
	if (!shopExists) {
		cout << "There is no shop by such a name. Try again";
	}
}

int main()
{
	inputData("dataWithStructure.txt");
	sortFile("dataWithStructure.txt", "sortedFile.txt");
	string shop;
	cout << "Enter the shop's name" << endl; cin >> shop;
	getProductsByShop(shop, "sortedFile.txt");

	return 0;
}