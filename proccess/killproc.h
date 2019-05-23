#pragma once
#include <wx/utils.h>
#include <wx/wxcrtvararg.h>

/// In this snippet notice the returned exit code of the app, it will be -1
/// and not 0, because this app will be killed
namespace KillProcess
{
	void main()
	{
		wxKillError rc = wxKILL_OK;
		wxGetProcessId();

		// default flat is  wxKILL_NOCHILDREN which does not kill the children processes
		wxKill(wxGetProcessId(), wxSIGKILL, &rc, wxKILL_CHILDREN);

		// Obviously this checks don't make sense here, because the process will be killed at this point
		// But I keep this code here, because this is what you will do when killing other processes
		// you would want to know if it was successful and show a message accordingly
		if (rc != wxKILL_OK)
		{
			wxPrintf("Error");
		}
		else
		{
			wxPrintf("Process killed successfully");
		}
	}
}
