#include <map>
#include <set>
#include <string>

#include "a05-provided.hxx"

auto inverse(std::map<std::string,std::size_t> const& m) ->
  std::map<std::size_t,std::set<std::string>>
{
	std::map<std::size_t,std::set<std::string>> retval;

	for (auto kv : m){
		auto result = retval.insert(make_pair(kv.second, std::set<std::string>{}));
		result.first->second.insert(kv.first);
	}

	return retval;
}

