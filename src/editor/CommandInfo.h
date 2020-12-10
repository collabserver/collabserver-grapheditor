#pragma once

#include <string>

/**
 * \brief
 * Command description and information.
 *
 * Information about one command.
 */
class CommandInfo {
   private:
    std::string _name;
    std::string _shortname;
    std::string _usage;
    std::string _description;

   public:
    CommandInfo(const std::string& name, const std::string& shortname, const std::string& usage,
                const std::string& description) {
        _name = name;
        _shortname = shortname;
        _usage = usage;
        _description = description;
    }

   public:
    const std::string& getName() const { return _name; }
    const std::string& getShortname() const { return _shortname; }
    const std::string& getUsage() const { return _usage; }
    const std::string& getDescription() const { return _description; }
};
