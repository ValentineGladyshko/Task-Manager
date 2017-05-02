#include "UpdatingTask.h"
#include "Updatef.h"


bool TaskManager::UpdatingTask::WantUpdate()
{
	Updatef^ form = gcnew Updatef;
	form->ShowDialog();
	return (form->flagDel == 1);
}
