#pragma once

#include <iostream> 
#include<fstream>
#include<string>
#include<vector>
#include"Libraries/clsString.h"
#include<queue>
#include<stack>
#include"Libraries/clsUtil.h"
using namespace std;

class clsMovie
{
	enum enMode{EmptyMode=1,UpdateMode=2,AddNewMode=3};
	enMode _Mode;

	string _Name;
	float _Rating = 0;
	short _Year = 0;

	bool _MarkForDelete = false;


    string _ConvertMovieObjectToLine(clsMovie Movie, string Separator = "#//#")
	{
		string Line = "";

		Line += Movie.Name + Separator;
		Line += to_string(Movie.Year) +Separator;
		Line += to_string(Movie.Rating);

		return Line;
	}

	static clsMovie _ConvertMovieLineToObject(string Line, string Separator = "#//#")
	{
		vector<string>vMovie;

		vMovie = clsString::Split(Line, Separator);

		return clsMovie(enMode::UpdateMode, vMovie[0],stoi(vMovie[1]),stof(vMovie[2]));
	}

	static clsMovie _GetEmptyObject()
	{
		return clsMovie(enMode::EmptyMode, "", 0,0);
	}

	static vector<clsMovie> _LoadMovieDataFromFile()
	{
		vector<clsMovie>vMovies;

		fstream MyFile;

		MyFile.open("Movies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsMovie Movie = _ConvertMovieLineToObject(Line);
				vMovies.push_back(Movie);
			}

			MyFile.close();
		}

		return vMovies;
	}

	void _SaveDataToFile(vector<clsMovie>vMovies)
	{
		fstream MyFile;

		MyFile.open("Movies.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsMovie& M : vMovies)
			{
				if (!M._MarkForDelete)
					MyFile << _ConvertMovieObjectToLine(M) << endl;
			}

			MyFile.close();
		}
	}

	void _UpdateData()
	{
		vector<clsMovie>vMovies;
		vMovies = _LoadMovieDataFromFile();

		for (clsMovie& M : vMovies)
		{
			if (M.GetName() == GetName())
			{
				M= *this;
				break;
			}
		}

		_SaveDataToFile(vMovies);

	}

	void _AddNewMovieToFile(clsMovie Movie)
	{
		fstream MyFile;

		MyFile.open("Movies.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << _ConvertMovieObjectToLine(Movie) << endl;

			MyFile.close();
		}
	}

	void _AddMovie()
	{
		_AddNewMovieToFile(*this);
	}

