#pragma once
#pragma once

#include <wx/wx.h>
#include <wx/process.h>
#include <wx/string.h>
#include <wx/txtstrm.h>

namespace ExecuteProcess
{
	void main()
	{
		wxProcess proc;
		proc.Redirect();
		long flags = wxEXEC_ASYNC | wxEXEC_SHOW_CONSOLE;

		// To hide the window of the process use this flag.
		//  flags |= wxEXEC_HIDE_CONSOLE;


		// You may use the pid later one, to kill the process for example
		long pid = wxExecute("whoami", flags, &proc);
		wxSleep(1);
		wxString input;

		// there is no waitForFinish method so we have to make sure
		// to sleep a little bit to let the process to have some output
		// as long as it has output we keep reading
		// If we don't sleep, it may not give an output YET, so the while loop
		// will not be executed
		while (proc.IsInputAvailable())
		{
			wxInputStream* processInputStream = proc.GetInputStream();
			wxTextInputStream tis(*processInputStream);
			input.Append(tis.ReadLine() + "\r\n");
		}

		while (proc.IsErrorAvailable())
		{
			wxInputStream* processInputStream = proc.GetInputStream();
			wxTextInputStream tis(*processInputStream);
			wxTextInputStream tes(*proc.GetErrorStream());
			input.Append(tis.ReadLine() + "\r\n");
		}

		wxPrintf("%s\n", input);
	}
}
