#pragma once
#include <iostream> 
#include"Objects/clsMovie.h"
#include"Libraries/clsInputValidate.h"
#include"Screens/clsScreen.h"
using namespace std;

class clsAddNewMovieScreen:protected clsScreen
{
	static void _ReadNewMovie(clsMovie & Movie)
	{
		
		cout << "\nEnter the movie's release year: ";
	    Movie.Year= clsInputValidate::ReadNumber<short>();

		cout << "\nEnter Rating (0-10): ";
		Movie.Rating= clsInputValidate::ReadNumber<float>();

	}

public:
	static void ShowAddNewMovieScreen()
	{
		_DrawScreenHeader("Add New Movie");

		cout << "\nEnter movie name: ";
		string MovieName = clsInputValidate::ReadString();

		while (clsMovie::IsMovieExist(MovieName))
		{
			cout << "\nThe Name Of Movie already exists,Enter another Movie Name: ";
			MovieName = clsInputValidate::ReadString();
		}

		clsMovie Movie = clsMovie::GetObjectWithModeAddNew(MovieName);

		_ReadNewMovie(Movie);

		clsMovie::enSave SaveMovie = Movie.Save();

		switch (SaveMovie)
		{
		case Movie.Succeeded:
		{
			cout << "\nMovie Added Succesfully-)";
		}
		break;

		case Movie.FailedMovieExists:
		{

			cout << "\nError,Movie already exists";
		}
		break;


		}
	}

};

