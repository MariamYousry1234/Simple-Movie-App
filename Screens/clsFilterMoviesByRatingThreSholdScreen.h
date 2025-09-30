#pragma once

#include <iostream> 
#include"Screens/clsScreen.h"
#include"Libraries/clsInputValidate.h"
#include"Objects/clsMovie.h"
#include<iomanip>
using namespace std;

class clsFilterMoviesByRatingThreSholdScreen :protected clsScreen
{
	static float _ReadRatingThreshold()
	{
		cout << "\nEnter The Rating Threshold: ";
		float Rating =
			clsInputValidate::ReadNumberBetween<float>(1, 10, "Enter a number between 1 and 10: ");
			
		return Rating;
	}

	static void _ShowMovieDetails(clsMovie Movie)
	{
		cout << setw(15) << left << Movie.Name <<
			setw(10) << left << to_string(Movie.Year)
			<< setw(10) << left << to_string(Movie.Rating) << endl;
	}
public:
	static void ShowFilterMoviesByRatingThreSholdScreen()
	{
		_DrawScreenHeader("Filter Movies By Rating ThreShold");

		float RatingThreshold = _ReadRatingThreshold();

		vector<clsMovie>vMovies = clsMovie::GetMoviesRatingThreshold(RatingThreshold);

		if (vMovies.size() == 0)
		{
			cout << "\n\nThere is No movies with rating above " << RatingThreshold << endl;
			return;
		}

		cout << "\n\nMovies with rating above " << RatingThreshold << " :" << endl;
		cout << "\n\n" << setw(15) << left << "Name" << setw(10) << left << "Year" << setw(10) << left << "Rating";
		cout << "\n________________________________________________\n";

		for (clsMovie& M : vMovies)
		{
		  _ShowMovieDetails(M);
		
		}
		cout << "________________________________________________\n";
		cout << "Total = " << vMovies.size() << " movie(s)" << endl;
	}
};

