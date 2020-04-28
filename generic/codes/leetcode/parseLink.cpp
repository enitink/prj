#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::string str("<https://dev79169.service-now.com/api/now/v2/table/alm_asset?sysparm_display_value=all&sysparm_limit=300&sysparm_offset=0>;rel=\"first\","
    "<https://dev79169.service-now.com/api/now/v2/table/alm_asset?sysparm_display_value=all&sysparm_limit=300&sysparm_offset=300>;rel=\"next\","
    "<https://dev79169.service-now.com/api/now/v2/table/alm_asset?sysparm_display_value=all&sysparm_limit=300&sysparm_offset=2700>;rel=\"last\"");

    std::string str2("sysparm_offset=");

    std::size_t found = 0;
    int max = 0;
    while ( (found = str.find(str2, found)) != std::string::npos )
    {
        found += str2.length();
        int number = 0;
        while( (str[found] >= '0') && (str[found] <= '9'))
        {
            number = (number * 10) + (str[found] - '0');
            ++found;
        }
        max = (max < number) ? number : max;
    }
    cout << max/300;

    return 0;
}