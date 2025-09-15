#pragma once
#include <iostream> 
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsMovie.h"
#include<iomanip>
#include<queue>
#include<stack>
using namespace std;


class clsSortMoviesByRatingScreen :protected clsScreen
{
	enum enSortingOrder { Ascending = 1, Decending = 2 };

	static enSortingOrder _ReadSortingOrder()
	{
		
		cout << "\nChoose Sorting Order:\n1.Ascending (Low to High).\n2.Descending (High to Low)\n";
		short Num= clsInputValidate::ReadNumber<short>();

		return (enSortingOrder)Num;
	}

	static void _ShowMovieDetails(clsMovie Movie)
	{
		cout << setw(15) << left << Movie.Name <<
			setw(10) << left << to_string(Movie.Year)
			<< setw(10) << left << to_string(Movie.Rating) << endl;
	}


public:
	static void ShowSortMoviesByRatingScreen()
	{
		_DrawScreenHeader("Sort Movies By Rating");

	
		enSortingOrder SortingOrder = _ReadSortingOrder();

		cout << "\n\n" << setw(15) << left << "Name" << setw(10) << left << "Year" << setw(10) << left << "Rating";
		cout << "\n________________________________________________\n";

		if (SortingOrder == enSortingOrder::Ascending)
		{
			queue<clsMovie>Movies = clsMovie::AscendingMoviesByRating();

			if (Movies.empty())
			{
				cout << "\nNo movies available to sort..\n";
				return;
			}


			while (!Movies.empty())
			{
				_ShowMovieDetails(Movies.front());
				Movies.pop();
			}
		}
		else
		{
			stack<clsMovie>Movies = clsMovie::DscendingMoviesByRating();

			if (Movies.empty())
			{
				cout << "\nNo movies available to sort..\n";
				return;
			}

			while (!Movies.empty())
			{
				_ShowMovieDetails(Movies.top());
				Movies.pop();
			}
		}


		cout << "\n________________________________________________\n";
	}
	
};

