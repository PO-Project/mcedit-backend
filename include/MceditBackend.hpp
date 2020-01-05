#ifndef MCEDITBACKEND_H_
#define MCEDITBACKEND_H_

#include <functional>
#include <memory>
#include <string>

#include "BackendBase.hpp"

namespace backends{

    class MceditBackend : public BackendBase{
        public:
           /* MceditBackend();
            ~MceditBackend();*/
            void bind(const std::string &command, std::function<void()> callback, const std::string &helpMessage) noexcept override {}
            void operator()() override;
            //void setTool(tools::ToolBase &newTool) override;

        protected:
            tools::ToolBase *tool;
    };

}

#endif
