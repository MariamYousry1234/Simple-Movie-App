#pragma once
#include <iostream> 
#include"Screens/clsScreen.h"
#include"Libraries/clsInputValidate.h"
#include"Objects/clsMovie.h"
#include<iomanip>
using namespace std;

class clsSearchMovieByNameScreen :protected clsScreen
{
	static string _ReadMoviesName()
	{
		cout << "\nEnter movie name: ";
		string MovieName= clsInputValidate::ReadString();

		return MovieName;
	}

	static void _ShowMovieDetails(clsMovie Movie)
	{
		cout << "\nThere is Movie Details: " << endl;
		cout << "_______________________\n\n";
		cout << setw(15) << left << "Name" << setw(10) << left << "Year" << setw(10) << left << "Rating";
		cout << "\n________________________________________________\n";

		cout << setw(15) << left << Movie.Name <<
			setw(10) << left << to_string(Movie.Year)
			<< setw(10) << left << to_string(Movie.Rating) << endl;

		cout << "\n________________________________________________\n";
	}

public:
	static void ShowSearchMovieByNameScreen()
	{
		_DrawScreenHeader("Search Movie By Name");

		string MovieName = _ReadMoviesName();

		if (clsMovie::IsMovieExist(MovieName))
		{
			clsMovie Movie = clsMovie::Find(MovieName);

			_ShowMovieDetails(Movie);
			
		}

		else
		{
			cout << "\nMovie is Not Found-(";
		}
	}
};

