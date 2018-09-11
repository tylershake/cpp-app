/** @file
 * An example exception.
 * A more elaborate description of exceptions. (optional)
 *
 * @author [organization]
 * @author [name] (optional)
 *
 * @par [unique category]
 * [designation]
 *
 * @par Notifications
 * [distribution designation]
 * [other designations]
 *
 * Copyright [year] [organization]
 */

#ifndef SRC_UTILS_EXCEPTIONS_HPP_
#define SRC_UTILS_EXCEPTIONS_HPP_

#include <exception>
#include <stdexcept>

/**
 * Includes exceptions for CPP project.
 */
namespace cpp_exceptions {

/**
 * An example exception.
 * A more elaborate description of example exception.
 */
struct ExampleException : public std::exception {
	/**
	 * Exception member function
	 * @return	exception statement
	 */
    const char* what() const throw() {
        return "Example exception";
    }
};

}  // namespace cpp_exceptions

#endif  // SRC_UTILS_EXCEPTIONS_HPP_
