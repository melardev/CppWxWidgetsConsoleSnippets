#pragma once
#include <wx/wx.h>

namespace StringUsage
{
	void main()
	{
		// The Make methods(i.e: MakeCapitalized()) change the string itself
		// the others(i.e Lower()) return another different string with the requested transformation.
		wxString someString("the quick brown fox jumps over the lazy dog");
		wxPrintf("Lower: %s\n", someString.Lower());

		someString.LowerCase(); // Same as MakeLower() but MakeLower returns the string
		wxPrintf("After LowerCase(): %s\n", someString);


		wxPrintf("MakeCapitalized: %s\n", someString.MakeCapitalized());

		wxPrintf("After MakeCapitalized(): %s\n", someString);

		wxPrintf("Upper(): %s\n", someString.Upper());

		wxPrintf("After .Upper(): %s\n", someString);

		someString.UpperCase(); // Same as MakeUpper() but MakeUpper returns the string
		wxPrintf("After UpperCase(): %s\n", someString);

		someString.Append("___Appended");
		someString.Prepend("Prepended___");

		wxPrintf("%s", someString);
	}
}
