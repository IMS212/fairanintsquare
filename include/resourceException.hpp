/**
 * @file resource_exception.hpp
 * @author Gnik Droy
 * @brief File containing exceptions related to resource management.
 *
 */
#pragma once
#include <stdexcept>
#include <string>

namespace sq{

/** The types of resource the game uses. */
enum class resourceType{
  /** A sfml texture object. */
  TEXTURE,
};

/**
 * @brief Class for managing resourceNotFound exceptions.
 */
class resourceNotFound : public std::runtime_error{
private:
  /** The identifier/name of the resource. */
  std::string name;
  /** The type of the resource. */
  sq::resourceType type;

public:
  /**
   * @brief Constructs the exception.
   * @param rtype The resource type
   * @param rname The name/identifier of the resource.
   */
  resourceNotFound(sq::resourceType rtype, const std::string &rname);

  /**
   * @brief Constructs the exception.
   * @param rtype The resource type
   * @param rname The name/identifier of the resource.
   * @param msg The custom exception message.
   */
  resourceNotFound(sq::resourceType rtype, const std::string &msg, const std::string &rname);

  /**
   * @brief Returns the resource name.
   * @return The resource name.
   */
  const std::string &getResourceName() const;

  /**
   * @brief Returns the resource type.
   * @return The resource type.
   */
  sq::resourceType getResourceType() const;
};
} // namespace sq
