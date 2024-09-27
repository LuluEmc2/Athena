#include <isbn.hpp>

#include <algorithm>

#include <nlohmann/json.hpp>
#include <httplib.h>

string remove_quotes(const string input) {
    string result = input;

    if (!result.empty() && result.front() == '"') {
        result.erase(result.begin());
    }

    if (!result.empty() && result.back() == '"') {
        result.erase(result.end() - 1);
    }

    if (!result.empty() && result.front() == '\'') {
        result.erase(result.begin());
    }

    if (!result.empty() && result.back() == '\'') {
        result.erase(result.end() - 1);
    }

    return result;
}

tuple<string, string, int> GetDocISBN(long int ISBN)
{
    httplib::Client cli("https://openlibrary.org");

    cli.set_follow_location(true);

    auto api_result = cli.Get("/isbn/" + to_string(ISBN) + ".json");

check_http_code:

    switch(api_result->status)
    {
        case 200:
            break;
        case 301:
        case 302:
        case 303:
        case 307:
        case 308:
            api_result = cli.Get("/");
            goto check_http_code;
        default:
            return {HTML_ERROR_TEXT, "", api_result->status};
    }

    nlohmann::json book_data = nlohmann::json::parse(api_result->body);

    string title = book_data.value(TITLE_PROPERTY, "");

    string description = book_data.value(DESCRIPTION_PROPERTY, "");

    int pages = book_data.value(PAGES_PROPERTY, 0);

    return {title, description, pages};
}