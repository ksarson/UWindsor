/*	Name:		Kolby Sarson
	SID:		104232327
	Homework:	Assignment 3
	Due Date:	February 26, 2018
	Class:		COMP 3400
*/

#include <regex> // for regular expression support
#include <vector>
#include <memory> // for std::make_shared and std::shared_ptr
#include <string>
#include <cstring> // for C's strcmp (see below)
#include <experimental/optional> // for std::optional
#include <iostream>
#include <experimental/filesystem> // for filesystem support

class program_input
{
public:
  virtual ~program_input() { } // necessary to properly deallocate memory
  virtual bool read() = 0;
};

using all_inputs_type = std::vector<std::shared_ptr<program_input>>;

class yob_baby_name_file : public program_input 
{
private:
	std::string fname_;
	unsigned year_;
public:
	yob_baby_name_file(std::string fname, unsigned year) 
	{
		fname_ = fname;
		year_ = year;
	}
	bool read() override
	{
		std::cout << "Reading yob_baby_name_file " << fname_ << " for year " << year_ << "\n";
		return true;
	}
};



std::vector<bool> read_all_inputs(all_inputs_type& ai)
{
  std::vector<bool> retval;
  retval.reserve(ai.size());
  for(auto i : ai)
  {
  	try { retval.push_back(i->read());} catch (...) { retval.push_back(false);}
  }
  return std::move(retval); // i.e., return a default constructed std::vector<bool>
}


std::ostream& output_usage(std::ostream& os, int /*argc*/, char *argv[])
{
  os << "Usage: " << argv[0] << " -d <directory>\n";
  return os;
}

int main(int argc, char* argv[]){

	namespace fs = std::experimental::filesystem;
	using namespace std;

	if (argc == 1)
		output_usage(cerr, argc, argv);

	experimental::optional<string> scan_directory;

	for (int args_pos=1; args_pos < argc; ++args_pos)
	{
	  if (strcmp(argv[args_pos], "-d") == 0)
	  {
	  	if (args_pos + 1 >= argc)
	  	{
	  		output_usage(cerr, argc, argv) << "\tNOTE: The d- option appears without a <directory> argument.\n";
	  		return 2;
	  	} 
	  	else
	  	{
	  		args_pos++;
	  		scan_directory = argv[args_pos];
	  		continue;
	  	}
	  }
	  else
	  	output_usage(cerr, argc, argv) << "\tNOTE: Invalid argument(s) provided.\n";
	}

	all_inputs_type all_inputs; // this variable will hold all discovered program input files
	for (auto& entry : fs::recursive_directory_iterator(scan_directory.value()))
	{
		if (!fs::is_regular_file(entry))
  			continue;

  		// determine if file anme is of the form yobYYYY.txt...
		static regex const baby_name_file_regex( R"(yob(\d{4}).txt)" );

		smatch mr; // variable to hold regex matched results
		string const fname = entry.path().filename(); // only match the filename

		if (regex_match(fname, mr, baby_name_file_regex))
		{
		  // regex_match() only returns true when the match is successful
		  all_inputs.push_back(make_shared<yob_baby_name_file>(fname, stoul(mr[1].str(), nullptr)));
		}
	}
	read_all_inputs(all_inputs); // i.e., process all discovered input (files)
}