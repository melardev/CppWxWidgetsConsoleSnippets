#pragma once
#include <wx/string.h>
#include <wx/wxcrtvararg.h>

namespace StringFormatUsage
{
	void main()
	{
		// wxString::Format(format, args...) returns a wxString
		wxPrintf("%s\n", wxString::Format("Username: %s\n", "Melardev"));
		wxPrintf("%s\n", wxString::Format("I ate %d apples\n", 3));
		wxPrintf("%s\n", wxString::Format("My mouse is at position (%.2f,%.2f)\n", 340.f, 225.f));
	}
}
