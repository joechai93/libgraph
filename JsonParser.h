#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/ostreamwrapper.h>
#include <string>

    class JsonParser
    {

    public:
        static rapidjson::Document Load(const std::string &filepath)
        {
            using namespace rapidjson;

            std::ifstream ifs{filepath.c_str()};
            if (!ifs.is_open())
            {
                std::cerr << "Could not open file for reading!\n";
                throw std::invalid_argument("Could not open file for reading!\n");
            }

            IStreamWrapper isw{ifs};

            Document doc{};
            doc.ParseStream(isw);

            return doc;
        }

        static void Save(const rapidjson::Document &document, const std::string &filepath)
        {
            using namespace rapidjson;

            std::ofstream ofs{filepath.c_str()};
            if (!ofs.is_open())
            {
                std::cerr << "Could not open file for writing!\n";
            }

            OStreamWrapper osw{ofs};
            Writer<OStreamWrapper> writer2{osw};
            document.Accept(writer2);
        }
    };

#endif
