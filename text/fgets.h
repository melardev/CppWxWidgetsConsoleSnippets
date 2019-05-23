#pragma once
#include <wx/wxcrtvararg.h>

namespace FGetsUsage
{
	void main()
	{
		wxPrintf("Just tell me what do you like from wxWidgets\n");
		char input[255];
		if (!wxFgets(input, WXSIZEOF(input), stdin))
			wxPrintf("An error occurred %s", strerror(errno));

		wxPrintf("What you liked was %s", input);
		wxPrintf("It is time to exit this snippet, are you Ok, [(Y)es or (N)o]?\n");

		if (!wxFgets(input, WXSIZEOF(input), stdin))
			wxPrintf("An error occured; %s", strerror(errno));

		if (wxStricmp(input[0], "y") == 0)
			wxPrintf("Ok, see you, bye bye\n");
		else
			wxPrintf("I don't care what you are talking about, I quit anyways, see you\n");
	}
}
