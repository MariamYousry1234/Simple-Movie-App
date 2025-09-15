#pragma once

#include <iostream> 
#include"clsInputValidate.h"
#include"clsAddNewMovieScreen.h"
#include"clsDeleteMovieScreen.h"
#include"clsEditMovieScreen.h"
#include"clsShowAllMoviesScreen.h"
#include"clsFilterMoviesByYearScreen.h"
#include"clsFilterMoviesByRatingThreSholdScreen.h"
#include"clsSearchMovieByNameScreen.h"
#include"clsSortMoviesByRatingScreen.h"
#include"clsHighestRatesMoviesScreen.h"
#include"clsShowAverageRatingScreen.h"
#include"clsAdditionalMovieStaticsScreen.h"
#include"clsTextBasedRatingCategoryScreen.h"
using namespace std;

class clsMovieMainMenuScreen
{
	enum enMainMenuOptions {
		eAddNewMovie = 1, eDeleteMovie = 2, eEditMovie = 3, eShowAllMovies = 4, eFilterMoviesByYear = 5,
		eFilterMoviesByRatingThreShold = 6,
		eSearchMovieByName = 7, eSortMoviesByRating = 8, eShowHighestRatesMovies = 9,
		eShowAverageRating = 10, eAdditionalMovieStatics = 11, eTextBasedRatingCategory = 12, eExit = 13
	};

	static short _ReadOption()
	{
			cout << "\n\t\t\tEnter Your Choice: ";
			short num= clsInputValidate::ReadNumberBetween<short>(1,13);

		return num;
	}

	static void GoToTheMainMenu()
	{
		cout << "\n\nPress any Key to go back to Movie Main Menu....";
		system("pause>nul");

		ShowMovieMainMenu();
	}

	static void _ShowAddNewMovieScreen()
	{
		clsAddNewMovieScreen::ShowAddNewMovieScreen();
	}

	static void _ShowDeleteMovieScreen()
	{
		clsDeleteMovieScreen::ShowDeleteMovieScreen();
	}

	static void _ShowEditMovieScreen()
	{
		clsEditMovieScreen::ShowEditMovieScreen();
	}

	static void _ShowAllMoviesScreen()
	{
		clsShowAllMoviesScreen::ShowAllMoviesScreen();
	}
	
	static void _ShowFilterMoviesByYearScreen()
	{
		clsFilterMoviesByYearScreen::ShowFilterMoviesByYearScreen();

	}

	static void _ShowFilterMoviesByRatingThreSholdScreen()
	{
		clsFilterMoviesByRatingThreSholdScreen::
			ShowFilterMoviesByRatingThreSholdScreen();
	}

	static void _ShowSearchMovieByNameScreen()
	{
		clsSearchMovieByNameScreen::ShowSearchMovieByNameScreen();
	}

	static void _ShowSortMoviesByRatingScreen()
	{
		clsSortMoviesByRatingScreen::ShowSortMoviesByRatingScreen();

	}

	static void _ShowHighestRatesMoviesScreen()
	{
		clsHighestRatesMoviesScreen::ShowHighestRatesMoviesScreen();
	}

	static void _ShowAverageRatingScreen()
	{
		clsShowAverageRatingScreen::ShowAverageRatingScreen();
	}

	static void _ShowAdditionalMovieStaticsScreen()
	{
		clsAdditionalMovieStaticsScreen::ShowAdditionalMovieStaticsScreen();
	}

	static void _ShowTextBasedRatingCategoryScreen()
	{
		clsTextBasedRatingCategoryScreen::ShowTextBasedRatingCategoryScreen();
	}

	static void _PerformOption(enMainMenuOptions Option)
	{

		switch (Option)
		{
		case enMainMenuOptions::eAddNewMovie:
			system("cls");
			_ShowAddNewMovieScreen();
			GoToTheMainMenu();
			break;

		case enMainMenuOptions::eDeleteMovie:
			system("cls");
			_ShowDeleteMovieScreen();
			GoToTheMainMenu();
			break;

		case enMainMenuOptions::eEditMovie:
			system("cls");
			_ShowEditMovieScreen();
			GoToTheMainMenu();
			break;


		case enMainMenuOptions::eShowAllMovies:
			system("cls");
			_ShowAllMoviesScreen();
			GoToTheMainMenu();
			break;

		case enMainMenuOptions::eFilterMoviesByYear:
			system("cls");
			_ShowFilterMoviesByYearScreen();
			GoToTheMainMenu();
			break;


		case enMainMenuOptions::eFilterMoviesByRatingThreShold:
			system("cls");
			_ShowFilterMoviesByRatingThreSholdScreen();
			GoToTheMainMenu();
			break;



		case enMainMenuOptions::eSearchMovieByName:
			system("cls");
			_ShowSearchMovieByNameScreen();
			GoToTheMainMenu();
			break;


		case enMainMenuOptions::eSortMoviesByRating:
			system("cls");
			_ShowSortMoviesByRatingScreen();
			GoToTheMainMenu();
			break;

		case enMainMenuOptions::eShowHighestRatesMovies:
			system("cls");
			_ShowHighestRatesMoviesScreen();
			GoToTheMainMenu();
			break;

		case enMainMenuOptions::eShowAverageRating:
			system("cls");
			_ShowAverageRatingScreen();
			GoToTheMainMenu();
			break;

		case enMainMenuOptions::eAdditionalMovieStatics:
			system("cls");
			_ShowAdditionalMovieStaticsScreen();
			GoToTheMainMenu();
			break;


		case enMainMenuOptions::eTextBasedRatingCategory:
			system("cls");
			_ShowTextBasedRatingCategoryScreen();
			GoToTheMainMenu();
			break;

		case enMainMenuOptions::eExit:
			break;
		}
	}

public:

	static void ShowMovieMainMenu()
	{
		system("cls");

		cout << "\n\n\t\t\t_______________Movies Manger________________" << endl;
		cout << "\t\t\t\t[1]  Add New Movie.  " << endl;
		cout << "\t\t\t\t[2]  Delete Movie.  " << endl;
		cout << "\t\t\t\t[3]  Edit Movie.  " << endl;
		cout << "\t\t\t\t[4]  Show All Movies.  " << endl;
		cout << "\t\t\t\t[5]  Filter Movies By Year.  " << endl;
		cout << "\t\t\t\t[6]  Filter Movies By Rating ThreShold.  " << endl;
		cout << "\t\t\t\t[7]  Search Movie By Name.  " << endl;
		cout << "\t\t\t\t[8]  Sort Movies By Rating.  " << endl;
		cout << "\t\t\t\t[9]  Show Highest Rates Movies.  " << endl;
		cout << "\t\t\t\t[10] Show Average Rating.  " << endl;
		cout << "\t\t\t\t[11] Additional Movie Statics.  " << endl;
		cout << "\t\t\t\t[12] Text Based Rating Category.  " << endl;
		cout << "\t\t\t\t[13] Exit.  " << endl;
		cout << "\t\t\t______________________________________________" << endl;

		_PerformOption((enMainMenuOptions)_ReadOption());
	}
};

