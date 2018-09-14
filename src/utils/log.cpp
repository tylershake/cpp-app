/** @file
 * Implementation of useful logging functions.
 * A more elaborate description of implementation. (optional)
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
 * @copyright Copyright [year] [organization]
 */

#include <fstream>
#include <cstdlib>

#include <boost/program_options.hpp>
#include <boost/log/core.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/filesystem.hpp>

#include "log.hpp"
#include "exceptions.hpp"
#include "config.hpp"

namespace cpp_log {

namespace logging = boost::log;
namespace logging_keywords = boost::log::keywords;
namespace program_options = boost::program_options;
namespace filesystem = boost::filesystem;

static logging_sources::severity_logger
    <logging_trivial::severity_level> glogger;
static bool initialize_called = false;

void initialize(void) {
    if (!initialize_called) {
        std::string config_file;
        std::string config_dir;
        LogSettings log_settings;
        program_options::variables_map variables_map;
        program_options::options_description description("Log Options");

        // set log and config file
        if (const char* env_h = std::getenv("HOME")) {
            std::string home_dir(env_h);
            log_settings.file = home_dir + "/.cache/" + PROJECT_NAME +
                "/log/cpp_app.log";
            config_dir = home_dir + "/.config/" + PROJECT_NAME;
            config_file = config_dir + "/cpp_app.conf";
        } else {
            throw std::runtime_error("Unable to find user home directory");
        }

        // setup options
        description.add_options()
            ("logger.level",
                program_options::value<std::string>
                    (&log_settings.level)->required(),
                "Logger severity level setting");

        // load conf file
        std::ifstream conf_file(config_file.c_str(),
            std::ifstream::in);
        if (!conf_file) {
            // copy config file from package
            // TODO(user): there probably is a smarter way to do this
            conf_file.close();
            conf_file.clear();
            std::string pkg_config("./config/cpp_app.conf");
            conf_file.open(pkg_config.c_str(), std::ifstream::in);
            if (!conf_file) {
                conf_file.close();
                conf_file.clear();
                pkg_config = "../config/cpp_app.conf";
                conf_file.open(pkg_config.c_str(), std::ifstream::in);
                if (!conf_file) {
                    conf_file.close();
                    conf_file.clear();
                    pkg_config = "../../config/cpp_app.conf";
                    conf_file.open(pkg_config.c_str(), std::ifstream::in);
                    if (!conf_file) {
                        throw std::runtime_error("Missing configuration file");
                    }
                }
            }
            filesystem::create_directories(config_dir);
            filesystem::copy_file(pkg_config, config_file);
            conf_file.close();
            conf_file.clear();
            conf_file.open(config_file.c_str(), std::ifstream::in);
        }
        program_options::store(
            program_options::parse_config_file(conf_file, description, true),
            variables_map);
        conf_file.close();
        program_options::notify(variables_map);

        if (log_settings.level == "TRACE") {
            logging::core::get()->set_filter(
                logging_trivial::severity >= logging_trivial::trace);
        } else if (log_settings.level == "DEBUG") {
            logging::core::get()->set_filter(
                logging_trivial::severity >= logging_trivial::debug);
        } else if (log_settings.level == "INFO") {
            logging::core::get()->set_filter(
                logging_trivial::severity >= logging_trivial::info);
        } else if (log_settings.level == "WARNING") {
            logging::core::get()->set_filter(
                logging_trivial::severity >= logging_trivial::warning);
        } else if (log_settings.level == "ERROR") {
            logging::core::get()->set_filter(
                logging_trivial::severity >= logging_trivial::error);
        } else if (log_settings.level == "FATAL") {
            logging::core::get()->set_filter(
                logging_trivial::severity >= logging_trivial::fatal);
        } else {
            throw std::invalid_argument(
                "Invalid logfile severity setting in config file");
        }

        // setup logger
        logging::register_simple_formatter_factory
            <logging_trivial::severity_level, char>("Severity");
        logging::add_file_log(
            log_settings.file,
            logging_keywords::auto_flush = true,
            logging_keywords::open_mode = std::ios_base::app,
            logging_keywords::format = "%TimeStamp% <%Severity%> %Message%");
        logging::add_common_attributes();
        initialize_called = true;
    }
}

void log_trace(const char* message, const char* file, int line) {
    if (initialize_called) {
        BOOST_LOG_SEV(glogger, logging_trivial::trace) << "[" << basename(file)
        << ": " << line << "]: " << message;
    } else {
        throw std::runtime_error("Logger not initialized");
    }
}

void log_debug(const char* message, const char* file, int line) {
    if (initialize_called) {
        BOOST_LOG_SEV(glogger, logging_trivial::debug) << "[" << basename(file)
        << ": " << line << "]: " << message;
    } else {
        throw std::runtime_error("Logger not initialized");
    }
}

void log_info(const char* message, const char* file, int line) {
    if (initialize_called) {
        BOOST_LOG_SEV(glogger, logging_trivial::info) << "[" << basename(file)
        << ": " << line << "]: " << message;
    } else {
        throw std::runtime_error("Logger not initialized");
    }
}

void log_warning(const char* message, const char* file, int line) {
    if (initialize_called) {
        BOOST_LOG_SEV(glogger, logging_trivial::warning) << "["
        << basename(file) << ": " << line << "]: " << message;
    } else {
        throw std::runtime_error("Logger not initialized");
    }
}

void log_error(const char* message, const char* file, int line) {
    if (initialize_called) {
        BOOST_LOG_SEV(glogger, logging_trivial::error) << "[" << basename(file)
        << ": " << line << "]: " << message;
    } else {
        throw std::runtime_error("Logger not initialized");
    }
}

void log_fatal(const char* message, const char* file, int line) {
    if (initialize_called) {
        BOOST_LOG_SEV(glogger, logging_trivial::fatal) << "[" << basename(file)
        << ": " << line << "]: " << message;
    } else {
        throw std::runtime_error("Logger not initialized");
    }
}

}  // namespace cpp_log