public:
	clsMovie()
	{

	}

	clsMovie(enMode Mode, string Name, short Year,float Rating)
	{
		_Mode = Mode;
		_Name = Name;
		_Rating = Rating;
		_Year = Year;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	void SetName(string Name)
	{
		_Name = Name;
	}

	string GetName()
	{
		return _Name;
	}

	__declspec(property(get = GetName, put = SetName))string Name;

	void SetRating(float Rating)
	{
		_Rating = Rating;
	}

	float GetRating()
	{
		return _Rating;
	}

	__declspec(property(get = GetRating, put = SetRating))float Rating;

	void SetYear(short Year)
	{
		_Year = Year;
	}

	short GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear))short Year;


	void SetMarkForDelete(bool Set)
	{
		_MarkForDelete = Set;
	}

	bool GetMarkForDelete()
	{
		return _MarkForDelete;
	}

	__declspec(property(get = GetMarkForDelete, put = SetMarkForDelete))bool MarkForDelete;

	static clsMovie Find(string MovieName)
	{
		string Name = clsString::LowerAllString(MovieName);

		fstream MyFile;

		MyFile.open("Movies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsMovie Movie = _ConvertMovieLineToObject(Line);

				if (clsString::LowerAllString(Movie.Name) == Name)
				{
					MyFile.close();
					return Movie;
				}

			}

			MyFile.close();
		}

		return _GetEmptyObject();

	}

	static bool IsYearExist(short Year)
	{
		fstream MyFile;

		MyFile.open("Movies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsMovie Movie = _ConvertMovieLineToObject(Line);

				if (Movie.Year == Year)
				{
					MyFile.close();
					return true;
				}

			}

			MyFile.close();
		}

		return false;

	}

	static bool IsMovieExist(string MovieName)
	{
		clsMovie Movie = clsMovie::Find(MovieName);

		return(!Movie.IsEmpty());
	}

	static clsMovie GetObjectWithModeAddNew(string MovieName)
	{
		return clsMovie(enMode::AddNewMode, MovieName, 0,0);
	}

	bool Delete()
	{
		vector<clsMovie>vMovies;
		vMovies = _LoadMovieDataFromFile();

		for (clsMovie& M : vMovies)
		{
			if (M.GetName()==GetName())
			{
				M.MarkForDelete = true;
				break;
			}
		}
		_SaveDataToFile(vMovies);
		*this = _GetEmptyObject();

		return true;
	}

	enum enSave { FailedEmptyObject = 0, Succeeded = 2, FailedMovieExists = 3 };

	enSave Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return enSave::FailedEmptyObject;
			break;

		case enMode::UpdateMode:

			_UpdateData();

			return enSave::Succeeded;
			break;

		case enMode::AddNewMode:
			if (IsMovieExist(GetName()))
			{

				return enSave::FailedMovieExists;
			}
			else
			{
				_AddMovie();
				_Mode = enMode::UpdateMode;
				return enSave::Succeeded;
			}
			break;
		}

	}

	static vector<clsMovie> GetMoviesList()
	{
		return _LoadMovieDataFromFile();
	}

	static vector<clsMovie>GetMoviesByYear(short Year)
	{
		vector<clsMovie>vMovies;

		fstream MyFile;

		MyFile.open("Movies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsMovie Movie = _ConvertMovieLineToObject(Line);

				if (Movie.Year == Year)
				{
					vMovies.push_back(Movie);			
				}

			}

			MyFile.close();
		}
		
		return vMovies;
	}

	static vector<clsMovie>GetMoviesRatingThreshold(float Rating)
	{
		vector<clsMovie>vMovies;

		fstream MyFile;

		MyFile.open("Movies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsMovie Movie = _ConvertMovieLineToObject(Line);

				if (Movie.Rating >= Rating)
				{
					vMovies.push_back(Movie);
				}

			}

			MyFile.close();
		}

		return vMovies;
	}

	static queue<clsMovie>AscendingMoviesByRating()
	{
		vector<clsMovie>vMovies = _LoadMovieDataFromFile();

		queue<clsMovie> AscendingMovies;

		if (vMovies.empty())
			return AscendingMovies;


		for (int i = 0; i < vMovies.size() - 1; i++)
		{
			for (int j = 0; j < vMovies.size()- 1; j++)
			{
				if (vMovies[j].Rating >= vMovies[j + 1].Rating)
				{
					clsUtil::Swap(vMovies[j], vMovies[j + 1]);
				}
			}
		}

		

		for (clsMovie M : vMovies)
		{
			AscendingMovies.push(M);

	    }

		vMovies.clear();

		return AscendingMovies;
	}

	static stack<clsMovie>DscendingMoviesByRating()
	{
		queue<clsMovie> AscendingMovies= AscendingMoviesByRating();

		stack<clsMovie> DscendingMovies;

		if (AscendingMovies.empty())
			return DscendingMovies;

		while (!AscendingMovies.empty())
		{
			DscendingMovies.push(AscendingMovies.front());
			AscendingMovies.pop();
		}

		return DscendingMovies;
	}

	static vector <clsMovie> MoviesMaxRating()
	{
		vector<clsMovie>vMovies = _LoadMovieDataFromFile();
			
		if (vMovies.size()==0)
			return vMovies;

		float MaxRating = vMovies[0].Rating;

		for (clsMovie M : vMovies)
		{
			if (M.Rating > MaxRating)
			{
				MaxRating = M.Rating;
			}
		}

		vector<clsMovie>vMaxRatingMovies;

		for (clsMovie M : vMovies)
		{
			if (M.Rating == MaxRating)
				vMaxRatingMovies.push_back(M);
		}

		return vMaxRatingMovies;
	}

	static vector <clsMovie> MoviesMinRating()
	{
		vector<clsMovie>vMovies = _LoadMovieDataFromFile();

		if (vMovies.size() == 0)
			return vMovies;

		float MinRating = vMovies[0].Rating;

		for (clsMovie M : vMovies)
		{
			if (M.Rating < MinRating)
			{
				MinRating = M.Rating;
			}
		}

		vector<clsMovie>vMinRatingMovies;

		for (clsMovie M : vMovies)
		{
			if (M.Rating == MinRating)
				vMinRatingMovies.push_back(M);
		}

		return vMinRatingMovies;
	}

	static float GetAverageRating()
	{
		vector<clsMovie>vMovies = _LoadMovieDataFromFile();

		if (vMovies.size() == 0)
			return 0;


		float SumRating = 0;

		for (clsMovie M : vMovies)
		{
			SumRating += M.Rating;
		}
		return SumRating;


		return (SumRating / vMovies.size());
	}

};

