/**
 * @file resource_exception.hpp
 * @author Gnik Droy
 * @brief File containing exceptions related to resource management.
 *
 */
#pragma once
#include <stdexcept>
#include <string>

namespace sq
{

/** The types of resource the game uses. */
enum resource_type
{
  /** A sfml texture object. */
  TEXTURE,
};

/**
 * @brief Class for managing resource_not_found exceptions.
 */
class resource_not_found : public std::runtime_error
{
private:
  /** The identifier/name of the resource. */
  std::string name;
  /** The type of the resource. */
  sq::resource_type type;

public:
  /**
   * @brief Constructs the exception.
   * @param rtype The resource type
   * @param rname The name/identifier of the resource.
   */
  resource_not_found(sq::resource_type rtype, const std::string &rname);

  /**
   * @brief Constructs the exception.
   * @param rtype The resource type
   * @param rname The name/identifier of the resource.
   * @param msg The custom exception message.
   */
  resource_not_found(sq::resource_type rtype, const std::string &msg, const std::string &rname);

  /**
   * @brief Returns the resource name.
   * @return The resource name.
   */
  const std::string &get_resource_name() const;

  /**
   * @brief Returns the resource type.
   * @return The resource type.
   */
  sq::resource_type get_resource_type() const;
};
} // namespace sq