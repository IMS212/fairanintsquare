#pragma once
#include <stdexcept>
#include <string>

namespace sq
{
enum resource_type
{
  TEXTURE,
};

class resource_not_found : public std::runtime_error
{
private:
  std::string name;
  sq::resource_type type;

public:
  resource_not_found(sq::resource_type rtype, const std::string &rname);
  resource_not_found(sq::resource_type rtype, const std::string &msg, const std::string &rname);
  const std::string &get_resource_name() const;
  sq::resource_type get_resource_type() const;
};
} // namespace sq