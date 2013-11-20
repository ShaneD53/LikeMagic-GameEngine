
#include "ActivityLogLine.hpp"

#include <string>
#include <vector>
#include <map>

namespace IoDbg {

enum class TestActionType
{
    ignore, write, expectAny, expectExact
};

class TestPlan
{
private:
    std::map<std::string, TestActionType> label_actions;

public:

    TestActionType actionType(ActivityLogLine entry) const;
    void setAction(std::string label, TestActionType action);
};

}
