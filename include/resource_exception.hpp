/**
 * @file resource_exception.hpp
 * @author Gnik Droy
 * @brief File containing exceptions related to resource management.
 *
 */
#pragma once
#include <stdexcept>
#include <string>

namespace sq {

/** The types of resource the game uses. */
enum class ResourceType {
    /** A sfml texture object. */
    TEXTURE,
};

/**
 * @brief Class for managing resourceNotFound exceptions.
 */
class ResourceNotFound : public std::runtime_error {
private:
    /** The identifier/name of the resource. */
    std::string name;
    /** The type of the resource. */
    sq::ResourceType type;

public:
    /**
   * @brief Constructs the exception.
   * @param rtype The resource type
   * @param rname The name/identifier of the resource.
   */
    ResourceNotFound(sq::ResourceType rtype, const std::string& rname);

    /**
   * @brief Constructs the exception.
   * @param rtype The resource type
   * @param rname The name/identifier of the resource.
   * @param msg The custom exception message.
   */
    ResourceNotFound(sq::ResourceType rtype, const std::string& msg, const std::string& rname);

    /**
   * @brief Returns the resource name.
   * @return The resource name.
   */
    const std::string& getResourceName() const;

    /**
   * @brief Returns the resource type.
   * @return The resource type.
   */
    sq::ResourceType getResourceType() const;
};
} // namespace sq
