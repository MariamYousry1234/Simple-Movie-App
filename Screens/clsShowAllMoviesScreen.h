#pragma once
#include <iostream> 
#include"Screens/clsScreen.h"
#include"Objects/clsMovie.h"
#include<iomanip>
using namespace std;

class clsShowAllMoviesScreen :protected clsScreen
{
	static void _ShowMovieDetails(clsMovie Movie)
	{
		cout << setw(15) << left << Movie.Name <<
			setw(10) << left << to_string(Movie.Year)
			<< setw(10) << left << to_string(Movie.Rating) << endl;
	}

public:
	static void ShowAllMoviesScreen()
	{
		vector<clsMovie>vMovies = clsMovie::GetMoviesList();
		string Subtitle = "( " + to_string(vMovies.size()) + ") Movies";
		_DrawScreenHeader("Show All Movies Screen", Subtitle);


		if (vMovies.size() == 0)
		{
			cout << "\nThere is No Movies To show it";
			return;
		}

		cout << setw(15) << left << "Name" << setw(10) << left << "Year" << setw(10) << left << "Rating";
		cout << "\n________________________________________________\n";

		for (clsMovie& M : vMovies)
		{
			_ShowMovieDetails(M);
		}
		cout << "\n________________________________________________";
	}
};

