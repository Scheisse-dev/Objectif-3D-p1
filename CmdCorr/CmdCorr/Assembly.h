#include "Domain/AppDomain.h"
#include "Command/CD/CdCommand.h"
REGISTER_CLASS(CdCommand)
#include "Command/CLS/ClsCommand.h"
REGISTER_CLASS(ClsCommand)
#include "Command/Drives/DrivesCommand.h"
REGISTER_CLASS(DrivesCommand)
#include "Command/Echo/EchoCommand.h"
REGISTER_CLASS(EchoCommand)
#include "Command/Exit/ExitCommand.h"
REGISTER_CLASS(ExitCommand)
#include "Command/Help/HelpCommand.h"
REGISTER_CLASS(HelpCommand)
#include "Command/TaskList/TaskListCommand.h"
REGISTER_CLASS(TaskListCommand)
#include "Command/Time/TimeCommand.h"
REGISTER_CLASS(TimeCommand)
#include "Command/Tree/TreeCommand.h"
REGISTER_CLASS(TreeCommand)
#include "Command/Type/TypeCommand.h"
REGISTER_CLASS(TypeCommand)
#include "Object/Object.h"
REGISTER_CLASS(Object)

