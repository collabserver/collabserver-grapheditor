#pragma once

#include <cassert>
#include <string>
#include <vector>
#include <iostream>

#include "utils.h"
#include "CommandInfo.h"


/**
 * \brief
 * Command interface. (Command design pattern)
 */
class Command {
    private:
        std::string _name;
        std::string _shortname;
        std::string _help;
        std::string _resume;

    protected:
        Command(const CommandInfo& info) {
            _name       = info.getName();
            _shortname  = info.getShortname();
            _help       = info.getUsage();
            _resume     = info.getDescription();
        }

    public:
        virtual ~Command() = default;

    public:
        virtual int exec(utils::config config, const std::vector<std::string> &arguments) = 0;

    public:
        const std::string& getName() const { return _name; }
        const std::string& getShortName() const { return _shortname; }
        const std::string& getHelp() const { return _help; }
        const std::string& getResume() const { return _resume; }
};


