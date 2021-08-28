#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <regex>
#include <sstream>

#include "args.h"

std::string ReplaceSeperator(std::string path, unsigned short sys)
{
  std::regex sep_re("\\\\|/");
  return std::regex_replace(path, sep_re, (sys ? "\\" : "/"));
}

std::vector<std::string> TokenizePath(std::string path)
{
  // matches both separators
  std::regex sep_re("\\\\|/");
  // finds paths that are relative but starts without "./"
  std::regex hidden_rel_re("^([^\\\\/\\.])");
  std::smatch m;
  std::vector<std::string> res;

  // appends "./" when path is implicitly relative
  path = std::regex_replace(path, hidden_rel_re, "./$1");

  // split path string into vector of tokens
  while (std::regex_search(path, m, sep_re))
  {
    int pos = m.position();
    res.push_back(path.substr(0, pos));
    path = path.substr(pos + 1);
  }

  // push last segment of path
  if (path.length() > 0)
    res.push_back(path);

  return res;
}

void PrependBase_path(std::vector<std::string> &tokens)
{
  // when first token points to current dir, prepend path to current
  if (tokens[0] == (std::string) ".")
  {
    std::vector<std::string> base_path = TokenizePath((std::string)std::filesystem::current_path());
    tokens.insert((tokens.begin() + 1), base_path.begin(), base_path.end());
    tokens.erase(tokens.begin());
  }
}

std::vector<std::string> ParseTokens(std::vector<std::string> tokens);

std::string ParsePath(parsed_args arg)
{
  std::regex
      abs_reg("^(?:\\\\|/).*$"),
      curr_reg("^\\.$"),
      up_reg("^\\.\\.$"),
      win_beg_reg("^\\\\([A-Z]:\\\\)");

  std::vector<std::string>
      base_path,
      path,
      result;

  // stream will serve in joing result path array
  std::stringstream ss;

  // check if relative path is taken into account (when path is absolute ignore it even when given)
  if (arg.rel.length() == 0 || std::regex_match(arg.path, abs_reg))
    arg.rel = ".";

  // tokenize base_path and path
  base_path = TokenizePath(arg.rel);
  path = TokenizePath(arg.path);

  // adds array of entries from root to curr dir if base_path path is relative
  PrependBase_path(base_path);

  // concatenate base_path with path
  path.insert(path.begin(), base_path.begin(), base_path.end());

  // build a result path array
  for (size_t i = 0; i < path.size(); i++)
  {
    // ignore "."
    if (std::regex_match(path[i], curr_reg))
      continue;
    // remove last entry on ".."
    else if (std::regex_match(path[i], up_reg))
      result.pop_back();
    // push entry otherwise
    else
      result.push_back(path[i]);
  }

  // iterate result and join with separator
  for (std::vector<std::string>::iterator i = result.begin(); i != result.end(); ++i)
  {
    // if not on last entry, append desired separator
    ss << *i << (i == result.end() - 1 ? "" : arg.sys == 0 ? "/" : "\\");
  }

  return std::regex_replace(ss.str(), win_beg_reg, "$1");
};
