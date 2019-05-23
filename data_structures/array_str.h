#pragma once
#include <wx/wx.h>

namespace ArrayStringUsage
{
	void main()
	{
		wxArrayString arrayString;
		arrayString.Add("Qt");
		arrayString.Add("wxWidgets", 2);
		arrayString.Add("Boost");
		arrayString.Add("ZeroMQ");
		arrayString.Add("OpenSSL");
		arrayString.Add("MFC");
		arrayString.Add("Python", 0);


		wxPrintf("There are %llu items in the array\n\n", arrayString.GetCount());

		wxAssertIsEqual(arrayString.GetCount(), arrayString.Count());

		if (arrayString.Index("wxWidgets") != wxNOT_FOUND)
		{
			wxPrintf("wxWidgets was found\n");
		}

		// second param is case sensitivity
		if (arrayString.Index("mfc", false) != wxNOT_FOUND)
		{
			wxPrintf("MFC was found\n");
		}

		if (arrayString.Index("Python", false) != wxNOT_FOUND)
		{
			// this won't happen
			wxPrintf("Python was found\n");
		}

		if (!arrayString.IsEmpty())
		{
			for (size_t i = 0; i < arrayString.size(); ++i)
			{
				const wxString& itemString = arrayString.Item(i);
				wxPrintf("%s\n", itemString);
			}
		}

		arrayString.Empty();
		wxPrintf("Array contains %llu elements now", arrayString.GetCount());
	}
}
