#pragma once
#include <wx/wx.h>

namespace SubString
{
	static void main()
	{
		const wxString text(wxT("wxWidgets substrings snippet - Cpp - By MelarDev"));
		if (text.Find(wxT('-')) != wxNOT_FOUND)
		{
			// Before() is the same as BeforeLast()
			// After() is the same as AfterFirst()
			const wxString lesson = text.BeforeFirst('-').Strip();
			const wxString author = text.AfterLast('-').Strip(wxString::leading);

			wxPrintf("Lesson: %s\nAuthor: %s\n", lesson, author);

			// Find and Index are the same, Index calls Find behind the scenes
			const size_t indexOfw = text.Index(wxChar(wxT('w')));
			const size_t indexOfW = text.Find(wxChar(wxT('W')));
			const size_t indexOfB = text.Find(wxChar(wxT('B')));
			const size_t indexOfNonexistent = text.Find(wxChar(wxT('z')));

			wxPrintf("First(w-W): %s\n", text.Mid(indexOfw, indexOfW));
			wxPrintf("Second(B-End): %s\n", text.Mid(indexOfB, text.Length()));
			// Unsigned gives max int(unsigned)
			wxPrintf("Non existent index value : %llu\n", indexOfNonexistent);
			// But I prefer to prefer to check against max int, signed => -1
			// wxPrintf("Was Not Found? %d", indexOfNonexistent == -1);
			// or:
			if (indexOfNonexistent == -1)
			{
				wxPuts("z was not found");
			}
		}
		else
		{
			wxPuts("String does not contains '-' token needed for this snippet");
		}
	}
}
