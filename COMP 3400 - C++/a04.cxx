#include <string>
#include <vector>
#include <ostream>

#include "a04-provided.hxx"
#include "a04-main-provided.hxx"

std::ostream& write_csv_row(
  std::ostream& os, 
  std::vector<std::string> const& v
)
{
	auto length = v.size();
	for(auto i : v){
		write_csv_field(std::cout, i);
		length--;
		if (length != 0)
			os.put(',');
	}
	os.put('\n');
	return os;
}

