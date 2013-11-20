#include "TestPlan.hpp"
using namespace std;
using namespace IoDbg;

TestActionType TestPlan::actionType(ActivityLogLine entry) const
{
    return label_actions.find(entry.label)->second;
}

void TestPlan::setAction(std::string label, TestActionType action)
{
    label_actions[label] = action;

    // also ignore replays for this label
    // (if we did not, tests would fail)
    label_actions[label + "Replay"] = TestActionType::ignore;
}
