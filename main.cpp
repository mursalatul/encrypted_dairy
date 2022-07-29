#include<iostream>
#include<string>

using namespace std;
typedef signed long long int ll;

// function pre-define
// convert the argument into binary form
string binary(ll num);
// convert the whole string into 8-bit binary form
string to_binary(string text);

int main()
{
	cout << "Text: ";
	string text, binary_text;
	getline(cin, text);
	binary_text = to_binary(text);
	cout << binary_text;
	return 0;
}

// function declarations
string binary(ll num)
{
	// b will store the binary form of num, [but in reverse order]
	string b;
	while (num)
	{
		if (num != 0)
		{
			b.append(to_string(num % 2));
			num /= 2;
		}
	}
	string bb(b.rbegin(), b.rend()); // reversing b and storing in bb
	return bb;
}

string to_binary(string text)
{
	ll text_size = text.size();
	string bin_str, binary_string;
	// convert each indivitual char of the string
	for (ll i = 0; i < text_size; i++)
	{
		bin_str = binary(text[i]); // char -> binary
		if (bin_str.size() != 8) // 8 bit or not
			bin_str.insert(0, 8 - bin_str.size(), '0'); // making 8-bit binary
		binary_string.append(bin_str);
		binary_string.append(" ");
	}
	return binary_string;
}