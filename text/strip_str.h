#pragma once
#include <wx/wx.h>

namespace StripString
{
	static void main()
	{
		const wxString text("\t\tWx Widgets is not only a GUI Framework\t.\n");

		wxPuts("Raw");
		wxPuts(text);
		wxPuts("Stripped (By default only trailing)");
		wxPuts(text.Strip());
		const wxString stripped = text.Strip(wxString::both); //both, leading, trailing(default)
		wxPuts("Stripped in both sides");
		wxPuts(stripped);
	}
}
