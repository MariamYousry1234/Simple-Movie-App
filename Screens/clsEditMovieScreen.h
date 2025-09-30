#pragma once
#include <iostream> 
#include"Screens/clsScreen.h"
#include"Libraries/clsInputValidate.h"
#include"Objects/clsMovie.h"
#include<iomanip>
using namespace std;

class clsEditMovieScreen :protected clsScreen
{
	static string _ReadMoviesName()
	{
		cout << "Enter the name of the movie you want to edit: ";
		string MovieName = clsInputValidate::ReadString();

		while (!clsMovie::IsMovieExist(MovieName))
		{
			cout << "\nThe Movie is Not Found-(\nEnter Another Movie Name To edit: ";
			MovieName = clsInputValidate::ReadString();
		}

		return MovieName;
	}

	static void _ShowMovieDetails(clsMovie Movie)
	{
		cout << "\nThere is Movie Details:\n\n";
		cout << setw(15) << left << "Name" << setw(10) << left << "Year" << setw(10) << left << "Rating";
		cout << "\n________________________________________________\n";

		cout << setw(15) << left << Movie.Name <<
			setw(10) << left << to_string(Movie.Year)
			<< setw(10) << left << to_string(Movie.Rating) << endl;
		cout << "\n________________________________________________\n";
	}

	static void _EditMovie(clsMovie& Movie)
	{

		cout << "\nEnter New Release Year: ";
		Movie.Year=clsInputValidate::ReadNumber<short>();

		cout << "\nEnter New Rating (0-10): ";
		 Movie.Rating= clsInputValidate::ReadNumber<float>();

		
	}

public:

	static void ShowEditMovieScreen()
	{
		_DrawScreenHeader("Edit Movie Screen");

		string MovieName = _ReadMoviesName();

		clsMovie Movie = clsMovie::Find(MovieName);

		_ShowMovieDetails(Movie);

		_EditMovie(Movie);

		clsMovie::enSave Save = Movie.Save();

		switch (Save)
		{
		case clsMovie::FailedEmptyObject:
		{
			cout << "\nError,Movie didn't Update";
		}
			break;
		case clsMovie::Succeeded:
		{
			cout << "\nMovie Updated Successfully...";
		}
			break;
	
		
		}
	}
};

