#pragma once
#include <wx/string.h>
#include <wx/utils.h>

namespace ExecCommand
{
	void main()
	{
		const wxString comamnd("ping localhost");
		// by default wxEXEC_ASYNC, in that case it runs it asynchronously, you would need
		// to use wxSleep(10) to let the program open at least 10 seconds so you have the command
		// window to see the program output
		::wxExecute(comamnd, wxEXEC_BLOCK);
	}
}
