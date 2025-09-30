#pragma once

#include <iostream> 
#include"Screens/clsScreen.h"
#include"Libraries/clsInputValidate.h"
#include"Objects/clsMovie.h"
#include<iomanip>

using namespace std;

class clsAdditionalMovieStaticsScreen :protected clsScreen
{
	static void _ShowMovieDetails(clsMovie Movie)
	{
		cout << setw(15) << left << Movie.Name <<
			setw(10) << left << to_string(Movie.Year)
			<< setw(10) << left << to_string(Movie.Rating) << endl;
	}

	static void _HighestRatedMovie()
	{
		vector<clsMovie>vHighestRatedMovies = clsMovie::MoviesMaxRating();

		cout << "\n\nHigest Rated Movies is:\n\n";
		cout << setw(15) << left << "Name" << setw(10) << left << "Year" << setw(10) << left << "Rating";
		cout << "\n________________________________________________\n";

		for (clsMovie& M : vHighestRatedMovies)
		{
			_ShowMovieDetails(M);

		}

		cout << "________________________________________________\n";
	}

	static void _LowestRatedMovie()
	{
		vector<clsMovie>vLowestRatedMovies = clsMovie::MoviesMinRating();

		cout << "\n\nLowest Rated Movies is:\n\n";
		cout << setw(15) << left << "Name" << setw(10) << left << "Year" << setw(10) << left << "Rating";
		cout << "\n________________________________________________\n";

		for (clsMovie& M : vLowestRatedMovies)
		{
			_ShowMovieDetails(M);

		}

		cout << "________________________________________________\n";
	}

public:
	static void ShowAdditionalMovieStaticsScreen()
	{
		_DrawScreenHeader("Additional Movie Statics");

		if (clsMovie::GetMoviesList().size() == 0)
		{
			cout << "\nThere is No Movies yet..";
			return;
		}

		cout << "\nTotal Number of Movies is: " << clsMovie::GetMoviesList().size();
		cout << "\nAverage Rating: " << clsMovie::GetAverageRating() << endl;
		_HighestRatedMovie();
		_LowestRatedMovie();


	}
};

