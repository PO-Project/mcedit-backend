#include "ExampleTool.hpp"
#include "MceditBackend.hpp"

int main(){
    tools::ExampleTool tool;
    backends::MceditBackend backend;
    backend.setTool(tool);
    tool.setBackend(backend);
    backend();
}
