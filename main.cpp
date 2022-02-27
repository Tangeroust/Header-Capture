#include <iostream>
#include <cpr/cpr.h>

using std::cout;
using std::string;
using std::cin;

int main() {

    string urlAddr = "http://httpbin.org";
    string startTag = "<h1>";
    string endTag = "</h1>";

    size_t start = 0;
    size_t sizeAnsw = 0;

    cpr::Response resp;

    resp = cpr::Get(cpr::Url(urlAddr + "/html"),
                    cpr::Header({{"accept", "text/html"}}));

    start =  resp.text.find(startTag) + startTag.size();
    sizeAnsw = resp.text.find(endTag) - start;

    cout << string(resp.text, start, sizeAnsw);

    return 0;
}