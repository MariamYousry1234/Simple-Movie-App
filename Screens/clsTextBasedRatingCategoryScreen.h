#pragma once
#include <iostream> 
#include"Screens/clsScreen.h"
#include"Libraries/clsInputValidate.h"
#include"Objects/clsMovie.h"
#include<iomanip>

using namespace std;


class clsTextBasedRatingCategoryScreen :protected clsScreen
{
	static string _StringCategory(float Rating)
	{
		if (Rating >= 0 && Rating <= 3)
			return "Terrible";

		if (Rating <= 5)
			return "Poor";

		if (Rating <= 6)
			return "Average";

		if (Rating <= 8)
			return "Good";

		if (Rating <= 10)
			return "Excellent";
	}

	static void _ShowMovieDetailsWithCategory(clsMovie Movie)
	{
		cout << setw(15) << left << Movie.Name <<
			setw(13) << left << to_string(Movie.Rating)
			<< setw(10) << left << _StringCategory(Movie.Rating) << endl;
	}


public:
	static void ShowTextBasedRatingCategoryScreen()
	{
		_DrawScreenHeader("Text Based Rating Category");

		vector<clsMovie>vMovies = clsMovie::GetMoviesList();


		if (vMovies.size() == 0)
		{
			cout << "\nThere is No Movies yet..";
			return;
		}

		cout << "_______________________________________\n";
		cout << setw(15) << left << "Name" << setw(10) << left << "Rating" << setw(10) << left << "Category";
		cout << "\n_______________________________________\n";


		for (clsMovie& M : vMovies)
		{
			_ShowMovieDetailsWithCategory(M);
		}
		cout << "_______________________________________\n";
	}
};

