#include <bal/abi.h>
#include <brutal/debug.h>
#include <embed/task.h>

TaskId embed_task_self(void)
{
    BrInspectArgs inspect = {
        .handle = BR_HANDLE_SELF,
    };

    assert_br_success(br_inspect(&inspect));
    return (TaskId)inspect.id;
}

void embed_task_exit(TaskId handle, int result)
{
    br_exit(&(BrExitArgs){
        .handle = handle,
        .result = result,
    });
}

void embed_task_abort(TaskId handle)
{
    br_exit(&(BrExitArgs){
        .handle = handle,
        .result = TASK_EXIT_FAILURE,
    });
}
