#pragma once
#include <iostream> 
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsMovie.h"
#include<iomanip>
using namespace std;

class clsFilterMoviesByYearScreen :protected clsScreen
{
	static short _ReadReleaseYear()
	{
		cout << "\nEnter the movie's release year: ";
		short ReleaseYear= clsInputValidate::ReadNumber<short>();
		
		return ReleaseYear;
	}

	static void _ShowMovieDetails(clsMovie Movie)
	{
		cout << setw(15) << left << Movie.Name <<
			setw(10) << left << to_string(Movie.Year)
			<< setw(10) << left << to_string(Movie.Rating) << endl;
	}

	static void _PrintMoviesByYear(vector<clsMovie>vMovies)
	{
		cout << "\n\n" << setw(15) << left << "Name" << setw(10) << left << "Year" << setw(10) << left << "Rating";
		cout << "\n________________________________________________\n";

		for (clsMovie& M : vMovies)
		{
		
			_ShowMovieDetails(M);
		}

		cout << "\n________________________________________________";
	}

public:
	static void ShowFilterMoviesByYearScreen()
	{
		_DrawScreenHeader("Filter Movies By Year");

		short ReleaseYear = _ReadReleaseYear();

		if (clsMovie::IsYearExist(ReleaseYear))
		{
			vector<clsMovie>vMovies = clsMovie::GetMoviesByYear(ReleaseYear);

			_PrintMoviesByYear(vMovies);
			cout << "\nTotal = " << vMovies.size() << " Movie (s)" << endl;
		}

		else
		{

			cout << "\nNo movies Found for this Year..";
		}

	}
};

