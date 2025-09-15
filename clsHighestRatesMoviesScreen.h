#pragma once
#include <iostream> 
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsMovie.h"
#include<iomanip>

using namespace std;


class clsHighestRatesMoviesScreen :protected clsScreen
{
	static void _ShowMovieDetails(clsMovie Movie)
	{
		cout << setw(15) << left << Movie.Name <<
			setw(10) << left << to_string(Movie.Year)
			<< setw(10) << left << to_string(Movie.Rating) << endl;
	}


public:
	static void ShowHighestRatesMoviesScreen()
	{
		_DrawScreenHeader("Highest Rates Movies");

		
		vector<clsMovie>vMovies = clsMovie::MoviesMaxRating();

		if (vMovies.size()==0)
		{
			cout << "\nThere is No Movies To show it";
			return;
		}

		cout << "\n\nHigest Rated Movies is:\n\n";
		cout << setw(15) << left << "Name" << setw(10) << left << "Year" << setw(10) << left << "Rating";
		cout << "\n________________________________________________\n";

		for (clsMovie& M : vMovies)
		{
			_ShowMovieDetails(M);
		}

		cout << "\n________________________________________________\n";
	}
};

