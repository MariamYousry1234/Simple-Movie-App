#pragma once
#include <iostream> 
#include"Screens/clsScreen.h"
#include"Libraries/clsInputValidate.h"
#include"Objects/clsMovie.h"
#include<iomanip>
using namespace std;

class clsDeleteMovieScreen:protected clsScreen
{ 
	static string _ReadMoviesName()
	{
		cout << "\nEnter movie name: ";
		string MovieName= clsInputValidate::ReadString();

		while (!clsMovie::IsMovieExist(MovieName))
		{
			cout << "\nThe Movie is Not Found-(\nEnter Another Movie Name To Delete: ";
			MovieName = clsInputValidate::ReadString();
		}

		return MovieName;
	}

	static void _ShowMovieDetails(clsMovie Movie)
	{
		cout << "\nThere is Movie Details:\n\n";
		cout << setw(15) << left << "Name" << setw(10) << left << "Year" << setw(10) << left << "Rating";
		cout << "\n________________________________________________\n";

		cout << setw(15) << left << Movie.Name <<
			setw(10) << left << to_string(Movie.Year)
			<< setw(10) << left << to_string(Movie.Rating) << endl;
		cout << "\n________________________________________________\n";
	}
public:
	static void ShowDeleteMovieScreen()
	{
		_DrawScreenHeader("Delete Movie Screen");

		string MovieName = _ReadMoviesName();

		clsMovie Movie = clsMovie::Find(MovieName);

		_ShowMovieDetails(Movie);

		cout << "\n\nAre You sure You want to delete this Movie?(Y/N)? ";
		char ToDelete = 'y';
		cin >> ToDelete;

		if (tolower(ToDelete) == 'y')
		{
			if (Movie.Delete())
				cout << "\nMovie Deleted Successfully...";
			
			else
				cout << "\nError,Movie didn't Delete";
		
		}
	}
};

